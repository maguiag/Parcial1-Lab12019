#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "musico.h"
#include "utn.h"

static int proximoId();
static int buscarLugarLibre(Musico* arrayMusico,int limiteMusico);


/** \brief Inicializa la estructura musicos
 * \param array Musico* puntero a array
 * \param limite int limite definido para la estructura musico
 * \return int [0] OK [1] ERROR
 *
 */

int musico_init(Musico* arrayMusico,int limiteMusico)
{
    int retorno=-1;
    int i;
    if(limiteMusico>0 && arrayMusico!=NULL)
    {
        retorno=0;
        for(i=0;i<limiteMusico;i++)
        {
            arrayMusico[i].isEmpty=1;
        }
    }
    return retorno;
}



/** \brief Muestra musico a partir del IdMusico que recibe
 *
 * \param array Musico* puntero al array
 * \param limite int limite definido para musico
 * \param idMusico int ID del musico que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int musico_mostrarPorId(Musico* arrayMusico,int limiteMusico,int idMusico)
{
    int retorno=-1;
    int i;
    if(limiteMusico>0 && arrayMusico!=NULL)
    {
        retorno=0;
        for(i=0;i<limiteMusico;i++)
        {
            if(!arrayMusico[i].isEmpty && arrayMusico[i].idMusico==idMusico)
            printf("[RELEASE] -ID: %d -NOMBRE: %s -APELLIDO: %s -EDAD: %d -IdOrquesta: %d -idInstrumento\n",
                                    arrayMusico[i].idMusico,
                                    arrayMusico[i].nombre,
                                    arrayMusico[i].apellido,
                                    arrayMusico[i].edad,
                                    arrayMusico[i].idOrquesta,
                                    arrayMusico[i].idInstrumento);
        }
    }
    return retorno;
}

/** \brief Da de alta al musico
 *
 * \param array Musico* puntero al array
 * \param limite int limite definido para Musico
 * \return int [0] OK [1] ERROR
 *
 */
