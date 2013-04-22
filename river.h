#ifndef RIVER_H
#define RIVER_H

#include "movingobject.h"

class River : public movingObject {
  public:
    /** A constructor to set a pointer to the parent MainWindow and required images and to set the location */
    River(MainWindow* m, QPixmap *pm, QPixmap *pm2, QPixmap *pm3, int nx, int ny);
    /** A method to move the river (inherited and unused) */
    void move(int timer);
    /** A method to determine if the TreasureHunter and river are colliding */
    bool collide(TreasureHunter *th);
    /** A method to animate the river at the proper time */
    void animate(int timer);
  private:
    /** A pointer to the image of the river's second state of animation */
    QPixmap *r2;
    /** A pointer to the image of the river's third state of animation */
    QPixmap *r3;
    /** A tracker for the current state of animation */
    int animation;
};

#endif
