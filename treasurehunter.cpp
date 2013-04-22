#include "treasurehunter.h"

TreasureHunter::TreasureHunter(QPixmap* s, QPixmap* l1, QPixmap* l2, QPixmap* r1, QPixmap* r2, int nx, int ny, int dif) : QGraphicsPixmapItem(*s) {
  x = nx;
  y = ny;
  setPos(x,y);
  width = 20;
  height = 35;
  vX = 35;
  vY = 50;
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
    if(y!=580){
    y += vY;
    }
  }
  else if(direction == 2){
    if(y-vY*2 > 175-height*2){
      y-=vY*2;
    }
    else if(y-vY*2 > 175-height*3){
      y-=vY;
      if((x>=30 && x<=110)||(x>=30+140 && x<=110+140)||(x>=30+140*2 && x<=110+140*2)||(x>=30+140*3 && x<=110+140*3)||(x>=30+140*4 && x<=110+140*4)){
        y-=vY;
      }
    }
    else {
      y-=vY;
    }
  }
  else if(direction == 3){
    x = x-vX*2;
    //y += vY;
  }
  if(x+width > 700){
    x = 700-width;
  }
  else if(x<0){
    x = 0;
  }
  if(y > 581){
    y = 580;
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

void TreasureHunter::logMove(int v){
  x+= v;
  if(x<0){
    x = 0;
  }
  else if(x+width > 700){
    x = 700-width;
  }
  setPos(x,y);
}

void TreasureHunter::setLoc(int nx, int ny){
  setPos(nx,ny);
  x = nx;
  y = ny;
}
