#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;
}

 char toggle_green()	/* only toggle green */
{
  static char state = 0;
  
  switch(state){
  case 0: green_on = 1; state = 1; break;
  case 1: green_on = 0; state = 0; break;
  }
  return 1;
}
//void state_advance()		/* alternate between toggling red & green */
//{
// char changed = 0;  

// static enum {R=0, G=1} color = G;
// switch (color) {
   // case R: changed = toggle_red(); color = G; break;
       //  case G: changed = toggle_green(); color = R; break;
       //        }

// led_changed = changed;
// led_update();
// }
void firststate(){
    static char current = 0;
   switch (current){
     case 0: red_on = 0; current = 1; break;
     case 1: red_on = 0; current = 2; break;
      case 2: red_on = 0; current = 3; break;
   case 3: red_on =1; current = 0; break;
     }
   led_changed = 1;
   led_update();
  }
void thirdstate(){
  static char current = 0;
  switch (current){
  case 0: red_on = 1; current = 1; break;
  case 1: red_on = 1; current = 2; break;
  case 2: red_on = 1; current = 3; break;
  case 3: red_on =0; current = 0; break;
  }
  led_changed = 1;
  led_update();
}
static char dimming = 0;
void dimmingstatemachine(){
  switch (dimming){
  case 0: firststate(); break;
  case 1: toggle_red(); break;
  case 2: thirdstate(); break;
  }
}
void change_dimming(){
  if(dimming == 0){
    dimming = 1;
  }
  else if(dimming == 1){
    dimming = 2;
  }
  else{
    dimming = 0;
  }
}
void producesound2(){
static char current = 0;
switch(current){
   case 0: buzzer_set_period(1000); current = 1;  break;
   case 1: buzzer_set_period(1010); current = 2; break;
   case 2: buzzer_set_period(1111); current = 3; break;
   case 3: buzzer_set_period(1200); current = 0; break;
     }
}
void producesound(){
  static char current = 0;
  switch(current){
  case 0: buzzer_set_period(1500); current = 1; break;
  case 1: buzzer_set_period(1750); current = 2; break;
  case 2: buzzer_set_period(2000); current = 3; break;
  case 3: buzzer_set_period(0); current = 0; break;
  }
}
void producesound3(){
  static char current = 0;
  switch(current){
  case 0: buzzer_set_period(2500); current =1; break;
  case 1: buzzer_set_period(2750); current = 2; break;
  case 2: buzzer_set_period(3000); current = 3; break;
  case 3: buzzer_set_period(3250); current = 0; break;
  }
}

