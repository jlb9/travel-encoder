/*  
*/
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const uint ENCODER = 13;
const uint BTN_PIN = 14;
const uint LED_PIN = 16;
const uint LED_test= PICO_DEFAULT_LED_PIN;

uint8_t s_button = 1;
uint8_t ps_button = 1;
uint8_t ps_encoder = 0;
uint8_t s_encoder = 0;
uint8_t cs_encoder = 0;
uint32_t x_press = 0;
uint32_t counter = 0;


uint64_t timer_start = 0;
uint64_t timer_end = 0;
uint64_t diff = 0;
uint64_t last_pressedTime;
uint64_t dbounce_time;

bool start = false;
bool s_timer = false;
bool e_timer = false;
bool i_timer = false;
bool idle = false;




int main ()
{

  

    gpio_init(LED_test);
    gpio_set_dir(LED_test, GPIO_OUT);
    stdio_init_all();
    gpio_init(ENCODER);
    gpio_init(LED_PIN);

    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(ENCODER, GPIO_IN);


    sleep_ms(2000); //2000  for startup 
    // printf("-------  1 IDLE  -------\n"); 


    while(1)
    {
        // s_button = (gpio_get(BTN_PIN));
        // printf("%d\n", s_button);

        if (gpio_get(BTN_PIN) == 0) {
            start = true;
            idle = false;

            ps_encoder = gpio_get(ENCODER);
            

            do {

                printf("Encoder: %d\n", gpio_get(ENCODER));
                gpio_put(LED_test, 1);
                gpio_put(LED_PIN, 1);
                
                while (x_press < 2000 & start == true) {

                    s_encoder = gpio_get(ENCODER);

                    if((s_encoder != ps_encoder) & s_timer == false) { 
                        printf("--- not equal ---\n");
                        timer_start = time_us_32();
                        s_timer = true;
                        printf("Start Timer: %lld\n", timer_start);

                        
                        // if (s_timer == false){
                        //     timer_start = time_us_32();
                        //     printf("Start Timer: %lld\n", timer_start);
                        //     s_timer = true;
                        // }
                        // else if(s_timer == true & (s_encoder == ps_encoder)) {
                        //     e_timer = time_us_32();
                        //     counter++;
                        //     if((time_us_32) - 
                    }
                    else if ((s_encoder == ps_encoder) & s_timer == true) {
                        counter++;
                        if (counter >20) {
                            timer_end = time_us_32();
                            printf("Stop Timer: %lld\n", timer_end);
                            start = false;
                        }

                    }
                    else {
                        printf("-equal-\n");
                        // printf("start_timer t/f= %d timestamp = %lld\n", s_timer, timer_start);
                        counter = 0;
                    }
                    ps_encoder = s_encoder;
                    printf("Counter: %d\n", counter);

                










                    if (gpio_get(BTN_PIN) == 0) {
                        // printf("exit: %ld\n", x_press);
                        if (x_press >1998)  {
                            printf("-- Release Button --\n");
                        }
                        x_press++;
                    }
    
                    else {
                        x_press = 0;

                    }
                }
                start = false;
                diff = timer_end - timer_start;
                
            }while(start == true);

            gpio_put(LED_test, 0);
            gpio_put(LED_PIN, 0);
            sleep_ms(1000);
            }

        else {
            sleep_ms(100);  //100
            // printf("IDLE - 2= %d \n", idle);
            if (idle == false) {
                printf("-------  IDLE  -------\n");
                printf("start_timer t/f= %d Start = %lld Stop = %lld Diff = %lld\n", s_timer, timer_start, timer_end, diff); 
            }
            idle = true;
            x_press = 0;        // take out 
            s_timer = false;


        }
        // sleep_ms(5000);
        // printf("IDLE - 3= %d \n", idle);
    }
}



/*
button to start
wait to read
trigger arm move  get time
trigger arm stop get time 

reset.

*/

