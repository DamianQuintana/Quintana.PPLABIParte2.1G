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


int cantidadDeanimalesColor(eMascota* mascota, int tam, int id, eColor* color, int tam2, eTipo* tipo, int tam3, eDuenio* duenio, int tam4)
{
    int i;
    int c = 0;
    int flag = 0;
    char descripcion[20];
    int idColor;
    do
    {
        if(flag == -1)
        {
            listarColores(color, tam2);
            printf("\nID de color no encontrado, reingrese uno de la lista");
            idColor = getInt();
        }
        for(i=0; i<tam; i++)
        {
            if(id == color[i].id || idColor == color[i].id) //Primero recorremos el array en busca del id de tipo para copiar su descripcion
            {
                strcpy(descripcion, color[i].nombreColor);
                flag = 1;
                break;
            }
            else
            {
                flag = -1;
            }
        }

    }
    while(flag == -1);

    for(i=0; i<tam; i++)
    {
        if((mascota[i].idColor == id || idColor == mascota[i].idColor) && (mascota[i].edad != -1)) //Luego volvemos a recorrerlo contando la cantidad de animales que son correspondientes a dicho tipo
        {
            c++;
        }
    }
    imprimirMascotas(mascota, tam, tipo, tam2, color, tam3, duenio, tam4);
    printf("\nLa cantidad de %s es de %d", descripcion, c);
    system("PAUSE");
    return 0;
}
int cantidadDeAnimalesTipo(eMascota* mascota, int tam, int id, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4)
{
    int i;
    int c = 0;
    int flag = 0;
    char descripcion[20];
    int idTipo;

    do
    {
        if(flag == -1)
        {
            listarTipos(tipo, tam2);
            printf("\nID de tipo no encontrado, reingrese uno de la lista");
            idTipo = getInt();
        }

        for(i=0; i<tam; i++)
        {
            if(id == tipo[i].id || idTipo == tipo[i].id) //Primero recorremos el array en busca del id de tipo para copiar su descripcion
            {
                strcpy(descripcion, tipo[i].descripcion);
                flag = 1;
                break;
            }
            else
            {
                flag = -1;
            }
        }

    }
    while(flag == -1);

    for(i=0; i<tam; i++)
    {
        if((mascota[i].idTipo == id || idTipo == mascota[i].idTipo) && (mascota[i].edad != -1)) //Luego volvemos a recorrerlo contando la cantidad de animales que son correspondientes a dicho tipo
        {
            c++;
        }
    }
    imprimirMascotas(mascota, tam, tipo, tam2, color, tam3, duenio, tam4);
    printf("\nLa cantidad de %s es de %d", descripcion, c);
    system("PAUSE");
    return 0;
}

int animalMasJoven(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4)
{
    int i;
    int masJoven = mascota[0].edad;
    for(i=0; i<tam; i++)
    {
        if(mascota[i].edad < masJoven)
        {
            masJoven = mascota[i].edad;
        }
    }

    imprimirMascotas(mascota, tam, tipo, tam2, color, tam3, duenio, tam4);
    printf("\nLa/las mascota/s mas joven/es es/son: \n");
    for(i=0; i<tam; i++)
    {
        if(mascota[i].edad <= masJoven)
        {
            imprimirUnaMascota(mascota, tam, mascota[i].id, tipo, tam2, color, tam3, duenio, tam4);
            system("PAUSE");
        }
    }
    return 0;
}

int mascotasPorTipo(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4)
{
    int i;
    int j;
    char descripcion[20];

    for(i=0; i<tam2; i++)
    {
        strcpy(descripcion, tipo[i].descripcion);
        printf("\nMASCOTAS DEL TIPO %s", descripcion);
        for(j=0; j<tam; j++)
        {
            if(tipo[i].id == mascota[j].idTipo)
            {
                imprimirUnaMascota(mascota, tam, mascota[j].id, tipo, tam2, color, tam3, duenio, tam4);
            }
        }
    }
    system("PAUSE");
    return 0;
}

