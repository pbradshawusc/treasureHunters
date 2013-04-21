#include "treasurehunter.h"

TreasureHunter::TreasureHunter(QPixmap* s, QPixmap* l1, QPixmap* l2, QPixmap* r1, QPixmap* r2, int nx, int ny, int dif) : QGraphicsPixmapItem(*s) {
  x = nx;
  y = ny;
  setPos(x,y);
  width = 20;
  height = 35;
  vX = 1;
  vY = 1;
  still = s;
  left1 = l1;
  left2 = l2;
  right1 = r1;
  right2 = r2;
  difficulty = dif;
  animation = 0;
}

void TreasureHunter::animate(int timer){
  if(timer % 15 == 0){
    if(animation == 0){
      setPixmap(*left1);
    }
    else if (animation == 1){
      setPixmap(*left2);
    }
    else if (animation == 2){
      setPixmap(*left1);
    }
    else if (animation == 3){
      setPixmap(*still);
    }
    else if (animation == 4){
      setPixmap(*right1);
    }
    else if (animation == 5){
      setPixmap(*right2);
    }
    else if (animation == 6){
      setPixmap(*right1);
    }
    else if (animation == 7){
      setPixmap(*still);
      animation = -1;
    }
    animation++;
  }
}

void TreasureHunter::move(int direction){
  if(direction == 0){
    y += vY;
  }
  else if(direction == 1){
    x += vX;
  }
  else if(direction == 2){
    y -+ vY;
  }
  else if(direction == 3){
    x -= vX;
  }
  setPos(x,y);
}

int TreasureHunter::getX(){
  return x;
}

int TreasureHunter::getY(){
  return y;
}

int TreasureHunter::getWidth(){
  return width;
}

int TreasureHunter::getHeight(){
  return height;
}
