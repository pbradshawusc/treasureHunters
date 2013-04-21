#include "log.h"

Log::Log(QPixmap *pm, int nx, int ny, int d, int dif) : movingObject(pm, nx, ny) {
  vX = d;
  vY = 0;
  width = 100;
  height = 50;
  difficulty = dif;
}

void Log::move(int timer){
  if(timer % 1/difficulty == 0){
    x+=vX;
    setPos(x,y);
  }
}

bool Log::collide(TreasureHunter *th){
  //return collidesWithItem(th);
  return true;
}

void Log::animate(int timer){
  timer++;
}
