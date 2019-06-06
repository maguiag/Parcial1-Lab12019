#include <stdio.h>
//#include <stdio_ext.h>
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
 * \return int [0] OK [-1] ERROR
 *
 */

int instrumento_init(Instrumento* arrayInstrumento,int limiteInstrumento)
{
    int retorno=-1;
    int i;
    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        retorno=0;
        for(i=0; i<limiteInstrumento; i++)
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
 * \return int [0] OK [-1] ERROR
 *
 */
int instrumento_mostrarPorId(Instrumento* arrayInstrumento,int limiteInstrumento,int idInstrumento)
{
    int retorno=-1;
    int i;
    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        retorno=0;
        for(i=0; i<limiteInstrumento; i++)
        {
            if(!arrayInstrumento[i].isEmpty && arrayInstrumento[i].idInstrumento==idInstrumento)
                printf("[RELEASE] IdI: %d  Nombre: %s  Tipo: %d \n",
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
 * \return int [0] OK [-1] ERROR
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

                if(!getValidInt("\nIngrese tipo: 1.cuerdas 2.viento-madera 3.viento-metal 4.percusion","\nDebe tener solo numeros",&auxTipo,0,6,2))
                {
                    retorno=0;
                    strcpy(arrayInstrumento[i].nombre,auxNombre);
                    arrayInstrumento[i].tipo=auxTipo;
                    arrayInstrumento[i].idInstrumento=proximoId();
                    arrayInstrumento[i].isEmpty=0;
                    printf("[RELEASE] El IdInstrumento es: %d\n",arrayInstrumento[i].idInstrumento);
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
 * \return int [0] OK [-1] ERROR
 *
 */
int instrumento_baja(Instrumento* arrayInstrumento,int limiteInstrumento,int idInstrumento)
{
    int retorno=-1;
    int i;
    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        retorno = -2;
        for(i=0; i<limiteInstrumento; i++)
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
 * \return int [0] OK [-1] ERROR
 *
 */
int instrumento_modificacion(Instrumento* arrayInstrumento,int limiteInstrumento,int idInstrumento)
{
    int retorno=-1;
    int i;
    char auxNombre[51];
    int auxTipo;

    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        retorno=-2;
        for(i=0; i<limiteInstrumento; i++)
        {
            if(!arrayInstrumento[i].isEmpty && arrayInstrumento[i].idInstrumento==idInstrumento)
            {
                if(!getValidString("\nIngrese nombre: \n","\nNo es un nombre","El maximo es 50",auxNombre,50,2))
                {
                    if(!getValidInt("\nIngrese tipo: \n","\nDebe tener solo numeros",&auxTipo,0,6,2))
                    {
                        retorno=0;
                        strcpy(arrayInstrumento[i].nombre,auxNombre);
                        arrayInstrumento[i].tipo=auxTipo;
                        arrayInstrumento[i].idInstrumento=proximoId();
                        arrayInstrumento[i].isEmpty=0;
                        printf("[RELEASE] El IdInstrumento es: %d\n",arrayInstrumento[i].idInstrumento);
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
 * \return int [0] OK [-1] ERROR
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
            for(i=0; i<limiteInstrumento-1; i++)
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
        }
        while(flagSwap);
    }
    return retorno;
}

/** \brief Busca el lugar libre en el array de instrumentos
 *
 * \param array Instrumento* puntero al array
 * \param limite int limite definido para el instrumento
 * \return int [0] OK [-1] ERROR
 *
 */
static int buscarLugarLibre(Instrumento* arrayInstrumento,int limiteInstrumento)
{
    int retorno = -1;
    int i;
    if(limiteInstrumento> 0 && arrayInstrumento!=NULL)
    {
        for(i=0; i<limiteInstrumento; i++)
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
 * \return int [0] OK, [-1] ERROR
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
            arrayInstrumento[i].tipo=tipo;
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
 * \return int retorna un entero que corresponde a la posicion en la que se encuentra ese Id, [-1] si error
 *
 */
int instrumento_buscarPorId(Instrumento* arrayInstrumento,int limiteInstrumento,int idInstrumento)
{
    int retorno=-1;
    int i;
    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        retorno=-2;
        for(i=0; i<limiteInstrumento; i++)
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


/**
** \brief Muestra instrumento
 * \param array Instrumento* puntero al array
 * \param limite int limite definido para el instrumento
 * \param
 * \return int [0] OK, [-1] ERROR
 *
 */
int instrumento_mostrar(Instrumento* arrayInstrumento,int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int auxTipo;

    if(limiteInstrumento>0 && arrayInstrumento!=NULL)
    {
        retorno=0;
        for(i=0; i<limiteInstrumento; i++)
        {
            if(!arrayInstrumento[i].isEmpty)
            {
               auxTipo=arrayInstrumento[i].tipo;
                switch(auxTipo)
                {
                    case 1:
                        printf("\nCuerdas \n");
                        break;
                    case 2:
                        printf("\nViento-madera \n");
                        break;
                    case 3:
                        printf("\nViento-metal \n");
                        break;
                    case 4:
                        printf("\nPercusion \n");
                        break;
                }
                printf("[RELEASE] IdI: %d  Nombre: %s  Tipo: %d \n",
                                                   arrayInstrumento[i].idInstrumento,
                                                   arrayInstrumento[i].nombre,
                                                   auxTipo);
            }
        }
    }
    return retorno;
}

/** \brief Busca instrumentos segun el tipo
 *
 * \param puntero a Intrumento, limite definido para instrumento
 * \param tipo de instrumento a buscar
 * \return entero que corresponde a la posicion del Id, [-1] [-2] si error
 *
 */

int instrumento_buscarPorTipo(Instrumento* arrayInstrumento,int limiteInstrumento,int tipo)
{
    int retorno=-1;
    int i;
    if(arrayInstrumento!=NULL && limiteInstrumento>0)
    {
        retorno=-2;
        for(i=0;i<limiteInstrumento;i++)
        {
            if(!arrayInstrumento[i].isEmpty && arrayInstrumento[i].tipo==tipo)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
