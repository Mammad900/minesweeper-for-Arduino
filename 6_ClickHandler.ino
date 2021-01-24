// Reveal a cell
void revealCell(int x,int y){
    if(States[x][y]==GROUND){
        drawCell(x,y);
        States[x][y]=DIGGED;
    }
}

// Handle a click at the specified cell
void handleClick(int X,int Y){
    //if(States[X][Y]==GROUND){
        switch(Map[X][Y]){
          case EMPTY:
            digsEmpty(X,Y,5);
            break;
          case MINE:
            gameOver();
            break;
          default:
            revealCell(X,Y);
            break;
        }
    //}
}

// (?) Reveal all non-marked cells around the cell, when there are as many marked cells around it as there are mines
void revealEmpty(int X,int Y,bool force=true){
    if((States[X][Y]==DIGGED)||(!force)){
        if((X>=Xcells)||
           (Y>=Ycells)||
           (X<0)||
           (Y<0)){
           return;
        }
        if(Map[X][Y]==EMPTY){
          revealCell(X,Y);
          int items[8][2]={
            {X-1,Y-1},
            {X  ,Y-1},
            {X+1,Y-1},
            {X+1,Y  },
            {X+1,Y+1},
            {X  ,Y+1},
            {X-1,Y+1},
            {X-1,Y  }
          };
          for(int i=0;i<8;i++){
            int x=items[i][0];
            int y=items[i][1];
            
            if((x>=Xcells)||
               (y>=Ycells)||
               (x<0)||
               (y<0)){
               continue;
            }
            revealCell(x,y);
          }
        }
    }
}

// calls digEmpty a few times
void digsEmpty(int X,int Y, int count){
    for(int i=0;i<count;i++){
        digEmpty(X,Y);
    }
}

// Reveal the area
void digEmpty(int X,int Y){
            revealEmpty(X,Y,false );
            int maxR;
            maxR=max(max(Xcells-X,Ycells-Y),max(Xcells-(Xcells-X),Ycells-(Ycells-Y))+1);
            for(int r=0;r<maxR;r++){
                for(int i=0;i<(r*2);i++){
                    int x=X-r;
                    int y=Y-r+i;
                    revealEmpty(x,y);
                }
                for(int i=0;i<(r*2);i++){
                    int x=X-r+i;
                    int y=Y-r;
                    revealEmpty(x,y);
                }
                for(int i=0;i<(r*2);i++){
                    int x=X+r;
                    int y=Y-r+i;
                    revealEmpty(x,y);
                }
                for(int i=0;i<(r*2);i++){
                    int x=X-r+i;
                    int y=Y+r;
                    revealEmpty(x,y);
                }
            }
}

// How many marked cells are around this cell?
int getSurroundingsM(int X,int Y){
  int result=0;
  int items[8][2]={
    {X-1,Y-1},
    {X  ,Y-1},
    {X+1,Y-1},
    {X+1,Y  },
    {X+1,Y+1},
    {X  ,Y+1},
    {X-1,Y+1},
    {X-1,Y  }
  };
  for(int i=0;i<8;i++){
    int x=items[i][0];
    int y=items[i][1];
    if((States[x][y])==MARKED){
        if((x>=Xcells)||
           (y>=Ycells)||
           (x<0)||
           (y<0)){
           continue;
        }
        
      result++;
    }
  }
  return result;
}

// Mark / unmark a cell
void mark(int x,int y){
    if(States[x][y]==GROUND){
        States[x][y]=MARKED;
        drawCell(x,y,MARKED);
    }
    else if(States[x][y]==MARKED){
        States[x][y]=GROUND;
        drawCell(x,y,GROUND);
    }
}

// If there are no mines around the cell, reveal the area
void middle(int x,int y){
    int s=getSurroundingsM(x,y);
    if(s==(Map[x][y])){
          int items[8][2]={
            {x-1,y-1},
            {x  ,y-1},
            {x+1,y-1},
            {x+1,y  },
            {x+1,y+1},
            {x  ,y+1},
            {x-1,y+1},
            {x-1,y  }
          };
        for(int i=0;i<8;i++){
            int x=items[i][0];
            int y=items[i][1];
                if((x>=Xcells)||
                   (y>=Ycells)||
                   (x<0)||
                   (y<0)){
                   continue;
                }
                if(States[x][y]==GROUND){
                    handleClick(x,y);
                }
        }
    }
}
