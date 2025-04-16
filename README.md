# SQLima: Clone Educacional do PostgreSQL

## 🧪 O que é SQLima?

SQLima é uma engine de banco de dados educacional inspirada no PostgreSQL, construída completamente do zero em C. Este projeto visa desmistificar o funcionamento interno de sistemas de banco de dados relacionais, recriando os componentes essenciais de forma estruturada, modular e educativa.

Diferentemente dos bancos de dados de produção, o SQLima prioriza clareza e aprendizado sobre otimizações de desempenho, tornando o código-fonte um excelente recurso para compreender o funcionamento interno de bancos de dados.

## 🎯 Objetivos do Projeto

- **Educacional:** Aprender internos de bancos de dados, programação de sistemas e C construindo um SGBD funcional
- **Modular:** Entender cada componente de um sistema de banco de dados independentemente
- **Multiplataforma:** Funcionar perfeitamente tanto em ambientes Linux quanto Windows
- **Progressivo:** Começar simples e adicionar recursos avançados incrementalmente

## 🏗️ Arquitetura

O SQLima implementa estes componentes essenciais de banco de dados:

1. **Interface de Linha de Comando:** Uma CLI robusta para entrada e execução de comandos SQL
2. **Parser:** Análise sintática SQL e geração de árvore de sintaxe abstrata (AST)
3. **Analisador Semântico:** Validação de esquema e verificação de tipos
4. **Motor de Execução:** Geração de planos e execução de consultas
5. **Motor de Armazenamento:** Armazenamento binário baseado em páginas para arquivos de banco de dados
6. **Sistema de Catálogo:** Armazenamento de metadados para informações de esquema
7. **Avaliador de Expressões:** Análise e avaliação de expressões
8. **Gerenciador de Índices:** Indexação baseada em árvores B+ e hash
9. **Gerenciador de Transações:** Conformidade ACID com WAL (Write-Ahead Logging)

## 🚀 Começando (TODO)

### Pré-requisitos

- Compilador C (GCC, Clang ou MSVC)
- CMake (3.15+)
- Git

## 📈 Roteiro de Desenvolvimento

O SQLima está sendo desenvolvido em módulos, cada um focado em um componente específico do banco de dados:

- [x] **Módulo 0:** Configuração do projeto (CMake, multiplataforma, testes)
- [ ] **Módulo 1:** CLI e manipulação de entrada
- [ ] **Módulo 2:** Tokenizador e Parser SQL
- [ ] **Módulo 3:** Análise Semântica
- [ ] **Módulo 4:** Execução de Consultas
- [ ] **Módulo 5:** Motor de Armazenamento
- [ ] **Módulo 6:** Catálogo do Sistema
- [ ] **Módulo 7:** Avaliação de Expressões
- [ ] **Módulo 8:** Indexação
- [ ] **Módulo 9:** Transações

<!-- ## 🧩 Estrutura do Projeto

```
sqlima/
├── src/                    # Código-fonte
│   ├── cli/                # Interface de linha de comando
│   ├── parser/             # Análise SQL
│   ├── analyzer/           # Análise semântica
│   ├── executor/           # Execução de consultas
│   ├── storage/            # Motor de armazenamento
│   ├── catalog/            # Catálogo do sistema
│   ├── expr/               # Sistema de expressões
│   ├── index/              # Subsistema de indexação
│   └── txn/                # Gerenciamento de transações
├── include/                # Headers públicos
├── tests/                  # Casos de teste
├── docs/                   # Documentação
└── CMakeLists.txt          # Configuração de build
``` -->

## 🤝 Contribuindo

SQLima é primariamente um projeto educacional. Contribuições que melhoram a clareza, documentação ou suporte multiplataforma são especialmente bem-vindas.

## 📚 Recursos de Aprendizado

- [Arquitetura do SQLite](https://www.sqlite.org/arch.html)

## ⚖️ Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo LICENSE para detalhes.

---

*SQLima não se destina ao uso em produção. É uma ferramenta de aprendizado para compreender o funcionamento interno de bancos de dados.*