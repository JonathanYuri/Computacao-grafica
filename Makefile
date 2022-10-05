ifeq ($(OS),Windows_NT)
RM = del /Q /F
ARG = -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32
ifdef ComSpec
SHELL := $(ComSpec)
endif
ifdef COMSPEC
SHELL := $(COMSPEC)
endif
else
RM = rm -rf
ARG = -lGL -lGLU -lglut
endif

all:
	g++ Listas/ola.cpp -o ola.exe $(ARG)
	g++ Listas/Flor-de-abril.cpp -o flor.exe $(ARG)
	g++ Listas/sistema-solar/sistema-solar.cpp -o sistema-solar.exe $(ARG)

ola:
	g++ Listas/ola.cpp -o ola.exe $(ARG)
	./ola.exe

flor:
	g++ Listas/Flor-de-abril.cpp -o flor.exe $(ARG)
	./flor.exe

sistema-solar:
	g++ Listas/sistema-solar/sistema-solar.cpp -o sistema-solar.exe $(ARG)
	./sistema-solar.exe

clean:
	@echo "clean project"
	-$(RM) *.exe
	@echo "clean completed"