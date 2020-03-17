
all: program1

program1.o: program1.cpp
	g++ -c program1.cpp -o program.o
program1: program1.o
	g++ program1.o -o program1

run1: program1
	./program1 filex.txt filey.txt output1.txt

clean: 
	rm *.o program1 program2 program3