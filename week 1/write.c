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
	int fd,fd1;
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
		printf("File Closed After Reading\n");


	fd1 = open("pqr.txt",O_CREAT|O_APPEND|O_RDWR,S_IRWXU|S_IRWXG|S_IRWXO);
		if(fd1 == -1)
		{
			fprintf(stderr, "Open For Write Failed\n%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__ );
			exit(EXIT_FAILURE);	
		}

	err = write(fd1,buff,sizeof(buff));
	if(err==-1)
		{
			fprintf(stderr,"\nwrite failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		}

	err=close(fd1);
		if(err==-1)
		{
			fprintf(stderr,"\nclose failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		}	
		printf("File Closed After Writing\n");





	return 0;
}