#ifndef LOG_H
#define LOG_H

#include "movingobject.h"

class Log : public movingObject {
  public:
    Log(MainWindow* m, QPixmap *pm, int nx, int ny, int d, int dif);
    void move(int timer);
    bool collide(TreasureHunter *th);
    void animate(int timer);
    int getVX();
  private:
    int direction;
    int difficulty;
};

#endif
