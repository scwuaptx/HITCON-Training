#include <stdio.h>

int main(){
	char buf[20];
	puts("ROP is easy is'nt it ?");
	printf("Your input :");
	fflush(stdout);
	read(0,buf,100);
	
}
