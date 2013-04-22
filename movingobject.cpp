#include "movingobject.h"
#include "mainwindow.h"

movingObject::movingObject( MainWindow *m, QPixmap *p, int nx, int ny ){
  pixMap = p;
  setPixmap( *p);
  x = nx;
  y = ny;
  setPos(x,y);
  mw = m;
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
