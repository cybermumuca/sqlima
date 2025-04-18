/**
 * @file memory.h
 * @brief Funções utilitárias para manipulação segura de memória no SQLima.
 */
#ifndef SQLIMA_MEMORY_H
#define SQLIMA_MEMORY_H

#include <stddef.h>

/**
 * @brief Aloca memória com verificação de falhas, terminando o processo em caso de erro
 *
 * @param size Quantidade de bytes para alocar
 * @return void* Ponteiro para a memória alocada (nunca retorna NULL)
 */
void *sqlima_malloc(size_t size);

/**
 * @brief Realoca memória com verificação de falhas, terminando o processo em caso de erro
 *
 * @param ptr Ponteiro original para realocar
 * @param size Novo tamanho desejado em bytes
 * @return void* Ponteiro para a memória realocada (nunca retorna NULL)
 */
void *sqlima_realloc(void *ptr, size_t size);

#endif /* SQLIMA_MEMORY_H */
