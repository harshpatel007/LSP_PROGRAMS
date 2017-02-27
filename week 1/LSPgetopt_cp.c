#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

typedef int flag_t;

flag_t s_used = FALSE;
flag_t d_used = FALSE;

void print_help();
void print_version();
void copy(char *,char *);


int ret = 0;
char *src_file_name = NULL;
char *dest_file_name = NULL;


int main(int argc, char *argv[])
{
	while((ret=getopt(argc,argv,"s:d:vh")) != -1)
	{
		switch((char)ret)
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

		if(s_used == TRUE && d_used == TRUE)
		{
			copy(src_file_name,dest_file_name);
		}
	}
	return 0;
	exit(EXIT_SUCCESS);
}

void print_help()
{
	printf("This is help -s source -d destination -v version -h help \n");
}

void print_version()
{
	printf("This is version V1.0\n");
}

void copy(char *source,char * destination)
{
	printf("\nHere we will copy");
	printf("\nSource File Name: %s\n",source);
	printf("Destination File Name: %s\n",destination);
}