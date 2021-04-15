#include<stdio.h>
#include<stdlib.h>

#define HELLO_WORLD "Hello World"

void print(int, char *[]);
void scan();

int main(int argc, char *argv[]){
	printf("%s\n", HELLO_WORLD);

	print(argc, argv);

	scan();

	char c;
	fflush(stdout);
	scanf("%c", &c);
	printf("%c\n", c);

	system("pause");
	return 0;
}

void scan(){
	int n;
	printf("%d\n", n);
	char c;
	printf("%c\n", c);
//	scanf("%d", &n);
	printf("%d\n", n);
}

void print(int argc, char *argv[]){
	printf("Count=%d\n", argc);
	printf("%s\n", argv[0]);
}

