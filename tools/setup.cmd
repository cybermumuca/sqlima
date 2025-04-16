@echo off
:: Script de configuração para desenvolvedores Windows
if not exist build mkdir build
cd build
cmake -DSQLIMA_BUILD_TESTS=ON -DSQLIMA_BUILD_EXAMPLES=ON ..
