/**
 * @file cli.h
 * @brief Funções da Interface de Linha de Comando (CLI) do SQLima.
 */
#ifndef SQLIMA_CLI_H
#define SQLIMA_CLI_H

/**
 * @brief Executa o loop principal da CLI.
 *
 * @param argc Número de argumentos da linha de comando.
 * @param argv Vetor de argumentos da linha de comando.
 * @return int Código de saída do programa.
 */
int cli_run(int argc, char *argv[]);

#endif /* SQLIMA_CLI_H */
