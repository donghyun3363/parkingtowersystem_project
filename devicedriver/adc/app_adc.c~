#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>

int main(int argc, char* argv[])
{
	int dev, adc_data;
	time_t inittime;
	FILE *f_in;

	inittime = time(NULL);

	while(time(NULL) - inittime<10)
	{
		f_in = fopen("/sys/devices/12d10000.adc/iio:device0/in_voltage0_raw","r");
		fscanf(f_in,"%d",&adc_data);
		printf("ADC data : %d\n",adc_data);
		fclose(f_in);
	}
	return 0;
}
