#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED
typedef struct
{

    char nombre[51];
    int tipo;
    int idInstrumento;
    int isEmpty;

}Instrumento;


int instrumento_init(Instrumento* arrayInstrumento,int limiteInstrumento);
int instrumento_mostrar(Instrumento* arrayInstrumento, int limiteInstrumento);
int instrumento_mostrarPorId(Instrumento* arrayInstrumento,int limiteInstrumento,int idInstrumento);
//int instrumento_mostrarDebug(Instrumento* arrayInstrumento,int limiteInstrumento);
int instrumento_alta(Instrumento* arrayCLiente,int limiteInstrumento);
int instrumento_baja(Instrumento* arrayInstrumento,int limiteClienete,int idInstrumento);
int instrumento_modificacion(Instrumento* arrayInstrumento,int limiteInstrumento,int idInstrumento);
int instrumento_ordenar(Instrumento* arrayInstrumento,int limiteInstrumento,int orden);
int instrumento_altaForzada(Instrumento* arrayInstrumento,int limiteInstrumento,char* nombre,int tipo);
int instrumento_buscarPorId(Instrumento* arrayInstrumento,int limiteInstrumento,int idInstrumento);



#endif // INSTRUMENTO_H_INCLUDED
