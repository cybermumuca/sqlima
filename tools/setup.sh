#!/bin/bash
# Script de configuração para desenvolvedores
mkdir -p build
cd build
cmake -DSQLIMA_BUILD_TESTS=ON -DSQLIMA_BUILD_EXAMPLES=ON ..
