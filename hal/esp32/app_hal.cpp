
#include "app_hal.h"
#include "lvgl.h"

#include <M5GFX.h>

M5GFX display;


static const uint32_t screenWidth = 540;
static const uint32_t screenHeight = 960;

const unsigned int lvBufferSize = screenWidth * 30; // 2 bytes per pixel for RGB565
uint8_t lvBuffer[lvBufferSize];

static lv_display_t *lvDisplay;
static lv_indev_t *lvInput;

#if LV_USE_LOG != 0
static void lv_log_print_g_cb(lv_log_level_t level, const char *buf)
{
  LV_UNUSED(level);
  LV_UNUSED(buf);
  Serial.write(buf);
}
#endif

/* Display flushing */
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, unsigned char *data)
{
  display.pushImage(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (uint16_t *)data);

  lv_display_flush_ready(disp); /* tell lvgl that flushing is done */
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_t *indev_driver, lv_indev_data_t *data)
{
  lgfx::touch_point_t tp[3];

  int nums = display.getTouchRaw(tp, 3);
  if (!nums)
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    data->state = LV_INDEV_STATE_PR;
    /*Set the coordinates*/
    data->point.x = tp[0].x;
    data->point.y = tp[0].y;
  }
}

/* Tick source, tell LVGL how much time (milliseconds) has passed */
static uint32_t my_tick(void)
{
  return millis();
}

void hal_setup(void)
{

  Serial.begin(115200);

  /* Initialize the display drivers */

  display.init();
  display.touch();
  display.setEpdMode(epd_mode_t::epd_quality);


  /* Set the tick callback */
  lv_tick_set_cb(my_tick);

  // lv_log_register_print_cb(lv_log_print_g_cb);

  /* Create LVGL display and set the flush function */
  lvDisplay = lv_display_create(screenWidth, screenHeight);
  lv_display_set_color_format(lvDisplay, LV_COLOR_FORMAT_RGB565);
  lv_display_set_flush_cb(lvDisplay, my_disp_flush);
  lv_display_set_buffers(lvDisplay, lvBuffer, NULL, lvBufferSize, LV_DISPLAY_RENDER_MODE_PARTIAL);

  /* Set the touch input function */
  lvInput = lv_indev_create();
  lv_indev_set_type(lvInput, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(lvInput, my_touchpad_read);

  Serial.println("Setup complete");
}

void hal_loop(void)
{
  /* NO while loop in this function! (handled by framework) */
  lv_timer_handler(); // Update the UI-
  delay(5);
}
