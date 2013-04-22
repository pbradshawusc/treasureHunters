#include "scene.h"
#include "mainwindow.h"

QScene::QScene(MainWindow *m) : QGraphicsScene() {
  mw = m;
  pressed = false;
}

void QScene::keyPressEvent(QKeyEvent *e){
  if(!pressed){
    mw->keyEvent(e);
    pressed = true;
  }
}

void QScene::keyReleaseEvent(QKeyEvent *e){
  if(e->key() == Qt::Key_W || e->key() == Qt::Key_S || e->key() == Qt::Key_A || e->key() == Qt::Key_D){
    pressed = false;
  }
}
