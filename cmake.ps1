# clean.ps1
Remove-Item -Recurse -Force build

# 为了让clangd能正常提示补全需要导出compile_commands.json
cmake -G Ninja -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON 
cmake --build build
