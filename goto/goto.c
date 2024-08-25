#include <stdio.h>
#include <stdlib.h>

#define HEADER_LEN 1024

int main(int argc, char *argv[]) {
	int retval = 0;

	int fd = open("./server.config", O_RDONLY);
	if (fd == -1) 
	{
		perror("open");
		return -1;
	}

	void *filebuf = malloc(CONFIG_LEN);
	if (filebuf == NULL)
	{
		perror("malloc");
		retval = -1;
		goto leave_fd;
	}

	int sfd = socket(AF_INET, SOCK_STREAM, NULL);
	if (sfd == -1)
	{
		perror("socket");
		retval = -1;
		goto leave_filebuf;
	}

	retval = 0;
	close(sfd);

leave_filebuf:
	free(filebuf);

leave_fd:
	close(fd);

	return 0;
}
