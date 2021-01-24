// Draw a cell with a specific color
void drawCellColor(int x,int y,int color){
  int W=(tft.width()/Xcells);
  int H=(tft.height()/Ycells);
  int X=x*W;
  int Y=y*H;
  tft.fillRect(X,Y,W,H,color);
  tft.drawRect(X,Y,W,H,TFT_BLACK);
}

// Draw a cell as empty
void drawCellEmpty(int X,int Y){
  drawCellColor(X,Y,TFT_WHITE);
}

// Draw a cell as ground
void drawCellGround(int X,int Y){
  drawCellColor(X,Y,TFT_GREEN);
}

// Draw a cell as marked as mine
void drawCellMarked(int X,int Y){
  drawCellColor(X,Y,TFT_RED);
}

// Draw a cell as a mine (when game over)
void drawCellMine(int X,int Y){
  drawCellColor(X,Y,TFT_BLACK);
}

// Draw a revealed cell which is surrouned by mines
void drawCellSur(int x,int y,int num){
  int W=(tft.width()/Xcells);
  int H=(tft.height()/Ycells);
  int X=x*W;
  int Y=y*H;
  tft.fillRect(X,Y,W,H,TFT_WHITE);
  tft.drawRect(X,Y,W,H,TFT_BLACK);
  tft.setCursor(X+2,Y+2);
  int colors[8]={TFT_BLUE,TFT_GREEN,TFT_RED,TFT_BLUE,TFT_OLIVE,TFT_CYAN,TFT_GREEN,TFT_RED};
  tft.setTextColor(colors[num+1]);
  tft.print(num);
}

// Draw a cell with specified state
void drawCell(int X,int Y,int State){
  switch(State){
    case EMPTY:
      drawCellEmpty(X,Y);
      break;
    case MINE:
      drawCellMine(X,Y);
      break;
    case MARKED:
      drawCellMarked(X,Y);
      break;
    case GROUND:
      drawCellGround(X,Y);
      break;
    default:
      drawCellSur(X,Y,State);
      break;
  }
}

// Draw a cell with info in map
void drawCell(int X,int Y){
  drawCell(X,Y,Map[X][Y]);
}

// Draw all cells as ground
void drawSrartingCells(){
  for(int x=0;x<Xcells;x++){
    for(int y=0;y<Ycells;y++){
      drawCellGround(x,y);
      States[x][y]=GROUND;
    }
  }
}
