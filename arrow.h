#ifndef ARROW_H
#define ARROW_H

#include "movingobject.h"

class Arrow : public movingObject {
  public:
    /** A constructor to set a pointer to the main window, the proper image, position and difficulty */
    Arrow(MainWindow* m, QPixmap *pm, int nx, int ny, int dif);
    /** A method to move the arrow's position */
    void move(int timer);
    /** A method to determine whether the arrow hits the given TreasureHunter */
    bool collide(TreasureHunter *th);
    /** An animation method (inherited but not needed) */
    void animate(int timer);
  private:
    /** keeps track of the game's difficulty */
    int difficulty;
};

#endif
