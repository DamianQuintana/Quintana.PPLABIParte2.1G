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

#define TAMM 5


int getInt(void)
{
    char numero[30];
    int numeroI;
    int longitud;
    int estado=0;
    int i;

    fflush(stdin);
    gets(numero);
    longitud = strlen(numero); // Copiamos la longitud de la cadeba

    do
    {

        for(i=0; i<longitud; i++)
        {
            estado = isalpha(numero[i]);
            if(numero[i] == '.' || numero[i] == ',') // En el caso de que alguno de los caracteres sean los siguientes, cambiamos el etado a 1
            {
                estado =1;
                break;
            }
        }

        if(estado !=0)
        {
            printf("Invalido, reingrese un numero entero: ");
            gets(numero);
            longitud = strlen(numero);
        }

    }
    while(estado !=0);

    numeroI = atoi(numero); // Transformo ese numero en entero
    return numeroI;
}
float getFloat(void)
{
    char numero[30];
    int numeroF;
    int longitud;
    int estado=0;
    int i;

    fflush(stdin);
    gets(numero);
    longitud = strlen(numero);

    do
    {
        for(i=0; i<longitud; i++)
        {
            estado = isalpha(numero[i]); // En cso de que el valor que ingresamos sea un caracter nos va a dar un 1
        }

        if(estado !=0)
        {
            printf("Invalido, reingrese un numero valido: ");
            gets(numero);
            longitud = strlen(numero);
        }

    }
    while(estado !=0); // Si el estado está en 0 quiere decir que solamente se ingresaron numeros

    numeroF = atof(numero); // Transforme ese numero en flotante y lo retorno
    return numeroF;
}

void getChar(char palabra[30])
{
    int estado = 1; //Variable de control de longitud y de validez de caracter
    int estado2 = 1;
    int longitud;
    int i;

    fflush(stdin);
    gets(palabra);
    longitud = strlen(palabra);

    do
    {
        if(longitud >= 25)//En caso de la longitud ser mayor que el máximo ponemos la bandera en 0 para indicar error
        {
            estado = 0;
        }
        else
        {
            estado = 1;
        }
        if(estado == 0)
        {
            printf("\n\nReingrese la palabra, demasiado larga: ");
            gets(palabra);
            longitud = strlen(palabra);
        }
        for(i = 0; i < longitud; i++)
        {
            estado = isalpha(palabra[i]); // Si es una letra me da un no cero

        }
        for(i=0; i<longitud; i++)
        {
            estado2 = isdigit(palabra[i]); // Si es un numero me devuelve un no cero;
        }
        if(estado2 !=0)
        {
            printf("\n\nReingrese la palabra, solo letras");
            gets(palabra);
            longitud = strlen(palabra);
        }
    }
    while(estado == 0 || estado2 != 0);
}
int hardCoding(eMascota* mascota, int tam)
{
    int i;
    int c = 0;
    int id[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    char nombre[16][20] = {"Juan", "Pedro", "Pepito", "Milu", "Pepa", "Albert", "Olaf", "Loki", "Lila", "Crema", "Rufino", "Olaf", "Lula", "Rocky", "Scooby", "Max"};
    int tipo[16] = {1002, 1001, 1001, 1000, 1000, 1003, 1004, 1003, 1000, 1001, 1004, 1003, 1004, 1003, 1000, 1001};
    int color[16] = {5000, 5001, 5002, 5003, 5004, 5004, 5000, 5002, 5000, 5003, 5002, 5003, 5004, 5004, 5002, 5003};
    int anios[16] = {6,5,3,2,1,10,12,6,5,1,5,2,3,7,11,12};
    int idDuenio[16] = {16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    for(i=0; i<tam; i++)
    {
        mascota[i].id = id[i];
        strcpy(mascota[i].nombre, nombre[i]);
        mascota[i].idTipo = tipo[i];
        mascota[i].idColor = color[i];
        mascota[i].edad = anios[i];
        mascota[i].idDuenio = idDuenio[i];
        c++;
    }
    return c;
}
int hardCodingTrabajos(eTrabajo* trabajo, int tam)
{
    int i;
    int c = 0;

    int id[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int idServicio[20] = {20001,20001,20001,20001,20001,20002,20002,20002,20002,20002,20002,20000,20000,20000,20000,20000,20000,20000,20000,20000};
    int idMascota[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,2,3,8,7};
    int dia[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int mes[20] = {1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,1,9,8,2};
    int anio[20] = {2001,2002,2003,2004,2005,2006,2004,2000,2019,2015,2000,2002,2013,2014,2015,2016,2005,2005,2004,2003};

    for(i=0; i<tam; i++)
    {
        trabajo[i].id = id[i];
        trabajo[i].idMascota = idMascota[i];
        trabajo[i].idServicio = idServicio[i];
        trabajo[i].fecha.dia = dia[i];
        trabajo[i].fecha.mes = mes[i];
        trabajo[i].fecha.anio = anio[i];
        c++;
    }
    return c;
}

