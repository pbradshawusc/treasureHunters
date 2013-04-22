#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QApplication>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QTextEdit>
#include <QGraphicsPixmapItem>
#include <vector>
#include "treasurehunter.h"
#include "movingobject.h"
#include "scene.h"

#include "river.h"
#include "car.h"
#include "log.h"
#include "crocodile.h"
#include "temple.h"
#include "guardian.h"
#include "arrow.h"
#include "holygrail.h"

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
    /** Allows Guardians to generate arrows on their own timers */
    void addArrow(int x, int y);
    /** This will process the events of pressing down a key that are caught by the QScene */
    void keyEvent( QKeyEvent *e );
    /** This will make the user lose a life and reset the game properly */
    void loseLife();
    /** This toggles the timer and pause screen */
    void togglePause();
    
private:
    /** The scene that holds the view where all of the implementation takes place. Dynamically allocated. */
    QScene *Scene;
    /** The view that holds all of the objects that act out the implementation. Dynamically allocated.*/
    QGraphicsView *View;
    /** The timer used to coordinate the animation of sliding tiles. Set to 5ms countdown. */
    QTimer *GlobalTimer;
    /** A push button that on signal clicked will generate the required game pieces and will start the timer. */
    QPushButton *Start;
    /** A push button that when clicked will delete the pause info text box, restart the timer, and then delete itself. */
    QPushButton *Resume;
    QPushButton *Restart;
    /** A (read only) Text Box that will show the user a welcome screen and info about controls and such. */
    QTextEdit *Intro;
    /** A (read only) Text Box that will show the user info about controls and such while the game is paused. */
    QTextEdit *PauseInfo;
    /** A (read only) Text Box that will show the user's name and score */
    QTextEdit *ShowScore;
    /** A (read only) Text Box that will show the user's number of remaining lives */
    QTextEdit *ShowLives;
    /** A (read only) Text Box that will show the remaining time */
    QTextEdit *ShowTime;
    /** A text box for the user to enter his/her desired name */
    QTextEdit *Name;
    /** A background for the entire game. */
    QGraphicsPixmapItem *Background;
    /** A QPushButton to close the game when clicked */
    QPushButton *CloseGame;
    /** A counter to keep track of the time that has passed (used in movement and score calculation) */
    int timeLeft;
    /** A tracker for the number of lives the user has left. */
    int numLives;
    /** A tracker for the score of the user */
    int score;
    /** A tracker of whether the game is active to limit movement of the player */
    bool paused;
    //Below are all of the pix maps needed for the game
    QPixmap ArrowI;
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
    QPixmap HolyGrailI;
    QPixmap LogI;
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
    /** A pointer to hold the player's sprite */
    TreasureHunter *player;
    std::vector<Log *> logs;
    std::vector<Arrow *> arrows;
    std::vector<Temple *> temples;
    std::vector<Guardian *> guardians;
    std::vector<Crocodile *> crocodiles;
    std::vector<Car *> cars;
    std::vector<HolyGrail *> grails;
    std::vector<River *> rivers;
    //Ensure that objects don't overlap on the map.
    /** ensures that cars aren't spawned overlapping each other (counter) row 1 */
    int cr;
    /** ensures that cars aren't spawned overlapping each other (counter) row 2 */
    int cl;
    /** ensures that logs aren't spawned overlapping each other (counter) row 1 */
    int l1;
    /** ensures that logs aren't spawned overlapping each other (counter) row 2 */
    int l2;
    /** ensures that logs aren't spawned overlapping each other (counter) row 3 */
    int l3;
    /** ensures that logs aren't spawned overlapping each other (counter) row 4 */
    int l4;
    /** a boolean to track whether the player is on a log or not (for movement and detection purposes) */
    bool onLog;
    /** keeps track of the numbers of temples full */
    int numTempHit;
    /** an interval for the timer, creates difficulty */
    int interval;
    /** keeps track of whether the pause screen is currently on or off */
    bool pauseScreenOn;
    /** A tracker for the current difficulty level */
    int difficulty;

public slots:
   /** A slot to start the game. Triggered when the start button is clicked. */
   void startGame();
   /** A slot to move the position of all movableObjects on the screen and update game stats */
   void move();
   /** A slot to restart the game when the try again button is available */
   void restart();

};

#endif // MAINWINDOW_H 
