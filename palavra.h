#ifndef PALAVRA_H
#define PALAVRA_H

typedef struct palavra Palavra;

typedef struct vetorPalavras VetorPalavras;

Palavra* InicializaPalavra(char* string);

void AumentaOcorrencias(Palavra* palavra);

void LiberaPalavra(Palavra* palavra);

int RetornaOcorrencias(Palavra* palavra);

char* RetornaString(Palavra* palavra);

int StringsIguais(Palavra* palavra, char* string);

void ImprimePalavra(Palavra* palavra);

VetorPalavras* InicializaVetorPalavras(int total);

void InserePalavraVetor(VetorPalavras* vetorPalavras, Palavra* palavra);

void LiberaVetorPalavras(VetorPalavras* vetorPalavras);

void ImprimeVetorPalavras(VetorPalavras* vetorPalavras);

#endif