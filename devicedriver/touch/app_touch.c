#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int dev;
	char touched[2]={0,};

	if((dev = open("/dev/touch", O_RDONLY)) < 0)
	{
		printf("error: cannot open device. \n");
		return 1;
	}

	if(read(dev, touched, sizeof(char)*2) < 0)
	{
		printf("error: cannot read data from touch device. \n");

		close(dev);
		return -1;
	}
	if(touched[0] == 0 && touched[1] == 0)
		printf("Nothing touched \n");
	else
	{
		printf("Touched: ");
		if(touched[0])
			printf("TOUCH1 ");
		if(touched[1])
			printf("TOUCH2 ");
		printf("\n");
	}
	close(dev);
	return 0;
}
