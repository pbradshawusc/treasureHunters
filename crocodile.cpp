#include "crocodile.h"

Crocodile::Crocodile(MainWindow* m, QPixmap *pm, QPixmap *c, int nx, int ny, int d) : movingObject(m, pm, nx, ny) {
  vX = d;
  vY = 0;
  width = 100;
  height = 50;
  c2 = c;
  animation = 0;
}

void Crocodile::move(int timer){
  if(timer % 1 == 0){
    x+=vX;
    setPos(x,y);
  }
}

bool Crocodile::collide(TreasureHunter *th){
  return collidesWithItem(th);
}

void Crocodile::animate(int timer){
  if(timer % 40 == 0){
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
