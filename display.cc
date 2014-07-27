#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

void display( void )
{

    int i, j, k;
    int inPoints, outPoints, numvpts; 
    int *inptr, *outptr;
    float point[4];
    float basepts[4];
    float *apts, *bpts;
    int numbasepoints, *numbaseptr, *numvptr; 

    struct vertex inVertexArray[MAX];	/* MAX is a declared constant */
    struct vertex outVertexArray[MAX];
    struct vertex *invp, *outvp;

    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */

    glColor3f( 0.0, 0.0, 1.0 );    /* Draw in Blue */ 

    /* Set up pointer definitions */

    invp = &inVertexArray[0];
    outvp = &outVertexArray[0];

    apts = &point[0];
    inPoints = 0;
    bpts = &basepts[0];
    inptr = &inPoints;
    numvptr = &numvpts;
    
    outptr = &outPoints;
    numbaseptr = &numbasepoints; 
    numbasepoints = 4;
    
    

    glClear(GL_COLOR_BUFFER_BIT);

    /* Define Viewport */
    glColor3f(1.0, 1.0, 1.0);
    glRecti(VIEWPORT_MIN,VIEWPORT_MIN,VIEWPORT_MAX,VIEWPORT_MAX);

    /* Define base points */
    defineBase( bpts, numbaseptr );
 
    /* Define the arrow points */
    definePoint( apts, inptr, bpts, numbaseptr );

    /* Peform whatever operations are needed */
    PipeLine( apts, *inptr );

    /* Convert the points to vertices */
    toVertex( apts, invp, *inptr );

    /* Set the color */
    glColor3f(1.0, 0.0, 0.0);

    /* Draw the Transformed Points */
    drawPoint( invp, *inptr );

    /* Swap out the buffers */
    glutSwapBuffers();

 }
