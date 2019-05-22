#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED


typedef struct
{
    int idMusico;
    char nombre[51];
    char apellido[51];
    int edad;
    int idOrquesta;
    int idInstrumento;
    int isEmpty;
}Musico;

int musico_init(Musico* arrayMusico,int limiteMusico);
int musico_mostrar(Musico* arrayMusico, int limiteMusico);
int musico_mostrarPorId(Musico* arrayMusico,int limiteMusico,int idMusico);
//int musico_mostrarDebug(Musico* arrayMusico,int limiteMusico);
int musico_alta(Musico* arrayCLiente,int limiteMusico);
int musico_baja(Musico* arrayMusico,int limiteClienete,int idMusico);
int musico_modificacion(Musico* arrayMusico,int limiteMusico,int idMusico);
//int musico_ordenar(Musico* arrayMusico,int limiteMusico,int orden);
int musico_altaForzada(Musico* arrayMusico,int limiteMusico,char* nombre,char* apellido,int edad, int idOrquesta,int idInstrumento);
int musico_buscarPorId(Musico* arrayMusico,int limiteMusico,int idMusico);


#endif // MUSICO_H_INCLUDED
