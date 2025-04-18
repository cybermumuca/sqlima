cmake_minimum_required(VERSION 3.15)
project(sqlima VERSION 0.1.0 LANGUAGES C)

# Configurações de compilação
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Flags de compilação
if(MSVC)
  # Flags para MSVC
  add_compile_options(/W4 /utf-8)
else()
  # Flags para GCC/Clang
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Coleta automaticamente todos os arquivos .c em src/ e subdiretórios
file(GLOB_RECURSE SQLIMA_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

# Exibe os arquivos encontrados (opcional, para debug)
message(STATUS "Arquivos encontrados: ${SQLIMA_SOURCES}")

# Cria o executável com todos os arquivos encontrados
add_executable(sqlima ${SQLIMA_SOURCES})

# Inclui o diretório src/ para localização de headers
target_include_directories(sqlima PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
