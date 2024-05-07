#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define max 500

int main(void){
	
	int shmid;
	char c;
	char *shm,*s;
	key_t key;
	
	key = 2211;
	
	if( (shmid = shmget(key,max,IPC_CREAT|0666)) < 0)
	exit(0);
	
	if( (shm = shmat(shmid,NULL,0)) == (char*)-1)
	exit(0);
	
	printf("Entered Data ->\n");
	
	s=shm;
	
	//for(s=shm ; *s!='\0'; s++)
	
	printf("%s",s);
	
	//putchar(*s);
	
	*shm = '\0';
	
	exit(0);
	
	}
