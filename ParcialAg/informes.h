#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

//informar_musicosByOrquesta(Orquesta* arrayOrquesta, int limiteOrquesta,Musico* arrayMusico,int limiteMusico);
//int informar_musicosByOrquesta(Orquesta* arrayOrquesta,int limiteOrquesta,Musico* arrayMusico,intlimiteMusico);
int contadorOrquesta(Orquesta* arrayOrquesta,int limiteOrquesta);
//int contador_musicosByOrquesta(Musico* arrayMusico,int limiteMusico);
int contador_orquestaByTipo(Orquesta* arrayOrquesta,int limiteOrquesta,int tipo);
int contador_instrumentosByTipo(Instrumento* arrayInstrumento,int limiteInstrumento,int tipo);
int contador_musicos(Musico* arrayMusico, int limiteMusico);
int informe_OrquestaMasMusicos(Orquesta* arrayOrquesta, int limiteOrquesta,Musico* arrayMusico, int limiteMusico);
int informar_musicosEdadMasTreinta(Musico* arrayMusico, int limiteMusico);
int informar_orquestaByLugar(Orquesta* arrayOrquesta, int limiteOrquesta, char* lugar);
int informar_orquestaMasCinco(Musico* arrayMusico, int limiteMusico,Orquesta* arrayOrquesta, int limiteOrquesta);
int informar_orquestaCompleta(Orquesta* arrayOrquesta,int limiteOrquesta,Musico* arrayMusico,int limiteMusico,Instrumento* arrayInstrumento,int limiteInstrumento);
int informar_promedioMusicos(Orquesta* arrayOrquesta,int limiteOrquesta,Musico* arrayMusico,int limiteMusico);
int informar_musicosPorOrquesta(Orquesta* arrayOrquesta,int limiteOrquesta,Musico* arrayMusico,int limiteMusico,int id);
int informar_musicosCuerda(Musico* arrayMusico,int limiteMusico,Instrumento* arrayInstrumento,int limiteInstrumento);

#endif // INFORMES_H_INCLUDED
