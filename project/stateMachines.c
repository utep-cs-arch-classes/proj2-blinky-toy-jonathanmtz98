#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

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
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}

void change_dimming(){
  static char dimming = 0;
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
void firststate(){
  static char current = 0;
  switch (current){
  case 0: toggle_green = 1; current = 1; break;
  case 1: toggle_green = 1; current = 2; break;
  case 2: toggle_green = 0; current = 0; break;
  }
  led_changed = 1;
  led_update();
}
void thirdstate(){
  static char current = 0;
  switch (current){
  case 0: toggle_red = 1; current = 1; break;
  case 1: toggle_red = 1; current = 2; break;
  case 2: toggle_red = 0; current = 0; break;
  }
  led_changed = 1;
  led_update();
}
void dimmingstatemachine(){
  switch (dimming){
  case 0: firststate(); break;
  case 1: toggle_red(); break;
  case 2: thirdstate(); break;
  }
}
