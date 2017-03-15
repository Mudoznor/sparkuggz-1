#include <stdio.h>
#include <wiringPi.h>
#include <sys/time.h>

int main()
{
	wiringPiSetup();
	pinMode(8,OUTPUT);
	pinMode(9,INPUT);
	
	while (1)
	{
		digitalWrite(8,LOW);
		digitalWrite(8,HIGH);
		delayMicroseconds(10);
		digitalWrite(8,LOW);
	
	    struct timeval t1 , t2;
	    
		int val;
	
		while (1)
		{
			val = digitalRead(9);
			if (val==HIGH)
				{
					printf("t1\n");
					break;
				}	
				else
					continue;
		}
		gettimeofday (&t1,NULL);
	
		while (1)
		{
			val = digitalRead(9);
			if (val==LOW)
				{
					printf("t2\n");
					break;
				}
				else
					continue;
		}
		gettimeofday (&t2,NULL);
		
		
		long T1 = t1.tv_sec*1000000+t1.tv_usec;
		long T2 = t2.tv_sec*1000000+t2.tv_usec;
		
		float dis =(float)(T2-T1)/1000000*34000/2;
		printf("%fcm\n",dis);
		delay(2000);	    
	}		       	
	
	return 0;
	
}
