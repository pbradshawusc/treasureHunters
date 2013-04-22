#ifndef HOLYGRAIL_H
#define HOLYGRAIL_H

#include "movingobject.h"

class HolyGrail : public movingObject {
  public:
    HolyGrail(MainWindow* m, QPixmap *pm, int nx, int ny, int rand);
    void move(int timer);
    bool collide(TreasureHunter *th);
    void animate(int timer);
};

#endif
