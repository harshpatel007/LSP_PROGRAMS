#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <getopt.h>
#include <fcntl.h>

int main()
{
	int fd,close_val;
	off_t start;
	fd= open("abc.txt",O_RDWR);

	start = lseek(fd,0,SEEK_SET);
	if(start == -1)
			fprintf(stderr, "lseek failed\n");
	printf("\n Set the seek to 0 i.e. start of the file\n");
	fprintf(stdout, "offset = %ld\n",start);


	start = lseek(fd,0,SEEK_END);
	if(start == -1)
		fprintf(stderr, "lseek failed\n");
	printf("\n set seek to end of the file\n");
	fprintf(stdout, "offset = %ld\n",start);
	
	start = lseek(fd,20,SEEK_CUR);
	if(start == -1)
	{	fprintf(stderr, "lseek failed\n");
	printf("\n seek 20 byte from current offset\n");
	fprintf(stdout, "offset = %ld\n",start);
	}

	start = lseek(fd,-30,SEEK_CUR);
	if(start == -1)
	{	fprintf(stderr, "lseek failed\n");
	printf("\n seek 30 bytes backwards fron current offset\n");
	fprintf(stdout, "offset = %ld\n",start);
	}
	
	start = lseek(fd,50,SEEK_SET);
	if(start == -1)
		fprintf(stderr, "lseek failed\n");
	printf("\n seek to 50 bytes from start  of the file\n");
	fprintf(stdout, "offset = %ld\n",start);
	
	close_val =close(fd);
	if(close_val == -1)
	{
		printf("\nFile close failed\n"); 
	}


	return 0;
}