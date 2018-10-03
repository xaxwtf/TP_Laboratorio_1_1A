#ifndef ArrayEmployees_H_INCLUDED
#define ArrayEmployees_H_INCLUDED
typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;
typedef struct{
    int id;
    char descripcion[21];
}eSector;

/** \brief inicializa todos las banderas(isEMpy) de cada una de las estructuras del array en 1
 *
 * \param lista es el puntero al array de estructuras
 * \param len es el tamaño del array
 * \return
 *
 */
void initEmployees(eEmployee *lista, int len,int dato);
/** \brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
posición libre.
 *
 * \param es el puntero a el array de empleados
 * \param es el tamaño del array de empleados
 * \param es id
 * \param es el nombre
 * \param es el apellido
 * \param es el salario
 * \param es el sector
 * \return 1 si logro cargar el dato y 0 si no
 *
 */
int addEmployee(eEmployee* lista, int len,int id,char name[],char lastName[],float salary, int sector);

/** \brief realiza una busqueda del la primera coincidencia
 *
 * \param es el array donde relizara la busqueda
 * \param es el tamaño del array
 * \param es el dato que se buscara
 * \return el indice donde encontro la 1ra concidencia y -1 si no encontro ninguna
 *
 */
int buscarPrimerLibre(eEmployee* lista, int len,int dato);

/** \brief Imprime en pantalla todos  sectores y su indice
 *
 * \param es el array de empleados
 * \param  el tamaño del array
 * \param es el encabezado que tendra
 * \return
 *
 */
void mostrarSectores(eSector* lista,int tam,char titulo[]);

/** \brief despiega un menu y solicita que el usario elija una opcion y la retorna
 *
 * \param es el array de empleados
 * \param es el tamaño del array
 * \return el id de la opcion elegida por el usuario o -1 en caso de 3 errores
 *
 */
int cargarSector(eSector *lista,int tam);

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
 *
 * \param es el array de empleados
 * \param es el tamaño del array
 * \param es el id de referencia para la busqueda
 * \return en indice en el cual encontro el dato 0 -1 si no lo encontro
 *
 */
int findEmployeeById(eEmployee* lista,int len,int id);

/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
 *
 * \param es el array de empleados
 * \param es el tamaño del array
 * \param es el id con el cual se relizara busqueda el cual permitira la baja logica
 * \param es el array de sectores
 * \param es el tamaño del array de sectores
 * \return 1 si logra realizar la baja logica o 0 si no
 *
 */
int removeEmployee(eEmployee* lista,int len,int id,eSector *sectores,int tamSec);

/** \brief recibe un empleado y imprime todos sus datos
 *
 * \param es el empleado del cual imprimiran los datos
 * \param es el array de sectores
 * \param es el tamaño del array sectores
 * \return
 *
 */
void imprimirEmpleado(eEmployee empleado,eSector* sectores,int tamSector);

/** \brief busca y carga la descripcion del sector al cual pertenece un empleado
 *
 * \param es el array de sectores donde realizara la busqueda
 * \param es el tamaño del array
 * \param el sector al cual pertenece el empleado
 * \param es donde guardara la descripcion obtenida
 * \return
 *
 */
void cargarDescSector(eSector* lista, int tam,int sector,char *descripcion);

/** \brief solicita al usuario un Id de empleado, despiega un menu y realiza los cambios en dicho usuario
 *
 * \param es el array de empleados
 * \param es el tamaño del array de empleados
 * \param es el array de sectores
 * \param es el tamaño del array de sectores
 * \return
 *
 */
void Modificar_Empleado(eEmployee *lista,int tamEmp,eSector* lista2,int tamSector);


/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 *
 * \param es el array de empleados
 * \param es el tamaño del array de empleados
 * \param indica el orden en el cual se ordenara el array asendente 1 y decente 0
 * \param es el array de sectores
 * \param es el tamaño del array de sectores
 * \return
 *
 */
void sortEmployees(eEmployee *lista, int tamEmp,int order,eSector *sectores, int tamsec);

/** \brief imprime un menu y realiza los informes descritos
 *
 * \param es el array de empleados
 * \param es el tamaño del array de empleados
 * \param es el array de sectores
 * \param es el tamaño del array de sectores
 * \return
 *
 */
void informes(eEmployee *lista,int tamEmp,eSector *sectores,int tamSec);

/** \brief imprime a todos los empleados y sus datos correspondientes
 *
 * \param es el array de empleados
 * \param es el tamaño del array de empeados
 * \param es el array de sectores
 * \param  es el tamaño del array de sectores
 * \return
 *
 */
void printEmployees(eEmployee *lista, int tamEmp,eSector *sectores,int tamSec);

/** \brief recorre el array y realiza una cuenta de la cantidad usuarios que superen el salario promedio
 *
 * \param es el array de empleados
 * \param es el tamaño del array
 * \return la cantida de empleados que superen salario promedio
 *
 */
int contDeSueldosArribaDelPromedio(eEmployee *lista,int tam);

/** \brief obtien el promedio de salarios y lo retorna
 *
 * \param es el array de empleados
 * \param es el tamaño del array de empleados
 * \return
 *
 */

float promedioSalarios(eEmployee *lista,int tam);







#endif // ArrayEmployees_H_INCLUDED
