#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fid;
	int cread;
	char buffer[20];

	fid = open("file.txt", O_RDONLY);

	if (fid < 0)
	{
		perror("file.txt");
		exit(1);
	}

	cread = read(fid, buffer, 19);
	buffer[cread] = '\0';

	printf("%s\n", buffer);

	close(fid);

	fid = open("file.txt", O_RDONLY);

	if (fid < 0)
	{
		perror("file.txt");
		exit(1);
	}

	cread = read(fid, buffer, 19);
	buffer[cread] = '\0';

	printf("%s\n", buffer);

	close(fid);

	return 0;
}
