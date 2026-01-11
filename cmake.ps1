# clean.ps1
Remove-Item -Recurse -Force build

# 为了让clangd能正常提示补全需要导出compile_commands.json
# 使用clang-cl
cmake -G Ninja -S . -B build -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_EXPORT_COMPILE_COMMANDS=ON 
cmake --build build
