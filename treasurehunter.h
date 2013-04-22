#ifndef TREASUREHUNTER_H
#define TREASUREHUNTER_H

#include <QGraphicsPixmapItem>

class TreasureHunter : public QGraphicsPixmapItem{
  public:
    /** A constructor to set pointers to the parent images, and set the location and difficulty */
    TreasureHunter(QPixmap* s, QPixmap* l1, QPixmap* l2, QPixmap* r1, QPixmap* r2, int nx, int ny);
    /** A method to animate the Treasure Hunter at the proper time through it's various stages of animation */
    void animate(int timer);
    /** A method to make the Treasure Hunter jump in the proper direction and set it's new location */
    void move(int direction);
    /** A method to make the Treasure Hunter slide along with the log that cases this funciton call */
    void logMove(int v);
    /** A method to see the x position of the Treasure Hunter */
    int getX();
    /** A method to see the y position of the Treasure Hunter */
    int getY();
    /** A method to see the width of the Treasure Hunter */
    int getWidth();
    /** A method to see the height of the Treasure Hunter */
    int getHeight();
    /** A method to reset the location of the Treasure Hunter */
    void setLoc(int nx, int ny);
  private:
    /** The x position of the Treasure Hunter */
    int x;
    /** The y position of the Treasure Hunter */
    int y;
    /** The width of the Treasure Hunter */
    int width;
    /** The height of the Treasure Hunter */
    int height;
    /** The x velocity (jump width) of the Treasure Hunter */
    int vX;
    /** The y velocity (jump height) of the Treasure Hunter */
    int vY;
    /** A tracker for the current stage of animation */
    int animation;
    /** A pointer to the parent image for the still stage of animation */
    QPixmap *still;
    /** A pointer to the parent image for the first/third left stage of animation */
    QPixmap *left1;
    /** A pointer to the parent image for the second left stage of animation */
    QPixmap *left2;
    /** A pointer to the parent image for the first/third right stage of animation */
    QPixmap *right1;
    /** A pointer to the parent image for the second right stage of animation */
    QPixmap *right2;
};

#endif
