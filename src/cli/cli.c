#include "cli.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlima.h>

int cli_run(int argc, char *argv[]) {
    printf("argc = %d\n", argc);
    printf("argv[0] = %s\n", argv[0]);

    printf("SQLima %s - Clone educacional do PostgreSQL\n", SQLIMA_VERSION);

    InputBuffer *user_input_buffer = create_input_buffer();

    if (user_input_buffer == NULL) {
        fprintf(stderr, "Erro fatal: falha ao alocar memória para buffer de entrada.\n");
        return EXIT_FAILURE;
    }

    while(1) {
        printf("sqlima> ");
        fflush(stdout);

        InputResult input_result = read_input(user_input_buffer);

        switch (input_result) {
            case INPUT_SUCCESS: {
                if(strcmp(user_input_buffer->buffer, ".exit") == 0) {
                    printf("Você escolheu sair\n");
                    free_input_buffer(user_input_buffer);
                    return EXIT_SUCCESS;
                }
                printf("Comando não reconhecido: '%s'.\n", user_input_buffer->buffer);

                continue;
            }
            case INPUT_ERROR_MEMORY: {
                printf("Não foi possível alocar memoria\n");
                return EXIT_FAILURE;
            }
            case INPUT_ERROR_IO: {
                printf("Não foi possível ler a entrada\n");
                return EXIT_FAILURE;
            }
            case INPUT_EOF: {
                return EXIT_SUCCESS;
            }
            case INPUT_OVERFLOW: {
                return EXIT_FAILURE;
            }
        }
    }
}
