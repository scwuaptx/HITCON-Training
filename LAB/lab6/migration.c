#include <stdio.h>

int count = 1337 ;

int main(){
	if(count != 1337)
		_exit(1);
	count++;
	char buf[40];
	setvbuf(stdout,0,2,0);
	puts("Try your best :");
	read(0,buf,64);
	return ;	
}