int contarMascotasPorTipoYColor(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4, int colorUser, int tipoUser)
{

    int i;
    int c = 0;

    char descripcion[20];
    char descripcionC[20];

    for(i=0; i<tam2; i++)
    {
        if(tipoUser == tipo[i].id)
        {
            strcpy(descripcion, tipo[i].descripcion);
        }
    }
    for(i=0; i<tam3; i++)
    {
        if(colorUser == color[i].id)
        {
            strcpy(descripcionC, color[i].nombreColor);
        }

    }

    for(i=0; i<tam; i++)
    {
        if(mascota[i].idColor == colorUser && mascota[i].idTipo == tipoUser)
            c++;

    }

    imprimirMascotas(mascota, tam, tipo, tam2, color, tam3, duenio, tam4);
    printf("\nLa cantidad de animales del color %s y tipo %s es de: %d",descripcionC, descripcion, c);
    system("PAUSE");
    return 0;
}
int coloresconMasMacotas(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4)
{
    int i;
    int j;
    int contadorColores[6];
    char descripcionColores[6][30];
    int auxColores[6];
    char auxNombres[6][30];

    for(i=0; i<6; i++)
    {
        contadorColores[i] = 0;
    }



    for(i=0; i<tam3; i++)
    {
        for(j=0; j<tam; j++)
        {
            if(mascota[j].idColor ==  color[i].id)
            {
                contadorColores[i]++;
                strcpy(descripcionColores[i], color[i].nombreColor);
            }
        }
    }


    /*METODO DE BURBUJEO POR DOS CRITERIOS*/
    for(i=0; i<6-1; i++)
    {
        for(j=i+1; j<6; j++)
        {
            if(contadorColores[i]<contadorColores[j])
            {
                auxColores[i] = contadorColores[i];
                contadorColores[i] = contadorColores[j];
                contadorColores[j] = auxColores[i];

                strcpy(auxNombres[i], descripcionColores[i]);
                strcpy(descripcionColores[i], descripcionColores[j]);
                strcpy(descripcionColores[j], auxNombres[i]);
            }
        }
    }

    imprimirMascotas(mascota, tam, tipo, tam2, color, tam3, duenio, tam4);
    printf("\nEl/los colores con mas animales es/son\n");
    printf("COLOR: %s ANIMALES DE ESE COLOR: %d\n", descripcionColores[0], contadorColores[0]);
    for(i=0; i<6; i++)
    {
        if(contadorColores[i] >= contadorColores[0] && strcmp(descripcionColores[0],descripcionColores[i]) != 0)
        {
            printf("COLOR: %s ANIMALES DE ESE COLOR: %d\n", descripcionColores[i], contadorColores[i]);

        }
    }
    system("PAUSE");
    return 0;
}

int trabajosHechosAMascota(eTrabajo* trabajo, int tam, eMascota* mascota, int tam2, eServicio* servicio, int tam3, int id)
{
    int i;

    int flag;

    float acumulador = 0;
    flag = buscarMascotaPorID(mascota, tam2, id);
    if(flag !=-1)
    {
        for(i=0; i<tam; i++)
        {

            if(trabajo[i].idMascota == id && mascota[i].edad != -1) //En el caso que el id ingresado sea igual al id de la mascota y el id del trabajo sea igual al del servicio ejecutamos la siguiente linea de codigo
            {
                printf("\nFECHA\t\tID\t\tID MASCOTA\t\tSERVICIO\n");
                printf("%d/%d/%d\t%d\t\t\t%d\t",trabajo[i].fecha.dia,trabajo[i].fecha.mes,trabajo[i].fecha.anio, trabajo[i].id,trabajo[i].idMascota);
                printf("\t");
                imprimirServicio(servicio, tam3, trabajo[i].idServicio);
            }
        }

    }
    else
    {
        printf("\nNo se encontro dicho ID");
    }

    system("PAUSE");
    return acumulador;
}
float deudaTotalMascota(eTrabajo* trabajo, int tam, eMascota* mascota, int tam2, eServicio* servicio, int tam3, int id)
{
    int i;
    int j;
    int flag;

    float acumulador = 0;
    flag = buscarMascotaPorID(mascota, tam2, id);
    if(flag !=-1)
    {
        for(i=0; i<tam; i++)
        {
            for(j=0; j<tam3; j++)
            {
                if(trabajo[i].idMascota == id && trabajo[i].idServicio == servicio[j].id && mascota[i].edad != -1)
                {
                    acumulador = acumulador + servicio[j].precio;
                }
            }
        }

    }
    else
    {
        printf("\nNo se encontro dicho ID");
    }

    return acumulador;
}
int serviciosAMascota(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4, int id, eServicio* servicio, int tam5, eTrabajo* trabajo, int tam6)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(trabajo[i].idServicio == id)
        {
            printf("\nFecha: %d/%d/%d\t\t", trabajo[i].fecha.dia,trabajo[i].fecha.mes,trabajo[i].fecha.anio);
            imprimirUnaMascota(mascota,tam, trabajo[i].idMascota, tipo, tam2, color, tam3, duenio, tam4);
        }

        system("PAUSE");

    }
     return 0;
}
int serviciosPorFecha(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4, eServicio* servicio, int tam5, eTrabajo* trabajo, int tam6, int dia, int mes, int anio)
{
    int i;
    int j;
    int c;

    for(i=0; i<tam6; i++)
    {
        if(trabajo[i].fecha.dia== dia &&trabajo[i].fecha.mes == mes&& trabajo[i].fecha.anio == anio)
        {
            c = trabajo[i].idServicio;
            for(j=0; j<tam5; j++)
            {
                if(c == servicio[j].id)
                {
                    printf("ID\t\t\tDESCRIPCION\t\t\tPRECIO\n");
                    printf("%d\t\t\t%s\t\t\t%f\n", servicio[j].id, servicio[j].descripcion, servicio[j].precio);
                    system("PAUSE");
                }
            }

        }
    }
    return 0;
}
