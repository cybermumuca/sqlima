/**
 * @file sqlima.h
 * @brief API pública do SQLima
 */
#ifndef SQLIMA_H
#define SQLIMA_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Versão do SQLima
 */
#define SQLIMA_VERSION "0.1.0"

/**
 * @brief Inicializa o SQLima
 * @return 0 se bem-sucedido, código de erro caso contrário
 */
int sqlima_init(void);

/**
 * @brief Finaliza o SQLima e libera recursos
 */
void sqlima_shutdown(void);

#ifdef __cplusplus
}
#endif

#endif /* SQLIMA_H */
