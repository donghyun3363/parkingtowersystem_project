#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
	int dev;
	int i=0;
	int con;
	dev = open("/dev/piezo", O_WRONLY);
	printf("buzzer on!\n");
	con=3;
	write(dev, &con, sizeof(con));
	con=1;	
	write(dev, &con, sizeof(con));
	con=2;
	write(dev, &con, sizeof(con));
	close(dev);
	return 0;
}

