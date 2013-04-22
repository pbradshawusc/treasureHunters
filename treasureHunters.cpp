#include <QtGui/QApplication>
#include "mainwindow.h"

/** @mainpage CSCI 102 Game Lab: Treasure Hunters!
  *
  *  @section purpose Purpose/Overview
  *  Treasure Hunters! is a game building off of Frogger. 
  *  The basic mechanics and goals are the same, but a few more features (objects to avoid and objects to catch) have been added.
  *  The game used Qt as a framework for building objects and animates using QPixmap's and Timers.
  *  The player is controlled with the WASD keys while all other objects are controlled by the program.
  *  The user can enter a name that will be displayed along with their score.
  *  To exit, the user must click the "x" button or the "Close" button in the corner.
  *
  *  @section requirements Requirements
  *  - Must have a GameDesignDoc (Not shown on webpage - MarkDown format available on GitHub if the repository is visible to your account at https://github.com/usc-csci102-spring2013/game_pbradsha/blob/master/GameDesignDoc.md)
  *    - Outline of 5 'things' with movement, function, and images
  *    - What are the controls
  *    - How does the score mechanic work
  *    - How are player's lives kept track of and how does the player die/lose a life
  *    - Show user interface layout and what buttons do
  *  - There must be at least 5 moving 'things' (at most 1 stationary). Below are the selected 5:
  *    - Guardians move left and right and shoot arrows
  *    - Arrows move down and kill the player
  *    - Logs move left and right and protect the player from the water while carrying him/her
  *    - Holy Grails move randomly around the screen and give the player and extra life
  *    - Temples do not move, but when touched they reset the arrows, time, and player's location and add to the player's score
  *  - User must be able to enter his/her name to be displayed with his/her score.
  *  - Must be able to start, pause, and quit the game
  *  - Display the player's score and lives (finite amount)
  *  - Allow for restarting the game
  *  - Game should speed up as time elapses, eventually making it too hard for a human to play
  *  - Document/Comment using Doxygen
  *  - Prepare the repository for submission
  *  - Re-clone the submission to ensure all code works and there are no errors or warnins
  *
  *  @author Patrick Bradshaw of the Front Row Crew
  */


int main(int argc, char *argv[]){

  QApplication a(argc, argv);
  MainWindow w;
    
  w.show();

  return a.exec();
    
}
