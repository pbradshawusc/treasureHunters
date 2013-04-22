#ifndef TEMPLE_H
#define TEMPLE_H

#include "movingobject.h"

class Temple : public movingObject {
  public:
    Temple(MainWindow* m, QPixmap *pm, QPixmap *pm2, int nx, int ny);
    void move(int timer);
    bool collide(TreasureHunter *th);
    void animate(int timer);
    bool hit();
    void setEmpty();
  private:
    bool full;
    QPixmap *f;
};

#endif
