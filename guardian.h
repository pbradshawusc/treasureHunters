#ifndef GUARDIAN_H
#define GUARDIAN_H

#include "movingobject.h"

class MainWindow;

class Guardian : public movingObject {
  public:
    Guardian(MainWindow *m, QPixmap *pm, QPixmap *pm2, QPixmap *pm3, QPixmap *pm4, int nx, int ny, int min, int mx, int rand);
    void move(int timer);
    bool collide(TreasureHunter *th);
    void animate(int timer);
  private:
    QPixmap *g2;
    QPixmap *g3;
    QPixmap *g4;
    int maxX;
    int minX;
    int animation;
};

#endif
