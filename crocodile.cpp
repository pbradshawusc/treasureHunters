#include "crocodile.h"

Crocodile::Crocodile(QPixmap *pm, QPixmap *c, int nx, int ny, int d, int dif) : movingObject(pm, nx, ny) {
  vX = d;
  vY = 0;
  width = 100;
  height = 50;
  difficulty = dif;
  c2 = c;
  animation = 0;
}

void Crocodile::move(int timer){
  if(timer % 1/difficulty == 0){
    x+=vX;
    setPos(x,y);
  }
}

bool Crocodile::collide(TreasureHunter *th){
  return collidesWithItem(th);
}

void Crocodile::animate(int timer){
  if(timer % 1/difficulty == 0){
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
