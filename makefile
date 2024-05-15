bin/main : main.c
	gcc -I /opt/homebrew/opt/libomp/include -L /opt/homebrew/opt/libomp/lib -Xpreprocessor -fopenmp -lomp main.c  -o bin/main