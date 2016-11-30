#include <stdio.h>
#include <unistd.h>
#include <string.h>

char buf[200] ;

void do_fmt(){
	while(1){
		read(0,buf,200);
		if(!strncmp(buf,"quit",4))
			break;
		printf(buf);
	}
	return ;
}

void play(){
	puts("=====================");
	puts("  Magic echo Server");
	puts("=====================");
	do_fmt();
	return;
}

int main(){
	setvbuf(stdout,0,2,0);
	play();
	return;
}
