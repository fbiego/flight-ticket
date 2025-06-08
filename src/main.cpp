



#include "lvgl.h"
#include "app_hal.h"
#include "jambojet/ui.h"


#ifdef ARDUINO
#include <Arduino.h>

void setup() {
  lv_init();
  hal_setup();

  ui_init("");

}

void loop() {
  hal_loop();  /* Do not use while loop in this function */
}

#else

int main(void)
{
	lv_init();

	hal_setup();

  ui_init("");


	hal_loop();
}

#endif /*ARDUINO*/