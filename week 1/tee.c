#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>

#define TRUE 0
#define FALSE 1
#define BUFF_SIZE 1024

typedef int flag_t;

flag_t s_used = FALSE;
flag_t d_used = FALSE;

char *src_file_name = NULL;
char *dest_file_name = NULL;
char buff[BUFF_SIZE];
int ret;

int fd_src,fd_dest;
int err; 

int nb_read;

void print_help();
void print_version();
void tee(char *,char *);

int main(int argc, char *argv[])
{
	while((ret=getopt(argc,argv,"hvs:d:"))!=-1)
	{
		switch(ret)
		{
			case 'h':
				print_help();
				break;
			case 'v':
				print_version();
				break;
			case 's':
				src_file_name = optarg;
				s_used = TRUE;
				break;
			case 'd':
				dest_file_name = optarg;
				d_used = TRUE;
				break;
		}
	}
	if(s_used == TRUE && d_used==TRUE)
	{
		tee(src_file_name,dest_file_name);
	}
	return 0;
	exit(EXIT_SUCCESS);
}

void print_help()
{
	printf("\nThis is help. tee command use -s: -d: -hv options\n");
}

void print_version()
{
	printf("\n This is version v1.0\n");
}

void tee(char *src_file_name,char *dest_file_name)
{
	fd_src = open(src_file_name,O_RDWR|O_APPEND,S_IRWXU|S_IRGRP|S_IROTH);
	if(fd_src == -1)
	{
		fprintf(stderr,"\nOpen Failed:src_file_name=%s:%s:%s:%s:%d\n",src_file_name,strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		exit(EXIT_FAILURE);
	}

	fd_dest = open(dest_file_name,O_RDWR|O_APPEND,S_IRWXU|S_IRGRP|S_IROTH);
	if(fd_dest==-1)
	{
		fprintf(stderr,"\nOpen Failed:dest_file_name=%s:%s:%s:%s:%d\n",dest_file_name,strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		exit(EXIT_FAILURE);	
	}

	while((nb_read = read(fd_src,buff,BUFF_SIZE))!=0)
	{
		err = write(fd_dest,buff,nb_read);
	}

	if(nb_read == -1)
	{
		fprintf(stderr,"\nRead failed:src_file_name=%s:%s:%s:%s:%d\n",src_file_name,strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		exit(EXIT_FAILURE);
	}

	if(err==-1)
	{
		fprintf(stderr,"\nWrite failed:src_file_name=%s:%s:%s:%s:%d\n",src_file_name,strerror(errno),__FILE__,__FUNCTION__,__LINE__);
			exit(EXIT_FAILURE);
	}
}

