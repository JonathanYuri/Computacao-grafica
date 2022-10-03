all:
	g++ Listas/ola.cpp -o ola -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32
	g++ Listas/casa.cpp -o casa -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32
	g++ Listas/Flor-de-abril.cpp -o flor -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32
	g++ Listas/sistema-solar/sistema-solar.cpp -o sistema-solar -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32

ola:
	g++ Listas/ola.cpp -o ola -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32

flor:
	g++ Listas/Flor-de-abril.cpp -o flor -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32

sistema-solar:
	g++ Listas/sistema-solar/sistema-solar.cpp -o sistema-solar -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32

casa:
	g++ Listas/casa.cpp -o casa -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32

clean:
	del *.exe