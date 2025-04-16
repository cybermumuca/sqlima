/**
 * @file sqlima_platform.h
 * @brief Abstrações específicas de plataforma
 */
#ifndef SQLIMA_PLATFORM_H
#define SQLIMA_PLATFORM_H

/* Detecção de plataforma */
#if defined(_WIN32) || defined(_WIN64)
    #define SQLIMA_PLATFORM_WINDOWS
#elif defined(__linux__)
    #define SQLIMA_PLATFORM_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
    #define SQLIMA_PLATFORM_MACOS
#else
    #error "Plataforma não suportada"
#endif

/* Importação/Exportação de símbolos */
#ifdef SQLIMA_PLATFORM_WINDOWS
    #ifdef SQLIMA_BUILDING_DLL
        #define SQLIMA_API __declspec(dllexport)
    #else
        #define SQLIMA_API __declspec(dllimport)
    #endif
#else
    #define SQLIMA_API __attribute__((visibility("default")))
#endif

/* Caminhos de sistema */
#ifdef SQLIMA_PLATFORM_WINDOWS
    #define SQLIMA_PATH_SEP "\\"
    #define SQLIMA_LINE_ENDING "\r\n"
#else
    #define SQLIMA_PATH_SEP "/"
    #define SQLIMA_LINE_ENDING "\n"
#endif

#endif /* SQLIMA_PLATFORM_H */
