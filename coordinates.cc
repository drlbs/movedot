#include "structs.h"

void defineBase( float *bpts, int *numbasepts )
{
   *(bpts+0)=350.0;  *(bpts+1)=350.0; *(bpts+2)=0.0;  *(bpts+3)=1.0;
   *numbasepts = 4;
}

void definePoint( float *apts, int *spts,  float *bpts, int *vpts )
{
        int j;

        for (j=0;j<*vpts;j++)  *(apts+j) = *(bpts+j);          
        *spts = *vpts / 4;
}

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
