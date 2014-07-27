#include "includes.h"
#include "structs.h"

void drawPoint( vertex *vp, int points )

    /* Puts a single point from the vertex on the screen */

{
    int i;

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
      glVertex2f( (vp)->x, (vp)->y );
    glEnd();

}

