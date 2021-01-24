// Creates a suitable map
// X and Y are used to create a map with an empty cell at X,Y
void createMap(int X,int Y){
  bool isGood=false;
  do{
    attemptCreateMap();
    isGood=(Map[X][Y]==EMPTY);
  } while(!isGood);
}

// Attempts to create a map, without checking if it's suitable
void attemptCreateMap(){
  for(int x=0;x<Xcells;x++){
    for(int y=0;y<Ycells;y++){
      Map[x][y]=EMPTY;
    }
  }
  for(int i=0;i<mineCount;i++){
    int X=random(Xcells);
    int Y=random(Ycells);
    if(Map[X][Y]==EMPTY){
      Map[X][Y]=MINE;
    }
  }
  for(int x=0;x<Xcells;x++){
    for(int y=0;y<Ycells;y++){
      if(Map[x][y]!=MINE){
        Map[x][y]=getSurroundings(x,y);
      }
    }
  }
}

// How many mines are around the cell?
int getSurroundings(int X,int Y){
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
    if((Map[x][y])==MINE){
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
