#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "mascota.h"
#include "auxiliar.h"
#include "tipos.h"
#include "servicio.h"
#include "color.h"
#include "trabajo.h"
#include "duenio.h"
#include "informes.h"


int inicializarTrabajos(eTrabajo* trabajo, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        trabajo[i].idServicio = -1; // Utilizaremos el id del servicio en -1 para indicar que esta libre esta posicion
    }
    return 0;

}
int buscarTrabajoLibre(eTrabajo* trabajo, int size)
{
    int flag;
    int i;

    for(i=0; i<size; i++)
    {
        if(trabajo[i].idServicio == -1) // En caso de la posicion estar libre
        {
            flag = i; // Devolvemos la posicion del primer lugar libre del array
            break;
        }
        else
        {
            flag = -1;
        }
    }

    return flag;//Retornamos la posicion del array

}
int agregarTrabajo(eTrabajo* trabajo, int size, int i, int id, eMascota* mascota, int size2, eServicio* servicio, int size3, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4)
{

    int j;
    int flag;

    trabajo[i].id = id;
    system("CLS");
    printf("\nIngrese la fecha: ");
    printf("\nDia: ");
    trabajo[i].fecha.dia = getInt(); //Validamos la entrada de "dia"
    printf("\nMes: ");
    trabajo[i].fecha.mes = getInt();//Validamos la entrada de "mes"
    printf("\nAnio: ");
    trabajo[i].fecha.anio = getInt();//Validamos la entrada de "año"
    imprimirMascotas(mascota, size2, tipo, tam2, color, tam3, duenio, tam4); //Imprimimos el array de mascotas para saber sobre que ID queremos trabajar
    printf("\nIngrese el ID de la mascota: ");
    trabajo[i].idMascota = getInt();
    do
    {
        flag = buscarMascotaPorID(mascota, size2, trabajo[i].idMascota); //Le asignamos a flag el valor que retorna la funcion, en caso de no encontrar dicho ID volvemos a pedirlo
        if(flag ==-1)
        {
            imprimirMascotas(mascota, size2, tipo, tam2, color, tam3, duenio, tam4); //En caso de ser incorrecot reimprimimos la lista de mascotas para su seleccion
            printf("\nNo se encontro esa mascota en el sistema, reingrese un ID valido: ");
            trabajo[i].idMascota = getInt(); // Validamos ese valor para que sea entero
            flag = buscarMascotaPorID(mascota, size2, trabajo[i].idMascota); // Buscamos ese id con la funcion

        }
    }
    while(flag ==-1);
    system("CLS");
    listarServicios(servicio, size3); //Imprimimos los servicios por pantalla
    printf("Ingrese el ID del servicio: ");
    trabajo[i].idServicio = getInt(); //Validamos ese valor de servicio
    do
    {
        if(flag == -1)
        {
            system("CLS");
            listarServicios(servicio, size3);//Imprimimos los servicios por pantalla
            printf("\nServicio invalido, no se encuentra en la lista\nIngresar alguno de los anteriores: ");
            trabajo[i].idServicio = getInt();//Validamos ese valor de servicio
        }
        for(j=0; j<size3; j++)
        {
            if(trabajo[i].idServicio != servicio[j].id) // Recorremos el array de servicios para buscar una coincidencia con el valor ingresado por teclado
            {
                flag = -1;
            }
            else
            {
                flag = 1;
                break;
            }
        }
    }
    while(flag == -1); // En caso de no encontrar ninguna coincidencia repetimos el bucle

    return 0;
}
int imprimirTrabajos(eTrabajo* trabajo, int size, eServicio* servicio, int size2)
{
    int i;
    system("CLS");
    printf("\nFECHA\t\tID\t\tID MASCOTA\t\tSERVICIO\n");
    for(i=0; i<size; i++)
    {
        if( trabajo[i].idServicio !=-1) // En el caso de que el servicio este dado de alta, lo mostramos por pantalla
        {
            printf("%d/%d/%d\t%d\t\t\t%d\t",trabajo[i].fecha.dia,trabajo[i].fecha.mes,trabajo[i].fecha.anio, trabajo[i].id,trabajo[i].idMascota);
            printf("\t");
            imprimirServicio(servicio, size2, trabajo[i].idServicio);
        }


    }
    return 0;
}

