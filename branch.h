#include <stdint.h>
void BEQ(uint32_t *R, uint32_t pos, uint32_t *pc);
void BNE(uint32_t *R, uint32_t pos, uint32_t *pc);
void BCS(uint32_t *R, uint32_t pos, uint32_t *pc);
void BCC(uint32_t *R, uint32_t pos, uint32_t *pc);
void BMI(uint32_t *R, uint32_t pos, uint32_t *pc);
void BPL(uint32_t *R, uint32_t pos, uint32_t *pc);
void BVS(uint32_t *R, uint32_t pos, uint32_t *pc);
void BVC(uint32_t *R, uint32_t pos, uint32_t *pc);
void BHI(uint32_t *R, uint32_t pos, uint32_t *pc);
void BLS(uint32_t *R, uint32_t pos, uint32_t *pc);
void BGE(uint32_t *R, uint32_t pos, uint32_t *pc);
void BLT(uint32_t *R, uint32_t pos, uint32_t *pc);
void BGT(uint32_t *R, uint32_t pos, uint32_t *pc);
void BLE(uint32_t *R, uint32_t pos, uint32_t *pc);
void BAL(uint32_t pos, uint32_t *pc);
