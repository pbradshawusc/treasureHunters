#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "treasurehunter.h"
#include <QGraphicsPixmapItem>

class MainWindow;

class movingObject : public QGraphicsPixmapItem {
  public:
    /** A constructor to set a pointer to the parent MainWindow and parent Pixmap image, and the location */
    movingObject(MainWindow *m, QPixmap *pm, int nx, int ny);
    /** A method to move the object at the proper time */
    virtual void move(int timer) = 0;
    /** A method to determine if the object is colliding with the given TreasureHunter */
    virtual bool collide(TreasureHunter *th) = 0;
    /** A method to animate the object */
    virtual void animate(int timer) = 0;
    /** A method to get the x position of the object */
    int getX();
    /** A method to get the y position of the object */
    int getY();
    /** A method to get the width of the object */
    int getWidth();
    /** A method to get the height of the object */
    int getHeight();
  protected:
    /** Tracker for x position of the object */
    int x;
    /** Tracker for y position of the object */
    int y;
    /** Tracker for width of the object */
    int width;
    /** Tracker for height of the object */
    int height;
    /** Tracker for x velocity of the object */
    int vX;
    /** Tracker for y velocity of the object */
    int vY;
    /** Pointer to the parent image */
    QPixmap *pixMap;
    /** Pointer to the parent MainWindow */
    MainWindow *mw;
};

#endif
