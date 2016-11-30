#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define TIMEOUT 60


struct flower{
	int vaild ;
	char *name ;
	char color[24] ;
};


struct flower* flowerlist[100] ;
unsigned int flowercount = 0 ;



void menu(){
	puts("");
	puts("☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ");
	puts("☆         Baby Secret Garden      ☆ ");
	puts("☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ");
	puts("");
	puts("  1 . Raise a flower " );
	puts("  2 . Visit the garden ");
	puts("  3 . Remove a flower from the garden");
	puts("  4 . Clean the garden");
	puts("  5 . Leave the garden");
	puts("");
	printf("Your choice : ");
}

int add(){
	struct flower *newflower = NULL ;
	char *buf = NULL ;
	unsigned size =0;
	unsigned index ;
	if(flowercount < 100){
		newflower = malloc(sizeof(struct flower));
		memset(newflower,0,sizeof(struct flower));
		printf("Length of the name :");
		if(scanf("%u",&size)== EOF) exit(-1);
		buf = (char*)malloc(size);
		if(!buf){
			puts("Alloca error !!");
			exit(-1);
		}
		printf("The name of flower :");
		read(0,buf,size);
		newflower->name = buf ;
		printf("The color of the flower :");
		scanf("%23s",newflower->color);
		newflower->vaild = 1 ;
		for(index = 0 ; index < 100 ; index++ ){
			if(!flowerlist[index]){
				flowerlist[index] = newflower ;
				break ;
			}
		}
		flowercount++ ;
		puts("Successful !");
	}else{
		puts("The garden is overflow");
	}
}

int del(){
	unsigned int index ;
	if(!flowercount){
		puts("No flower in the garden");
	}else{
		printf("Which flower do you want to remove from the garden:");
		scanf("%d",&index);
		if(index < 0 ||index >= 100 || !flowerlist[index]){
			puts("Invalid choice");
			return 0 ;
		}
		(flowerlist[index])->vaild = 0 ;
		free((flowerlist[index])->name);
		puts("Successful");
	}
}

void magic(){
    int fd ;
    char buffer[100];
    fd = open("/home/babysecretgarden/flag",O_RDONLY);
    read(fd,buffer,sizeof(buffer));
    close(fd);
    printf("%s",buffer);
    exit(0);
}

void clean(){
	unsigned index ;
	for(index = 0 ; index < 100 ; index++){
		if(flowerlist[index] && (flowerlist[index])->vaild == 0){
			free(flowerlist[index]);
			flowerlist[index] = NULL;
			flowercount--;
		}
	}
	puts("Done!");
}

int visit(){
	unsigned index ;
	if(!flowercount){
		puts("No flower in the garden !");
	}else{
		for(index = 0 ; index < 100 ; index++){
			if(flowerlist[index] && (flowerlist[index])->vaild){
				printf("Name of the flower[%u] :%s\n",index,(flowerlist[index])->name);
				printf("Color of the flower[%u] :%s\n",index,(flowerlist[index])->color);
			}
		}	
	}
}

void handler(int signum){
	puts("timeout");
	exit(1);
}
void init(){
	int fd;
	fd = open("/dev/urandom",0);
	close(fd);
	setvbuf(stdout,0,2,0);
	signal(SIGALRM,handler);
	alarm(TIMEOUT);
}


int main(){
	init();
	int choice ;
	char buf[10];
	while(1){
		menu();
		read(0,buf,8);
		choice = atoi(buf);
		switch(choice){
			case 1:
				add();
				break ;
			case 2:
				visit();
				break ;
			case 3:
				del();
				break ;
			case 4:
				clean();
				break ;
			case 5:
				puts("See you next time.");
				exit(0);
			default :
				puts("Invalid choice");
				break ;
		}

	}

}
