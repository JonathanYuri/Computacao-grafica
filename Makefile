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

	g++ Testes/casa.cpp -o casa.exe $(ARG)
	g++ Testes/figura.cpp -o figura.exe $(ARG)

clean:
	@echo cleaning...
	-$(RM) *.exe
	@echo clean completed