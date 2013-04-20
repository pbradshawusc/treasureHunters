#include "mainwindow.h"
#include <cmath>
#include <QMessageBox>
#include <QApplication>
#include <QBrush>
#include <QColor>
#include <QKeyEvent>
#include <iostream>

MainWindow::MainWindow()  {
    //We need a scene and a view to do graphics in QT
    Scene = new QGraphicsScene();
    View = new QGraphicsView( Scene );
    
    Start = new QPushButton( View );
    Start->setGeometry(300,365,100,40);
    Start->setText("&Let's Play!");
    
    connect(Start, SIGNAL(clicked()), this, SLOT(startGame()));
    
    //This sets the size of the window and gives it a title.
    View->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
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

    //we must set the focus on the window so that it will catch key presses
    setFocus();
    
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
    Log.convertFromImage( qi );
    Log = Log.scaled(100,40);
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

}

void MainWindow::move(){
  
}

void MainWindow::keyPressEvent( QKeyEvent *e ){
  switch( e->key() ){
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
    case Qt::Key_Down:
    
    ;
  }
}
