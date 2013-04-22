#ifndef CROCODILE_H
#define CROCODILE_H

#include "movingobject.h"

class Crocodile : public movingObject {
  public:
    /** A constructor to set a pointer to the parent mainWindow, pointers to the required images, position, direction, and difficulty */
    Crocodile(MainWindow* m, QPixmap *pm, QPixmap *c, int nx, int ny, int d, int dif);
    /** A method to move the crocodile at the proper time in the proper direction */
    void move(int timer);
    /** A method to determine if the crocodile is colliding with the given TreasureHunter */
    bool collide(TreasureHunter *th);
    /** A method to animate the crocodile at the proper time */
    void animate(int timer);
  private:
    /** A tracker for direction */
    int direction;
    /** A tracker for difficulty */
    int difficulty;
    /** A tracker for the state of animation the crocodile is currently in */
    int animation;
    /** A pointer to the crocodile's image for its second state of animation */
    QPixmap *c2;
};

#endif
