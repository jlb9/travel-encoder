#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const uint ENCODER = 13;
const uint BTN_PIN = 14;
const uint LED_PIN = 16;

uint8_t s_button = 1;
uint8_t ps_button = 1;
uint8_t ps_encoder = 0;
uint8_t s_encoder = 0;
uint8_t cs_encoder = 0;
uint32_t x_press = 0;


uint64_t timer_start = 0;
uint64_t timer_end = 0;
uint64_t diff = 0;
uint64_t last_pressedTime;
uint64_t dbounce_time;

bool start = false;
bool s_timer = false;
bool idle = false;




int main ()
{
  

    stdio_init_all();
    gpio_init(ENCODER);
    gpio_init(LED_PIN);

    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(ENCODER, GPIO_IN);


   
   

    while(1)
    {   
        gpio_init(ENCODER);
        gpio_init(LED_PIN);

        gpio_set_dir(BTN_PIN, GPIO_IN);
        gpio_set_dir(LED_PIN, GPIO_OUT);

        const uint LED_test= PICO_DEFAULT_LED_PIN;
        gpio_init(LED_test);
        gpio_set_dir(LED_test, GPIO_OUT);
        // s_encoder = (gpio_get(ENCODER));
        // //printf("%d\n", gpio_get(encoder));

        // if(s_encoder == 1 & ps_encoder == 0) {
        //     begin = true;
        // }
        
        //printf("start= %d\n", start);
        
        // begin = time_us_32();
        // printf("Start = %lld\n", start);

        // sleep_ms(4000);

        // end = time_us_32();
        // printf("End = %lld\n", end);
      

        // diff = end - begin;

        // printf("Diff = %lld altered = %lld\n", diff, diff/1000);
        // //(gpio_get(ENCODER))
        // uint32_t t1 = time_us_32();


        s_button = (gpio_get(BTN_PIN));
        // printf("%d\n", s_button);
        

        if (gpio_get(BTN_PIN)== 0) {
            start = true;
            idle = false;

            ps_encoder = gpio_get(ENCODER);
            

            do {
                gpio_put(LED_test, 1);
                gpio_put(LED_PIN, 1);

                // printf("%d\n", gpio_get(ENCODER));
                
                // if(s_encoder != ps_encoder)     //{-----------------------------
                //     s_timer = true;
                //     timer_start = time_us_32();

                // }     //---------------------------------------------------------
                while (x_press < 2000)

                    // printf("%d\n", gpio_get(ENCODER));
                
                    // if(s_encoder != ps_encoder)          //===========================================
                    //     s_timer = true;
                    // timer_start = time_us_32();      //===========================================       
                    // printf("Start = %lld\n", timer_start);

                    // sleep_ms(4000);

                    // timer_end = time_us_32();
                    // printf("End = %lld\n", timer_end);
                

                    // diff = timer_end - timer_start;

                    // printf("Diff = %lld altered = %lld\n", diff, diff/1000);
                    // (gpio_get(ENCODER));
                    // uint32_t t1 = time_us_32();           //===========================================

                    if (gpio_get(BTN_PIN) == 0) {
                        printf("press: %ld\n", x_press);
                        x_press++;
                    }
    
                    else {
                        x_press = 0;

                    }

                start = false;
                
            }while(start == true);

            gpio_put(LED_test, 0);
            sleep_ms(100);
            }

        else {

            if (idle == false) {
                printf("-------  IDLE  -------\n");  
            }
            idle = true;
            x_press = 0;        // take out 
            s_timer = false;

        }

        
        // gpio_put(LED_PIN, start);
        // if (start == true){
        //     gpio_put(LED_PIN, start);

        // }
        // else {
        //     gpio_put(BTN_PIN, 0);
        // }

        // if(s_button = !ps_button) {

        //     last_pressedTime = time_us_32();
        //     printf("%lld\n", last_pressedTime);
        // }
        // if (time_us_32() - last_pressedTime > dbounce_time) {
        //     printf("cnage led");

        // }



    }
}



/*
button to start
wait to read
trigger arm move  get time
trigger arm stop get time 

reset.

*/

