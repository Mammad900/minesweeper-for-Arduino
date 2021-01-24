#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>   // Hardware-specific library
#define MINPRESSURE 50
#define MAXPRESSURE 500
#include <FreeDefaultFonts.h>
#include <MouseController.h>// Require mouse control library
USBHost usb;// Initialize USB Controller
int CurserTemp[11][15];int xp=120,yp=160,lx,ly;
MouseController mouse(usb);// Attach mouse controller to USB
MCUFRIEND_kbv tft;
int pixel_x, pixel_y; 

// Mouse version of Touch_getXY
bool Touch_getXY(void) {
  readPixels(xp,yp);
  pixel_x=lx=xp;
  pixel_y=ly=yp;
  tft.fillTriangle(xp,yp,xp+10,yp+10,xp,yp+13,TFT_WHITE);
  tft.drawTriangle(xp,yp,xp+10,yp+10,xp,yp+13,0);
  delay(10);
  usb.Task();
  drawPixels(lx,ly);
  return mouse.getButton(LEFT_BUTTON);
}

// Initialize TFT screen
void start(int clr=TFT_BLACK) {
  uint16_t ID = tft.readID(); tft.begin(ID);
  tft.setRotation(0);tft.fillScreen(clr);
}

// Handling cursor
void readPixels(int x,int y){
  for(int k=0;k<11;k++){
    for(int j=0;j<15;j++){
      CurserTemp[k][j]=tft.readPixel(k+x,y+j);
    }
  }
}
void drawPixels(int x,int y){
  for(int k=0;k<11;k++){
    for(int j=0;j<15;j++){
      tft.drawPixel(k+x,j+y,CurserTemp[k][j]);
    }
  }
}
void mouseMoved() {
  xp+=mouse.getXChange();
  if(xp>240)xp=240;
  if(xp<0)xp=0;
  yp+=mouse.getYChange();
  if(yp>320)yp=320;
  if(yp<0)yp=0;
}
void mouseDragged() {
  mouseMoved();
}
