#include <stdint.h>
void LDR(uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2);
void LDRB(uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2);
void LDRH(uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2);
void LDRSB(uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2);
void LDRSH(uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2);
void STR(uint8_t *memoria,uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2);
void STRB(uint8_t *memoria,uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2);
void STRH(uint8_t *memoria,uint32_t *registro,uint32_t *Rt,uint32_t R1,uint32_t R2);
