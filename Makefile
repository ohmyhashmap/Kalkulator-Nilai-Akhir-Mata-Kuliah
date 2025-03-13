compile :
	gcc uts.c -o uts -Wall
	gcc strtok.c -o strtok -Wall
test_01 :
	./uts
test_02 :
	./strtok