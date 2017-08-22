#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include"textlcd_ioctl.h"

int DisplayControls(int idev)
{
	int value;
	
	printf("***Display Controls***\n");
	printf("1. Disolay on\n");
	printf("2. Disolay off\n");
	printf("3. Cursor on\n");
	printf("4. Cursor off\n");

	scanf("%d", &value);

	if(value == 1)
		ioctl(idev, TEXTLCD_DISPLAY_ON,NULL);
	else if(value == 2)
		ioctl(idev, TEXTLCD_DISPLAY_OFF,NULL);
	else if(value == 3)
		ioctl(idev, TEXTLCD_DISPLAY_CURSOR_ON,NULL);
	else if(value == 4)
		ioctl(idev, TEXTLCD_DISPLAY_CURSOR_OFF,NULL);

	return 1;
}

int DisplayClear(int idev)
{
	ioctl(idev,TEXTLCD_CLEAR,NULL);
	return 1;
}

int Cursor_shift(int idev)
{
	int value;
	
	printf("***Cursor shift***\n");
	printf("1. Cursor Right\n");
	printf("2. Cursor Left\n");
	printf("3. Return Home\n");

	scanf("%d", &value);

	if(value == 1)
		ioctl(idev, TEXTLCD_CURSOR_SHIFT_RIGHT,NULL);
	else if(value == 2)
		ioctl(idev, TEXTLCD_CURSOR_SHIFT_LEFT,NULL);
	else if(value == 3)
		ioctl(idev, TEXTLCD_RETURN_HOME,NULL);

	return 1;
}

int DisplayWrite(int idev)
{
	int value, iSize=0,i;
	char charData[30]={0};
	
	printf("***Display Write***\n");
	printf("1. 1 LINE\n");
	printf("2. 2 LINE\n");
	
	scanf("%d", &value);

	if(value == 1)
	{
		ioctl(idev, TEXTLCD_DD_ADDRESS_1,NULL);
		printf("1 Line Input : ");
	}
	else if(value == 2)
	{
		ioctl(idev, TEXTLCD_DD_ADDRESS_2,NULL);
		printf("2 Line Input : ");
	}

	scanf("%s",&charData);

	for(i=0;i<count(charData);i++)
		ioctl(idev,TEXTLCD_WRITE_BYTE,charData[i]);
}
int count(char cNum[])
{
	int i=0;
	while(cNum[i] != '\0')
		i++;
	return i;
}
int main(int argc, char* argv[])
{
	int dev,iexit=1,value=0;
	char temp, buf[8]= {0,};
	unsigned char t =0;

	dev=open("dev/textlcd",O_WRONLY);

	if(dev<0)
		printf("Fail;cannot file open\n");

	while(iexit)
	{
		printf("***Text LCD***\n");
		printf("1. Display Controls\n");
		printf("2. Display Clear\n");
		printf("3. Cursor Shitf\n");
		printf("4. Display Write\n");
		printf("5. Exit\n");
	
		scanf("%d", &value);

		switch(value)
		{
		case 1:
			DisplayControls(dev);
			break;
		case 2:
			DisplayClear(dev);
			break;
		case 3:
			Cursor_shift(dev);
			break;
		case 4:
			DisplayWrite(dev);
			break;
		case 5:
			iexit = 0;
			break;
		}
	}
	close(dev);
	return 0;
}
