#include "cli.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "meta_command.h"

int cli_run(int argc, char *argv[]) {
    printf("argc = %d\n", argc);
    printf("argv[0] = %s\n", argv[0]);

    printf("SQLima\n");

    InputBuffer *user_input_buffer = create_input_buffer();

    while(1) {
        printf("sqlima> ");
        fflush(stdout);

        InputResult input_result = read_input(user_input_buffer);

        switch (input_result) {
            case INPUT_SUCCESS: {
                if (user_input_buffer->buffer[0] == '.') {
                    switch(do_meta_command(user_input_buffer)) {
                        case META_COMMAND_SUCCESS: continue;
                        case META_COMMAND_UNRECOGNIZED_COMMAND: {
                            printf("Comando não reconhecido: '%s'.\n", user_input_buffer->buffer);
                            continue;
                        }
                    }
                }
                continue;
            }
            case INPUT_ERROR_IO: {
                printf("Não foi possível ler a entrada\n");
                return EXIT_FAILURE;
            }
            case INPUT_EOF: {
                return EXIT_SUCCESS;
            }
        }
    }
}
