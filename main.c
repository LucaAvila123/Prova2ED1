#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.h"
#include "palavra.h"

int MaiorOcorrencias(const void* a, const void* b){
    if(RetornaOcorrencias((Palavra*) a) > RetornaOcorrencias((Palavra*) b))
        return 1;
    
    else if(RetornaOcorrencias((Palavra*) a) < RetornaOcorrencias((Palavra*) b))
        return -1;
    
    else
        return 0;
}
int main(){

    FILE* arquivo = fopen("entrada.txt", "r");

    ArvWord* arv = CriaArvorePalavraVazia();
    char* string;

    while(fscanf(arquivo, "%ms", &string) != EOF){
        if((string[strlen(string) - 1] < 'a' || string[strlen(string) - 1] > 'z') && (string[strlen(string) - 1] < 'A' || string[strlen(string) - 1] > 'Z'))
            string[strlen(string) - 1] = '\0';
        
        arv = InsereOuIncrementaNaArvore(arv, string);

        free(string);
    }

    printf("%d %d\n", PalavrasDistintas(arv), TotalPalavras(arv));

    ImprimePalavra(NoMaiorOcorrencia(arv));
    printf("\n");
    ImprimeArvPalavra(arv);
    printf("\n");

    VetorPalavras* vetorPalavras = InicializaVetorPalavras(PalavrasDistintas(arv));
    InsereDaArvoreNoVetor(arv, vetorPalavras);
    qsort(vetorPalavras, PalavrasDistintas(arv), sizeof(Palavra*), MaiorOcorrencias);
    ImprimeVetorPalavras(vetorPalavras);

    LiberaArvPalavra(arv);

    fclose(arquivo);

    return 0;
}