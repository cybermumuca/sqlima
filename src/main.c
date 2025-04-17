/**
 * @file main.c
 * @brief Ponto de entrada do SQLima
 */
#include "sqlima.h"
#include "cli/cli.h"
#include <stdio.h>
#include <locale.h>

#ifdef _WIN32
    #include <windows.h>
#endif

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");

    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif


    return cli_run(argc, argv);
}
