#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static int state_count = 0;
  static char blink_count = 0;
  if (++blink_count == 50) {
    state_advance();
    blink_count = 0;
  }
  if(++state_count == 325){
    change_dimming();
    state_count = 0;
  }
}