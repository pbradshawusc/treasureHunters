#ifndef ARROW_H
#define ARROW_H

#include "movingobject.h"

class Arrow : public movingObject {
  public:
    Arrow(MainWindow* m, QPixmap *pm, int nx, int ny, int dif);
    void move(int timer);
    bool collide(TreasureHunter *th);
    void animate(int timer);
  private:
    int difficulty;
};

#endif
