#ifndef ARVORE_H
#define ARVORE_H

#include "palavra.h"
typedef struct arvPalavras ArvWord;

ArvWord* CriaArvorePalavraVazia(void);

ArvWord* CriaArvorePalavra(char* string, ArvWord* saee, ArvWord* saed);

ArvWord* InsereOuIncrementaNaArvore(ArvWord* arv, char* string);

void LiberaArvPalavra(ArvWord* arv);

void ImprimeArvPalavra(ArvWord* arv);

int PalavrasDistintas(ArvWord* arv);

int TotalPalavras(ArvWord* arv);

Palavra* NoMaiorOcorrencia(ArvWord* arv);

void InsereDaArvoreNoVetor(ArvWord* a, VetorPalavras* vetorPalavras);

#endif