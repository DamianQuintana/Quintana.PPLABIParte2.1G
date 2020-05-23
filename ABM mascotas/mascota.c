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
#include "duenio.h"
#include "informes.h"


int inicializarMascotas(eMascota* mascota, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        mascota[i].edad = -1; //Utilizaremos como bandera de estado la edad de la mascota, indicando como -1, libre
    }
    return 0;
}
int buscarMascotaLibre(eMascota* mascota, int size)
{
    int flag;
    int i;

    for(i=0; i<size; i++)
    {
        if(mascota[i].edad == -1) // En caso de la posicion estar libre
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
int agregarMascota(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, int id, int i, eDuenio* duenio, int tam4)
{
    int j;
    int flag;

    system("CLS");
    printf("\nIngrese la edad de su mascota: ");
    mascota[i].edad = getInt(); //Llamamos a la función getInt para validar el parametro "edad"

    while(mascota[i].edad == 0 || mascota[i].edad < 0) // En caso de haber ingresado solamente enter o un valor menor a 0 volvemos a pedir el valor
    {
        printf("\nEdad invalida, reingrese ");
        mascota[i].edad = getInt(); //Llamamos a la función getInt para validar el parametro "edad"
    }
    mascota[i].id = id; // Asignamos el id autoincremental
    system("CLS");
    printf("\nIngrese el nombre de su mascota: ");
    getChar(mascota[i].nombre);//Llamamos a la funcion getChar para validar el parametro "nombre"
    system("CLS");
    listarTipos(tipo, tam2); //Imprimimos los tipos por pantalla
    printf("\nIngrese su tipo de mascota: ");
    mascota[i].idTipo = getInt();//Llamamos a la función getInt para validar el parametro "idTipo"
    do //Utilizamos la siguiente secuencia de "do while" para evitar que se tome un valor como id de tipo que no sea alguno de los cargados
    {
        for(j=0; j<tam2; j++) //Recorremos el array de tipo en busca de que el id de tipo coincida con alguno de los tipos de lista
        {
            if(mascota[i].idTipo != tipo[j].id) //En caso de que ninguno de los tipos que encontramos coincida
            {
                flag = -1; // Ponemos la bandera en -1 indicando error
            }
            else
            {
                flag = 0; // En caso de encotrar un valor igual al tipo cambiamos el valor de flag a 0
                break;
            }
        }
        if(flag == -1) // En el caso de no haber encontrado dicho ID ejecutamos la siguiente línea de código
        {
            listarTipos(tipo, tam2);
            printf("\nNo se encontro dicho ID de tipo, reingrese uno de la lista: "); //En caso de no haber encontrado dicho ID volvemos a pedirlo
            mascota[i].idTipo = getInt();//Llamamos a la función getInt para validar el parametro "idTipo"
        }
    }
    while(flag == -1); // Seguiremos pidiendo que el usuario reingrese el id de tipo hasta que el id coincida
    printf("Ingrese el ID del dueño de su mascota: ");
    imprimirDuenios(duenio, tam4);
    mascota[i].idDuenio = getInt();
    do //Utilizamos la siguiente secuencia de "do while" para evitar que se tome un valor como id de tipo que no sea alguno de los cargados
    {
        for(j=0; j<tam4; j++) //Recorremos el array de tipo en busca de que el id de tipo coincida con alguno de los tipos de lista
        {
            if(mascota[i].idDuenio != duenio[j].id) //En caso de que ninguno de los tipos que encontramos coincida
            {
                flag = -1; // Ponemos la bandera en -1 indicando error
            }
            else
            {
                flag = 0; // En caso de encotrar un valor igual al tipo cambiamos el valor de flag a 0
                break;
            }
        }
        if(flag == -1) // En el caso de no haber encontrado dicho ID ejecutamos la siguiente línea de código
        {
            imprimirDuenios(duenio, tam4);
            printf("\nNo se encontro dicho ID de duenio, reingrese uno de la lista: "); //En caso de no haber encontrado dicho ID volvemos a pedirlo
            mascota[i].idDuenio = getInt();//Llamamos a la función getInt para validar el parametro "idDuenio"
        }
    }
    while(flag == -1);



    listarColores(color, tam3); //Llamamos a la función para que muestre por pantalla el listado de los colores a elegir
    printf("\nIngrese el color de su mascota: ");
    mascota[i].idColor = getInt();//Llamamos a la función getInt para validar el parametro "idColor"
    do //Utilizamos la siguiente secuencia de "do while" para evitar que se tome un valor como id de tipo que no sea alguno de los cargados
    {
        for(j=0; j<tam3; j++)
        {
            if(mascota[i].idColor != color[j].id) //En caso de que ninguno de los tipos que encontramos coincida
            {
                flag = -1; // Ponemos la bandera en -1 indicando error
            }
            else
            {
                flag = 0; //En caso de encontrarlo ponemos la bandera en 0
                break;
            }
        }
        if(flag == -1)
        {
            listarColores(color, tam3);
            printf("\nNo se encontro dicho ID de color, reingrese uno de la lista: ");
            mascota[i].idColor = getInt();//Llamamos a la función getInt para validar el parametro "idColor"
        }
    }
    while(flag == -1);

    return 0;

}
int imprimirMascotas(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4)
{
    int i;
    system("CLS");
    printf("\nID\t\tIDDUENIO\tNOMBRE\t\tEDAD\t\t\tTIPO\t\tCOLOR\n");
    for(i=0; i<tam; i++)
    {
        if(mascota[i].edad != -1) //En el caso que la edad de la mascota no sea -1 (valor que indica que está libre, no dado de alta)imprimiremos sus datos
        {
            printf("%d\t\t%d\t\t%s\t\t%d\t\t",mascota[i].id, mascota[i].idDuenio, mascota[i].nombre, mascota[i].edad);
            printf("\t");
            imrpirmirTipo(tipo, tam2, mascota[i].idTipo);
            imprimirColor(color, tam3, mascota[i].idColor);
        }
    }
    return 0;
}
int buscarMascotaPorID(eMascota* mascota, int tam, int id)
{
    int i;
    int flag;

    for(i=0; i<tam; i++)
    {
        if(mascota[i].id == id && mascota[i].edad != -1) //En el caso de que el ID ingresado sea igual al id del array y se encuentre dado de alta
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
int imprimirUnaMascota(eMascota* mascota, int tam, int id, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4)
{
    int i;
    i = buscarMascotaPorID(mascota, tam, id); // En caso de no encontrarla, i nos devolverá -1
    if(i!=-1) //En caso de haber encontrado dicho ID imprimimos sus datos por pantalla
    {
    printf("\nID\t\tIDDUENIO\tNOMBRE\t\tEDAD\t\t\tTIPO\t\tCOLOR\n");
            printf("%d\t\t%d\t\t%s\t\t%d\t\t",mascota[i].id, mascota[i].idDuenio, mascota[i].nombre, mascota[i].edad);
        printf("\t");
        imrpirmirTipo(tipo, tam2, mascota[i].idTipo);
        imprimirColor(color, tam3, mascota[i].idColor);
    }
    return 0;
}
int ModificarMascota(eMascota* mascota, int tam, int id, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4)
{
    int modify; // Variable donde guardamos el dato que se vaya a modificar
    int flag = 0; // Variable de control y retorno
    int i; // Variable donde guardamos la posicion de la mascota en el array
    int j;
    int flag2 = 0;
    int idBusqueda;

    i = buscarMascotaPorID(mascota, tam, id); // Guardamos en la variable "i" la posicion de la mascota en el array
    while(i==-1) // Si no encontre dicho ID voy a ejecutar la siguiente linea de codigo
    {
        printf("\nNo se encontro dicho ID de mascota en el sistema, los cargados son: "); //Muestro el mensaje de error indicando cuales son los ID dados de alta
        imprimirMascotas(mascota, tam, tipo, tam2, color, tam3, duenio, tam4);
        printf("\nIngrese un valor de ID esta lista: ");
        scanf("%d", &idBusqueda); // Pedimos nuevamente el ingreso del ID
        i = buscarMascotaPorID(mascota, tam, idBusqueda); //Volvemos a buscarlo en el caso de no haberlo encontrado
    }


    if(i != -1) // En caso de encontrar a la mascota ejecutamos la siguiente línea de código
    {
        imprimirUnaMascota(mascota, tam, id, tipo, tam2, color, tam3, duenio, tam4);
        printf("\nQue dato desea modificar\n1-Tipo\n2-Edad\n3-Nada");
        scanf("%d", &modify);
        switch(modify)
        {
        case 1:
            system("CLS");
            listarTipos(tipo, tam2);
            printf("\nIngrese el nuevo tipo: ");
            mascota[i].idTipo = getInt();
            do //Utilizamos la siguiente secuencia de "do while" para evitar que se tome un valor como id de tipo que no sea alguno de los cargados
            {
                for(j=0; j<tam2; j++)
                {
                    if(mascota[i].idTipo != tipo[j].id) //En caso de que ninguno de los tipos que encontramos coincida
                    {
                        flag = -1; // Ponemos la bandera en -1 indicando error
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == -1)
                {
                    system("CLS");
                    listarTipos(tipo, tam2);
                    printf("\nNo se encontro dicho ID de tipo, reingrese uno de la lista: ");
                    mascota[i].idTipo = getInt();
                }
            }
            while(flag == -1);
            flag2 = 1;
            break;

        case 2:
            system("CLS");
            printf("\nIngrese la nueva edad: ");
            mascota[i].edad = getInt();
            flag2 = 1;
            break;

        case 3:
            flag2 = -1; // En caso de no haber modificado nada ponemos la bandera de estado en -1
            break;
        }
    }

    return flag2; //Retorno 1 en caso de haber modificado, retorno -1 en caso contrario
}
int quitarMascota(eMascota* mascota, int tam, int id, eTipo* tipo, int tam2, eColor* color, int tam3, eDuenio* duenio, int tam4)//RETOCAR
{
    int i; // Variable de control para la estructura "for"
    int decision; // Variable de control para la confirmación de baja
    int flag = 0; // Variable de control para indicar si se dió de baja

    i = buscarMascotaPorID(mascota, tam, id);
    if(i != -1) // En caso de este valor ser diferente a -1 (error) ejecutamos el siguiente bloque
    {
        system("CLS"); // Limpiamos pantalla
        imprimirUnaMascota(mascota, tam, id, tipo, tam2, color, tam3, duenio, tam4);
        printf("\nDesea darlo de baja? \n1-Si\n2-No\nUsted ingreso: "); // Imprimimos por pantalla consultando la reconfirmación
        scanf("%d", &decision); // Tomamos el ingreso por teclado
        if(decision == 1) //En caso de que la opción sea = 1 damos de baja al empleado
        {
            flag = 0; // Indicamos "flag = 0" diciendo que la baja está "OK"
            mascota[i].edad = -1; // Indicamos la edad en -11 para "lugar libre"
        }
        else
        {
            flag = -1; // En caso de no haberse dado de baja cambiamos el valor de flag a -1
        }
    }
    else
    {
        flag = -1; // En caso de no encontrar dicho ID en sistema cambiamos el valor de flag a -1
        system("CLS"); // Limpiamos pantalla
        printf("No se encontro en el sistema ese ID\n"); //Mostramos por mensaje el error
        system("PAUSE"); // Pausamos la ejecución del programa
    }
    return flag; // Retornamos el valor de flag - 1 En caso de no haberse dado de baja
}
int ordenarMascotas(eMascota* mascota, int size)
{

    int i;
    int j;
    eMascota auxMascotas[size]; // Variable auxiliar

    /*METODO DE BURBUJEO POR DOS CRITERIOS*/
    for(i=0; i<size-1; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(mascota[i].idTipo<mascota[j].idTipo) //Ordenado por tipo
            {
                auxMascotas[i] = mascota[i];
                mascota[i] = mascota[j];
                mascota[j] = auxMascotas[i];
            }
            else if(mascota[i].idTipo == mascota[j].idTipo && (strcmp(mascota[i].nombre, mascota[j].nombre)) <0) // En caso de que los tipos sean iguales, utilizo el criterio por nombre
            {
                auxMascotas[i] = mascota[i];
                mascota[i] = mascota[j];
                mascota[j] = auxMascotas[i];
            }
        }
    }

    return 0;
}
