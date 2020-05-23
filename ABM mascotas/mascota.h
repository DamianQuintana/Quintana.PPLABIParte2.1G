struct
{
    int id;
    char nombre[30];
    char sexo;
}typedef eDuenio;

struct
{
    int dia;
    int mes;
    int anio;

} typedef eFecha; //Definición de la estructura de fecha
struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int idDuenio;

} typedef eMascota; //Definicion de la estructura de mascota
struct
{
    int id;
    char nombreColor[20];

} typedef eColor; //Definicion de la estructura de color

struct
{
    int id;
    char descripcion[20];

} typedef eTipo; // Definición de la estructura de tipo
struct
{
    int id;
    int idMascota;
    int idServicio;

    eFecha fecha; //Estructura anidada de fecha
} typedef eTrabajo; //Definicion de la estructura de trabajo

/** \brief Inicializamos el array de mascotas, ponemos la edad en -1 para indicar libre
 *
 * \param mascota eMascota* Puntero al array de mascotas
 * \param tam int Tamaño del array
 * \return int Devolvemos un 0 para indicar OK
 *
 */
int inicializarMascotas(eMascota* mascota, int tam);
/** \brief Buscamos la primer posicion libre en el array de mascotas
 *
 * \param mascota eMascota*Puntero al array de mascotas
 * \param size int Tamaño del array
 * \return int Devolvemos la posicion libre del array
 *
 */
int buscarMascotaLibre(eMascota* mascota, int size);

/** \brief Busca la primer posicion libre del array de mascotas y permite la carga de sus datos
 *
 * \param mascota eMascota*Puntero al array de mascotas
 * \param tam int TAmaño del array
 * \param tipo eTipo*Puntero al array
 * \param tam2 int TAmaño del array
 * \param color eColor*Puntero al array
 * \param tam3 int TAmaño del array
 * \param id int ID a agregar
 * \param i int Posicion donde agregar
 * \param duenio eDuenio*Puntero al array
 * \param tam4 int TAmaño del array
 * \return int Devuelve un 0 al finalizar
 *
 */
int agregarMascota(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, int id, int i, eDuenio* duenio, int tam4);//REHECHA

int imprimirUnaMascota(eMascota* mascota, int tam, int id, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4);
/** \brief Busca una mascota por ID y nos devuelve su posicion del array
 *
 * \param mascota eMascota*Puntero al array de mascotas
 * \param tam int Tamaño del array
 * \param id int ID a buscar
 * \return int Posicion del array
 *
 */
int buscarMascotaPorID(eMascota* mascota, int tam, int id);


/** \brief Busca un id de mascota y lo modifica segun opcion del usario
 *
 * \param mascota eMascota* Puntero al array
 * \param tam int Tamaño del array
 * \param id int id a buscaar
 * \param tipo eTipo* Puntero al array
 * \param tam2 intTamaño del array
 * \param color eColor* Puntero al array
 * \param tam3 intTamaño del array
 * \param duenio eDuenio* Puntero al array
 * \param tam4 intTamaño del array
 * \return int Deuvlve 1 si todo ok -1 si no se dio de baaj
 *
 */
int ModificarMascota(eMascota* mascota, int tam, int id, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4);

int quitarMascota(eMascota* mascota, int tam, int id, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4);//RETOCAR
/** \brief Ordena el array de mascotas
 *
 * \param mascota eMascota*Puntero al array de mascotas
 * \param size intTamaño del array
 * \return int 0 si esta todo OK
 *
 */
int ordenarMascotas(eMascota* mascota, int size);
/** \brief Toma el array de mascotas e imprime las posiciones que estén dadas de alta
 *
 * \param mascota eMascota* Puntero al array de mascotas
 * \param tam int Tamaño del array
 * \param tipo eTipo* Puntero al array de tipos
 * \param tam2 int Tamaño del array
 * \param color eColor* Puntero al array de colores
 * \param tam3 int Tamaño del array
 * \return int Devuelve un 0 si esta todo OK
 *
 */
int imprimirMascotas(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4);

