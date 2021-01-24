/*
 * Minesweeper for Arduino Due
 * By Mammad900 (https://github.com/mammad900)
 * 
 * Hardware required:
 * 1. Arduino Due
 * 2. MCUFRIEND_kbv compatible TFT screen (Touch isn't needed)
 * 3. OTG cable
 * 4. USB mouse
 * 
 * Software required:
 * 1. Arduino IDE
 * 2. Arduino SAM core
 * 3. Library: MCUFRIEND_kbv
 * 4. Library: Adafruit_GFX
 * 5. Library: USBHost
 */

// Cell states
#define DIGGED 0
#define EMPTY 0
#define SUR1 1
#define SUR2 2
#define SUR3 3
#define SUR4 4
#define SUR5 5
#define SUR6 6
#define SUR7 7
#define SUR8 8
#define MINE 9
#define GROUND 10
#define MARKED 11

// Current clicked cell
#define CellX (pixel_x/(tft.width() /Xcells))
#define CellY (pixel_y/(tft.height()/Ycells))
