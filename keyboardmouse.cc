#include "includes.h"
#include "prototypes.h"

void mouse(int button, int state, int x, int y) { 

/* Handler for mouse interaction -- does nothing but start animation */

    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                /* Could put other items in here */
                glutIdleFunc(moveDisplay);
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
            {
                /* Could put other items in here */
                glutIdleFunc(moveDisplay);
            }
            break;
        default:
            break;
    }
}

 

void keyboard( unsigned char key, int x, int y ) {

/* Keyboard intecaction -- one function -- kill the program */

  if ( key == 'q' || key == 'Q') exit(0);
	  glutIdleFunc(moveDisplay);

}


