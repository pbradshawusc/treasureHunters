#ifndef TREASUREHUNTER_H
#define TREASUREHUNTER_H

#include <QGraphicsPixmapItem>

class TreasureHunter : public QGraphicsPixmapItem{
  public:
    TreasureHunter(QPixmap* s, QPixmap* l1, QPixmap* l2, QPixmap* r1, QPixmap* r2, int nx, int ny, int dif);
    void animate(int timer);
    void move(int direction);
  private:
    int x;
    int y;
    int width;
    int height;
    int vX;
    int vY;
    int difficulty;
    int animation;
    QPixmap *still;
    QPixmap *left1;
    QPixmap *left2;
    QPixmap *right1;
    QPixmap *right2;
};

#endif
