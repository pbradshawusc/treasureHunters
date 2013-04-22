#include "scene.h"
#include "mainwindow.h"

QScene::QScene(MainWindow *m) : QGraphicsScene() {
  mw = m;
  pressed = false;
  /*timer = new QTimer;
  timer->setInterval(3);
  connect(timer, SIGNAL(timeout()), this, SLOT(move()));
  numEvents = 0;
  timer->start();*/
}

void QScene::keyPressEvent(QKeyEvent *e){
  /*if(numEvents == 0){
    event1 = e;
    numEvents++;
  }
  else if(numEvents == 1){
    bool okay = false;
    if(event1->key() == Qt::Key_A){
      if(e->key() == Qt::Key_D){
        event1 = e;
      }
      else if(e->key() == Qt::Key_A){
      }
      else{
        okay = true;
      }
    }
    else if (event1->key() == Qt::Key_D){
      if(e->key() == Qt::Key_A){
        event1 = e;
      }
      else if(e->key() == Qt::Key_D){
      }
      else{
        okay = true;
      }
    }
    else if (event1->key() == Qt::Key_W){
      if(e->key() == Qt::Key_S){
        event1 = e;
      }
      else if(e->key() == Qt::Key_W){
      }
      else{
        okay = true;
      }
    }
    else if (event1->key() == Qt::Key_S){
      if(e->key() == Qt::Key_W){
        event1 = e;
      }
      else if(e->key() == Qt::Key_S){
      }
      else{
        okay = true;
      }
    }
    if(okay){
      event2 = e;
      numEvents++;
    }
  }
  else{
    if(e->key() == Qt::Key_A || e->key() == Qt::Key_D){
      if(event1->key() == Qt::Key_A || event1->key() == Qt::Key_D){
        event1 = e;
      }
      else if(event2->key() == Qt::Key_A || event2->key() == Qt::Key_D){
        event2 = e;
      }
    }
    else if(e->key() == Qt::Key_W || e->key() == Qt::Key_S){
      if(event1->key() == Qt::Key_W || event1->key() == Qt::Key_S){
        event1 = e;
      }
      else if(event2->key() == Qt::Key_W || event2->key() == Qt::Key_S){
        event2 = e;
      }
    }
  } */
  if(!pressed){
    mw->keyEvent(e);
    pressed = true;
  }
}

void QScene::keyReleaseEvent(QKeyEvent *e){
  /*if(event1->key() == e->key()){
    event1 = NULL;
    numEvents--;
  }
  else if (event2->key() == e->key()){
    event2 = NULL;
    numEvents--;
  }
}

void QScene::move(){
  if(event1 != NULL){
    mw->keyEvent(event1);
  }
  if(event2 != NULL){
    mw->keyEvent(event2);
  }*/
  if(e->key() == Qt::Key_W || e->key() == Qt::Key_S || e->key() == Qt::Key_A || e->key() == Qt::Key_D){
    pressed = false;
  }
}
