#include "includes.h"
#include "constants.h"
#include "globals.h"

#include "globals.cc"

void moveDisplay(void) {
    if ((X_POSITION < VIEWPORT_MAX) && (Y_POSITION == VIEWPORT_MIN)) {
        X_POSITION = X_POSITION + 1; 
    }
    else if ((X_POSITION == VIEWPORT_MAX) && (Y_POSITION < VIEWPORT_MAX)) {
        Y_POSITION = Y_POSITION + 1; 
    }
    else if ((X_POSITION > VIEWPORT_MIN) && (Y_POSITION == VIEWPORT_MAX)) {
        X_POSITION = X_POSITION - 1; 
    }
    else if ((X_POSITION == VIEWPORT_MIN) && (Y_POSITION > VIEWPORT_MIN)) {
        Y_POSITION = Y_POSITION - 1; 
    }

    glutPostRedisplay();
}


