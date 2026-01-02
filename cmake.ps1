# clean.ps1
Remove-Item -Recurse -Force build
cmake -S . -G "MinGW Makefiles" -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
