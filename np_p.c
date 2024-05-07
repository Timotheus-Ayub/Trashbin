#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

#define FIFO_FILE "/tmp/myfifo"
#define buff 255

int main(){
	
	int fd;
	char buffer[buff];
	ssize_t bytes;
	
	mkfifo(FIFO_FILE,0666);
	
	fd = open(FIFO_FILE,O_WRONLY);
	
	if(fd == -1){
	
	perror("Open");
	exit(0);
	
	}
	
	
	while(1){
	
	printf("Producer : Enter Message (or 'exit' to end) = ");
	
	fgets(buffer,buff,stdin);
	
	bytes = write(fd,buffer,strlen(buffer));
	
	
	if(bytes == -1){
	
	perror("Read");
	exit(0);
	
	}
	
	if((strncmp(buffer,"exit",4)) == 0 )
	break;
		
	}
	
	
	close(fd);
	unlink(FIFO_FILE);
	
	return 0;
	
	}



