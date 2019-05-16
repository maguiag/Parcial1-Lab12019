#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"
#include "utn.h"

static int proximoId();
static int buscarLugarLibre(Instrumento* arrayInstrumento,int limiteInstrumento);


/** \brief Inicializa la estructura instrumentos
 * \param array Instrumento* puntero a array
 * \param limite int limite definido para la estructura instrumento
 * \return int [0] OK [1] ERROR
 *
 */

int instrumento_init(Instrumento* arrayInstrumento,int limiteInstrumento)
{
    int retorno=-1;
    int i;
    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        retorno=0;
        for(i=0;i<limiteInstrumento;i++)
        {
            arrayInstrumento[i].isEmpty=1;
        }
    }
    return retorno;
}



/** \brief Muestra instrumento a partir del IdInstrumento que recibe
 *
 * \param array Instrumento* puntero al array
 * \param limite int limite definido para instrumento
 * \param idInstrumento int ID del instrumento que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int instrumento_mostrarPorId(Instrumento* arrayInstrumento,int limiteInstrumento,int idInstrumento)
{
    int retorno=-1;
    int i;
    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        retorno=0;
        for(i=0;i<limiteInstrumento;i++)
        {
            if(!arrayInstrumento[i].isEmpty && arrayInstrumento[i].idInstrumento==idInstrumento)
            printf("[RELEASE] -ID.INSTRUMENTO: %d -NOMBRE: %s -TIPO: %d %s\n",
                                    arrayInstrumento[i].idInstrumento,
                                    arrayInstrumento[i].nombre,
                                    arrayInstrumento[i].tipo);
        }
    }
    return retorno;
}

/** \brief Da de alta al instrumento
 *
 * \param array Instrumento* puntero al array
 * \param limite int limite definido para Instrumento
 * \return int [0] OK [1] ERROR
 *
 */
