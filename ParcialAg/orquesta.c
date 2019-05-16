#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "orquesta.h"
#include "utn.h"

static int proximoId();
static int buscarLugarLibre(Orquesta* arrayOrquesta,int limiteOrquesta);


/** \brief Inicializa la estructura orquestas
 * \param array Orquesta* puntero a array
 * \param limite int limite definido para la estructura orquesta
 * \return int [0] OK [1] ERROR
 *
 */

int orquesta_init(Orquesta* arrayOrquesta,int limiteOrquesta)
{
    int retorno=-1;
    int i;
    if(limiteOrquesta>0 && arrayOrquesta!=NULL)
    {
        retorno=0;
        for(i=0;i<limiteOrquesta;i++)
        {
            arrayOrquesta[i].isEmpty=1;
        }
    }
    return retorno;
}


/** \brief Muestra orquesta a partir del IdOrquesta que recibe
 *
 * \param array Orquesta* puntero al array
 * \param limite int limite definido para orquesta
 * \param idOrquesta int ID del orquesta que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int orquesta_mostrarPorId(Orquesta* arrayOrquesta,int limiteOrquesta,int idOrquesta)
{
    int retorno=-1;
    int i;
    if(limiteOrquesta>0 && arrayOrquesta!=NULL)
    {
        retorno=0;
        for(i=0;i<limiteOrquesta;i++)
        {
            if(!arrayOrquesta[i].isEmpty && arrayOrquesta[i].idOrquesta==idOrquesta)
            printf("[RELEASE] -ID: %d -NOMBRE: %s -LUGAR: %s -TIPO: %d\n",
                                                        arrayOrquesta[i].idOrquesta,
                                                        arrayOrquesta[i].nombre,
                                                        arrayOrquesta[i].lugar,
                                                        arrayOrquesta[i].tipo);
        }
    }
    return retorno;
}

/** \brief Da de alta al orquesta
 *
 * \param array Orquesta* puntero al array
 * \param limite int limite definido para Orquesta
 * \return int [0] OK [1] ERROR
 *
 */
int orquesta_alta(Orquesta* arrayOrquesta,int limiteOrquesta)
{
    int retorno=-1;
    int i;
    char auxNombre[51];
    char auxLugar[51];
    int auxTipo;

    if(limiteOrquesta>0 && arrayOrquesta!=NULL)
    {
        i=buscarLugarLibre(arrayOrquesta,limiteOrquesta);
        if(i>=0)
        {
            if(!getValidString("\nIngrese nombre: ","\nNo es un nombre","El maximo es 50",auxNombre,50,2))
            {
                if(!getValidString("\nIngrese el lugar: ","\nNo es un lugar","El maximo es de 50",auxLugar,50,2))
                {
                    if(!getValidInt("\nIngrese tipo de orquesta: ","\nDebe tener solo numeros",auxTipo,1,5,2))
                    {
                        retorno=0;
                        strcpy(arrayOrquesta[i].nombre,auxNombre);
                        strcpy(arrayOrquesta[i].lugar,auxLugar);
                        strcpy(arrayOrquesta[i].tipo,auxTipo);
                        arrayOrquesta[i].idOrquesta=proximoId();
                        arrayOrquesta[i].isEmpty=0;
                        printf("El IdOrquesta es: %d\n",arrayOrquesta[i].idOrquesta);
                    }
                }
            }
            else
            {
                retorno=-3;
            }
        }
        else
        {
            retorno=-2;
        }
    }
    return retorno;
}


/** \brief Da de baja al orquesta por el ID
 *
 * \param array Orquesta* , MUsico*
 * \param limite int limite definido para orquesta y musico
 * \param idOrquesta int Id del orquesta que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int orquesta_baja_musico(Orquesta* arrayOrquesta,int limiteOrquesta,int idOrquesta, Musico* arrayMusico, int limiteMusico)
{
    int retorno=-1;
    int i;
    if(limiteOrquesta>0 && arrayOrquesta!=NULL)
    {
        retorno = -2;
        for(i=0;i<limiteOrquesta;i++)
        {
            if(!arrayOrquesta[i].isEmpty && arrayOrquesta[i].idOrquesta==idOrquesta)
            {
                arrayOrquesta[i].isEmpty=1;
                retorno=0;
                break;
            }
        }
    }
    if(limiteMusico>0 && arrayMusico!=NULL)
    {
        for(i=0; i<limiteMusico;i++)
        {
            retorno=-2;
            if(!arrayMusico[i].isEmpty && arrayMusico[i].idMusico==id)
            {
                arrayMusico[i].isEmpty=1;
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Muestra orquestas
 *
 * \param array Orquesta* puntero al array
 * \param limite int limite definido para el orquesta
 * \param
 * \return int [0] OK [1] ERROR
 *
 */
int orquesta_mostrar(Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
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
        return retorno;
    }
}


/** \brief Busca el lugar libre en el array de orquestas
 *
 * \param array Orquesta* puntero al array
 * \param limite int limite definido para el orquesta
 * \return int [0] OK [1] ERROR
 *
 */
static int buscarLugarLibre(Orquesta* arrayOrquesta,int limiteOrquesta)
{
    int retorno = -1;
    int i;
    if(limiteOrquesta> 0 && arrayOrquesta!=NULL)
    {
        for(i=0;i<limiteOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Incremente el Id al ser llamada
 *
 * \return int retorna el valor correspondiente al proximoId
 *
 */
static int proximoId()
{
    static int proximoId=-1;
    proximoId++;
    return proximoId;
}

/** \brief Fuerza el alta de orquesta
 *
 * \param array Orquesta* puntero al array
 * \param limite int limite definido para el array
 * \param nombre char* fuerza el nombre
 * \param apellido char* fuerza el apellido
 * \param cuit char* fuerza el cuit
 * \return int [0] OK [1] ERROR
 *
 */
int orquesta_altaForzada(Orquesta* arrayOrquesta,int limiteOrquesta,char* nombre,char* lugar,int tipo)
{
    int retorno=-1;
    int i;

    if(limiteOrquesta>0 && arrayOrquesta!=NULL)
    {
        i=buscarLugarLibre(arrayOrquesta,limiteOrquesta);
        if(i>=0)
        {
            retorno=0;
            strcpy(arrayOrquesta[i].nombre,nombre);
            strcpy(arrayOrquesta[i].lugar,lugar);
            strcpy(arrayOrquesta[i].tipo,tipo);
            arrayOrquesta[i].idOrquesta=proximoId();
            arrayOrquesta[i].isEmpty=0;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief retorna un entero que corresponde a la posicion del Id
 *
 * \param array Orquesta* puntero al array
 * \param limite int limite definido para orquesta
 * \param idOrquesta int id del orquesta buscado
 * \return int retorna un entero que corresponde a la posicion en la que se encuentra ese Id
 *
 */
int orquesta_buscarPorId(Orquesta* arrayOrquesta,int limiteOrquesta,int idOrquesta)
{
    int retorno=-1;
    int i;
    if(limiteOrquesta>0 && arrayOrquesta!=NULL)
    {
        retorno=-2;
        for(i=0;i<limiteOrquesta;i++)
        {
            if(!arrayOrquesta[i].isEmpty && arrayOrquesta[i].idOrquesta==idOrquesta)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}


