void vmatm (int, float *, float *); 
void buildTranslate( float, float, float, float * );
void applyTransformation( float *, int , float * ); 
void PipeLine( float *, int );
void defineBase( float *, int * );
void definePoint( float *, int *,  float *, int * );
void toVertex ( float *, struct vertex *, int  );
void drawPoint( vertex *, int );
void myinit( void );
void display( void );
void clearBox();
void moveDisplay(void); 
void mouse(int, int, int, int);  
void keyboard( unsigned char , int , int  ); 
int main(int , char** );

