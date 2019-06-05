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


/** \brief contador de orquestas
 *
 * \param puntero a orquesta, limite del array
 * \param idOrquesta a buscar
 * \return contador
 *
 */

int contadorOrquesta(Orquesta* arrayOrquesta,int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int cantOrquestas=0;
    if(arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        for(i=0; i<limiteOrquesta; i++)
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

/** \brief cunta musicos segun idOrquesta
 *
 * \param pauntero a orquesta,
 * \param limite del array
 * \return contador
 *
 */

int contador_musicosByOrquesta(Musico* arrayMusico,int limiteMusico,int idOrquesta)
{
    int retorno =-1;
    int i;
    int contMusicosByOrquesta=0;

    if(arrayMusico!=NULL && limiteMusico>0)
    {
        for(i=0; i<limiteMusico; i++)
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

/** \brief contador de orquestas segun tipo
 *
 * \param puntero a orquesta, limite del array
 * \param tipo de orquesta a contar
 * \return contador
 *
 */

int contador_orquestaByTipo(Orquesta* arrayOrquesta,int limiteOrquesta,int tipo)
{
    int retorno=-1;
    int i;
    int contOrqByTipo=0;
    if(arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        for(i=0; i<limiteOrquesta; i++)
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

/** \brief cuneta intrumentos segun el tipo
 *
 * \param puntero a instrumento, limite del array
 * \param tipo de instrumento a contar
 * \return contador
 *
 */

int contador_instrumentosByTipo(Instrumento* arrayInstrumento,int limiteInstrumento,int tipo)
{
    int retorno=-1;
    int i;
    int contInst=0;
    if(arrayInstrumento!=NULL && limiteInstrumento>0)
    {
        for(i=0; i<limiteInstrumento; i++)
        {
            if(arrayInstrumento[i].isEmpty==0 && arrayInstrumento[i].tipo==tipo)
            {
                contInst++;
            }
        }
        retorno=contInst;
    }
    return retorno;
}

/** \brief cuenta la cantidad de musicos
 *
 * \param puntero  musico
 * \param limite del array musico
 * \return contador
 *
 */

int contador_musicos(Musico* arrayMusico, int limiteMusico)
{
    int retorno=-1;
    int i;
    int cantMusicos=0;
    if(arrayMusico!=NULL && limiteMusico>0)
    {
        for(i=0; i<limiteMusico; i++)
        {
            if(!arrayMusico[i].isEmpty)
            {
                cantMusicos++;
            }
        }
        retorno=cantMusicos;
    }
    return retorno;
}


/** \brief Informa la orquesta con mas musicos
 *
 * \param puntero a orquesta, limite del array orquesta
 * \param puntero a musico, limite del array musico
 * \return [0] si ok, [-1] si error
 *
 */

int informe_OrquestaMasMusicos(Orquesta* arrayOrquesta, int limiteOrquesta,
                               Musico* arrayMusico, int limiteMusico)
{
    int retorno=-1;
    int i;
    int j;
    int IndiceOrquesta;
    int cantMusicos;
    int masMusicos=0;


    if((arrayOrquesta!=NULL && limiteOrquesta>0) && (arrayMusico!=NULL && limiteMusico>0))
    {
        retorno = 0;
        for(i=0; i<limiteOrquesta; i++)
        {
            if(!arrayOrquesta[i].isEmpty)
            {
                cantMusicos= 0;
                for(j=0; j<limiteMusico; j++)
                {
                    retorno = 0;
                    if(!arrayMusico[j].isEmpty && arrayMusico[j].idOrquesta == arrayOrquesta[i].idOrquesta)
                    {
                        cantMusicos++;
                    }
                }
                if(cantMusicos>masMusicos)
                {
                    masMusicos = cantMusicos;
                    IndiceOrquesta = i;
                }
            }

        }
        orquesta_mostrarPorId(arrayOrquesta,limiteOrquesta,IndiceOrquesta);
        printf("Tiene %d musicos\n",masMusicos);
    }
return retorno;
}





/** \brief Informa musicos de mas de 30 años
 *
 * \param puntero a musico
 * \param limite del array musico
 * \return [0] si ok, [-1] si error
 *
 */

int informar_musicosEdadMasTreinta(Musico* arrayMusico, int limiteMusico)
{
    int retorno=-1;
    int i;

    if(arrayMusico!=NULL && limiteMusico>0)
    {
        for(i=0; i<limiteMusico; i++)
        {
            if(!arrayMusico[i].isEmpty && arrayMusico[i].edad>30)
            {
                retorno=0;
                printf("\nId: %d Nombre: %s Apellido: %s Edad: %d Orquesta: %d Instrumento: %d \n",
                       arrayMusico[i].idMusico,
                       arrayMusico[i].nombre,
                       arrayMusico[i].apellido,
                       arrayMusico[i].edad,
                       arrayMusico[i].idOrquesta,
                       arrayMusico[i].idInstrumento);
            }
        }
    }
    return retorno;
}

/** \brief Informa las orquesta segun por lugar
 *
 * \param puntero a orquesta, limite  del array orquesta
 * \param puntero al lugar
 * \return [0] si ok, [-1] si error
 *
 */

int informar_orquestaByLugar(Orquesta* arrayOrquesta, int limiteOrquesta, char* lugar)
{
    int retorno=-1;
    int i;
    if(arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        for(i=0; i<limiteOrquesta; i++)
        {
            if(!arrayOrquesta[i].isEmpty)
            {
                if(!strcmp(arrayOrquesta[i].lugar,lugar))
                {
                    retorno=0;
                    printf("\nId:  %d Nombre: %s Tipo: %d\n",
                           arrayOrquesta[i].idOrquesta,
                           arrayOrquesta[i].nombre,
                           arrayOrquesta[i].tipo);
                }
            }
        }

    }
    return retorno;
}

/** \brief informa las orquestas con mas de 5 musicos
 *
 * \param puntero a musico, limite del array musico
 * \param puntero a orquesta, limite del array orquesta
 * \return [0] si ok, [-1] si error
 *
 */

int informar_orquestaMasCinco(Musico* arrayMusico, int limiteMusico,
                              Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int contadorMusicos;


    if((arrayMusico!=NULL && limiteMusico>0)&&(arrayOrquesta!=NULL && limiteOrquesta>0))
    {
        for(i=0; i<limiteOrquesta; i++)
        {
            if(!arrayMusico[i].isEmpty)
            {
                contadorMusicos=contador_musicosByOrquesta(arrayMusico,limiteMusico,arrayMusico[i].idOrquesta);
                if(contadorMusicos>5)
                {
                    retorno=0;
                    printf("\nId: %d Nombre: %s Lugar: %s Tipo: %d\n",arrayOrquesta[i].idOrquesta,
                           arrayOrquesta[i].nombre,
                           arrayOrquesta[i].lugar,
                           arrayOrquesta[i].tipo);
                }
            }
        }
    }
    return retorno;
}

/** \brief informas las orquestas completas
 *
 * \param puntero a orquesta, puntero a musico, puntero a instrumanto
 * \param limite del array orquesta, limite del array musico, limite del array instrumento
 * \return [0] si ok, [-1] si error
 *
 */

int informar_orquestaCompleta(Orquesta* arrayOrquesta,int limiteOrquesta,
                             Musico* arrayMusico,int limiteMusico,
                             Instrumento* arrayInstrumento,int limiteInstrumento)
{
    int retorno=-1;
    int cuerda=0;
    int percusion=0;
    int viento=0;
    int auxIndice;
    int i;
    int j;

    if((arrayOrquesta!=NULL && limiteOrquesta>0) && (arrayMusico!=NULL && limiteMusico>0) && (arrayInstrumento!=NULL && limiteInstrumento>0))
    {
        for(i=0; i<limiteOrquesta; i++)
        {
            if(!arrayOrquesta[i].isEmpty)
            {
                for(j=0; j<limiteMusico; j++)
                {
                    if(!arrayMusico[j].isEmpty && arrayOrquesta[i].idOrquesta==arrayMusico[i].idOrquesta)
                    {
                        instrumento_buscarPorId(arrayInstrumento,limiteInstrumento,&auxIndice);
                        switch(arrayInstrumento[auxIndice].tipo)
                        {
                        case 1:
                            cuerda++;
                            break;
                        case 2:
                        case 3:
                            viento++;
                            break;
                        case 4:
                            percusion++;
                            break;
                        }
                    }
                }
                if(cuerda>=5 && viento>=3 && percusion>=2)
                {
                    retorno=0;
                    printf("Id: %d - Nombre: %s - Lugar: %s - tipo: %s",arrayOrquesta[i].idOrquesta,
                           arrayOrquesta[i].nombre,
                           arrayOrquesta[i].lugar,
                           arrayOrquesta[i].tipo);
                }
            }
        }
    }
    return retorno;
}

/** \brief Informa promedio de musicos
 *
 * \param puntero a orquesta, limite del array orquesta
 * \param puntero a musico, limite del array Musico
 * \return [0] si ok, [-1] si error
 *
 */

int informar_promedioMusicos(Orquesta* arrayOrquesta,int limiteOrquesta,
                             Musico* arrayMusico,int limiteMusico)
{
    int retorno=-1;
    int cantMusicos;
    int cantOrquestas;

    if((arrayOrquesta!=NULL && limiteOrquesta>0) && (arrayMusico!=NULL && limiteMusico>0))
    {
        cantMusicos=contador_musicos(arrayMusico,limiteMusico);
        cantOrquestas=contadorOrquesta(arrayOrquesta,limiteOrquesta);
        if(cantOrquestas==0)
        {
            printf("\nERROR\n");
            retorno=-1;
        }
        else
        {
            retorno=0;
            printf("\nEl promedio de musicos es de: %.2f",(float)cantMusicos/cantOrquestas);
        }
    }

    return retorno;
}

/** \brief Informa musicos segun orquesta
 *
 * \param puntero a orquesta, limite del array orquesta
 * \param puntero a musico, limite del array musico
 * \param id de la orquesta a buscar
 * \return [0] si ok, [-1] si error
 *
 */

int informar_musicosPorOrquesta(Orquesta* arrayOrquesta,int limiteOrquesta,
                                Musico* arrayMusico,int limiteMusico,
                                int id)
{
    int retorno=-1;
    if((arrayOrquesta!=NULL && limiteOrquesta>0) && (arrayMusico!=NULL && limiteMusico>0))
    {
        retorno=0;
        orquesta_mostrarPorId(arrayOrquesta,limiteOrquesta,id);
        musico_mostrarPorOrquesta(arrayMusico,limiteMusico,id);
    }
    return retorno;
}

/** \brief Informa musicos con instrumentos de cuerda
 *
 * \param puntero a musico, limite del array musico
 * \param puntero a instrumento, limite del array instrumento
 * \return [0] si ok, [-1] si error
 *
 */

int informar_musicosCuerda(Musico* arrayMusico,int limiteMusico,
                           Instrumento* arrayInstrumento,int limiteInstrumento)
{
    int retorno=-1;
    int auxIndice;
    int i;

    if((arrayMusico!=NULL && limiteMusico>0) && (arrayInstrumento!=NULL && limiteInstrumento>0))
    {
        musico_ordenarApellido(arrayMusico,limiteMusico,1);
        for(i=0; i<limiteMusico; i++)
        {

            if(!arrayMusico[i].isEmpty)
            {
                instrumento_buscarPorId(arrayInstrumento,limiteInstrumento,&auxIndice);
                if(arrayInstrumento[auxIndice].tipo==1)
                {
                    retorno=0;
                    printf("\nId: %d Nombre: %s Apellido: %s Edad: %d Orquesta: %d \n",arrayMusico[auxIndice].idMusico,
                           arrayMusico[auxIndice].nombre,
                           arrayMusico[auxIndice].apellido,
                           arrayMusico[auxIndice].edad,
                           arrayMusico[auxIndice].idOrquesta);
                }
            }
        }
    }

    return retorno;
}
