#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct
{
    int idOrquesta;
    char nombre[51];
    char lugar[51];
    int tipo[12];
    int isEmpty;
}Orquesta;

int orquesta_init(Orquesta* arrayOrquesta,int limiteOrquesta);
int orquesta_mostrar(Orquesta* arrayOrquesta, int limiteOrquesta);
int orquesta_mostrarPorId(Orquesta* arrayOrquesta,int limiteOrquesta,int idOrquesta);
//int orquesta_mostrarDebug(Orquesta* arrayOrquesta,int limiteOrquesta);
int orquesta_alta(Orquesta* arrayCLiente,int limiteOrquesta);
int orquesta_baja_musico(Orquesta* arrayOrquesta,int limiteOrquesta,int idOrquesta, Musico* arrayMusico, int limiteMusico);//int orquesta_modificacion(Orquesta* arrayOrquesta,int limiteOrquesta,int idOrquesta);
//int orquesta_ordenar(Orquesta* arrayOrquesta,int limiteOrquesta,int orden);
int orquesta_altaForzada(Orquesta* arrayOrquesta,int limiteOrquesta,char* nombre,char* lugar,int tipo)
int orquesta_buscarPorId(Orquesta* arrayOrquesta,int limiteOrquesta,int idOrquesta);


#endif // ORQUESTA_H_INCLUDED
