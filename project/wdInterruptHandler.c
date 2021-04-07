#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static int state_count = 0;
  static char blink_count = 0;
  if (++blink_count == 2) {
    //    state_advance();
    dimmingstatemachine();
    blink_count = 0;
  }
  if(++state_count == 325){
    change_dimming();
    state_count = 0;
  }
}
