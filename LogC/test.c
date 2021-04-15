#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"src/logc.h"

int main(int argc, char *argv[], char *envp){
	char a = 'a';
	printf("%d\n", a);
	printf("%d\n", atoi(&a));

	char *s = "abcde";
	char *s2 = "abcde";

	int n = strcmp(s, s2);

	printf("%s\n", s);

	printf("%d\n", n);

	char *f = argv[0];
	//if(&f=="exe"){
	//	printf("%s", "Windows");
	//}
	
	printf("%s\n", f);
	int i = atoi(f);
	printf("%d\n", i);

	
	printf("Count=%d\n", argc);
	while(argc-->-1){
		//char *c = *argv++;
		//printf("%s\n", *++argv);
		//println(c);
	}

	return 0;
}
