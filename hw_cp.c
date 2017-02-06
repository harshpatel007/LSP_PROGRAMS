#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>

#define TRUE 0
#define FALSE 1

typedef int flag_t;

static struct option opt_arr[] = 
{ 	
	{"help",no_argument,0,'h'},
	{"version",no_argument,0,'v'},
	{"recursive",no_argument,0,'R'},
	{"src",required_argument,0,'s'},
	{"dest",required_argument,0,'d'},
	{0,0,0,0}
};

void print_help();
void print_version();
void print_recursive();
void copy(char *,char *);

int val,i=0;
int ret;
char *src,*dest;
flag_t s_used=FALSE,d_used=FALSE;


int main(int argc, char *argv[])
{
	while((ret= getopt_long(argc,argv,"hvRs:d:",opt_arr,&i)) != -1)
	{
		switch((char)ret)
		{
			case 'h':
				print_help();
				break;
			case 'v' :
				print_version();
				break;
			case 'R':
				print_recursive();
				break;
			case 's':
				s_used=TRUE;
				src=optarg;
				break;
			case 'd':
				d_used=TRUE;
				dest=optarg;
				copy(src,dest);
				break;
			default:
				printf("\nINVALID\n");			
				exit(EXIT_FAILURE);
		}
	}
	return 0;
	exit(EXIT_SUCCESS);
}


void print_help()
{
	static const char helpstr[]="\nThis is help,\
use h/help,v/version,R/recursive s/src: d/dest:\nThank you!\n";
	printf(helpstr);
}
void print_version()
{
	printf("\nThis is version 0.1\n");
}

void copy(char *src,char *dest)
{
	if(s_used ^ d_used)
	{
		printf("\nProblem with argument passing\n");
	}
	else
	{
		printf("\nSrc=%s",src);
		printf("\ndest=%s",dest);
	}
}

void print_recursive(void)
{
	printf("\nThe Recursive option is used\n");
}
