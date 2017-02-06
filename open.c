#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

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
	
	err=close(fd);
		if(fd==-1)
		{
			fprintf(stderr,"\nclose failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		}	
		printf("File Closed\n");
	return 0;
}