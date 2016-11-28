#include <stdio.h>
#include <unistd.h>



void get_flag(){
	int fd ;
	int password;
	int magic ;
	char key[] = "Do_you_know_why_my_teammate_Orange_is_so_angry???";
	char cipher[] = {7, 59, 25, 2, 11, 16, 61, 30, 9, 8, 18, 45, 40, 89, 10, 0, 30, 22, 0, 4, 85, 22, 8, 31, 7, 1, 9, 0, 126, 28, 62, 10, 30, 11, 107, 4, 66, 60, 44, 91, 49, 85, 2, 30, 33, 16, 76, 30, 66};
	fd = open("/dev/urandom",0);
	read(fd,&password,4);
	printf("Give me maigc :");
	scanf("%d",&magic);
	if(password == magic){
		for(int i = 0 ; i < sizeof(cipher) ; i++){
			printf("%c",cipher[i]^key[i]);
		}
	}
}


int main(){
	setvbuf(stdout,0,2,0);
	get_flag();
	return 0 ;
}