int instrumento_alta(Instrumento* arrayInstrumento,int limiteInstrumento)
{
    int retorno=-1;
    int i;
    char auxNombre[51];
    int auxTipo;

    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        i=buscarLugarLibre(arrayInstrumento,limiteInstrumento);
        if(i>=0)
        {
            if(!getValidString("\nIngrese nombre: ","\nNo es un nombre","El maximo es 50",auxNombre,50,2))
            {

                    if(!getValidInt("\nIngrese tipo: ","\nDebe tener solo numeros",auxTipo,0,6,2))
                    {
                        retorno=0;
                        strcpy(arrayInstrumento[i].nombre,auxNombre);
                        strcpy(arrayInstrumento[i].tipo,auxTipo);
                        arrayInstrumento[i].idInstrumento=proximoId();
                        arrayInstrumento[i].isEmpty=0;
                        printf("El IdInstrumento es: %d\n",arrayInstrumento[i].idInstrumento);
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


/** \brief Da de baja al instrumento por el ID
 *
 * \param array Instrumento* puntero al array
 * \param limite int limite definido para instrumento
 * \param idInstrumento int Id del instrumento que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int instrumento_baja(Instrumento* arrayInstrumento,int limiteInstrumento,int idInstrumento)
{
    int retorno=-1;
    int i;
    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        retorno = -2;
        for(i=0;i<limiteInstrumento;i++)
        {
            if(!arrayInstrumento[i].isEmpty && arrayInstrumento[i].idInstrumento==idInstrumento)
            {
                arrayInstrumento[i].isEmpty=1;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Modifica al instrumento a partir de su Id
 *
 * \param array Instrumento* puntero al array
 * \param limite int limite definido para el instrumento
 * \param idInstrumento int Id del instrumento buscado
 * \return int [0] OK [1] ERROR
 *
 */
int instrumento_modificacion(Instrumento* arrayInstrumento,int limiteInstrumento,int idInstrumento)
{
    int retorno=-1;
    int i;
    char auxNombre[51];
    char auxApellido[51];
    char auxCuit[12];

    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        retorno=-2;
        for(i=0;i<limiteInstrumento;i++)
        {
            if(!arrayInstrumento[i].isEmpty && arrayInstrumento[i].idInstrumento==idInstrumento)
            {
                if(!getValidString("\nIngrese nombre: ","\nNo es un nombre","El maximo es 50",auxNombre,50,2))
                {
                    if(!getValidString("\nIngrese apellido: ","\nNo es un apellido","El maximo es de 50",auxApellido,50,2))
                    {
                        if(!getValidInt("\nIngrese CUIT: ","\nDebe tener solo numeros","El maximo es de 11",auxCuit,12,2))
                        {
                            retorno=0;
                            strcpy(arrayInstrumento[i].nombre,auxNombre);
                            strcpy(arrayInstrumento[i].apellido,auxApellido);
                            strcpy(arrayInstrumento[i].cuit,auxCuit);
                            arrayInstrumento[i].idInstrumento=proximoId();
                            arrayInstrumento[i].isEmpty=0;
                        }
                    }
                }
                else
                {
                    retorno=-3;
                }
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Ordena a los instrumentos de menor a mayo o de mayor a menor segun el "orden"
 *
 * \param array Instrumento* puntero al array
 * \param limite int limite definido para el instrumento
 * \param orden int [1] de menor a mayor, [0] de mayor a menor
 * \return int [0] OK [1] ERROR
 *
 */
int instrumento_ordenar(Instrumento* arrayInstrumento,int limiteInstrumento,int orden)
{
    int retorno=-1;
    int i;
    int flagSwap;
    Instrumento auxiliarEstructura;

    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        do
        {
            flagSwap=0;
            for(i=0;i<limiteInstrumento-1;i++)
            {
                if(!arrayInstrumento[i].isEmpty && !arrayInstrumento[i+1].isEmpty)
                {
                    if((strcmp(arrayInstrumento[i].nombre,arrayInstrumento[i+1].nombre)>0 && orden) || (strcmp(arrayInstrumento[i].nombre,arrayInstrumento[i+1].nombre)<0 && !orden)) //******
                    {
                        auxiliarEstructura=arrayInstrumento[i];
                        arrayInstrumento[i]=arrayInstrumento[i+1];
                        arrayInstrumento[i+1]=auxiliarEstructura;
                        flagSwap=1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

/** \brief Busca el lugar libre en el array de instrumentos
 *
 * \param array Instrumento* puntero al array
 * \param limite int limite definido para el instrumento
 * \return int [0] OK [1] ERROR
 *
 */
static int buscarLugarLibre(Instrumento* arrayInstrumento,int limiteInstrumento)
{
    int retorno = -1;
    int i;
    if(limiteInstrumento> 0 && arrayInstrumento!=NULL)
    {
        for(i=0;i<limiteInstrumento;i++)
        {
            if(arrayInstrumento[i].isEmpty==1)
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

/** \brief Fuerza el alta de instrumento
 *
 * \param array Instrumento* puntero al array
 * \param limite int limite definido para el array
 * \param nombre char* fuerza el nombre
 * \param apellido char* fuerza el apellido
 * \param cuit char* fuerza el cuit
 * \return int [0] OK [1] ERROR
 *
 */
int instrumento_altaForzada(Instrumento* arrayInstrumento,int limiteInstrumento,char* nombre,int tipo)
{
    int retorno=-1;
    int i;

    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        i=buscarLugarLibre(arrayInstrumento,limiteInstrumento);
        if(i>=0)
        {
            retorno=0;
            strcpy(arrayInstrumento[i].nombre,nombre);
            strcpy(arrayInstrumento[i].tipo,tipo);
            arrayInstrumento[i].idInstrumento=proximoId();
            arrayInstrumento[i].isEmpty=0;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief retorna un entero que corresponde a la posicion del Id
 *
 * \param array Instrumento* puntero al array
 * \param limite int limite definido para instrumento
 * \param idInstrumento int id del instrumento buscado
 * \return int retorna un entero que corresponde a la posicion en la que se encuentra ese Id
 *
 */
int instrumento_buscarPorId(Instrumento* arrayInstrumento,int limiteInstrumento,int idInstrumento)
{
    int retorno=-1;
    int i;
    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        retorno=-2;
        for(i=0;i<limiteInstrumento;i++)
        {
            if(!arrayInstrumento[i].isEmpty && arrayInstrumento[i].idInstrumento==idInstrumento)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

