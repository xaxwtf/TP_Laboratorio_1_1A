/** \brief Solicita un Numero Entero, lo verifica y guarda
 *
 * \param es La direcion de Memoria Donde se guardara el dato
 * \param es el Mensaje Mostrado al Solicitar el dato
 * \param es el Mensaje mostrado en caso que indique un dato Incorrecto
 * \param es el limite Inferior para verificar el dato
 * \param es el limite superior para verificar el dato
 * \return 1 si se logro cargar el dato -1 si no
 *
 */
int getInt(int *dir,char msg[], char Emsg[],int Linf, int Lsup);

/** \brief Solicita Un Numero, Valida y guarda
 *
 * \param es la direcion de memoria donde se guardara el dato obtenido
 * \param es el Mensaje Imprimido al solicitar el dato
 * \param es el mensaje en caso de error
 * \param es el limite inferior de validacion
 * \param es el limite superir de la validacion
 * \return 1 si se logro cargar el Numero -1 si no
 *
 */
int getFloat(float *dir,char msg[],char Emsg [], float Linf,float Lsup);

/** \brief Solicita Un Caracter al Usuario,Valida y lo guarda
 *
 * \param es la direcion de Memoria donde se guardara el Dato
 * \param es el Mensaje a ser mostrado
 * \param es el mensaje a ser mostrado en caso de error
 * \param es el Limite Inferior para la Validacion
 * \param es el Limite Superior para la Validacion
 * \return retorna 1 si logro cargar el dato -1 si no
 *
 */
int getChar(char *dir,char msg[],char Emsg[],char linf,char lsup);
/** \brief Realiza una divicion entre los numeros ingresados y valida que no se divida por 0
 *
 * \param es el 1er numero indicado por el Usuario
 * \param es el 2do numero indicado por el Usuario
 * \return El resultado de la divicion entre los 2 numeros
 *
 */

float dividir(float,float);
/** \brief inicializa un array en el valor que indique el programador
 *
 * \param vector: es el array al cual se le asiganara el dato
 * \param tam es el tamaño del array al cual se le asignara el dato
 * \param es el dato que se le asiganara a cada pocicion del array
 * \param desde el Indice a partir del cual le Asignara el valor indicado
 * \return
 *
 */
void inizArray(int vector[],int tam,int valor,int desde);
