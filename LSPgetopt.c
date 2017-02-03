#include <stdio.h>
#include <getopt.h>

int ret= 0;
void print_help();
void print_version();
int main(int argc, char const *argv[])
{
	while((ret = getopt(argc,argv,"vh")) != -1)
	{
		switch((char)ret)
		{
			case 'h':
				print_help();
			break;
			case 'v':
				print_version();
				break;
		}
	}	
	return 0;
}

void print_help()
{
	printf("This is help\n");
}

void print_version()
{
	printf("This is version v1.0\n");
}
