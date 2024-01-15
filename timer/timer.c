#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const int SIGNAL = 13;
const int BTN_PIN = 14;
const uint LED_PIN = 15;


bool begin = false;

uint64_t start = 0;
uint64_t end = 0;
uint64_t diff = 0;




int main ()
{
  

    stdio_init_all();
    gpio_init(SIGNAL);
    gpio_init(LED_PIN);

    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(SIGNAL, GPIO_IN);


printf("begin");
   

    while(1)
    {

        s_encoder = (gpio_get(SIGNAL));
        s_button = (gpio_get(BTN_PIN));
        //printf("%d\n", gpio_get(encoder));

        if(s_encoder == 1 & ps_encoder == 0) {
            begin = true;
        }
        
        //printf("start= %d\n", start);
        
        // start = time_us_32();
        // printf("Start = %lld\n", start);

        // sleep_ms(4000);

        // end = time_us_32();
        // printf("End = %lld\n", end);
      

        // diff = end - start;

        // printf("Diff = %lld altered = %lld\n", diff, diff/1000);
        // //(gpio_get(SIGNAL))
        // uint32_t t1 = time_us_32();

        

        if(s_button = ! ps_button) {

            last_pressedTime = time_us_32();
    }
        if (time_us_32() - last_pressedTime > dbounce_time) {
            printf("cnage led")

        }
    }
}



/*
button to start
wait to read
trigger arm move  get time
trigger arm stop get time 

reset.

*/

