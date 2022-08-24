#include "palavra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct palavra{
    char* string;
    int ocorrencias;
};

struct vetorPalavras{
    Palavra** vetor;
    int total;
    int indiceAtual;
};

Palavra* InicializaPalavra(char* string){
    Palavra* palavra = (Palavra*) calloc (1, sizeof(Palavra));
    palavra -> string = strdup(string);
    palavra -> ocorrencias = 1;

    return palavra;
}

void AumentaOcorrencias(Palavra* palavra){
    if(palavra)
        palavra -> ocorrencias += 1;
}

void LiberaPalavra(Palavra* palavra){
    if(palavra){
        free(palavra -> string);
        free(palavra);
    }
}

int RetornaOcorrencias(Palavra* palavra){
    if(palavra)
        return palavra -> ocorrencias;
    
    return 0;
}

char* RetornaString(Palavra* palavra){
    if(palavra)
        return palavra -> string;
    
    return NULL;
}

int StringsIguais(Palavra* palavra, char* string){
    if(palavra){
        if(!strcmp(RetornaString(palavra), string))
            return 1;
    }

    return 0;
}

void ImprimePalavra(Palavra* palavra){
    if(palavra)
        printf("Palavra: %s ; Ocorrencias: %d ", RetornaString(palavra), RetornaOcorrencias(palavra));
}

VetorPalavras* InicializaVetorPalavras(int total){
    VetorPalavras* vetorPalavras = (VetorPalavras*) calloc (1, sizeof(VetorPalavras));

    vetorPalavras -> vetor = (Palavra**) calloc (total, sizeof(Palavra*));
    for(int i=0; i < total; i++){
        vetorPalavras -> vetor[i] = (Palavra*) calloc (1, sizeof(Palavra));
    }

    vetorPalavras -> indiceAtual = -1;
    vetorPalavras -> total = total;

    return vetorPalavras;
}

void InserePalavraVetor(VetorPalavras* vetorPalavras, Palavra* palavra){
    if(vetorPalavras && palavra){
        vetorPalavras -> indiceAtual++;
        //significa que ja chegou ao total do vetor e nao pode colocar mais coisa
        if(vetorPalavras -> indiceAtual == vetorPalavras -> total)
            return;
        vetorPalavras -> vetor[vetorPalavras -> indiceAtual] = palavra;
    }
}

void LiberaVetorPalavras(VetorPalavras* vetorPalavras){
    if(vetorPalavras){
        for(int i=0; i<vetorPalavras->total; i++){
            LiberaPalavra(vetorPalavras -> vetor[i]);
        }
        free(vetorPalavras);
    }
}

void ImprimeVetorPalavras(VetorPalavras* vetorPalavras){
    if(vetorPalavras){
        for(int i = 0; i < vetorPalavras -> total; i++){
            ImprimePalavra(vetorPalavras -> vetor[i]);
            printf("\n");
        }
    }
}

Palavra** RetornaArray(VetorPalavras* vetorPalavras){
    return vetorPalavras -> vetor;
}