#if (Xcells>24)||(Ycells>32)
#error "Map size larger than 24*32. Maximum allowed size is 24*32 cells."
#endif

#ifndef __SAM3X8E__
#error "This app may only be compiled for an Arduino Due"
#endif

void setup() {
  start();
  // A6 because A0--A5 are used for TFT
  randomSeed(analogRead(A6));

  drawSrartingCells();
  while (!Touch_getXY());
  createMap(CellX, CellY);
  //handleClick(CellX,CellY);
}
int x=0;
void loop() {
    // put your main code here, to run repeatedly:
    // Use hacked Touch_getXY(). Returns state of left mouse button
    // Use mouse.getButton() too.
    if (Touch_getXY()){
        handleClick(CellX, CellY);
        delay(150);
    }
    if((millis()-x)>500){
        if(mouse.getButton(RIGHT_BUTTON)){
            mark(CellX,CellY);
            x=millis();
        }
        if(mouse.getButton(MIDDLE_BUTTON)){
            middle(CellX,CellY);
            x=millis();
        }
    }
}
