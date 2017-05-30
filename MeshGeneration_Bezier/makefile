RM=rm
default: prog
prog: main.o bezier1.o
	g++ -o p main.o bezier1.o -lGL -lGLU -lglut
main.o: main.cpp bezier1.h primitive.h
	g++ -c main.cpp 
bezier1.o: bezier1.cpp bezier1.h
	g++ -c bezier1.cpp
clean: 
	$(RM) p *.o 
