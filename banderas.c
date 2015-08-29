 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include "banderas.h"
void banderas(unsigned int *R,unsigned long int R0,unsigned long int R1)
{
unsigned long int RR
RR=R0+R1;
if(RR>=pow(2,31))
{
    R[0]=1;
}
else
{
    R[0]=0;
}
if (RR==0)
{
    R[1]=1;
}
else
{
    R[1]=0;
}
if(((R1>=pow(2,31))&&(R0>=pow(2,31)))||((R0>=pow(2,31))&&(R1<pow(2,31))&&(RR<pow(2,31)))||((R1>=pow(2,31))&&(R0<pow(2,31))&&(RR<pow(2,31))))
{
    R[2]=1;
}
else
{
    R[2]=0;
}
if(((R1>=pow(2,31))&&(R0>=pow(2,31))&&(RR<pow(2,31)))||((R0<pow(2,31))&&(R1<pow(2,31))&&(RR>=pow(2,31))))
{if(((Rn>=pow(2,31))&&(Rm>=pow(2,31))&&(R<pow(2,31)))||((Rn<pow(2,31))&&(Rm<pow(2,31))&&(R>=pow(2,31))))
    R[3]=1;
}
else
{
    R[3]=0;
}
}
