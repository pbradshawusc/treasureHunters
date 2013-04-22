#include "arrow.h"

Arrow::Arrow(MainWindow* m, QPixmap *pm, int nx, int ny, int dif) : movingObject(m, pm, nx, ny){
  difficulty = dif;
  vX = 0;
  vY = 1;
  width = 20;
  height = 40;
}

void Arrow::move(int timer){
  if(timer%1 == 0){
    y += vY;
    setPos(x,y);
  }
}

bool Arrow::collide(TreasureHunter *th){
  return (collidesWithItem(th));
}

void Arrow::animate(int timer){
  timer++;
}
