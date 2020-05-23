


/** \brief Inicializa el array de trabajos, pone su id de servicio en -1
 *
 * \param trabajo eTrabajo* Puntero al array de trabajos
 * \param tam int Tamaño del array de trabajo
 * \return int Devuelve 0 si todo OK
 *
 */
int inicializarTrabajos(eTrabajo* trabajo, int tam);
/** \brief Busca la primer posicion del array de trabajo libre
 *
 * \param trabajo eTrabajo*Puntero al array de trabajos
 * \param size int Tamaño del array de trabajo
 * \return int Devuelve la primer posicion libre del array
 *
 */
int buscarTrabajoLibre(eTrabajo* trabajo, int size);

int agregarTrabajo(eTrabajo* trabajo, int size, int i, int id, eMascota* mascota, int size2, eServicio* servicio, int size3, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4);
/** \brief Imprime los trabajos que esten dados de alta
 *
 * \param trabajo eTrabajo*Puntero al array de trabajos
 * \param size intTamaño del array de trabajo
 * \param servicio eServicio*Puntero al array de servicios
 * \param size2 intTamaño del array de servicios
 * \return intDevuelve 0 si todo OK
 *
 */
int imprimirTrabajos(eTrabajo* trabajo, int size, eServicio* servicio, int size2);
