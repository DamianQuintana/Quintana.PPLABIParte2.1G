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


int listarServicios(eServicio* servicio, int tam)
{
    int i;
    system("CLS");
    printf("\nLISTADO DE SERVICIOS\n");
    printf("ID\t\t\tDESCRIPCION\t\t\tPRECIO\n");
    for(i=0; i<tam; i++)
    {
        printf("%d\t\t\t%s\t\t\t%f\n", servicio[i].id, servicio[i].descripcion, servicio[i].precio);// En caso de que el id del tipo ingresado sea igual al id del array de servicios, imprimimos la descripcion por pantalla
    }
    return 0;
}

int imprimirServicio(eServicio* servicio, int tam, int id)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(id == servicio[i].id)
        {
            printf("%s\n", servicio[i].descripcion);
            break;
        }
    }
    return 0;
}
