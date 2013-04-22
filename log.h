#ifndef LOG_H
#define LOG_H

#include "movingobject.h"

class Log : public movingObject {
  public:
    /** A constructor to set a pointer to the parent MainWindow, parent image, location, direction, and difficulty */
    Log(MainWindow* m, QPixmap *pm, int nx, int ny, int d, int dif);
    /** A method to move the log in the proper direction at the proper time */
    void move(int timer);
    /** A method to determine if the log and given Treasure Hunter are colliding */
    bool collide(TreasureHunter *th);
    /** A mehtod to animate the log (inherited from movingObject and unused) */
    void animate(int timer);
    /** A method to get the horizontal velocity of the log (needed for keeping the TreasureHunter on top of the log) */
    int getVX();
  private:
    /** A tracker for the direction of the log */
    int direction;
    /** A tracker for the current difficulty setting */
    int difficulty;
};

#endif
