#include <stdio.h>

void See_something(unsigned int addr){
	int *address ;
	address = (int *)addr ;
	printf("The content of the address : %p\n",*address);
};

void Print_message(char *mesg){
	char buf[48];
	strcpy(buf,mesg);
	printf("Your message is : %s",buf);
}

int main(){
	char address[10] ;
	char message[256];
	unsigned int addr ;
	puts("###############################");
	puts("Do you know return to library ?");
	puts("###############################");
	puts("What do you want to see in memory?");
	printf("Give me an address (in dec) :");
	fflush(stdout);
	read(0,address,10);
	addr = strtol(address);
	See_something(addr) ;
	printf("Leave some message for me :");
	fflush(stdout);
	read(0,message,256);
	Print_message(message);
	puts("Thanks you ~");
	return 0 ;
}
