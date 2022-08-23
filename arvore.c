#include "arvore.h"
#include "palavra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvPalavras{
    Palavra* palavra;
    ArvWord* esquerda;
    ArvWord* direita;
};

ArvWord* CriaArvorePalavraVazia(void){
    return NULL;
}

ArvWord* CriaArvorePalavra(char* string, ArvWord* saee, ArvWord* saed){
    ArvWord* arvPalavras = (ArvWord*) calloc (1, sizeof(ArvWord));
    arvPalavras -> palavra = InicializaPalavra(string);

    arvPalavras -> esquerda = saee;
    arvPalavras -> direita  = saed;

    return arvPalavras;
}

ArvWord* InsereOuIncrementaNaArvore(ArvWord* arv, char* string){
    if(arv){
        if(StringsIguais(arv -> palavra, string)){
            AumentaOcorrencias(arv -> palavra);
            return arv;
        }
        if(strcmp(RetornaString(arv -> palavra), string) > 0){
            arv -> esquerda = InsereOuIncrementaNaArvore(arv -> esquerda, string);
            return arv;
        }
        if(strcmp(RetornaString(arv -> palavra), string) < 0){
            arv -> direita = InsereOuIncrementaNaArvore(arv -> direita, string);
            return arv;
        }
    }

    arv = CriaArvorePalavra(string, NULL, NULL);

    return arv;
}

void LiberaArvPalavra(ArvWord* arv){
    if(arv){
        LiberaArvPalavra(arv -> esquerda);
        LiberaArvPalavra(arv -> direita);
        LiberaPalavra(arv -> palavra);
        free(arv);
    }
}

void ImprimeArvPalavra(ArvWord* arv){
    printf("<");
    if(arv){
        ImprimePalavra(arv -> palavra);
        ImprimeArvPalavra(arv -> esquerda);
        ImprimeArvPalavra(arv -> direita);
    }
    printf(">");
}

int PalavrasDistintas(ArvWord* arv){
    if(arv){
        if(!arv -> esquerda && !arv -> direita)
            return 1;
        else
            return PalavrasDistintas(arv -> esquerda) + PalavrasDistintas(arv -> direita) + 1;
        
    }
    return 0;
}

int TotalPalavras(ArvWord* arv){
    if(arv){
        if(!arv -> esquerda && !arv -> direita)
            return RetornaOcorrencias(arv -> palavra);
        else
            return TotalPalavras(arv -> esquerda) + TotalPalavras(arv -> direita) + RetornaOcorrencias(arv -> palavra);

    }
    return 0;
}

static void private_retorna_palavra_maior_frequencia_arvore_palavra(ArvWord* a, Palavra** p){
    if(!a) return;
    // quando p é NULL, já é retornado 0 na sua frequencia
    if(RetornaOcorrencias(a->palavra) > RetornaOcorrencias(*p)){
        *p = a->palavra;
    }
    private_retorna_palavra_maior_frequencia_arvore_palavra(a->esquerda, p);
    private_retorna_palavra_maior_frequencia_arvore_palavra(a->direita,  p);
    return ;
}

Palavra* NoMaiorOcorrencia(ArvWord* arv){
    if(!arv) return NULL;
    Palavra * p = NULL; 
    private_retorna_palavra_maior_frequencia_arvore_palavra(arv, &p);
    return p;

}

void InsereDaArvoreNoVetor(ArvWord* a, VetorPalavras* vetorPalavras){
    if(a && vetorPalavras){
        InserePalavraVetor(vetorPalavras, a -> palavra);
        InsereDaArvoreNoVetor(a -> esquerda, vetorPalavras);
        InsereDaArvoreNoVetor(a -> direita,  vetorPalavras);
    }
}