mytool:main.o tool1.o tool2.o
	gcc main.o tool1.o tool2.o -o mytool
main.o: main.c 
	gcc main.c  -c -Wall -g -o main.o
tool1.o:tool1.c
	gcc tool1.c -c -Wall -g -o tool1.o
tool2.o:tool2.c
	gcc tool2.c -c -Wall -g -o tool2.o


