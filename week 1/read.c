#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFF_SIZE 1024
char buff[BUFF_SIZE];

int err;

int main()
{
	int fd;
	fd = open("abc.txt",O_APPEND,S_IRUSR);
	if(fd == -1)
	{
		fprintf(stderr, "Open Failed\n%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__ );
		exit(EXIT_FAILURE);	
	}


	printf("\nOpen Success:fd=%d \n",fd);
	

	err = read(fd,buff,sizeof(buff));
	if(err==-1)
		{
			fprintf(stderr,"\nread failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		}

		printf("Read data:%s\n",buff);	

	err=close(fd);
		if(err==-1)
		{
			fprintf(stderr,"\nclose failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		}	
		printf("File Closed\n");
	return 0;
}