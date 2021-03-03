# Minesweeper for Arduino

A minesweeper game that runs on an Arduino Due and is controlled by a USB mouse instead of touch-screen

## Usage

1. Download/clone the repository
2. Open `minesweeper-for-Arduino.ino` in Arduino IDE
3. Chose 'Arduino Due' as board and select the right port
4. Upload the app to Arduino Due
5. Connect a USB mouse to Arduino Due native USB port using USB OTG connector
6. Enjoy the game!

## Hardware required

1. Arduino Due
2. MCUFRIEND_kbv compatible TFT screen (Touch isn't needed)
3. OTG cable
4. USB mouse

## Software required

1. Arduino IDE
2. Arduino SAM core
3. Library: MCUFRIEND_kbv
4. Library: Adafruit_GFX
5. Library: USBHost

## Controls

This app's behavior and controls are like most other minesweeper games, but it's closer to Google minesweeper game.

**Left-click**: Reveal cell  
**Right-click**: Mark cell as mine  
**Middle-click**: When all mines around cell are marked, reveal all non-marked surrounding cells
