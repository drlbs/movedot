***
/* Andrew J. Pounds, Ph.D.
 * CSC 315 Fall 2010 
 * A very simple animation program to move a dot around the square 
 */

#include <math.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define WINDOW_MAX 700
#define WINDOW_MIN 0
#define VIEWPORT_MAX 600
#define VIEWPORT_MIN 100
#define MAX 10

***
typedef struct vertex { 
    float x;
    float y;
    float z;
    float w;
} vertex;

***
float X_POSITION  = 100.0;
float Y_POSITION  = 100.0;

***
void vmatm (int SIZE, float *pA, float *pB) {


    // pA is a pointer to the first element of matrix A
    // pB is a pointer to the first element of vector B
    // On return, B will contain transformed coordinates

    int i, j;
    float temp[4];

    for (i=0; i<SIZE; i++)
        temp[i] = 0.0;

    for (i=0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            temp[i] += *(pA+(i*SIZE+j)) * *(pB+j);

    for (i=0; i<SIZE; i++)
        *(pB+i) = temp[i];
}


***
void buildTranslate( float x, float y, float z, float *pA )
{
     *(pA+0)=1.0; *(pA+1)=0.0; *(pA+2)=0.0; *(pA+3)=x;
     *(pA+4)=0.0; *(pA+5)=1.0; *(pA+6)=0.0; *(pA+7)=y;
     *(pA+8)=0.0; *(pA+9)=0.0; *(pA+10)=1.0; *(pA+11)=z;
     *(pA+12)=0.0; *(pA+13)=0.0; *(pA+14)=0.0; *(pA+15)=1.0;
}
***
void applyTransformation( float *vp, int vpts, float *TM ) 
{
	float temp[4];
	float *tmp;
        int i;

	tmp = &temp[0];

	for (i=0;i<vpts;i++)
	{
		*(tmp+0)= *(vp+(i*4)+0);
		*(tmp+1)= *(vp+(i*4)+1);
		*(tmp+2)= *(vp+(i*4)+2);
		*(tmp+3)= *(vp+(i*4)+3);
		vmatm( 4, TM, tmp );
		*(vp+(i*4)+0) = *(tmp+0); 
		*(vp+(i*4)+1) = *(tmp+1); 
		*(vp+(i*4)+2) = *(tmp+2); 
		*(vp+(i*4)+3) = *(tmp+3); 
        }
}


***
	
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

***
void defineBase( float *bpts, int *numbasepts )
{
   *(bpts+0)=350.0;  *(bpts+1)=350.0; *(bpts+2)=0.0;  *(bpts+3)=1.0;
   *numbasepts = 4;
}

***
void definePoint( float *apts, int *spts,  float *bpts, int *vpts )
{
        int j;

        for (j=0;j<*vpts;j++)  *(apts+j) = *(bpts+j);          
        *spts = *vpts / 4;
}
***
void toVertex ( float *apts, struct vertex *vp, int pts )

/* Takes points from array and places them into vertex points */

{
	int i;

	for (i=0;i<pts;i++)
	{
	   (vp+i)->x = *(apts+(i*4)+0);
	   (vp+i)->y = *(apts+(i*4)+1);
	   (vp+i)->z = *(apts+(i*4)+2);
	   (vp+i)->w = *(apts+(i*4)+3);
	}

}

***
void drawPoint( vertex *vp, int points )

    /* Puts a single point from the vertex on the screen */

{
    int i;

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
      glVertex2f( (vp)->x, (vp)->y );
    glEnd();

}

***
void myinit( void )

/* Set up the projection */
{
/* attributes */

      glClearColor(0.0, 0.0, 0.0, 1.0); /* black background */
      glPointSize(5.0);

/* set up viewing */

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0, (float) WINDOW_MAX, 
                 0.0, (float) WINDOW_MAX);
      glMatrixMode(GL_MODELVIEW);
}
***
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

***
void clearBox()
{
       glClear(GL_COLOR_BUFFER_BIT); 
}
***
void moveDisplay(void) {
    if ((X_POSITION < 600.0) && (Y_POSITION == 100.0)) {
        X_POSITION = X_POSITION + 1; 
    }
    else if ((X_POSITION == 600.0) && (Y_POSITION < 600.0)) {
        Y_POSITION = Y_POSITION + 1; 
    }
    else if ((X_POSITION > 100.0) && (Y_POSITION == 600.0)) {
        X_POSITION = X_POSITION - 1; 
    }
    else if ((X_POSITION == 100.0) && (Y_POSITION > 100.0)) {
        Y_POSITION = Y_POSITION - 1; 
    }

    glutPostRedisplay();
}

***
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

 

***
void keyboard( unsigned char key, int x, int y ) {

/* Keyboard intecaction -- one function -- kill the program */

  if ( key == 'q' || key == 'Q') exit(0);
	  glutIdleFunc(moveDisplay);

}

***
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowSize(WINDOW_MAX,WINDOW_MAX); 
    glutInitWindowPosition(0,0); 
    glutCreateWindow("The Moving Dot"); 
    myinit(); 
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display); 
    glutMainLoop();
}

