#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

unsigned int password ;

int main(){

	setvbuf(stdout,0,2,0);
	char buf[100];
	char input[16];
	int fd ;
	srand(time(NULL));
	fd = open("/dev/urandom",0);
	read(fd,&password,4);
	printf("What your name ? ");
	read(0,buf,99);
	printf("Hello ,");
	printf(buf);
	printf("Your password :");
	read(0,input,15);
	if(atoi(input) != password){
		puts("Goodbyte");
	}else{
		puts("Congrt!!");
		system("cat /home/crack/flag");
	}
}
