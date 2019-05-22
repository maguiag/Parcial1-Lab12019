#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

informar_musicosByOrquesta(Orquesta* arrayOrquesta, int limiteOrquesta,Musico* arrayMusico,int limiteMusico);

contadorOrquesta(Orquesta* arrayOrquesta, int limiteOrquesta);
contador_musicosByOrquesta(Musico* arrayMusico,int limiteMusico, int idOrquesta);
contador_orquestaByTipo(Orquesta* arrayOrquesta, int limiteOrquesta, int tipo);
contador_instrumentosByTipo(Instrumento* arrayInstrumento, int limiteInstrumento,int tipo);


#endif // INFORMES_H_INCLUDED
