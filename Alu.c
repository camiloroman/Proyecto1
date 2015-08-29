#include <stdio.h>
#include <stdlib.h>
#include "Alu.h"

void ADD(uint32_t *R0,uint32_t R1,uint32_tt R2)
{
    R0=R1+R2;
}

void AND(uint32_t *R0,uint32_t R1,uint32_t R2)
{
    R0=R1&R2;
}

void EOR(uint32_t *R0,uint32_t R1,uint32_t R2)
{
    R0=R1^R2;
}

void MOV(uint32_t *R0,uint32_t R1)
{
    R0=R1;
}

void ORR(uint32_t *R0,uint32_t R1,uint32_t R2)
{
    R0=R1|R2;
}

void SUB(uint32_t *R0,uint32_t R1,uint32_t R2)
{
    R0=R1-R2;
}