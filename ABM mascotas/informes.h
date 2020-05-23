

int cantidadDeanimalesColor(eMascota* mascota, int tam, int id, eColor* color, int tam2, eTipo* tipo, int tam3, eDuenio* duenio, int tam4);
int cantidadDeAnimalesTipo(eMascota* mascota, int tam, int id, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4);
int animalMasJoven(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4);
int mascotasPorTipo(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4);
int contarMascotasPorTipoYColor(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4, int colorUser, int tipoUser);
int coloresconMasMacotas(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4);
int trabajosHechosAMascota(eTrabajo* trabajo, int tam, eMascota* mascota, int tam2, eServicio* servicio, int tam3, int id);
float deudaTotalMascota(eTrabajo* trabajo, int tam, eMascota* mascota, int tam2, eServicio* servicio, int tam3, int id);
int serviciosAMascota(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4, int id, eServicio* servicio, int tam5, eTrabajo* trabajo, int tam6);
int serviciosPorFecha(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4, eServicio* servicio, int tam5, eTrabajo* trabajo, int tam6, int dia, int mes, int anio);
