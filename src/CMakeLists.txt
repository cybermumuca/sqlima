# Adiciona subdiretórios
add_subdirectory(cli)
# add_subdirectory(common)

# Biblioteca principal (ainda vazia, será preenchida depois)
# add_library(sqlima_core
#   # Arquivos do núcleo do banco de dados
# )


# Executável principal
add_executable(sqlima_cli main.c)
target_link_libraries(sqlima_cli PRIVATE
    sqlima_cli_lib  # Biblioteca definida em src/cli/CMakeLists.txt
    sqlima_common # Biblioteca definida em src/common/CMakeLists.txt
    # sqlima_core # Adicionar quando a lib principal for criada
)

# Garante que o executável encontre os headers globais
target_include_directories(sqlima_cli PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Instalação
install(TARGETS sqlima_cli
        RUNTIME DESTINATION bin)
