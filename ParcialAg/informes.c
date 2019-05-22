#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"
#include "utn.h"
#include "informes.h"


/** \brief imprime cantidad de musicos por orquesta
 *
* \param array Musico* puntero al array
 * \param limite int limite definido para el musico
 * \param
 * \return int [0] OK [-1] ERROR
 *
 */



informar_musicosByOrquesta(Orquesta* arrayOrquesta, int limiteOrquesta,Musico* arrayMusico,int limiteMusico)
{
    int retorno=-1;
    int i;
    int j;
    int idOrquesta;
    int contadorMusicos=0;

    if(limiteOrquesta>0 && arrayOrquesta!=NULL)
    {
        retorno =0;
        for(i=0; i<limiteOrquesta; i++)
        {

            if(!arrayOrquesta[i].isEmpty)
            {
                idOrquesta=arrayOrquesta[i].idOrquesta;
                for(j=0; j<limiteMusico; j++)
                {
                    if(!arrayMusico[j].isEmpty && arrayMusico[j].idOrquesta==idOrquesta)
                    {
                        contadorMusicos++;
                    }
                }
                printf("[RELEASE] - ID Orquesta: %d - Nombre: %s - Tipo: %d - Cantidad de musicos: %d \n ",arrayOrquesta[i].idOrquesta,
                                                                                                           arrayOrquesta[i].nombre,
                                                                                                           arrayOrquesta[i].tipo,
                                                                                                           contadorMusicos);
            }
            contadorMusicos =0;
        }
    }
    return retorno;
}

/*
informe_orquestaMasMusicos(Orquesta* arrayOrquesta, int limiteOrquesta, Musico* arrayMusico, int limiteMusico)
{
    int retorno=-1;
    int i;
    int j;
    int indiceOrquesta;



    return retorno;
}


/** \brief informa los instrumentos con el id de la orquesta
 *
 * \param Orquesta* y su limite
 * \param Instrumento* y su limite
 * \return [0] si OK, [-1] si ERROR
 *
 */

contadorOrquesta(Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int cantOrquestas=0;
    if(arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        for(i=0;i<limiteOrquesta;i++)
        {
            if(!arrayOrquesta[i].isEmpty)
            {
                cantOrquestas++;
            }
        }
        retorno=cantOrquestas;
    }
    return retorno;
}


contador_musicosByOrquesta(Musico* arrayMusico,int limiteMusico, int idOrquesta)
{
    int retorno =-1;
    int i;
    int contMusicosByOrquesta=0;
    if(arrayMusico!=NULL && limiteMusico>0)
    {
        for(i=0;i<limiteMusico;i++)
        {
            if(arrayMusico[i].isEmpty==0 && arrayMusico[i].idOrquesta==idOrquesta)
            {
                contMusicosByOrquesta++;
            }
        }
        retorno=contMusicosByOrquesta;
    }
    return retorno;
}


contador_orquestaByTipo(Orquesta* arrayOrquesta, int limiteOrquesta, int tipo)
{
    int retorno=-1;
    int i;
    int contOrqByTipo=0;
    if(arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        for(i=0;i<limiteOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty==0 && arrayOrquesta[i].tipo==tipo)
            {
                contOrqByTipo++;
            }
        }
        return contOrqByTipo;
    }

    return retorno;
}


contador_instrumentosByTipo(Instrumento* arrayInstrumento, int limiteInstrumento,int tipo)
{
    int retorno=-1;
    int i;
    int contInstrByTipo=0;
    if(arrayInstrumento!=NULL && limiteInstrumento>0)
    {
        for(i=0;i<limiteInstrumento;i++)
        {
            if(arrayInstrumento[i].isEmpty==0 && arrayInstrumento[i].tipo==tipo)
            {
                contInstrByTipo++;
            }
        }
        retorno=contInstrByTipo;
    }
    return retorno;
}




int informe_OrquestaMas5(Musico* arrayMusico,int limiteMusico,int idOrquesta)
{
    int retorno=-1;
    int i;
    int cantidadMusico;
    int mas5;
    if(arrayMusico!=NULL && limiteMusico>0)
    {
        retorno =0;
        for(i=0;i<limiteMusico;i++)
        {
            if(!arrayMusico[i].isEmpty)
            {
                cantidadMusico=contador_musicosByOrquesta(arrayMusico,limiteMusico,idOrquesta);
                if(cantidadMusico>5)
                {
                printf("[RELEASE] - ID Orquesta: %d - Nombre: %s - Tipo: %d - Cantidad de musicos: %d \n ",arrayOrquesta[i].idOrquesta,
                                                                                                           arrayOrquesta[i].nombre,
                                                                                                           arrayOrquesta[i].tipo,
                                                                                                           cantidadMusico);
                }
            }
        }
    }


return retorno;

}




listar_musicosMas30(Musico* arrayMusico, int limiteMusico)
{
    int retorno=-1;
    int i;
    int minimaEdad=30;

    if(arrayMusico!=NULL && limiteMusico>0)
    {
        retorno=0;
        for(i=0;i<limiteMusico;i++)
        {
            if(!arrayMusico[i].isEmpty)
            {
                if(musico[i].edad>minimaEdad)
                {
                    printf("[RELEASE] -ID: %d -NOMBRE: %s -APELLIDO: %s -EDAD: %d -IdOrquesta: %d -idInstrumento\n",
                                    arrayMusico[i].idMusico,
                                    arrayMusico[i].nombre,
                                    arrayMusico[i].apellido,
                                    arrayMusico[i].edad,
                                    arrayMusico[i].idOrquesta,
                                    arrayMusico[i].idInstrumento);
                }
            }
        }
    }
    return retorno;
}

listar_musicos_orquestaById(Orquesta* arrayOrquesta, int limiteOrquesta, int idOrquesta,)

{

    int retorno=-1;
    int i;
    int j;
    if(limiteOrquesta>0 && arrayOrquesta!=NULL)
    {
        retorno=0;
        for(i=0; i<limiteOrquesta; i++)
        {
            if(!arrayOrquesta[i].isEmpty)//==0
            printf("[RELEASE] - ID Orquesta: %d - Nombre: %s - Lugar: %s - Tipo: %d \n ",arrayOrquesta[i].idOrquesta,
                                                                                        arrayOrquesta[i].nombre,
                                                                                        arrayOrquesta[i].lugar,
                                                                                        arrayOrquesta[i].tipo);
        }

    }
    return retorno;
}
