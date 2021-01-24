// Show all mines and reset Arduino Due
void gameOver(){
    for(int x=0;x<Xcells;x++){
        for(int y=0;y<Ycells;y++){
            drawCell(x,y);
        }
    }
    delay(2000);
    rstc_start_software_reset(RSTC);
    while(1);
}
