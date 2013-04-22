#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>

class MainWindow;

class QScene : public QGraphicsScene {
  //Q_OBJECT
  public:
    /** Default constructor to set pointer back to the parent MainWindow */
    QScene(MainWindow *m);
  protected:
    /** A method to catch and handle key presses by sending them to the MainWindow */
    void keyPressEvent( QKeyEvent *e );
    /** A method to catch key releases by sending them to the MainWindow */
    void keyReleaseEvent(QKeyEvent *e);
    /** A pointer to the parent Main Window */
    MainWindow *mw;
    /** A tracker for whether a key is currently pressed or not */
    bool pressed;
};

#endif
