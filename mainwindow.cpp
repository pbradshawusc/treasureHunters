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
#include <string>
#include <QString>
#include <sstream>
//Here are all of the game pieces
#include "river.h"
#include "car.h"
#include "log.h"
#include "crocodile.h"
#include "temple.h"
#include "guardian.h"
#include "arrow.h"
#include "holygrail.h"

MainWindow::MainWindow() : QMainWindow()  {
    //We need a scene and a view to do graphics in QT
    Scene = new QScene(this);
    View = new QGraphicsView( Scene );
    
    Start = new QPushButton( View );
    Start->setGeometry(300,365,100,40);
    Start->setText("&Let's Play!");
    connect(Start, SIGNAL(clicked()), this, SLOT(startGame()));
    
    CloseGame = new QPushButton( View );
    CloseGame->setGeometry(5,5,80,40);
    CloseGame->setText("&Close");
    connect(CloseGame, SIGNAL(clicked()), qApp, SLOT(quit()));
    
    //This sets the size of the window and gives it a title.
    View->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    this->setFixedSize(WINDOW_MAX_X*2, WINDOW_MAX_Y*2);
    View->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    View->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    View->setWindowTitle( "Treasure Hunters!");
    View->setSceneRect(0,0,WINDOW_MAX_X*2, WINDOW_MAX_Y*2-4); //Test!!!!
    
    Name = new QTextEdit( View );
    Name->setGeometry(275,435,150,30);
    Name->setText("Name");
    
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
    Intro->append("Guide your hunter with WASD and avoid the cars and gators! Catch the Holy Grail for an extra life!");
    Intro->setAlignment(Qt::AlignCenter);
    Intro->append("Press \"P\" to toggle pause.");
    QPalette p = Intro->palette();
    p.setColor(QPalette::Base, QColor( 234, 206, 106 ));
    Intro->setPalette(p);
    Name->setPalette(p);
    
    GlobalTimer = new QTimer();
    interval = 7;
    GlobalTimer->setInterval(interval);
    connect(GlobalTimer,SIGNAL(timeout()),this,SLOT(move()));
    
    //Now let's create all of the pixmaps we'll need for the game
    QImage qi("./Images/Arrow", "gif");
    ArrowI.convertFromImage( qi );
    ArrowI = ArrowI.scaled(20,40);
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
    HolyGrailI.convertFromImage( qi );
    HolyGrailI = HolyGrailI.scaled(60,60);
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
    
    srand(time(NULL));
}

MainWindow::~MainWindow(){
  for(std::vector<Log *>::iterator it = logs.begin(); it != logs.end(); ++it){
    delete (*it);
    logs.erase(it);
    it--;
  }
  for(std::vector<Car *>::iterator it = cars.begin(); it != cars.end(); ++it){
    delete (*it);
    cars.erase(it);
    it--;
  }
  for(std::vector<Crocodile *>::iterator it = crocodiles.begin(); it != crocodiles.end(); ++it){
    delete (*it);
    crocodiles.erase(it);
    it--;
  }
  for(std::vector<Arrow *>::iterator it = arrows.begin(); it != arrows.end(); ++it){
    delete (*it);
    arrows.erase(it);
    it--;
  }
  for(std::vector<Guardian *>::iterator it = guardians.begin(); it != guardians.end(); ++it){
    delete (*it);
    guardians.erase(it);
    it--;
  }
  for(std::vector<Temple *>::iterator it = temples.begin(); it != temples.end(); ++it){
    delete (*it);
    temples.erase(it);
    it--;
  }
  for(std::vector<HolyGrail *>::iterator it = grails.begin(); it != grails.end(); ++it){
    delete (*it);
    grails.erase(it);
    it--;
  }
  for(std::vector<River *>::iterator it = rivers.begin(); it != rivers.end(); ++it){
    delete (*it);
    rivers.erase(it);
    it--;
  }
  if(player != NULL){
    delete player;
  }
}

void MainWindow::show() {
    //This is how we get our view displayed.
    View->show();
}

