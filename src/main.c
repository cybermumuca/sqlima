/**
 * @file main.c
 * @brief Ponto de entrada do SQLima
 */
#include "cli.h"
#include <stdio.h>
#include <locale.h>

#ifdef _WIN32
    #include <windows.h>
#endif

int main(int argc, char *argv[]) {
    return cli_run(argc, argv);
}
