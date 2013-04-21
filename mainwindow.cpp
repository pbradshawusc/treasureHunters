#include "mainwindow.h"
#include <cmath>
#include <QMessageBox>
#include <QApplication>
#include <QBrush>
#include <QColor>
#include <QKeyEvent>
#include <iostream>
#include <cmath>
#include <cstdlib>
//Here are all of the game pieces
#include "river.h"
#include "car.h"
#include "log.h"
#include "crocodile.h"

MainWindow::MainWindow() : QMainWindow()  {
    //We need a scene and a view to do graphics in QT
    Scene = new QGraphicsScene();
    View = new QGraphicsView( Scene );
    
    Start = new QPushButton( View );
    Start->setGeometry(300,365,100,40);
    Start->setText("&Let's Play!");
    
    connect(Start, SIGNAL(clicked()), this, SLOT(startGame()));
    
    //This sets the size of the window and gives it a title.
    View->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    this->setFixedSize(WINDOW_MAX_X*2, WINDOW_MAX_Y*2);
    View->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    View->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    View->setWindowTitle( "Treasure Hunters!");
    
    Intro = new QTextEdit( View );
    Intro->setGeometry(175,100,350,250);
    Intro->setReadOnly(true);
    Intro->setFontPointSize(25);
    Intro->setText("Welcome to Treasure Hunters!");
    Intro->setAlignment(Qt::AlignCenter);
    Intro->setFontPointSize(14);
    Intro->append(" ");
    Intro->setAlignment(Qt::AlignCenter);
    Intro->append("Can you guide your hunter through the treacherous desert to the pyramids?");
    Intro->setAlignment(Qt::AlignCenter);
    Intro->append("Guide your hunter with the arrow keys and avoid the cars and gators! Catch the Holy Grail for an extra life!");
    Intro->setAlignment(Qt::AlignCenter);
    Intro->append("Press \"P\" to pause.");
    QPalette p = Intro->palette();
    p.setColor(QPalette::Base, QColor( 234, 206, 106 ));
    Intro->setPalette(p);
    
    GlobalTimer = new QTimer();
    GlobalTimer->setInterval(5);
    connect(GlobalTimer,SIGNAL(timeout()),this,SLOT(move()));
    
    //Now let's create all of the pixmaps we'll need for the game
    QImage qi("./Images/Arrow", "gif");
    Arrow.convertFromImage( qi );
    Arrow = Arrow.scaled(20,40);
    qi.load("./Images/Desert", "png");
    Desert.convertFromImage( qi );
    Desert = Desert.scaled(WINDOW_MAX_X*2 - 2, WINDOW_MAX_Y*2 - 2);
    qi.load("./Images/Car Left 1", "gif");
    CarLeft1.convertFromImage( qi );
    CarLeft1 = CarLeft1.scaled(80,50);
    qi.load("./Images/Car Left 2", "gif");
    CarLeft2.convertFromImage( qi );
    CarLeft2 = CarLeft2.scaled(80,50);
    qi.load("./Images/Car Right 1", "gif");
    CarRight1.convertFromImage( qi );
    CarRight1 = CarRight1.scaled(80,50);
    qi.load("./Images/Car Right 2", "gif");
    CarRight2.convertFromImage( qi );
    CarRight2 = CarRight2.scaled(80,50);
    qi.load("./Images/Crocodile Left 1", "gif");
    CrocodileLeft1.convertFromImage( qi );
    CrocodileLeft1 = CrocodileLeft1.scaled(100,40);
    qi.load("./Images/Crocodile Left 2", "gif");
    CrocodileLeft2.convertFromImage( qi );
    CrocodileLeft2 = CrocodileLeft2.scaled(100,40);
    qi.load("./Images/Crocodile Right 1", "gif");
    CrocodileRight1.convertFromImage( qi );
    CrocodileRight1 = CrocodileRight1.scaled(100,40);
    qi.load("./Images/Crocodile Right 2", "gif");
    CrocodileRight2.convertFromImage( qi );
    CrocodileRight2 = CrocodileRight2.scaled(100,40);
    qi.load("./Images/Log", "png");
    LogI.convertFromImage( qi );
    LogI = LogI.scaled(100,40);
    qi.load("./Images/Guardian 1", "gif");
    Guardian1.convertFromImage( qi );
    Guardian1 = Guardian1.scaled(50,40);
    qi.load("./Images/Guardian 2", "gif");
    Guardian2.convertFromImage( qi );
    Guardian2 = Guardian2.scaled(50,40);
    qi.load("./Images/Guardian 3", "gif");
    Guardian3.convertFromImage( qi );
    Guardian3 = Guardian3.scaled(50,40);
    qi.load("./Images/Guardian 4", "gif");
    Guardian4.convertFromImage( qi );
    Guardian4 = Guardian4.scaled(50,40);
    qi.load("./Images/Holy Grail", "gif");
    HolyGrail.convertFromImage( qi );
    HolyGrail = HolyGrail.scaled(60,60);
    qi.load("./Images/Water Sprite Part 1", "png");
    WaterPart1.convertFromImage( qi );
    WaterPart1 = WaterPart1.scaled(WINDOW_MAX_X*2 - 2,200);
    qi.load("./Images/Water Sprite Part 2", "png");
    WaterPart2.convertFromImage( qi );
    WaterPart2 = WaterPart2.scaled(WINDOW_MAX_X*2 - 2,200);
    qi.load("./Images/Water Sprite Part 3", "png");
    WaterPart3.convertFromImage( qi );
    WaterPart3 = WaterPart3.scaled(WINDOW_MAX_X*2 - 2,200);
    qi.load("./Images/Pyramid Empty", "png");
    PyramidEmpty.convertFromImage( qi );
    PyramidEmpty = PyramidEmpty.scaled(80,60);
    qi.load("./Images/Pyramid Full", "gif");
    PyramidFull.convertFromImage( qi );
    PyramidFull = PyramidFull.scaled(80,60);
    qi.load("./Images/Treasure Hunter Still", "gif");
    TreasureHunterStill.convertFromImage( qi );
    TreasureHunterStill = TreasureHunterStill.scaled(20,35);
    qi.load("./Images/Treasure Hunter Left 1", "gif");
    TreasureHunterLeft1.convertFromImage( qi );
    TreasureHunterLeft1 = TreasureHunterLeft1.scaled(20,35);
    qi.load("./Images/Treasure Hunter Left 2", "gif");
    TreasureHunterLeft2.convertFromImage( qi );
    TreasureHunterLeft2 = TreasureHunterLeft2.scaled(20,35);
    qi.load("./Images/Treasure Hunter Right 1", "gif");
    TreasureHunterRight1.convertFromImage( qi );
    TreasureHunterRight1 = TreasureHunterRight1.scaled(20,35);
    qi.load("./Images/Treasure Hunter Right 2", "gif");
    TreasureHunterRight2.convertFromImage( qi );
    TreasureHunterRight2 = TreasureHunterRight2.scaled(20,35);
    
    Background = new QGraphicsPixmapItem(Desert);
    Scene->addItem(Background);
    
    paused = true;

    this->setFocus();
    std::cout<<hasFocus()<<std::endl;
    //setFocusPolicy(Qt::StrongFocus);
    
    srand(0);
}