void MainWindow::startGame() {
  player = new TreasureHunter(&TreasureHunterStill, &TreasureHunterLeft1, &TreasureHunterLeft2, &TreasureHunterRight1, &TreasureHunterRight2, 335, 530);
  Scene->addItem(player);
  player->setZValue(100000);
  
  Intro->setVisible(false);
  Start->setVisible(false);
  Name->setVisible(false);
    
  paused = false;
  //Add River
  rivers.push_back(new River(this, &WaterPart1, &WaterPart2, &WaterPart3, 0, 175));
  Scene->addItem(rivers[0]);
  //Add Temples
  temples.push_back(new Temple(this, &PyramidEmpty, &PyramidFull, 30, 115));
  temples.push_back(new Temple(this, &PyramidEmpty, &PyramidFull, 30+140, 115));
  temples.push_back(new Temple(this, &PyramidEmpty, &PyramidFull, 30+140*2, 115));
  temples.push_back(new Temple(this, &PyramidEmpty, &PyramidFull, 30+140*3, 115));
  temples.push_back(new Temple(this, &PyramidEmpty, &PyramidFull, 30+140*4, 115));
  for(unsigned int i = 0; i < temples.size(); i++){
    Scene->addItem(temples[i]);
  }
  //Add Guardians
  guardians.push_back(new Guardian(this, &Guardian1, &Guardian2, &Guardian3, &Guardian4, 30, 70, 0, 700/3, rand()));
  guardians.push_back(new Guardian(this, &Guardian1, &Guardian2, &Guardian3, &Guardian4, 330, 70, 700/3, (700/3)*2, rand()));
  guardians.push_back(new Guardian(this, &Guardian1, &Guardian2, &Guardian3, &Guardian4, 630, 70, (700/3)*2, (700/3)*3, rand()));
  for(unsigned int i = 0; i < guardians.size(); i++){
    Scene->addItem(guardians[i]);
  }
  timeLeft = 12500;
  score = 0;
  numLives = 3;
  GlobalTimer->start();
  cr = 0;
  cl = 0;
  l1 = 0;
  l2 = 0;
  l3 = 0;
  l4 = 0;
  
  ShowScore = new QTextEdit(View);
  ShowLives = new QTextEdit(View);
  ShowTime = new QTextEdit(View);
  ShowScore->setReadOnly(true);
  ShowLives->setReadOnly(true);
  ShowTime->setReadOnly(true);
  QPalette p = Intro->palette();
  ShowScore->setGeometry(15,580,200,50);
  ShowLives->setGeometry(300,12,70,30);
  ShowTime->setGeometry(588,580,100,50);
  std::stringstream s;
  QString n = Name->toPlainText();
  s << n.toLocal8Bit().constData() << "'s Score: \n" << score;
  QString qs = (s.str()).c_str();
  ShowScore->setText(qs);
  std::stringstream l;
  l << "Lives: " << numLives;
  qs = (l.str()).c_str();
  ShowLives->setText(qs);
  ShowTime->setText("Time");
  p.setColor(QPalette::Base, QColor( 234, 206, 106 ));
  ShowScore->setPalette(p);
  ShowLives->setPalette(p);
  ShowTime->setPalette(p);
  ShowScore->setVisible(true);
  ShowLives->setVisible(true);
  ShowTime->setVisible(true);
  
  difficulty = 1;
  
  numTempHit = 0;
  
  Restart = new QPushButton(View);
  Restart->setText("Restart");
  Restart->setGeometry(290, 580, 80, 30);
  Restart->setVisible(false);
  connect(Restart, SIGNAL(clicked()), this, SLOT(restart()));
  
  pauseScreenOn = false;
  
  View->setFocus();
}

