struct
{
    int id;
    char descripcion[25];
    float precio;

} typedef eServicio; //Definicion de la estructura de servicio

/** \brief Imprime los servicios por pantalla
 *
 * \param servicio eServicio* Puntero al array de servicios
 * \param tam int Tamaño del array de servicios
 * \return int Devuelve 0 si Ok
 *
 */
int listarServicios(eServicio* servicio, int tam);
/** \brief Imprime determinado servicio segun ID
 *
 * \param servicio eServicio*Puntero al array de servicios
 * \param tam intTamaño del array de servicios
 * \param id int ID a buscar
 * \return int Devuelve 0 si OK
 *
 */
int imprimirServicio(eServicio* servicio, int tam, int id);