MainWindow::~MainWindow(){
  //delete View;
  delete Scene;
  delete GlobalTimer;
}

void MainWindow::show() {
    //This is how we get our view displayed.
    View->show();
}

void MainWindow::startGame() {
  player = new TreasureHunter(&TreasureHunterStill, &TreasureHunterLeft1, &TreasureHunterLeft2, &TreasureHunterRight1, &TreasureHunterRight2, 335, 585, 1);
  Scene->addItem(player);
  
  ShowScore = new QTextEdit(View);
  ShowLives = new QTextEdit(View);
  ShowTime = new QTextEdit(View);
  ShowScore->setReadOnly(true);
  ShowLives->setReadOnly(true);
  ShowTime->setReadOnly(true);
  QPalette p = Intro->palette();
  p.setColor(QPalette::Base, QColor( 234, 206, 106 ));
  ShowScore->setPalette(p);
  ShowLives->setPalette(p);
  ShowTime->setPalette(p);
  ShowScore->setGeometry(0,0,100,100);
  //ShowLives->setGeometry(150,5,20,10);
  //ShowTime->setGeometry(350,5,20,10);
  ShowScore->setText("Score");
  ShowLives->setText("Lives");
  ShowTime->setText("Time");
  
  delete Intro;
  delete Start;
  
  paused = false;
  pieces.push_back(new River(&WaterPart1, &WaterPart2, &WaterPart3, 0, 175));
  //pieces.push_back(new Car(&CarRight1, &CarRight2, 0, 350, 1, 1));
  for(unsigned int i = 0; i < pieces.size(); i++){
    Scene->addItem(pieces[i]);
  }
  timeLeft = 10000;
  GlobalTimer->start();
  difficulty = 1;
  cr = 0;
  cl = 0;
  l1 = 0;
  l2 = 0;
  /*this->setFocus();
  std::cout<<hasFocus()<<std::endl;*/
}