void MainWindow::move(){
  std::stringstream s;
  QString n = Name->toPlainText();
  s << n.toLocal8Bit().constData() << "'s Score: \n" << score;
  QString qs = (s.str()).c_str();
  ShowScore->setText(qs);
  std::stringstream l;
  l << "Lives: " << numLives;
  qs = (l.str()).c_str();
  ShowLives->setText(qs);
  if(numLives == 0){
    ShowLives->setText("Game Over!");
    ShowLives->setGeometry(295,300,110,30);
    GlobalTimer->stop();
    paused = true;
    Restart->setVisible(true);
    return;
  }
  int random = std::rand() % 2000;
  random -= 1000;
  cr++;
  cl++;
  l1++;
  l2++;
  l3++;
  l4++;
  if(random < -980 && cr > 80){
    cars.push_back(new Car(this, &CarRight1, &CarRight2, -80, 426, 1));
    Scene->addItem(cars[cars.size()-1]);
    cr = 0;
  }
  random = std::rand() % 2000;
  random -= 1000;
  if(random > 980 && cl > 80){
    cars.push_back(new Car(this, &CarLeft1, &CarLeft2, WINDOW_MAX_X*2, 476, -1));
    Scene->addItem(cars[cars.size()-1]);
    cl = 0;
  }
  random = std::rand() % 2000;
  random -= 1000;
  if(random > 970 && l1 > 100){
    if(random > 998){
      crocodiles.push_back(new Crocodile(this, &CrocodileRight1, &CrocodileRight2, -100, 175, 1));
      Scene->addItem(crocodiles[crocodiles.size()-1]);
    }
    else{
      logs.push_back(new Log(this, &LogI, -100, 175, 1));
      Scene->addItem(logs[logs.size()-1]);
    }
    l1 = 0;
  }
  random = std::rand() % 2000;
  random -= 1000;
  if(random < -970 && l2 > 100){
    if(random < -997){
      crocodiles.push_back(new Crocodile(this, &CrocodileLeft1, &CrocodileLeft2, WINDOW_MAX_X*2, 225, -1));
      Scene->addItem(crocodiles[crocodiles.size()-1]);
    }
    else {
      logs.push_back(new Log(this, &LogI, WINDOW_MAX_X*2, 225, -1));
      Scene->addItem(logs[logs.size()-1]);
    }
    l2 = 0;
  }
  random = std::rand() % 2000;
  random -= 1000;
  if(random > 970 && l3 > 100){
    if(random > 996){
      crocodiles.push_back(new Crocodile(this, &CrocodileRight1, &CrocodileRight2, -100, 275, 1));
      Scene->addItem(crocodiles[crocodiles.size()-1]);
    }
    else{
      logs.push_back(new Log(this, &LogI, -100, 275, 1));
      Scene->addItem(logs[logs.size()-1]);
    }
    l3 = 0;
  }
  random = std::rand() % 2000;
  random -= 1000;
  if(random < -970 && l4 > 100){
    if(random < -995){
      crocodiles.push_back(new Crocodile(this, &CrocodileLeft1, &CrocodileLeft2, WINDOW_MAX_X*2, 325, -1));
      Scene->addItem(crocodiles[crocodiles.size()-1]);
    }
    else {
      logs.push_back(new Log(this, &LogI, WINDOW_MAX_X*2, 325, -1));
      Scene->addItem(logs[logs.size()-1]);
    }
    l4 = 0;
  }
  onLog = false;
  for(std::vector<Log *>::iterator it = logs.begin(); it != logs.end(); ++it){
    (*it)->move(timeLeft);
    (*it)->animate(timeLeft);
    if((*it)->collide(player)){
      player->logMove((*it)->getVX());
      onLog = true;
    }
    if((*it)->getX() >= WINDOW_MAX_X*2 || (*it)->getX() + (*it)->getWidth() < 0){
      delete (*it);
      logs.erase(it);
      --it;
    }
  }
  if(!onLog && rivers[0]->collide(player)){
    loseLife();
  }
  random = std::rand() % 20000;
  if(random>19990){
    int x = rand()%(WINDOW_MAX_X*2);
    int y = rand()%(WINDOW_MAX_Y*2);
    grails.push_back(new HolyGrail(this, &HolyGrailI, x, y, rand()));
    Scene->addItem(grails[grails.size()-1]);
  }
  for(std::vector<Crocodile *>::iterator it = crocodiles.begin(); it != crocodiles.end(); ++it){
    (*it)->move(timeLeft);
    (*it)->animate(timeLeft);
    if((*it)->collide(player)){
      loseLife();
    }
    if((*it)->getX() >= WINDOW_MAX_X*2 || (*it)->getX() + (*it)->getWidth() < 0){
      delete (*it);
      crocodiles.erase(it);
      --it;
    }
  }
  for(std::vector<Car *>::iterator it = cars.begin(); it != cars.end(); ++it){
    (*it)->move(timeLeft);
    (*it)->animate(timeLeft);
    if((*it)->collide(player)){
      loseLife();
    }
    if((*it)->getX() >= WINDOW_MAX_X*2 || (*it)->getX() + (*it)->getWidth() < 0){
      delete (*it);
      cars.erase(it);
    }
  }
  for(std::vector<Guardian *>::iterator it = guardians.begin(); it != guardians.end(); ++it){
    (*it)->move(timeLeft);
    (*it)->animate(timeLeft);
    //(*it)->collide(player);
    if((*it)->getX() >= WINDOW_MAX_X*2 || (*it)->getX() + (*it)->getWidth() < 0){
      delete (*it);
      guardians.erase(it);
      --it;
    }
  }
  for(std::vector<Arrow *>::iterator it = arrows.begin(); it != arrows.end(); ++it){
    (*it)->move(timeLeft);
    (*it)->animate(timeLeft);
    if((*it)->collide(player)){
      loseLife();
      break;
    }
    if((*it)->getX() >= WINDOW_MAX_X*2 || (*it)->getX() + (*it)->getWidth() < 0){
      delete (*it);
      arrows.erase(it);
      --it;
    }
  }
  for(std::vector<Temple *>::iterator it = temples.begin(); it != temples.end(); ++it){
    (*it)->animate(timeLeft);
    if(!((*it)->hit())){
      if((*it)->collide(player)){
        numTempHit++;
        player->setLoc(335, 530);
        score+=timeLeft*difficulty;
        timeLeft = 12500;
        for(std::vector<Arrow *>::iterator it = arrows.begin(); it != arrows.end(); ++it){
          delete (*it);
          arrows.erase(it);
          --it;
        }
      }
    }
  }
  for(std::vector<HolyGrail *>::iterator it = grails.begin(); it != grails.end(); ++it){
    (*it)->move(timeLeft);
    if((*it)->collide(player)){
      numLives++;
      delete(*it);
      grails.erase(it);
      --it;
    }
    else if((*it)->getX() >= WINDOW_MAX_X*2 || (*it)->getX() + (*it)->getWidth() < 0){
      delete (*it);
      grails.erase(it);
      --it;
    }
    else if((*it)->getY() >= WINDOW_MAX_Y*2 || (*it)->getY() + (*it)->getHeight() < 0){
      delete (*it);
      grails.erase(it);
      --it;
    }
  }
  if(numTempHit == 3){
    interval--;
    GlobalTimer->setInterval(interval);
    for(std::vector<Temple *>::iterator it = temples.begin(); it != temples.end(); ++it){
      (*it)->setEmpty();
    }
    numTempHit = 0;
    difficulty++;
  }
  player->animate(timeLeft);
  if(timeLeft%100 == 0){
    std::stringstream t;
    t << "Time: \n" << (timeLeft/100);
    QString qs = (t.str()).c_str();
    ShowTime->setText(qs);
  }
  timeLeft--;
  if(timeLeft == 0){
    loseLife();
  }
}

