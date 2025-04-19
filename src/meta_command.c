#include "meta_command.h"
#include <string.h>
#include <stdlib.h>

/**
 * @brief Executa um meta comando.
 * @param input_buffer O buffer de entrada que contém o comando.
 * @return MetaCommandResult O resultado da execução do meta comando.
*/
MetaCommandResult do_meta_command(InputBuffer *input_buffer) {
    if (strcmp(input_buffer->buffer, ".exit") == 0) {
        exit(EXIT_SUCCESS);
    }

    return META_COMMAND_UNRECOGNIZED_COMMAND;
}
