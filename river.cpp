#include "river.h"
#include <cmath>

River::River(MainWindow* m, QPixmap *pm, QPixmap *pm2, QPixmap *pm3, int nx, int ny) : movingObject(m, pm, nx, ny){
  width = 698;
  height = 200;
  r2 = pm2;
  r3 = pm3;
  vX = 0;
  vY = 0;
  animation = 0;
}
void River::move(int timer){
  timer++;
  return;
}

bool River::collide(TreasureHunter *th){
  if(abs(th->getX()-x) >= (th->getWidth()/3)){
    if(abs(th->getY()-y) >= (th->getHeight()/3)){
      return true;
    }
  }
  return false;
}

void River::animate(int timer){
  if(timer%15 == 0){
    if(animation == 0){
      setPixmap(*r2);
    }
    else if(animation == 1){
      setPixmap(*r3);
    }
    else if(animation == 2){
      setPixmap(*pixMap);
      animation = -1;
    }
    animation++;
  }
}
