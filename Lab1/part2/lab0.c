/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2016, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

#include <rpi3.h>

int main()
{
    int count = 0, roof = 2;

    /* Enable GPIO16 as an output */
    GPIO->GPFSEL1 |= (1 << 18);

    /*Blink every time count reaches 2^n where n is the number of blinks*/
    while(1) 
    {
        if(count == roof){
            /* Turn LED on */
            GPIO->GPSET0 |= (1 << 16);

            /*wait*/
            for(int i = 0; i < 100000; i++){}

            /* Turn LED off*/
	    GPIO->GPCLR0 |= (1 << 16);

            //Reset counter & raise the roof
            count = 0;
            roof *= 2;
        }

        count++;
    }

	return 0;
}
