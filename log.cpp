#include "log.h"

Log::Log(MainWindow* m, QPixmap *pm, int nx, int ny, int d) : movingObject(m, pm, nx, ny) {
  vX = d;
  vY = 0;
  width = 100;
  height = 50;
}

void Log::move(int timer){
  if(timer % 1 == 0){
    x+=vX;
    setPos(x,y);
  }
}

bool Log::collide(TreasureHunter *th){
  return collidesWithItem(th);
}

void Log::animate(int timer){
  timer++;
}

int Log::getVX(){
  return vX;
}
