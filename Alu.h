
/**
* \brief funcion ADD que realiza sumas
* \param *R0 puntero del primer valor de los registros
* \param R1 segundo registro
* \param R2 tercer registro
*/
void ADD(uint32_t *R0,uint32_t R1,uint32_t R2);

/**
* \brief funcion ADD que realiza multiplicaciones
* \param *R0 puntero del primer valor de los registros
* \param R1 segundo registro
* \param R2 tercer registro
*/
void AND(uint32_t *R0,uint32_t R1,uint32_t R2);

/**
* \brief funcion EOR que reliza la operacion logica XOR
* \param *R0 puntero del primer valor de los registros
* \param R1 segundo registro
* \param R2 tercer registro
*/
void EOR(uint32_t *R0,uint32_t R1,uint32_t R2);

/**
* \brief funcion MOV mueve datos de un registro a otro
* \param *R0 puntero en el que se guarda el dato	
* \param R1 registro del que se extrae el dato
*/
void MOV(uint32_t *R0,uint32_t R1);

/**
* \brief funcion EOR que reliza la operacion logica XOR
* \param *R0 puntero del primer valor de los registros
* \param R1 segundo registro
* \param R2 tercer registro
*/
void ORR(uint32_t *R0,uint32_t R1,uint32_t R2);

/**
* \brief funcion sub que realiza restas
* \param *R0 puntero del primer valor de los registros
* \param R1 segundo registro
* \param R2 tercer registro
*/
void SUB(uint32_t *R0,uint32_t R1,uint32_t R2);
