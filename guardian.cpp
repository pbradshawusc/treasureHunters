#include "guardian.h"
#include <cstdlib>
#include <iostream>
#include "mainwindow.h"

Guardian::Guardian(MainWindow *m, QPixmap *pm, QPixmap *pm2, QPixmap *pm3, QPixmap *pm4, int nx, int ny, int min,  int mx, int rand) : movingObject(m, pm, nx, ny){
  g2 = pm2;
  g3 = pm3;
  g4 = pm4;
  vX = 1;
  vY = 0;
  width = 50;
  height = 40;
  maxX = mx;
  minX = min;
  animation = 0;
  srand(rand);
}

void Guardian::move(int timer){
  if(timer%1 == 0){
    x+=vX;
    setPos(x,y);
    if(x+width >= maxX || x <= minX){
      vX = -vX;
    }
  }
}

bool Guardian::collide(TreasureHunter *th){
  return false;
}

void Guardian::animate(int timer){
  if(timer%20 == 0 && timer<12001){
    int random = rand() % 5;
    if(random > 3){
      if(animation == 0){
        setPixmap(*g2);
      }
      else if(animation == 1){
        setPixmap(*g3);
      }
      else if(animation == 2){
        setPixmap(*g4);
        mw->addArrow(x+15,y+height);
      }
      else if(animation == 3){
        setPixmap(*pixMap);
        animation = 0;
      }
      animation ++;
    }
  }
}
