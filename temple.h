#ifndef TEMPLE_H
#define TEMPLE_H

#include "movingobject.h"

class Temple : public movingObject {
  public:
    /** A constructor to set pointers to the parent MainWindow and Pixmap images, and to set the location */
    Temple(MainWindow* m, QPixmap *pm, QPixmap *pm2, int nx, int ny);
    /** A method to move (inherited and unused) */
    void move(int timer);
    /** A method to determine if the Temple and TreasureHunter are colliding */
    bool collide(TreasureHunter *th);
    /** A method to animate the Temple to it's full state when necessary */
    void animate(int timer);
    /** A method to return whether the temple has been hit or not */
    bool hit();
    /** A method to set the temple to empty (bool and image) */
    void setEmpty();
  private:
    /** A tracker for whether the temple is full or empty */
    bool full;
    /** A pointer to the image of a full temple */
    QPixmap *f;
};

#endif
