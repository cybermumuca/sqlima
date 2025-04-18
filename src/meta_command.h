/**
 * @file meta_command.h
 * @brief Funções para manipulação de meta comandos da CLI do SQLima.
 */
#ifndef SQLIMA_META_COMMAND_H
#define SQLIMA_META_COMMAND_H
#include "input.h"

/**
 * @enum MetaCommandResult
 * @brief Enumera possíveis resultados ao executar um metacomando
 *
 * Meta comandos são comandos especiais prefixados com um ponto (ex: .exit, .tables)
 * que controlam o comportamento do CLI do SQLima ao invés de interagir com o banco de dados.
 * Este enum representa os possíveis resultados do processamento desses comandos.
 */
typedef enum {
    META_COMMAND_SUCCESS,              // O meta comando foi reconhecido e executado com sucesso
    META_COMMAND_UNRECOGNIZED_COMMAND  // O meta comando não foi reconhecido
} MetaCommandResult;

/**
 * @brief Executa um meta comando.
 * @param input_buffer O buffer de entrada que contém o comando.
 * @return MetaCommandResult O resultado da execução do meta comando.
*/
MetaCommandResult do_meta_command(InputBuffer *input_buffer);

#endif /* SQLIMA_META_COMMAND_H */
