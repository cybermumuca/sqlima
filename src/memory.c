#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Aloca memória com verificação de falhas
 *
 * @param size Quantidade de bytes para alocar
 * @return Ponteiro para a memória alocada
 */
void *sqlima_malloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, "Erro fatal: sqlima_malloc falhou ao alocar %zu bytes.\n", size);
        exit(EXIT_FAILURE);
    }
    
    return ptr;
}

/**
 * @brief Realoca memória com verificação de falhas
 *
 * Análogo ao sqlima_malloc, mas para realloc. A memória original
 * permanece intacta caso o realloc falhe (embora o processo termine).
 *
 * @param ptr Ponteiro original para realocar
 * @param size Novo tamanho desejado em bytes
 * @return Ponteiro para a memória realocada
 */
void *sqlima_realloc(void *ptr, size_t size) {
    void *new_ptr = realloc(ptr, size);

    if (new_ptr == NULL) {
        fprintf(stderr, "Erro fatal: sqlima_realloc falhou ao realocar para %zu bytes.\n", size);
        exit(EXIT_FAILURE);
    }

    return new_ptr;
}
