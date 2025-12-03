// Copyright 2023 OakNinja (@oakninja)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* SPI pins */
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN A5
#define SPI_MOSI_PIN A7
#define SPI_MISO_PIN A6 // Unused

/* LCD Configuration */
#define LCD_RST_PIN B0
#define LCD_DC_PIN B1
#define LCD_CS_PIN B10
#define LCD_BLK_PIN B2 // Unused in this configuration
#define LCD_SPI_DIVISOR 4
#define LCD_WAIT_TIME 150
#define LCD_ROTATION QP_ROTATION_90
#define LCD_OFFSET_X 0
#define LCD_OFFSET_Y 0
//#define LCD_INVERT_COLOR

// QP Configuration
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
//#define ST7789_NO_AUTOMATIC_VIEWPORT_OFFSETS

// Timeout configuration, default 30000 (30 sek). 0 = No timeout. Beware of image retention.
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0

#define LCD_WIDTH 320
#define LCD_HEIGHT 170
#define SPI_MODE 3
#define ST7789