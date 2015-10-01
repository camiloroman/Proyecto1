#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include "branch.h"

void BEQ(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if(R[1]==1)
	{
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}

void BNE(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if(R[1]==0)
	{
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}


void BCS(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if(R[2]==1)
	{
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}

void BCC(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if(R[1]==0)
	{
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}

void BMI(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if(R[0]==1)
	{
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}
void BPL(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if(R[0]==0)
	{
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}

void BVS(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if(R[3]==1)
	{
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}

void BVC(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if(R[3]==0)
	{
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}
void BHI(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if((R[2]==1)&&(R[1]==0))
	{
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}

void BLS(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if((R[2]==0)&&(R[1]==1))
	{
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}
void BGE(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if(R[0]==R[3])
    {
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}

void BLT(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if(R[0]!=R[3])
	{
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}

void BGT(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if((R[1]==0)&&(R[0]==R[3]))
    {
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}

void BLE(uint32_t *R, uint32_t pos, uint32_t *pc)
{
	if((R[1]==0)||(R[0]!=R[3]))
{
		*pc+=pos;
	}
	else
	{
		return 0;
	}
}

void BAL(uint32_t pos, uint32_t *pc)
{
	*pc+=pos;
}

