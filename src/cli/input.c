#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @brief Tamanho inicial do buffer de entrada */
#define INPUT_BUFFER_INITIAL_SIZE 24

/**
 * @brief Cria e inicializa um novo InputBuffer
 * @return InputBuffer* inicializado ou NULL em caso de falha
 */
InputBuffer *create_input_buffer(void) {
    InputBuffer *input_buffer = malloc(sizeof(InputBuffer));

    if (input_buffer == NULL) return NULL;

    input_buffer->buffer = malloc(INPUT_BUFFER_INITIAL_SIZE);

    if (input_buffer->buffer == NULL) {
        free(input_buffer);
        return NULL;
    }

    input_buffer->size = INPUT_BUFFER_INITIAL_SIZE;
    input_buffer->length = 0;

    return input_buffer;
}

/**
 * @brief Lê toda a entrada do usuário
 * @param input_buffer Buffer onde a entrada será armazenada
 * @return `InputResult` Código de resultado da operação
*/
InputResult read_input(InputBuffer* input_buffer) {
    if (input_buffer == NULL) {
        return INPUT_ERROR_MEMORY;
    }

    const size_t chunk_size = 64;
    char *current_position = input_buffer->buffer;
    size_t remaining = input_buffer->size - 1;

    while (1) {
        if(fgets(current_position, remaining, stdin) == NULL) {
            if (feof(stdin)) {
                if (input_buffer->length == 0) return INPUT_EOF;

                break;
            }

            return INPUT_ERROR_IO;
        }

        const size_t bytes_read = strlen(current_position);
        input_buffer->length += bytes_read;

        if (bytes_read > 0 && current_position[bytes_read - 1] == '\n') {
            current_position[bytes_read - 1] = '\0';
            input_buffer->length--;
            break;
        }

        current_position += bytes_read;
        remaining -= bytes_read;

        if (remaining < chunk_size) {
            const size_t new_size = input_buffer->size * 2;

            char *new_buffer = realloc(input_buffer->buffer, new_size);

            if (new_buffer == NULL) {
                return INPUT_ERROR_MEMORY;
            }

            current_position = new_buffer + input_buffer->length;
            input_buffer->buffer = new_buffer;
            input_buffer->size = new_size;
            remaining = new_size - input_buffer->length - 1;
        }
    }

    return INPUT_SUCCESS;
}

/**
 * @brief Libera a memória utilizada pelo InputBuffer
 * @param input_buffer O buffer a ser liberado
 */
void free_input_buffer(InputBuffer *input_buffer) {
    free(input_buffer->buffer);
    free(input_buffer);
}
