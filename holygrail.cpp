#include "holygrail.h"

HolyGrail::HolyGrail(MainWindow* m, QPixmap *pm, int nx, int ny, int rand) : movingObject(m, pm, nx, ny){
  vX = 2;
  vY = 2;
  width = 60;
  height = 60;
  std::srand(rand);
}

void HolyGrail::move(int timer){
  int random = std::rand() % 3;
  random -= 1;
  vX += random;
  random = std::rand() % 3;
  random -= 1;
  vY += random;
  if(vY>2){
    vY = 2;
  }
  else if(vY<-2){
    vY = -2;
  }
  if(vX>2){
    vX = 2;
  }
  else if(vX<-2){
    vX = -2;
  }
  y+=vY;
  x+=vX;
  setPos(x,y);
}

bool HolyGrail::collide(TreasureHunter *th){
  return collidesWithItem(th);
}

void HolyGrail::animate(int timer){
  timer++;
}
