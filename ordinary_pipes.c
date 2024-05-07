#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define buff 50
#define r_end 0
#define w_end 1

int main(void){
	
	int fd[2];
	char w_msg[buff] = "Ordinary Pipes\n";
	char r_msg[buff];
	pid_t pid;
	
	if(pipe(fd) == -1){
	
	fprintf(stderr,"Pipe Failed!");
	
	return 1;
	
	}
	
	if( (pid=fork()) < 0){
	
	fprintf(stderr,"Fork Failed!");
	
	return 1;
	
	}
	
	if(pid > 0){
	
	close(fd[r_end]);
	write(fd[w_end],w_msg,strlen(w_msg)+1);
	printf("Parent Sended Message = %s\n",w_msg);
	close(fd[w_end]);
	}
	
	else if(pid == 0){
	
	close(fd[w_end]);
	read(fd[r_end],r_msg,buff);
	
	printf("Child Recived Message = %s\n",r_msg);
	
	close(fd[r_end]);
	
	}
	
	return 0;
	
	}




