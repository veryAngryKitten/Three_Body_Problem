@echo off
g++ main.cpp -o app.exe ^
  -I"C:/libs/glfw-3.4.bin.WIN64/include" ^
  -L"C:/libs/glfw-3.4.bin.WIN64/lib-mingw-w64" ^
  -lglfw3 -lopengl32 -lgdi32

echo.
echo Running app...
app.exe
pause