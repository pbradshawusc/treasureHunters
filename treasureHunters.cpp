#include <QtGui/QApplication>
#include "mainwindow.h"

/** @mainpage CSCI 102 Game Lab: Treasure Hunters!
  *
  *  @section purpose Purpose/Overview
  *  
  *  
  *  @section requirements Requirements
  *  
  *  
  *
  *  @author Patrick Bradshaw of the Front Row Crew
  */


int main(int argc, char *argv[]){

  QApplication a(argc, argv);
  MainWindow w;
    
  w.show();

  return a.exec();
    
}
