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

// Definicion de los tamaños
#define TAMT 5 // Tamaño tipos
#define TAMC 5 // Tamaño colores
#define TAMS 3 // Tamaño servicios
#define TAMTT 20 // Tamaño trabajos
#define TAMM 16 // Tamaño mascotas
#define TAMD 16 // Tamaño del array de duenios

int main()
{
    eTipo tipo[TAMT] = {{1000, "Ave"},{1001, "Perro"},{1002, "Gato"},{1003, "Roedor"},{1004, "Pez"}}; //Hardocdeo del array de estructuras
    eColor color[TAMC]= {{5000, "Negro"},{5001, "Blanco"},{5002, "Gris"},{5003, "Rojo"},{5004, "Azul"}};//Hardocdeo del array de estructuras
    eServicio servicio[TAMS] = {{20000, "Corte", 250},{20001, "Desparasitado", 250},{20002, "Castrado", 250}};//Hardocdeo del array de estructuras
    eTrabajo trabajo[TAMTT]; // = {{1, 1, 20000, {10,05,2020}},{2, 1, 20000, {10,05,2020}},{3, 1, 20000, {10,05,2020}},{4, 1, 20000, {10,05,2020}},{5, 1, 20000, {10,05,2020}},}; //Definicion de estructura
    eMascota mascota[TAMM];//Definicion de estructura
    eDuenio duenios[TAMD]; //Definicion del array de estructura de duenios

    int menu; //Variable de control del menu
    int lugarLibre;//Variable de control para los indices libres
    int idMascota = 0; //Variable donde iremos guardando los ID de las mascotas, autoincremental
    char decision; //Variable de control para saber si se desea cargar otra mascota
    int modifyID;//Variable donde guardamos el ID a modificar
    int removeID;//Variable donde guardo el ID a dar de baja
    int control;//Variable de control para las funciones
    int idTrabajos = 0; // Variable autoincremental del id de los trabajos
    int controlMenu;
    int menInformes;
    int idBusqueda;
    int colorUser;
    int tipoUser;
    int i;
    float totalTrabajos;
    int dia;
    int mes;
    int anio;
    /*Duenios*/

    inicializarMascotas(mascota, TAMM); // Inicializo el array de mascotas, es decir, pongo sus edades en -1
    inicializarTrabajos(trabajo, TAMTT); // Inicializa el array de trabajos, es decir, pongo sus id de servicio en -1
    idMascota = hardCoding(mascota, TAMM); //Con la opcion del tamaño decidimos cuantos elemntos queremos hardcodear, es decir, si el array de mascotas es de 6 pero le pasamos un 3, todavía tendremos posiciones libres para cargar manualmente
    idTrabajos = hardCodingTrabajos(trabajo, TAMTT); //Con la opcion del tamaño decidimos cuantos elemntos queremos hardcodear, es decir, si el array de mascotas es de 6 pero le pasamos un 3, todavía tendremos posiciones libres para cargar manualmente
    inicializarDuenios(duenios, TAMD);
    hardcodearDuenios(duenios, TAMD);

    do
    {
        system("PAUSE");
        system("CLS");
        printf("\n\t\t\t\t\t1- Alta mascota");
        printf("\n\t\t\t\t\t2- Modificar mascota");
        printf("\n\t\t\t\t\t3- Baja mascota");
        printf("\n\t\t\t\t\t4- Listar mascotas");
        printf("\n\t\t\t\t\t5- Listar tipos");
        printf("\n\t\t\t\t\t6- Listar colores");
        printf("\n\t\t\t\t\t7- Listar servicios ");
        printf("\n\t\t\t\t\t8- Alta trabajo");
        printf("\n\t\t\t\t\t9- Listar trabajos");
        printf("\n\t\t\t\t\t10- Informes");
        printf("\n\t\t\t\t\t11 - Salir");
        printf("\n\n\nPara cargar una mascota, primero debera dar una de baja");
        printf("\n\nHasta no ingresar a la primera opcion no se podra ingresar a las demas opcionesS");
        if(controlMenu != 1)
        {
            printf("\nNo hay mascotas cargadas\n");
        }
        else
        {
            printf("\nYa hay mascotas dadas de alta\n");
        }
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
            do
            {
                controlMenu = 1; // Variable de control, si entramos en la primer opciona la ponemos en 1
                lugarLibre = buscarMascotaLibre(mascota, TAMM); // utilizamos la variable lugarLibre para guardar la primer posicion libre del array
                if(lugarLibre != -1)// En caso de haber encontrado lugar
                {
                    idMascota++; // Incrementamos el contador de ID en 1
                    agregarMascota(mascota, TAMM, tipo, TAMT, color, TAMC, idMascota, lugarLibre, duenios, TAMD); //Realizamos la llamada a la función agregar mascota, en caso de no haber lugar libre  ya sabemos que no se realizará la carga
                    printf("\nAlta exitosa");
                    printf("\nDesea cargar otra mascota?\ns - SI\nn - NO");
                    fflush(stdin);
                    scanf("%c", &decision); // Consultamos si desea cargar otra mascota
                }
                else
                {
                    printf("\nNo hay mas espacio"); // En caso de no haber encontrado lugar
                    decision = 'n';
                }
            }
            while(decision == 's');

            break;

        case 2:
            if(controlMenu == 1) // Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                system("CLS");
                imprimirMascotas(mascota, TAMM, tipo, TAMT, color, TAMC, duenios, TAMD); //Imprimimos el array de mascotas
                printf("\nIngrese el ID que desea modificar: ");
                scanf("%d", &modifyID);
                control = ModificarMascota(mascota, TAMM, modifyID, tipo, TAMT, color, TAMC, duenios, TAMD); // Llamada de funcion donde vamos a guardar el valor retornado en control
                if(control!=-1)
                {
                    system("CLS");
                    printf("\nModificado con exito");
                }
                else
                {
                    system("CLS");
                    printf("No se modifico");
                }

            }
            else
            {
                printf("\nPrimero cargue alguna mascota");
            }

            break;

        case 3:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {

                system("CLS");
                imprimirMascotas(mascota, TAMM, tipo, TAMT, color, TAMC, duenios, TAMD); //Imprimimos el array de macotas
                printf("\nIngrese el ID que desea dar de baja: ");
                scanf("%d", &removeID);
                control = quitarMascota(mascota, TAMM, removeID, tipo, TAMT, color, TAMC, duenios, TAMD);// Llamada de funcion donde vamos a guardar el valor retornado en control
                if(control == -1)
                {
                    system("CLS");
                    printf("\nNo se dio de baja");
                }
                else
                {
                    system("CLS");
                    printf("\nBaja exitosa");
                }


            }
            else
            {
                system("CLS");
                printf("\nPrimero cargue alguna mascota");
            }

            break;

        case 4:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                ordenarMascotas(mascota, TAMM); // Llamada a la funcion
                imprimirMascotas(mascota, TAMM, tipo, TAMT, color, TAMC, duenios, TAMD);// Llamada a la funcion
            }
            else
            {
                system("CLS");
                printf("\nPrimero cargue alguna mascota");
            }

            break;

        case 5:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                listarTipos(tipo, TAMT);// Llamada a la funcion
            }
            else
            {
                system("CLS");
                printf("\nPrimero cargue alguna mascota");
            }

            break;

        case 6:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                listarColores(color, TAMC);// Llamada a la funcion

            }
            else
            {
                system("CLS");
                printf("\nPrimero cargue alguna mascota");
            }
            break;

        case 7:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                listarServicios(servicio, TAMS);

            }
            else
            {
                system("CLS");
                printf("\nPrimero cargue alguna mascota");
            }
            break;

        case 8:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                do
                {
                    lugarLibre = buscarTrabajoLibre(trabajo, TAMTT); //Buscamos la primer posicion libre en el array de trabajos
                    if(lugarLibre != -1)
                    {
                        idTrabajos++; //En caso de haber encontrado una posicion libre incrementamos el contador de ID
                        agregarTrabajo(trabajo, TAMTT,  lugarLibre, idTrabajos, mascota, TAMM, servicio, TAMS, tipo, TAMT, color, TAMC, duenios, TAMD);//Llamamos a la funcion agregar trabajo
                        system("CLS");
                        printf("\nDesea cargar otro trabajo?\ns - SI\nn - NO");
                        fflush(stdin);
                        scanf("%c", &decision);
                    }
                    else
                    {
                        system("CLS");
                        printf("\nNo hay mas espacio");
                        decision = 'n';
                    }
                }
                while(decision == 's');

            }
            else
            {
                system("CLS");
                printf("\nPrimero cargue alguna mascota");
            }

            break;

        case 9:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                imprimirTrabajos(trabajo, TAMTT, servicio, TAMS); //Imprimimos el array de trabajos
            }
            else
            {
                system("CLS");
                printf("\nPrimero cargue alguna mascota");
            }

            break;

        case 10:
            if(controlMenu == 1) // Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                do
                {
                    system("CLS");
                    printf("BIENVENIDO AL MENU DE INFORMES");
                    printf("\n1 - Mostrar mascotas del color seleccionado por el usuario");
                    printf("\n2 - Mostrar mascotas de un tipo seleccionado");
                    printf("\n3 - Informar mascotas de menor edad");
                    printf("\n4 - Listado de las mascotas separado por tipo");
                    printf("\n5 - Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo");
                    printf("\n6 - Mostrar el o los colores con mas cantidad de mascotas");
                    printf("\n7 - Pedir una mascota y mostrar todos los trabajos que se hicieron a la misma");
                    printf("\n8 - Pedir una macota e informar la suma de los importes de los servicios que se le hicieron a la misma");
                    printf("\n9 - Pedir un servicio y mostra las mascotas a las que se le realizo ese servicio y la fecha");
                    printf("\n10 - Pedir una fecha y mostrar todos los servicios realizados en la misma");
                    printf("\n11 - Salir del menu de informes para volver al anterior");
                    scanf("%d", &menInformes);
                    switch(menInformes)
                    {
                    case 1:
                        printf("\nIngrese de que color de mascota que desea contar");
                        listarColores(color, TAMC);
                        idBusqueda = getInt();
                        imprimirMascotas(mascota, TAMM, tipo, TAMT, color, TAMC, duenios, TAMD);
                        cantidadDeanimalesColor(mascota, TAMM, idBusqueda, color, TAMC, tipo, TAMT, duenios, TAMD);
                        break;

                    case 2:
                        printf("\nIngrese de que tipo demascota desea contar");
                        listarTipos(tipo, TAMT);
                        idBusqueda = getInt();
                        imprimirMascotas(mascota, TAMM, tipo, TAMT, color, TAMC, duenios, TAMD);
                        cantidadDeAnimalesTipo(mascota, TAMM, idBusqueda, tipo, TAMT, color, TAMC, duenios, TAMD);
                        break;

                    case 3:
                        animalMasJoven(mascota, TAMM, tipo, TAMT, color, TAMC, duenios, TAMD);
                        break;

                    case 4:
                        mascotasPorTipo(mascota, TAMM, tipo, TAMT, color, TAMC, duenios, TAMD);
                        break;

                    case 5:

                        listarColores(color, TAMC);
                        printf("Ingrese el color a buscar: ");
                        colorUser = getInt();
                        do //Utilizamos la siguiente secuencia de "do while" para evitar que se tome un valor como id de tipo que no sea alguno de los cargados
                        {
                            for(i=0; i<TAMC; i++)
                            {
                                if(colorUser != color[i].id) //En caso de que ninguno de los tipos que encontramos coincida
                                {
                                    control = -1; // Ponemos la bandera en -1 indicando error
                                }
                                else
                                {
                                    control = 0;
                                    break;
                                }
                            }
                            if(control == -1)
                            {
                                system("CLS");
                                listarColores(color, TAMC);
                                printf("\nNo se encontro dicho ID de color, reingrese uno de la lista: ");
                                colorUser = getInt();
                            }
                        }
                        while(control == -1);
                        listarTipos(tipo, TAMT);
                        printf("Ingrese el tipo a buscar: ");
                        tipoUser = getInt();
                        do //Utilizamos la siguiente secuencia de "do while" para evitar que se tome un valor como id de tipo que no sea alguno de los cargados
                        {
                            for(i=0; i<TAMC; i++)
                            {
                                if(tipoUser != tipo[i].id) //En caso de que ninguno de los tipos que encontramos coincida
                                {
                                    control = -1; // Ponemos la bandera en -1 indicando error
                                }
                                else
                                {
                                    control = 0;
                                    break;
                                }
                            }
                            if(control == -1)
                            {
                                system("CLS");
                                listarTipos(tipo, TAMT);
                                printf("\nNo se encontro dicho ID de tipo, reingrese uno de la lista: ");
                                tipoUser = getInt();
                            }
                        }
                        while(control == -1);

                        contarMascotasPorTipoYColor(mascota, TAMM, tipo, TAMT, color, TAMC, duenios, TAMD, colorUser, tipoUser);
                        break;

                    case 6:
                        coloresconMasMacotas(mascota, TAMM, tipo, TAMT, color, TAMC, duenios, TAMD);
                        break;
                    case 7:
                        imprimirMascotas(mascota, TAMM, tipo, TAMT, color, TAMC, duenios, TAMD);
                        printf("\nIngrese de que mascota desea saber que traajos se le realizaron");
                        idBusqueda = getInt();
                        trabajosHechosAMascota(trabajo, TAMT, mascota, TAMM, servicio, TAMS, idBusqueda);
                        break;

                    case 8:
                        imprimirMascotas(mascota, TAMM, tipo, TAMT, color, TAMC, duenios, TAMD);
                        printf("\nIngrese de que mascota desea saber su deuda");
                        idBusqueda = getInt();
                        totalTrabajos = deudaTotalMascota(trabajo, TAMTT, mascota, TAMM, servicio, TAMS, idBusqueda);
                        if(totalTrabajos == 0)
                        {
                            printf("\nDicha mascota no esta dada de alta\n");
                            system("PAUSE");
                        }
                        else
                        {
                            imprimirTrabajos(trabajo, TAMTT, servicio, TAMS);
                            printf("\nLa mascota de ID %ddebe %.2f",idBusqueda, totalTrabajos);
                            system("PAUSE");
                        }
                        break;

                    case 9:
                        listarServicios(servicio, TAMS);
                        printf("\nIngrese el servicio que desea ver a quien fue realizado");
                        idBusqueda = getInt();
                        serviciosAMascota(mascota, TAMM, tipo, TAMT, color, TAMC, duenios, TAMD, idBusqueda, servicio, TAMS, trabajo, TAMTT);

                        break;

                    case 10:
                        printf("\nIngrese una fecha para buscar los servicios");
                        printf("\nDia");
                        dia = getInt();
                        printf("\Mes");
                        mes = getInt();
                        printf("\nAnio");
                        anio= getInt();
                        serviciosPorFecha(mascota, TAMM, tipo, TAMT, color, TAMC, duenios, TAMD, servicio, TAMS, trabajo, TAMTT, dia, mes, anio);
                        break;
                    }
                }
                while(menInformes != 11);

            }
            else
            {
                printf("\nPrimero cargue alguna mascota");
            }


            break;
        }
    }
    while(menu!=11);
}

