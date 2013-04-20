#include "movingobject.h"

movingObject::movingObject( QPixmap *p, int nx, int ny ){
  pixMap = p;
  setPixmap( *p);
  x = nx;
  y = ny;
}