void MainWindow::move(){
  int random = std::rand() % 2000;
  random -= 1000;
  cr++;
  cl++;
  l1++;
  l2++;
  if(random < -980 && difficulty * cr > 80){
    pieces.push_back(new Car(&CarRight1, &CarRight2, -80, 390, 1, 1));
    Scene->addItem(pieces[pieces.size()-1]);
    cr = 0;
  }
  if(random > 980 && difficulty * cl > 80){
    pieces.push_back(new Car(&CarLeft1, &CarLeft2, WINDOW_MAX_X*2, 440, -1, 1));
    Scene->addItem(pieces[pieces.size()-1]);
    cl = 0;
  }
  if(random > 970 && difficulty * l1 > 100){
    if(random > 994){
      pieces.push_back(new Crocodile(&CrocodileRight1, &CrocodileRight2, -100, 300, 1, 1));
      Scene->addItem(pieces[pieces.size()-1]);
    }
    else{
      pieces.push_back(new Log(&LogI, -100, 300, 1, 1));
      Scene->addItem(pieces[pieces.size()-1]);
    }
    l1 = 0;
  }
  if(random < -970 && difficulty * l2 > 100){
    if(random < -994){
      pieces.push_back(new Crocodile(&CrocodileLeft1, &CrocodileLeft2, WINDOW_MAX_X*2, 250, -1, 1));
      Scene->addItem(pieces[pieces.size()-1]);
    }
    else {
      pieces.push_back(new Log(&LogI, WINDOW_MAX_X*2, 250, -1, 1));
      Scene->addItem(pieces[pieces.size()-1]);
    }
    l2 = 0;
  }
  for(std::vector<movingObject *>::iterator it = pieces.begin(); it < pieces.end(); ++it){
    (*it)->move(timeLeft);
    (*it)->animate(timeLeft);
    if((*it)->getX() >= WINDOW_MAX_X*2 || (*it)->getX() + (*it)->getWidth() < 0){
      delete (*it);
      pieces.erase(it);
    }
  }
  player->animate(timeLeft);
  timeLeft--;
  if(timeLeft == 0){
    timeLeft = 10000;
    GlobalTimer->stop();
  }
}

void MainWindow::keyPressEvent( QKeyEvent *e ){
std::cout<<hasFocus()<<std::endl;
if(!paused && (player != NULL)){
  switch( e->key() ){
    case Qt::Key_Left:
      player->move(3);
    case Qt::Key_Right:
      player->move(1);
    case Qt::Key_Up:
      player->move(0);
    case Qt::Key_Down:
      player->move(2);
  }
  //QWidget::keyPressEvent(e);
}
}
