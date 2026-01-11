#!/usr/bin/env bash
set -euo pipefail

# 删除 build 目录（如果存在）
rm -rf build

# 生成构建目录并导出 compile_commands.json（给 clangd 用）
# 使用clang clang++
cmake -G Ninja -S . -B build -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# 构建
cmake --build build
