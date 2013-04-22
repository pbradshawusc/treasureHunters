#ifndef HOLYGRAIL_H
#define HOLYGRAIL_H

#include "movingobject.h"

class HolyGrail : public movingObject {
  public:
    /** A constructor to set a pointer to the parent MainWindow, the pixmap image, the position, and a random seed */
    HolyGrail(MainWindow* m, QPixmap *pm, int nx, int ny, int rand);
    /** A method to move the grail in a random direction at the proper time */
    void move(int timer);
    /** A method to see if the grail is colliding with the given TreasureHunter */
    bool collide(TreasureHunter *th);
    /** A method to animate the grail (inherited from movingObject and not needed) */
    void animate(int timer);
};

#endif
