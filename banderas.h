/**
* \brief funcion para crear banderas
* \param *R registro donde se almacenan los resultados
* \param R0 primer valor a operar
* \param R1 segundo valor a operar
*/ 
void banderas(uint32_t *R,uint32_t R0,uint32_t R1);

/**
* \brief funcion de desplazamiento logico a la izquierda
* \param *R registro donde se almacenan los resultados
* \param R0 valor a operar
* \param R1 numero de desplazamientos
*/ 
void LSL(uint32_t *R,uint32_t R0,uint32_t R1);

/**
* \brief funcion de desplazamiento logico a la derecha
* \param *R registro donde se almacenan los resultados
* \param R0 valor a operar
* \param R1 numero de desplazamientos
*/ 
void LSR(uint32_t *R,uint32_t R0,uint32_t R1);

/**
* \brief funcion de rotacion a la derecha
* \param *R registro donde se almacenan los resultados
* \param R0 valor a operar
* \param R1 numero de desplazamientos
*/ 
void ROR(uint32_t *R,uint32_t R0,uint32_t R1);

/**
* \brief funcion de desplazamiento aritmetico a la derecha
* \param *R registro donde se almacenan los resultados
* \param R0 valor a operar
* \param R1 numero de desplazamientos
*/ 
void ASR(uint32_t *R,uint32_t R0,uint32_t R1);

/**
* \brief funcion AND entre un registro y el complemento de otro
* \param *R registro donde se almacenan los resultados
* \param R0 valor a operar
*/ 
void BIC(uint32_t *R,uint32_t R0);

/**
* \brief funcion que guarda el complemento de un registro
* \param *R registro donde se almacenan los resultados
* \param R0 valor a operar
*/ 
void MVN(uint32_t *R,uint32_t R0);

/**
* \brief funcion que obtiene el complemento a dos de un numero
* \param *R registro donde se almacenan los resultados
* \param R0 valor a operar
*/ 
void RSB(uint32_t *R,uint32_t R0);

/**
* \brief funcion que hace un retardo
* \param *R registro donde se almacenan los resultados
* \param R0 valor a operar
*/ 
void NOP(uint32_t *R,uint32_t R0);

/**
* \brief funcion que cambia el orden de los Bytes
* \param *R registro donde se almacenan los resultados
* \param R0 valor a operar
*/ 
void REV(uint32_t *R, uint32_t R0);

/**
* \brief funcion que cambia el orden en grupos de 16 bits
* \param *R registro donde se almacenan los resultados
* \param R0 valor a operar
*/ 
void REVIG(uint32_t *R, uint32_t R0);


/**
* \brief funcion que cambia el orden de los Bytes del halfword bajo
* \param *R registro donde se almacenan los resultados
* \param R0 valor a operar
*/ 
void REVSH(uint32_t *R, uint32_t R0);