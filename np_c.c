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
	
	
	fd = open(FIFO_FILE,O_RDONLY);
	
	if(fd == -1){
	
	perror("Open");
	exit(0);
	
	}
	
	
	while((bytes = read(fd,buffer,buff))>0){
	
	buffer[bytes] = '\0';
	
	printf("Consumer : Recieved Message = %s",buffer);
	
	
	if(bytes == -1){
	
	perror("Read");
	exit(0);
	
	}
	
		
	}
	
	printf("Message Ended!");
	
	close(fd);
	unlink(FIFO_FILE);
	
	return 0;
	
	}



