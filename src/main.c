#include <zephyr.h>
#include <device.h>
#include <sys/printk.h>
#include <kernel.h>
#include <string.h>


#define STACKSIZE 1024   // stacksize
#define PRIORITY 7        / Priority




int delay = 1000;

struct printk_data_t {
	void *fifo_reserved; /* 1st word reserved for use by fifo */
	char tx_msg[50];
    int time;

};	

K_FIFO_DEFINE(my_fifo);
struct printk_data_t tx_message  = {.tx_msg = "Pranav SHah",.time = 1000};
		
void print1(void)
{
	while(1)
	{
   
		printk("Hello World!");   // printing of the first thread
      
		printk( "%d\n", delay); // printing of delay
       
		
		
		delay = delay+1000;
		if(delay>10000)			//Time is resetting after 10 secs
		{
			delay=1000;
		}
            k_fifo_put(&my_fifo,&tx_message);
              k_msleep(delay);
		 
		
		
	}
}

void print2(void)
{
 
     
	while(1)
	{
         
	        struct printk_data_t *rx= k_fifo_get(&my_fifo, K_FOREVER);  
            k_msleep(rx->time);
	        printk("%s%d\n",rx->tx_msg,rx->time);
      
           //printk("My name is Pranav Shah\n");  //Printing of second thread
           
            
		
		
	}
}

K_THREAD_DEFINE(print1_id, STACKSIZE,print1, NULL, NULL, NULL,7, 0, 0); 
K_THREAD_DEFINE(print2_id, STACKSIZE,print2, NULL, NULL, NULL,7, 0, 0); 