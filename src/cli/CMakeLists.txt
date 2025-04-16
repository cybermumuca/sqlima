# filepath: c:\Users\sx1n\Desktop\projetos\sqlima\src\cli\CMakeLists.txt
# Define a biblioteca para o módulo CLI
add_library(sqlima_cli_lib
    cli.c
)

# Garante que os headers públicos e internos sejam encontrados
target_include_directories(sqlima_cli_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR} # Para incluir "cli.h"
    ${CMAKE_SOURCE_DIR}/include # Para incluir "sqlima.h", etc.
)

# Dependências (se houver, adicionar depois)
# target_link_libraries(sqlima_cli_lib PRIVATE sqlima_common)
