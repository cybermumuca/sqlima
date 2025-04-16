/**
 * @file main.c
 * @brief Ponto de entrada do SQLima CLI
 */
#include "sqlima.h"
#include "cli/cli.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("SQLima %s - Clone educacional do PostgreSQL\n", SQLIMA_VERSION);

    // Inicializa o mecanismo do banco
    if (sqlima_init() != 0) {
        fprintf(stderr, "Falha ao inicializar o SQLima\n");
        return 1;
    }

    // Inicia o loop da CLI
    int result = cli_run(argc, argv);

    // Finaliza e libera recursos
    sqlima_shutdown();

    return result;
}
