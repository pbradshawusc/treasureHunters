#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QTextEdit>
#include <QGraphicsPixmapItem>
#include <vector>
#include "treasurehunter.h"

#define WINDOW_MAX_X 350
#define WINDOW_MAX_Y 323

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    /** Default Constructor */
    MainWindow();
    /** Default Destructor */
    ~MainWindow();
    /** Makes the game visible */
    void show();  
    
private:
    /** The scene that holds the view where all of the implementation takes place. Dynamically allocated. */
    QGraphicsScene *Scene;
    /** The view that holds all of the objects that act out the implementation. Dynamically allocated.*/
    QGraphicsView *View;
    /** The timer used to coordinate the animation of sliding tiles. Set to 5ms countdown. */
    QTimer *GlobalTimer;
    /** A push button that on signal clicked will generate the required game pieces and will start the timer. */
    QPushButton *Start;
    /** A push button that when clicked will delete the pause info text box, restart the timer, and then delete itself. */
    QPushButton *Resume;
    /** A (read only) Text Box that will show the user a welcome screen and info about controls and such. */
    QTextEdit *Intro;
    /** A (read only) Text Box that will show the user info about controls and such while the game is paused. */
    QTextEdit *PauseInfo;
    /** A background for the entire game. */
    QGraphicsPixmapItem *Background;
    /** A counter to keep track of the time that has passed (used in movement and score calculation) */
    int timeLeft;
    /** A tracker for the number of lives the user has left. */
    int numLives;
    /** A tracker for the score of the user */
    int score;
    /** A tracker of whether the game is active to limit movement of the player */
    bool paused;
    //Below are all of the pix maps needed for the game
    QPixmap Arrow;
    QPixmap CarLeft1;
    QPixmap CarLeft2;
    QPixmap CarRight1;
    QPixmap CarRight2;
    QPixmap CrocodileLeft1;
    QPixmap CrocodileLeft2;
    QPixmap CrocodileRight1;
    QPixmap CrocodileRight2;
    QPixmap Desert;
    QPixmap Guardian1;
    QPixmap Guardian2;
    QPixmap Guardian3;
    QPixmap Guardian4;
    QPixmap HolyGrail;
    QPixmap Log;
    QPixmap PyramidEmpty;
    QPixmap PyramidFull;
    QPixmap TreasureHunterStill;
    QPixmap TreasureHunterLeft1;
    QPixmap TreasureHunterLeft2;
    QPixmap TreasureHunterRight1;
    QPixmap TreasureHunterRight2;
    QPixmap WaterPart1;
    QPixmap WaterPart2;
    QPixmap WaterPart3;
    //Below are all of the objects needed for the game (or their containers)
    TreasureHunter *player;
    
protected:
    /** This will catch the events of pressing down a key. */
    void keyPressEvent( QKeyEvent *e );

public slots:
   /** A slot to start the game. Triggered when the start button is clicked. */
   void startGame();
   /** A slot to move the position of all movableObjects on the screen */
   void move();

};

#endif // MAINWINDOW_H 
