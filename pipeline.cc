#include "constants.h"
#include "structs.h"
#include "prototypes.h"
#include "globals.h"

void PipeLine( float *vp, int vpts )
{
    /* This routine will run the graphics transformation pipeline */

    /* Set up useful temporary variables */
    float TransformationMatrix[16];
    float *TM;

    TM = &TransformationMatrix[0];

    /* In this code we always translate to the origin so any calculated coordinate will
       not have to worry with relative coordinates. */ 

    buildTranslate( -350.0, -350.0, 0.0,  TM );
    applyTransformation( vp, vpts, TM );   	

    buildTranslate( X_POSITION, Y_POSITION, 0.0,  TM );
    applyTransformation( vp, vpts, TM );   	

}
