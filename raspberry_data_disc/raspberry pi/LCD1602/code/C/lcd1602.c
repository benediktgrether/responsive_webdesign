#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <lcd.h>

const unsigned char Buf[] = "------world-------";
const unsigned char myBuf[] = "-----hello-------";

int main(void)
{
	int fd;
	int i;
	
	if(wiringPiSetup() == -1){
		exit(1);
	}
	
	fd = lcdInit(2,16,4, 1,2, 3,4,5,6,0,0,0,0); //see /usr/local/include/lcd.h
	printf("%d", fd);
	if (fd == -1){
		printf("lcdInit 1 failed\n") ;
		return 1;
	}
	sleep(1);
	lcdClear(fd);
	lcdPosition(fd, 0, 0); 
	lcdPuts(fd, "Welcome To--->");

	lcdPosition(fd, 0, 1); 
	lcdPuts(fd, "    raspberry pi");

	sleep(1);
	lcdClear(fd);
	
	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|           Control LCD1602            |\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");

	while(1){
		lcdClear(fd);
		for(i=0; i<16; i++){
			lcdPosition(fd, i, 0);
			lcdPutchar(fd, *(myBuf+i));
			delay(100);
		}
		for(i=0;i<sizeof(Buf)-1;i++){
			lcdPosition(fd, i, 1);
			lcdPutchar(fd, *(Buf+i));
			delay(200);
		}
		sleep(0.5);
	}
	return 0;
}
