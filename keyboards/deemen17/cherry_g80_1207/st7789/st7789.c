// Copyright 2023 OakNinja (@oakninja)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "qp.h"
#include "qp_comms.h"

#include "qp_st77xx_opcodes.h"
#include "qp_st7789.h"
#include "font/hitmo2.qff.h"

#include "color.h"
#include "config.h"

static painter_font_handle_t font;
static painter_device_t      lcd;

__attribute__((weak)) void ui_init(void) {
    lcd = qp_st7789_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
    font = qp_load_font_mem(font_hitmo2);
    qp_init(lcd, LCD_ROTATION);
    qp_set_viewport_offsets(lcd, LCD_OFFSET_X, LCD_OFFSET_Y);
    qp_power(lcd, true);
    qp_rect(lcd, 0, 0, LCD_WIDTH, LCD_HEIGHT, HSV_BLACK, 1);
    qp_flush(lcd);
}

__attribute__((weak)) void ui_task(void) {
    static const char *text = "DEEMEN17 WORKS MADE ME";
    int16_t text_width  = qp_textwidth(font, text);
    int16_t text_height = font->line_height;
    int16_t x = (LCD_WIDTH  - text_width)  / 2;
    int16_t y = (LCD_HEIGHT - text_height) / 2;
    qp_drawtext(lcd, x, y, font, text);
}

void keyboard_post_init_kb(void) {
    ui_init();
    keyboard_post_init_user();
}

void housekeeping_task_kb(void) {
    ui_task();
}
