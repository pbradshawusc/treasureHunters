#ifndef CAR_H
#define CAR_H

#include "movingobject.h"

class Car : public movingObject {
  public:
    /** A constructor to set a pointer to the mainWindow, the proper image files, position, direction, and difficulty */
    Car(MainWindow* m, QPixmap *pm, QPixmap *pm2, int nx, int ny, int d, int dif);
    /** A method to move the car in the proper direction at the proper time */
    void move(int timer);
    /** A method to determine if the car is colliding with the given TreasureHunter */
    bool collide(TreasureHunter *th);
    /** A method to animate the car at the proper time */
    void animate(int timer);
  private:
    /** a tracker for direction */
    int direction;
    /** a helper value to keep track of what stage of animation the car is in */
    int animation;
    /** A pointer to the car's second QPixmap image */
    QPixmap *c2;
    /** a tracker for difficulty */
    int difficulty;
};

#endif
