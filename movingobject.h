#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "treasurehunter.h"
#include <QGraphicsPixmapItem>

class movingObject : public QGraphicsPixmapItem {
  public:
    movingObject(QPixmap *pm, int nx, int ny);
    virtual void move(int timer) = 0;
    virtual bool collide(TreasureHunter *th) = 0;
    virtual void animate(int timer) = 0;
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    /*int getvX();
    int getVY();
    QPixmap *getPixMap();*/
  protected:
    int x;
    int y;
    int width;
    int height;
    int vX;
    int vY;
    QPixmap *pixMap;
};

#endif
