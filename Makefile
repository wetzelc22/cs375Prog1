
all: program1 program2

program1.o: program1.cpp
	g++ -c program1.cpp -o program1.o
program1: program1.o
	g++ program1.o -o program1
program2.o: program2.cpp
	g++ -c program2.cpp -o program2.o
program2: program2.o
	g++ program2.o -o program2

run1: program1
	./program1 filex.txt filey.txt output1.txt
run2: program2
	./program2 filex.txt filey.txt output2.txt

clean: 
	rm *.o program1 program2 program3
