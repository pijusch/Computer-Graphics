default: prog
prog: tidier.o runner_tidier.o
	g++ -o prog tidier.o runner_tidier.o
tidier.o: tidier.cpp tidier.h
	g++ -c tidier.cpp
runner_tidier.o: runner_tidier.cpp
	g++ -c runner_tidier.cpp
