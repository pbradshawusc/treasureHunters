#ifndef RIVER_H
#define RIVER_H

#include "movingobject.h"

class River : public movingObject {
  public:
    River(MainWindow* m, QPixmap *pm, QPixmap *pm2, QPixmap *pm3, int nx, int ny);
    void move(int timer);
    bool collide(TreasureHunter *th);
    void animate(int timer);
  private:
    QPixmap *r2;
    QPixmap *r3;
    int animation;
};

#endif
