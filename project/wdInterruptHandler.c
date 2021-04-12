#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

char button = 0;
void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static int state_count = 0;
  static char blink_count = 0;

  if(++blink_count == 5){
    if(button == 0){
    producesound2();
    blink_count = 0; 
  }
  }
  else if(blink_count == 125){
      if(button == 1){
    producesound();
    blink_count = 0;
      }
  }
    else if(blink_count == 2){
      if(button == 2){
    dimmingstatemachine();
    blink_count = 0;
    if(++state_count == 325){
      change_dimming();
      state_count = 0;
    }
      }
    }
    else if(blink_count == 175 && button == 3){
    producesound3();
    blink_count = 0;
      }
  // if (++blink_count == 2) {
    //    state_advance();
  // dimmingstatemachine();
  // blink_count = 0;
    // }
  // if(++state_count == 325){
  //  change_dimming();
  //  state_count = 0;
  // }

}
