#ifndef CAR_H
#define CAR_H

#include "movingobject.h"

class Car : public movingObject {
  public:
    Car(QPixmap *pm, QPixmap *pm2, int nx, int ny, int d, int dif);
    void move(int timer);
    bool collide(TreasureHunter *th);
    void animate(int timer);
  private:
    int direction;
    int animation;
    QPixmap *c2;
    int difficulty;
};

#endif