int musico_alta(Musico* arrayMusico,int limiteMusico)
{
    int retorno=-1;
    int i;
    char auxNombre[51];
    char auxApellido[51];
    int auxEdad;
    int auxIdOrquesta;
    int auxIdInstrumento;

    if(limiteMusico>0 && arrayMusico!=NULL)
    {
        i=buscarLugarLibre(arrayMusico,limiteMusico);
        if(i>=0)
        {
            if(!getValidString("\nIngrese nombre: ","\nNo es un nombre","El maximo es 50",auxNombre,50,2))
            {
                if(!getValidString("\nIngrese el apellido: ","\nNo es un apellido","El maximo es de 50",auxApellido,50,2))
                {
                    if(!getValidInt("\nIngrese Edad: ","\nDebe tener solo numeros",auxEdad,5,99,2))
                    {
                       if(!getValidInt("\nIngrese Id Orquesta: ","\nSolo numeros",auxIdOrquesta,1,6,2))
                       {
                        if(!getValidInt("\nIngrese Id Instrumento: ","\nSolo numeros",auxIdInstrumento,1,6,2))

                        retorno=0;
                        strcpy(arrayMusico[i].nombre,auxNombre);
                        strcpy(arrayMusico[i].apellido,auxApellido);
                        strcpy(arrayMusico[i].edad,auxEdad);
                        strcpy(arrayMusico[i].idOrquesta,auxIdOrquesta);
                        strcpy(arrayMusico[i].idInstrumento,auxIdInstrumento);
                        arrayMusico[i].idMusico=proximoId();
                        arrayMusico[i].isEmpty=0;
                        printf("El IdMusico es: %d\n",arrayMusico[i].idMusico);
                       }

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


/** \brief Da de baja al musico por el ID
 *
 * \param array Musico* puntero al array
 * \param limite int limite definido para musico
 * \param idMusico int Id del musico que estoy buscando
 * \return int [0] OK [1] ERROR
 *
 */
int musico_baja(Musico* arrayMusico,int limiteMusico,int idMusico)
{
    int retorno=-1;
    int i;
    if(limiteMusico>0 && arrayMusico!=NULL)
    {
        retorno = -2;
        for(i=0;i<limiteMusico;i++)
        {
            if(!arrayMusico[i].isEmpty && arrayMusico[i].idMusico==idMusico)
            {
                arrayMusico[i].isEmpty=1;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Modifica al musico a partir de su Id
 *
 * \param array Musico* puntero al array
 * \param limite int limite definido para el musico
 * \param idMusico int Id del musico buscado
 * \return int [0] OK [1] ERROR
 *
 */
int musico_modificacion(Musico* arrayMusico,int limiteMusico,int idMusico)
{
    int retorno=-1;
    int i;
    int auxEdad;
    int auxIdOrquesta;

    if(limiteMusico>0 && arrayMusico!=NULL)
    {
        retorno=-2;
        for(i=0;i<limiteMusico;i++)
        {
            if(!arrayMusico[i].isEmpty && arrayMusico[i].idMusico==idMusico)
            {
                if(!getValidInt("\nIngrese edad: ","\nSolo numeros",auxEdad,5,99,2))
                {
                    if(!getValidInt("\nIngrese IdOrquesta: ","\nSolo numeros",auxIdOrquesta,1,6,2))
                    {

                            retorno=0;
                            strcpy(arrayMusico[i].edad,auxEdad);
                            strcpy(arrayMusico[i].idOrquesta,auxIdOrquesta);
                            arrayMusico[i].idMusico=proximoId();
                            arrayMusico[i].isEmpty=0;

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


/** \brief Busca el lugar libre en el array de musicos
 *
 * \param array Musico* puntero al array
 * \param limite int limite definido para el musico
 * \return int [0] OK [1] ERROR
 *
 */
static int buscarLugarLibre(Musico* arrayMusico,int limiteMusico)
{
    int retorno = -1;
    int i;
    if(limiteMusico> 0 && arrayMusico!=NULL)
    {
        for(i=0;i<limiteMusico;i++)
        {
            if(arrayMusico[i].isEmpty==1)
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

/** \brief Fuerza el alta de musico
 *
 * \param array Musico* puntero al array
 * \param limite int limite definido para el array
 * \param nombre char* fuerza el nombre
 * \param apellido char* fuerza el apellido
 * \param cuit char* fuerza el cuit
 * \return int [0] OK [1] ERROR
 *
 */
int musico_altaForzada(Musico* arrayMusico,int limiteMusico,char* nombre,char* apellido,int edad, int idOrquesta,int idInstrumento)
{
    int retorno=-1;
    int i;

    if(limiteMusico>0 && arrayMusico!=NULL)
    {
        i=buscarLugarLibre(arrayMusico,limiteMusico);
        if(i>=0)
        {
            retorno=0;
            strcpy(arrayMusico[i].nombre,nombre);
            strcpy(arrayMusico[i].apellido,apellido);
            strcpy(arrayMusico[i].edad,edad);
            strcpy(arrayMusico[i].idOrquesta,idOrquesta);
            strcpy(arrayMusico[i].instrumento,instrumento);
            arrayMusico[i].idMusico=proximoId();
            arrayMusico[i].isEmpty=0;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief retorna un entero que corresponde a la posicion del Id
 *
 * \param array Musico* puntero al array
 * \param limite int limite definido para musico
 * \param idMusico int id del musico buscado
 * \return int retorna un entero que corresponde a la posicion en la que se encuentra ese Id
 *
 */
int musico_buscarPorId(Musico* arrayMusico,int limiteMusico,int idMusico)
{
    int retorno=-1;
    int i;
    if(limiteMusico>0 && arrayMusico!=NULL)
    {
        retorno=-2;
        for(i=0;i<limiteMusico;i++)
        {
            if(!arrayMusico[i].isEmpty && arrayMusico[i].idMusico==idMusico)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}


