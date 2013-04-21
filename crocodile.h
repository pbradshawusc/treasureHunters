#ifndef CROCODILE_H
#define CROCODILE_H

#include "movingobject.h"

class Crocodile : public movingObject {
  public:
    Crocodile(QPixmap *pm, QPixmap *c, int nx, int ny, int d, int dif);
    void move(int timer);
    bool collide(TreasureHunter *th);
    void animate(int timer);
  private:
    int direction;
    int difficulty;
    int animation;
    QPixmap *c2;
};

#endif
