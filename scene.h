#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>

class MainWindow;

class QScene : public QGraphicsScene {
  //Q_OBJECT
  public:
    QScene(MainWindow *m);
  protected:
    void keyPressEvent( QKeyEvent *e );
    void keyReleaseEvent(QKeyEvent *e);
    MainWindow *mw;
    bool pressed;
    //QTimer *timer;
    //QKeyEvent *event1;
    //QKeyEvent *event2;
    //int numEvents;
  //public slots:
    //void move();
};

#endif
