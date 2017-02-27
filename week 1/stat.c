#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct stat sb;

int main()
{
	int err;
		err = stat("open.c",&sb);
		if(err==-1)
		{
			fprintf(stderr, "\n stat failed%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
			exit(EXIT_FAILURE);
		}
		printf("\n Inode no = %ld\n", sb.st_ino);
	return 0;
}
