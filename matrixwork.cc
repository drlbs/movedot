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


void buildTranslate( float x, float y, float z, float *pA )
{
     *(pA+0)=1.0; *(pA+1)=0.0; *(pA+2)=0.0; *(pA+3)=x;
     *(pA+4)=0.0; *(pA+5)=1.0; *(pA+6)=0.0; *(pA+7)=y;
     *(pA+8)=0.0; *(pA+9)=0.0; *(pA+10)=1.0; *(pA+11)=z;
     *(pA+12)=0.0; *(pA+13)=0.0; *(pA+14)=0.0; *(pA+15)=1.0;
}

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

