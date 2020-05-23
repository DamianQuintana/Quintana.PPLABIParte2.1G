/** \brief Toma una cadena de caracteres  y la valida para que solamente se ingresen enteros
 *
 * \param void
 * \return int Devuelve un valor entero validado
 *
 */
int getInt(void);
/** \brief Toma una cadena de caracteres y la valida para que se ingresen números
 *
 * \param void
 * \return float Devuelve un valor flotante validado
 *
 */
float getFloat(void);
/** \brief Toma una cadena de caracteres y la valida para que solo se ingresen letras
 *
 * \param palabra[30] char Palabra a ingresar
 * \return void Devuelve 0 si esta todo ok
 *
 */
void getChar(char palabra[30]);
/** \brief Toma un array de mascotas existente y lo carga valor por valor en el array creado en el main
 *
 * \param mascota eMascota* Puntero al array de mascotas
 * \param tam int Tamaño que deseamos hardcodear del array de mascotas
 * \return int devolvemos el id del ultimo valor hardcodeado
 *
 */
int hardCoding(eMascota* mascota, int tam);
int hardCodingTrabajos(eTrabajo* trabajo, int tam);
