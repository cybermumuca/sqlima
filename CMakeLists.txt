cmake_minimum_required(VERSION 3.15)
project(sqlima VERSION 0.1.0 LANGUAGES C)

# Opções de compilação
option(SQLIMA_BUILD_TESTS "Build SQLima tests" ON)
option(SQLIMA_BUILD_EXAMPLES "Build SQLima examples" OFF)

# Configurações de compilação
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Flags de compilação
if(MSVC)
  # Flags para MSVC
  add_compile_options(/W4 /WX)
else()
  # Flags para GCC/Clang
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Includes globais
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Adicionar subdiretórios do projeto
add_subdirectory(src)

# Configuração de testes
if(SQLIMA_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

# Exemplos
if(SQLIMA_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()
