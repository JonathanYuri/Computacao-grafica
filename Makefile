all:
	g++ Listas/ola.cpp -o ola -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32
	g++ Listas/Flor-de-abril.cpp -o flor -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32
	g++ Listas/sistema-solar.cpp -o sistemasolar -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32

ola:
	g++ Listas/ola.cpp -o ola -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32

flor:
	g++ Listas/Flor-de-abril.cpp -o flor -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32

sistemasolar:
	g++ Listas/sistema-solar.cpp -o sistemasolar -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32

clean:
	del *.exe