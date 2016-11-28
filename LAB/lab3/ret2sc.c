#include <stdio.h>

char name[50];

int main(){
	setvbuf(stdout,0,2,0);
	printf("Name:");
	read(0,name,50);
	char buf[20];
	printf("Try your best:");
	gets(buf);
	return ;
}
