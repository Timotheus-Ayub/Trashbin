#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define max 25

int main(void){
	
	int shmid;
	char c;
	char *shm,*s,*s1="Hello",*s2="World\n";
	key_t key;
	
	key = 2211;
	
	if( (shmid = shmget(key,max,IPC_CREAT|0666)) < 0)
	exit(0);
	
	if( (shm = shmat(shmid,NULL,0)) == (char*)-1)
	exit(0);
	
	s = shm;
	
	
//	for(c='a';c<='z';c++)	
		
//	while(c!='0'){
	
//	c = getchar();
	
//	if(c =='0')
//	break;
//	*s++ = c;
	
//	}
	
	
	sprintf(s,"%s",s1);
	s += strlen(s1);
	
	sprintf(s,"%s",s2);
	s += strlen(s2);
	
//	*s++ = '\0';
	
	while(*shm !='\0')
	sleep(1);
	
	exit(0);
	
	}
