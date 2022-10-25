#include <zephyr.h>
#include <device.h>
#include <sys/printk.h>


#define STACKSIZE 1024   // stacksize
#define PRIORITY 7        / Priority


int delay = 1000;			
		
void print1(void)
{
	while(1)
	{
		printk("Hello World!");   // printing of the first thread
		//printk( "%d\n", delay); // printing of delay
       
		
		
		delay = delay+1000;
		if(delay>10000)			//Time is resetting after 10 secs
		{
			delay=1000;
		}
		 k_msleep(delay);
		
		
	}
}

void print2(void)
{
	while(1)
	{
	     
           k_msleep(1000);
	     
           printk("My name is Pranav Shah\n");  //Printing of second thread
           
            
		
		
	}
}

K_THREAD_DEFINE(print1_id, STACKSIZE,print1, NULL, NULL, NULL,PRIORITY, 0, 0); 
K_THREAD_DEFINE(print2_id, STACKSIZE,print2, NULL, NULL, NULL,PRIORITY, 0, 0); 