void MainWindow::keyEvent( QKeyEvent *e ){
  if(!paused && (player != NULL) && timeLeft < 12001){
    switch( e->key() ){
      case Qt::Key_A:
        player->move(3);
        break;
      case Qt::Key_D:
        player->move(1);
        break;
      case Qt::Key_W:
        player->move(2);
        break;
      case Qt::Key_S:
        player->move(0);
        break;
      case Qt::Key_P:
        togglePause();
        break;
    }
  }
  else if(paused && e->key() == Qt::Key_P){
    togglePause();
  }
}

void MainWindow::addArrow(int x, int y) {
  arrows.push_back(new Arrow(this, &ArrowI, x, y));
  Scene->addItem(arrows[arrows.size()-1]);
  arrows[arrows.size()-1]->setZValue(9999);
}

void MainWindow::loseLife(){
  numLives--;
  player->setLoc(335, 530);
  timeLeft = 12500;
  for(std::vector<Arrow *>::iterator it = arrows.begin(); it != arrows.end(); ++it){
    delete (*it);
    arrows.erase(it);
    --it;
  }
}

void MainWindow::restart(){
  Restart->setVisible(false);
  numLives = 3;
  score = 0;
  timeLeft = 12500;
  paused = false;
  ShowLives->setGeometry(300,12,70,30);
  std::stringstream l;
  l << "Lives: " << numLives;
  QString qs = (l.str()).c_str();
  ShowLives->setText(qs);
  GlobalTimer->start();
  difficulty = 1;
  interval = 7;
  GlobalTimer->setInterval(interval);
  numTempHit = 0;
  for(std::vector<Temple *>::iterator it = temples.begin(); it != temples.end(); ++it){
    (*it)->setEmpty();
  }
}

void MainWindow::togglePause(){
  if(pauseScreenOn){
    GlobalTimer->start();
    paused = false;
    pauseScreenOn = false;
    if(PauseInfo != NULL){
      delete PauseInfo;
    }
  }
  else {
    GlobalTimer->stop();
    paused = true;
    pauseScreenOn = true;
    PauseInfo = new QTextEdit( View );
    PauseInfo->setGeometry(175,100,350,250);
    PauseInfo->setReadOnly(true);
    PauseInfo->setFontPointSize(25);
    PauseInfo->setText("Paused");
    PauseInfo->setAlignment(Qt::AlignCenter);
    PauseInfo->setFontPointSize(14);
    PauseInfo->append(" ");
    PauseInfo->setAlignment(Qt::AlignCenter);
    PauseInfo->append("Guide your hunter with WASD and avoid the cars and gators! Catch the Holy Grail for an extra life!");
    PauseInfo->setAlignment(Qt::AlignCenter);
    PauseInfo->append("Press \"P\" to toggle pause.");
    QPalette p = Intro->palette();
    p.setColor(QPalette::Base, QColor( 234, 206, 106 ));
    PauseInfo->setPalette(p);
    PauseInfo->setVisible(true);
  }
}
