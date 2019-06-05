#include <stdio.h>
//include <stdio_ext.h>
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
    char lugar[31];

    Orquesta orquesta[CANT_ORQ];
    Musico musico[CANT_MUSICOS];
    Instrumento instrumento[CANT_INSTR];

    orquesta_init(orquesta,CANT_ORQ);
    musico_init(musico,CANT_MUSICOS);
    instrumento_init(instrumento,CANT_INSTR);

    orquesta_altaForzada(orquesta,CANT_ORQ,"Orquesta1","Lugar1",1);
    orquesta_altaForzada(orquesta,CANT_ORQ,"Orquesta2","Lugar1",1);
    orquesta_altaForzada(orquesta,CANT_ORQ,"Orquesta3","Lugar2",1);
    orquesta_altaForzada(orquesta,CANT_ORQ,"Orquesta4","Lugar3",1);

    musico_altaForzada(musico,CANT_MUSICOS,"Mus1","Amus1",30,1,2);
    musico_altaForzada(musico,CANT_MUSICOS,"Mus2","Amus2",20,2,5);
    musico_altaForzada(musico,CANT_MUSICOS,"Mus3","Amus3",25,4,2);
    musico_altaForzada(musico,CANT_MUSICOS,"Mus4","Amus4",27,4,1);
    musico_altaForzada(musico,CANT_MUSICOS,"Mus5","Amus5",22,1,3);
    musico_altaForzada(musico,CANT_MUSICOS,"Mus6","Amus6",35,3,4);

    instrumento_altaForzada(instrumento,CANT_INSTR,"Inst1",1);
    instrumento_altaForzada(instrumento,CANT_INSTR,"Inst2",2);
    instrumento_altaForzada(instrumento,CANT_INSTR,"Inst3",2);
    instrumento_altaForzada(instrumento,CANT_INSTR,"Inst4",3);
    instrumento_altaForzada(instrumento,CANT_INSTR,"Inst5",4);

    do
    {
     getValidInt("\n1.Agregar orquesta\n2.Eliminar Orquesta\n3.Imprimir Orquesta\n4.Agregar musico\n5.Modificar Musico\n6.Eliminar musico\n7.Imprimir musico\n8.Agregar instrumento\n9.imprimir instrumento\n10.Orquesta +5\n11.Musicos +30\n12.Orquesta por lugar\n13.Orquesta completa\n14.Musicos xOrquesta\n16.Orquesta +Musicos\n16.Musicos cuerda\n17.Promedio\n18.SALIR\n",
         "\nERROR",&opcion,1,20,3);
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
        case 10:
            informar_orquestaMasCinco(musico,CANT_MUSICOS,orquesta,CANT_ORQ);
            break;
        case 11:
            informar_musicosEdadMasTreinta(musico,CANT_MUSICOS);
            break;
        case 12:
            if(!getStringAlfaNumerico("\nIngrese lugar: ", lugar))
            {
                informar_orquestaByLugar(orquesta,CANT_ORQ,lugar);
            }
            else
                {
                    printf("\nError");
                }
            break;
        case 13:
            informar_orquestaCompleta(orquesta,CANT_ORQ,musico,CANT_MUSICOS,instrumento,CANT_INSTR);
            break;
        case 14:
            orquesta_mostrar(orquesta,CANT_ORQ);
            if(!getValidInt("\nIngrese Id: ","\nERROR\n",&auxId,1,1000,3))
            {
                informar_musicosPorOrquesta(orquesta,CANT_ORQ,musico,CANT_MUSICOS,auxId);
            }
            break;
        case 15:
            informe_OrquestaMasMusicos(orquesta,CANT_ORQ,musico,CANT_MUSICOS);
            break;
        case 16:
            informar_musicosCuerda(musico,CANT_MUSICOS,instrumento,CANT_INSTR);
            break;
        case 17:
            informar_promedioMusicos(orquesta,CANT_ORQ,musico,CANT_MUSICOS);
            break;
    }
    }while(opcion!=19);

    return 0;
}
