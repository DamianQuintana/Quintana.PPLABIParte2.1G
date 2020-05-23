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

int listarColores(eColor* color, int tam)
{
    int i;
    system("CLS");
    printf("\nLISTADO DE COLORES\n");
    printf("\nID\t\t\tDESCRIPCION\n");
    for(i=0; i<tam; i++)
    {
        printf("%d\t\t\t%s\n", color[i].id, color[i].nombreColor); //Imprimimos por pantalla los datos de los colores

    }
    return 0;
}
int imprimirColor(eColor* color, int tam, int id)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(id == color[i].id)// En caso de que el id del tipo ingresado sea igual al id del array de color, imprimimos la descripcion por pantalla
        {
            printf("%s\n", color[i].nombreColor); //Imprimimos por pantalla el nombre del color
        }

    }
    return 0;
}
