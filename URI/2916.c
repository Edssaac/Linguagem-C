#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int comparar(const void *a, const void *b)
{
    if ( *(int*)a > *(int*)b ) ///Se o primeiro elemento for maior que o segundo;
        return -1;
    else if ( *(int*)a < *(int*)b ) ///Se o segundo elemento for maior o primeiro;
        return 1;
    else return 0; /// Se forem iguais;
}


int main()
{
    int qNotas, qMaiores, i, j;
    int *nota;
    long long total;

    while ( scanf("%d %d", &qNotas, &qMaiores) != EOF ) ///Enquanto n�o for fim-de-arquivo:
    {
        nota = (int *) malloc(qNotas * sizeof(int)); ///Criando um vetor din�mico;

        for ( i=0; i<qNotas; i++ ) ///Lendo cada um nos valores a serem inseridos na entrada:
        {
            scanf("%d", &nota[i] );
        }

        qsort(nota, qNotas, sizeof(int), comparar); ///Realizando a compara��o e ordenando;

        total=0;
        for ( i=0; i<qMaiores; i++) ///Somando os qMaiores elementos desejados;
        {
            total += nota[i];
            //printf("%d\n", nota[i]);
        }

        total %= 1000000007; ///Pegando o resultado pelo m�dulo de 10**9 + 7;

        printf("%lld\n", total); ///Imprimindo a resposta calculada;
        free(nota); ///Liberando o espa�o da mem�ria usado parar criar o vetor;
    }

    return 0;
}


