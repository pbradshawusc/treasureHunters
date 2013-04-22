#include "temple.h"
#include <iostream>

Temple::Temple(MainWindow* m, QPixmap *pm, QPixmap *pm2, int nx, int ny) : movingObject(m, pm, nx, ny){
  full = false;
  f = pm2;
  width = 80;
  height = 60;
}

void Temple::move(int timer){
  timer++;
}

bool Temple::collide(TreasureHunter *th){
  //if(th->getX()+th->getWidth()>=x && th->getX()<=x+width && th->getY()<=y+height && th->getY()+th->getHeight()>=y){
  if(collidesWithItem(th)){
    full = true;
    return true;
  }
  //std::cout << th->getX() << " " << th->getY() << " " << x << " " << y << std::endl;
  return false;
}

void Temple::animate(int timer){
  timer++;
  if(full == true){
    setPixmap(*f);
  }
}
