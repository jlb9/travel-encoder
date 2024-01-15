#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const int SIGNAL = 13;
const int BTN_PIN = 14;
const uint LED_PIN = 16;

uint8_t s_encoder = 0;
uint8_t ps_encoder = 0;
uint8_t s_button = 1;
uint8_t ps_button = 1;
uint32_t last_pressedTime 0;

bool begin = false;

uint64_t start = 0;
uint64_t end = 0;
uint64_t diff = 0;
uint64_t dbounce_time = 50000;



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
    if (time_us_32() - last_pressedTime > dbounce_time;)
    

            // printf("Button pressed\n");
            // gpio_put(LED_PIN, 1);
        }
        // else {
        //     printf("------ OFF ------\n");
        //     gpio_put(LED_PIN, 0);
        // }
            

           






        // gpio_put(LED_PIN, 0);
        // sleep_ms(250);
        // gpio_put(LED_PIN, 1);
        // puts("Hello Word\n");
        // sleep_ms(2000);
    }
}



/*
button to start
wait to read
trigger arm move  get time
trigger arm stop get time 

reset.

*/

/*------------------------------------------move ?

    */