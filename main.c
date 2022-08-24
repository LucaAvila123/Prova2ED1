#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.h"
#include "palavra.h"

int MaiorOcorrencias(const void* a, const void* b){
    Palavra* p1 = *((Palavra**) a);
    Palavra* p2 = *((Palavra**) b);

    int final = RetornaOcorrencias(p1) - RetornaOcorrencias(p2);
    if(final > 0) return 1;
    if(final < 0) return -1;
    if(final == 0) return 0;
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
    // lembre-se de que o tipo vetorPalavras não é um vetor propriamente dito, mas sim um tipo que guarda um vetor, e o qsort não vai ler isso
    // O qsort lê o vetor, não o TAD que o guarda 
    qsort(RetornaArray(vetorPalavras), PalavrasDistintas(arv), sizeof(Palavra*), MaiorOcorrencias);
    ImprimeVetorPalavras(vetorPalavras);

    LiberaArvPalavra(arv);

    fclose(arquivo);

    return 0;
}