/**
 * @file input.h
 * @brief Funções para manipulação de entradas do SQLima.
 */
#ifndef SQLIMA_INPUT_H
#define SQLIMA_INPUT_H

#include <stddef.h>

/**
 * @enum InputResult
 * @brief Resultado da operação de leitura de input
 */
typedef enum {
    INPUT_SUCCESS,          /* Leitura bem-sucedida */
    INPUT_EOF,              /* Fim do arquivo (EOF) encontrado */
    INPUT_ERROR_IO,         /* Erro de I/O */
    INPUT_ERROR_MEMORY,     /* Erro de alocação de memória */
    INPUT_OVERFLOW          /* Tamanho máximo de buffer atingido */
} InputResult;

/**
 * @struct InputBuffer
 * @brief Gerencia um buffer dinâmico para entrada do usuário
 *
 * Mantém estado entre chamadas para permitir crescimento incremental.
 * Responsável pelo ciclo de vida completo da memória alocada.
 */
typedef struct {
    char *buffer;       /* Ponteiro para o texto digitado */
    size_t size;        /* Tamanho total alocado do buffer */
    size_t length;      /* Quantidade de caracteres digitados (sem \0) */
} InputBuffer;

/**
 * @brief Cria e inicializa um novo InputBuffer
 * @return InputBuffer* Buffer inicializado ou NULL em caso de falha
 */
InputBuffer *create_input_buffer(void);

/**
 * @brief Lê toda a entrada do usuário
 * @param input_buffer Buffer onde a entrada será armazenada
 * @return InputResult - Código de resultado da operação
*/
InputResult read_input(InputBuffer *input_buffer);

/**
 * @brief Libera a memória utilizada pelo InputBuffer
 * @param input_buffer O buffer a ser liberado
 */
void free_input_buffer(InputBuffer *input_buffer);

#endif /* SQLIMA_INPUT_H */
