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
#include "informes.h"


int inicializarDuenios(eDuenio* duenio, int tam)
{
     int i;
    for(i=0; i<tam; i++)
    {
        duenio[i].id = -1; //Utilizaremos como bandera de estado la edad de la mascota, indicando como -1, libre
    }
    return 0;

}

int buscarDuenioLibre(eDuenio* duenio, int tam)
{
    int flag;
    int i;

    for(i=0; i<tam; i++)
    {
        if(duenio[i].id== -1) // En caso de la posicion estar libre
        {
            flag = i; // Devolvemos la posicion del primer lugar libre del array
            break;
        }
        else
        {
            flag = -1; //En caso de no encontrar posiciones libres ponemos la bandera en -1
        }
    }

    return flag;//Retornamos la posicion del array

}
int hardcodearDuenios(eDuenio* duenio, int tam)
{
    int i;
    int c = 0;
    int id[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    char nombre[16][20] = {"Juan", "Albert", "Maria", "Adriana", "Demian", "John", "Christian", "Loki", "Tito", "Lucas", "Milen", "Federico", "Pepe", "Julian", "Marta", "Aclides"};
    char sexo[16] = {'m','m','f','f','m','m','m','m','m','m','f','m','m','m','f','m'};
    for(i=0; i<tam; i++)
    {
        duenio[i].id = id[i];
        strcpy(duenio[i].nombre, nombre[i]);
        duenio[i].sexo = sexo[i];
        c++;
    }
    return c;
}
int buscarDuenioPorID(eDuenio* duenio, int tam, int id)
{

    int i;
    int flag;

    for(i=0; i<tam; i++)
    {
        if(duenio[i].id) //En el caso de que el ID ingresado sea igual al id del array y se encuentre dado de alta
        {
            flag = i;// Guardamos su posicion en el array
            break;
        }
        else
        {
            flag = -1; //En el caso contrario cargamos a flag con -1
        }
    }
    return flag;//Devolvemos la psosición de ese elemento

}

int imprimirUnDuenio(eDuenio* duenio, int tam, int id)
{
    int i;
    i = buscarDuenioPorID(duenio, tam, id); // En caso de no encontrarla, i nos devolverá -1
    if(i!=-1) //En caso de haber encontrado dicho ID imprimimos sus datos por pantalla
    {
        system("CLS");
        printf("\nID\t\tNOMBRE\t\tSEXO\n");
        printf("%d\t\t%s\t\t%c\n",duenio[i].id, duenio[i].nombre, duenio[i].sexo);
    }
    return 0;

}


int imprimirDuenios(eDuenio* duenio, int tam)
{
     int i;
    system("CLS");
    printf("\nID\t\tNOMBRE\t\tSEXO\n");
    for(i=0; i<tam; i++)
    {
        if(duenio[i].id != -1) //En el caso que la edad del duenio no sea -1 (valor que indica que está libre, no dado de alta)imprimiremos sus datos
        {
            printf("%d\t\t%s\t\t%c\n",duenio[i].id, duenio[i].nombre, duenio[i].sexo);

        }
    }
    return 0;
}

