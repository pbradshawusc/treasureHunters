#ifndef GUARDIAN_H
#define GUARDIAN_H

#include "movingobject.h"

class MainWindow;

class Guardian : public movingObject {
  public:
    /** A constructor to set a pointer to the parent MainWindow, the proper images, the position, the min and max of the horizontal range, and a random seed */
    Guardian(MainWindow *m, QPixmap *pm, QPixmap *pm2, QPixmap *pm3, QPixmap *pm4, int nx, int ny, int min, int mx, int rand);
    /** A method to move the Guardian at the proper time in the proper direction */
    void move(int timer);
    /** A method to determine if the Guardian is colliding with the given TreasureHunter (inherited from movingObject but not needed) */
    bool collide(TreasureHunter *th);
    /** A method to animate the Guardian and shoot arrows */
    void animate(int timer);
  private:
    /** A pointer to the Guardian's image in its second state of animation */
    QPixmap *g2;
    /** A pointer to the Guardian's image in its third state of animation */
    QPixmap *g3;
    /** A pointer to the Guardian's image in its fourth state of animation */
    QPixmap *g4;
    /** A tracker for the max X position of the Guardian */
    int maxX;
    /** A tracker for the minimum X position of the Guardian */
    int minX;
    /** A tracker for the current state of animation */
    int animation;
};

#endif
