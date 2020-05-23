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

int listarTipos(eTipo* tipo, int tam)
{

    int i;
    system("CLS");
    printf("\nLISTADO DE TIPOS\n");
    printf("\nID\t\t\tDESCRIPCION\n");
    for(i=0; i<tam; i++)
    {
        printf("%d\t\t\t%s\n", tipo[i].id, tipo[i].descripcion); //Imprimimos los tipos
    }
    return 0;
}
int imrpirmirTipo(eTipo* tipo, int tam, int id)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(id == tipo[i].id) // En caso de que el id del tipo ingresado sea igual al id del array de tipos, imprimimos la descripcion por pantalla
        {
            printf("%s\t\t", tipo[i].descripcion);
            break;
        }
    }
    return 0;
}
