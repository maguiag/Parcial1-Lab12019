#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"
#include "utn.h"
#include "informes.h"
#define CANT_ORQ 50
#define CANT_INSTR 20
#define CANT_MUSICOS 1000

int main()
{
    int opcion;
    int auxId;

    Orquesta orquesta[CANT_ORQ];
    Musico musico[CANT_MUSICOS];
    Instrumento instrumento[CANT_INSTR];

    orquesta_init(orquesta,CANT_ORQ);
    musico_init(musico,CANT_MUSICOS);
    instrumento_init(instrumento,CANT_INSTR);

    orquesta_altaForzada(orquesta,CANT_ORQ,Orquesta1,Lugar1,1);
    musico_altaForzada(musico,CANT_MUSICOS,"juan","gomez",33,20,1);
    instrumento_altaForzada(instrumento,CANT_INSTR,"guitarra",1);

    do
    {
     getValidInt("\n1.Agregar orquesta\n2.Eliminar Orquesta\n3.Imprimir Orquesta\n4.Agregar musico\n5.Modificar Musico\n6.Eliminar musico\n7.Imprimir musico\n8.Agregar instrumento\n9.imprimir instrumento\n10.SALIR\n",
         "\nERROR",&opcion,1,11,2);
    switch(opcion)
    {
        case 1:
        orquesta_alta(orquesta,CANT_ORQ);
        break;
        case 2:
        getValidInt("\nid Orquesta? \n","\nerror",&auxId,0,50,2);
        orquesta_baja_musico(orquesta,CANT_ORQ,auxId,musico,CANT_MUSICOS);
        break;
        case 3:
        orquesta_mostrar(orquesta,CANT_ORQ);
        break;
        case 4:
        musico_alta(musico,CANT_MUSICOS);
        break;
        case 5:
        musico_mostrar(musico,CANT_MUSICOS);
        getValidInt("\nId musico? \n", "\nerror",&auxId,0,1000,2);
        musico_modificacion(musico,CANT_MUSICOS,auxId);
        break;
        case 6:
        musico_mostrar(musico,CANT_MUSICOS);
        getValidInt("\nId musico? \n", "\nerror",&auxId,0,1000,2);
        musico_baja(musico,CANT_MUSICOS,auxId);
        break;
        case 7:
        musico_mostrar(musico,CANT_MUSICOS);
        break;
        case 8:
        instrumento_alta(instrumento,CANT_INSTR);
        instrumento_mostrar(instrumento,CANT_INSTR);
        break;
        case 9:
        instrumento_mostrar(instrumento,CANT_INSTR);
        break;
    }
    }while(opcion!=10);

    return 0;
}
