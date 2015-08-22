
/**
* \brief funcion ADD que realiza sumas
* \param *R0 puntero del primer valor de los registros
* \param R1 segundo registro
* \param R2 tercer registro
*/
void ADD(unsigned long int *R0,unsigned long int R1,unsigned long int R2);

/**
* \brief funcion ADD que realiza multiplicaciones
* \param *R0 puntero del primer valor de los registros
* \param R1 segundo registro
* \param R2 tercer registro
*/
void AND(unsigned long int *R0,unsigned long int R1,unsigned long int R2);

/**
* \brief funcion EOR que reliza la operacion logica XOR
* \param *R0 puntero del primer valor de los registros
* \param R1 segundo registro
* \param R2 tercer registro
*/
void EOR(unsigned long int *R0,unsigned long int R1,unsigned long int R2);

/**
* \brief funcion MOV mueve datos de un registro a otro
* \param *R0 puntero en el que se guarda el dato	
* \param R1 registro del que se extrae el dato
*/
void MOV(unsigned long int *R0,unsigned long int R1);

/**
* \brief funcion EOR que reliza la operacion logica XOR
* \param *R0 puntero del primer valor de los registros
* \param R1 segundo registro
* \param R2 tercer registro
*/
void ORR(unsigned long int *R0,unsigned long int R1,unsigned long int R2);

/**
* \brief funcion sub que realiza restas
* \param *R0 puntero del primer valor de los registros
* \param R1 segundo registro
* \param R2 tercer registro
*/
void SUB(unsigned long int *R0,unsigned long int R1,unsigned long int R2);
