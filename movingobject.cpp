#include "movingobject.h"

movingObject::movingObject( QPixmap *p, int nx, int ny ){
  pixMap = p;
  setPixmap( *p);
  x = nx;
  y = ny;
  setPos(x,y);
}

int movingObject::getX(){
  return x;
}

int movingObject::getY(){
  return y;
}
int movingObject::getWidth(){
  return width;
}

int movingObject::getHeight(){
  return height;
}
/*
int movingObject::getvX(){

}
int movingObject::getVY(){

}

QPixmap *movingObject::getPixMap(){

}*/
