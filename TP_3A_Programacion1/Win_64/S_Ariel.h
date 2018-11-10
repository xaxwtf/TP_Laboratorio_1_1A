#ifndef S_Ariel_H_INCLUDED
#define S_Ariel_H_INCLUDED
/** \brief Solicita un numero al usario y lo devuelve
 *
 * \param es el mensaje  a ser mostrado al solicitar el dato
 * \return devuelve en numero ingresado por el usuario
 *
 */

int pedir_entero(char mensaje[]);

/** \brief solitia un numero al usuario y lo devulve
 *
 * \param es el mensaje a ser mostrado
 * \return el numero obtenido del usuario
 *
 */

float pedir_flotante(char mensaje[]);
/** \brief Solicita un Numero Entero, lo verifica y guarda
 *
 * \param es La direcion de Memoria Donde se guardara el dato
 * \param es el Mensaje Mostrado al Solicitar el dato
 * \param es el Mensaje mostrado en caso que indique un dato Incorrecto
 * \param es el limite Inferior para verificar el dato
 * \param es el limite superior para verificar el dato
 * \param es la cantidad de veces que solicitara el dato en caso de error
 * \return 1 si se logro cargar el dato 0 si no
 *
 */
int getInt(int *dir,char msg[], char Emsg[],int Linf, int Lsup,int intentos);

/** \brief solicita un numero al usuario lo valida y guarda
 *
 * \param es la direcion de memoria donde se guardara el dato
 * \param es el mensaje al ser mostrado al solicitar el dato
 * \param es el mensaje a ser mostrado en caso de no cumplir la validacion
 * \param es el limite inferior de validacion
 * \param es el limite superior de validacion
 * \param es la cantidad de veces que volvera a pedir el dato en caso de error
 * \return 1 si logro cargar el dato y 0 si no
 *
 */
int getFloat(float *dir,char msg[],char Emsg [], float Linf,float Lsup,int intentos);

/** \brief solicita un caracter lo valida y guarda
 *
 * \param es la direcion de memoria en la que se guardara el dato
 * \param es el mensaje a ser motrado al solicitar el dato
 * \param es el mensaje a ser mostrado en caso de error en la validacion
 * \param es el limite inferio de la validacion
 * \param es el limite superior de la validacion
 * \return 1 si logro cargar el dato y 0 si no
 *
 */
int getChar(char *dir,char msg[],char Emsg[],char linf,char lsup);
/** \brief recibe una cadena de caracteres y lo ordena
 *
 * \param es el array a ser ordenado
 * \param es el tamaño del array
 * \return
 *
 */
void ordenar_char(char *lista,int tam);
/** \brief solicita valida y guarda una cadena de caracteres
 *
 * \param es la direcion de memoria donde se guardara el dato
 * \param es el mensaje a ser mostrado
 * \param es el mensaje a ser mostrado en caso que no se cumpla la validacion
 * \param es el limite inferior de validacion
 * \param es el limite superior de la validacion
 * \param es la cantidad de veces que volvera  pedir el dato en caso de error
 * \return -1 si logro cargar el dato y 0 si no
 *
 */

int getString(char *input, char mensaje[],char Emensaje[],int Linf,int Lsup,int intentos);

/** \brief recibe una cadena de caracteres y lo guarda en un formato
 *
 * \param es la cadena a cambiar de formato
 * \return
 *
 */
void string_save(char *date);

/** \brief intercambia las pociciones de los datos ingresados
 *
 * \param es la 1ra variable solicitada
 * \param
 * \return
 *
 */

void mi_swap(int* dato,int* dato2);

/** \brief recibe una cadena y valida que solo sea numerica
 *
 * \param  vec es la cadena  a validar
 * \return 1 si la cadena solo contiene numeros y 0 si no
 *
 */
int soloNumeros(char vec[]);

/** \brief recibe una cadena y valida que tenga solo letras
 *
 * \param vec es la cadena a validar
 * \return 1 si contiene solo letras y 0 si no
 *
 */
int soloLetras(char vec[]);

/** \brief Imprime un mensaje y solicita una cadena de caracteres
 *
 * \param es la variable donde se guardara la cadena
 * \param es el mensaje a ser imprimido por pantalla
 * \return
 *
 */
void pedir_cadena(char dep[],char mensaje[]);

/** \brief solicita un numero al usuario y valida que solo sea un numero
 *
 * \param es la direcion de memoria donde se guardara el dato
 * \param es el mensaje a ser motrado al solicitar el dato
 * \param es el mensaje mostrado en caso de error
 * \param es la cantidad de veces que volvera a solicitar el dato en caso de error
 * \return 1 si logro cargar el dato y 0 si no
 *
 */
int get_String_soloNum(int *num, char msj[],char emsj[],int intentos);
#endif // S_Ariel_H_INCLUDED
