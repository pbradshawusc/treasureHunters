#include "car.h"

Car::Car(MainWindow* m, QPixmap *pm, QPixmap *pm2, int nx, int ny, int d) : movingObject(m, pm, nx, ny) {
  c2 = pm2;
  animation = 0;
  vX = d;
  vY = 0;
  width = 80;
  height = 50;
}

void Car::move(int timer){
  if(timer % 1 == 0){
    x+=vX;
    setPos(x,y);
  }
}

bool Car::collide(TreasureHunter *th){
  return collidesWithItem(th);
}

void Car::animate(int timer){
  if(timer % 50 == 0){
    if(animation == 0){
      setPixmap(*c2);
    }
    else if(animation == 1){
      setPixmap(*pixMap);
      animation = -1;
    }
    animation++;
  }
}
