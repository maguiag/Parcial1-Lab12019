#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"
#include "utn.h"
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

    do
    {
     getValidInt("\n1.Agregar orquesta\n2.Eliminar Orquesta\n3.Imprimir Orquesta\n4.Agregar musico\n5.Modificar MUsico\n6.Eliminar musico\n7.IMprimir musico\n8.Agregar instrumento\n9.imprimir instrumento\n10.SALIR\n",
    "\nERROR",&opcion,1,11,2)
    switch(opcion)
    {
        case 1:
        orquesta_alta(orquesta,CANT_ORQ);
        break;
        case 2:
        getValidInt("\nid Orquesta?","\nerror",&auxId,0,50,2);
        orquesta_baja_musico(orquesta,CANT_ORQ,auxId,musico,CANT_MUSICOS);


    }
    }


    return 0;
}
