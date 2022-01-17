#include <stdio.h>
#include <stdlib.h>

int main()
{

    int tamSequencia, altura, qPicos=1;
    int *alturas;

    ///Lendo o tamanho da sequ�ncia da montanha:
    scanf("%d", &tamSequencia);

    ///Criando um vetor din�mico para armazenar o tamamho de cada parte da montanha:
                  ///malloc( quantidadeItens * tamanhoTipoDeDados );
    alturas = (int*) malloc( tamSequencia * sizeof(int) );


    ///Lendo a altura de cada parte:
    for ( altura=0; altura<tamSequencia; altura++ )
    {
        scanf("%d", &alturas[altura]);
    }

    /**
    L�gica:
    como n�o h� n�meros consecutivos iguais, se houver tr�s n�meros consecutivos na sequ�ncia,
    tal que o n�mero do meio � menor do que os outros dois n�meros, ent�o a montanha tem mais de um pico.

    Ou seja: a quantidade de picos j� come�a com 1, por�m se a condi��o aplicada for v�lida,
    ent�o significa que h� mais de um pico na montanha.

    123 = o n�mero do meio (2) n�o � menor que o primeiro (1) nem que o terceiro (3), logo essa montanha tem apenas um pico, no caso o 3.
    825 = o n�mero do meio (2) � menor que o primeiro (8) e menor que o terceiro (5), ent�o a montanha tem dois picos, no caso o 8 e o 5.
    **/

    for ( altura=1; altura<tamSequencia-1; altura++ )
    {
        ///Ai-1 > Ai e Ai < Ai+1
        if ( alturas[altura-1]>alturas[altura] && alturas[altura]<alturas[altura+1] )
        {
            qPicos++;
        }
    }


    printf( (qPicos==1) ? "N\n" : "S\n" );
    free(alturas);

    return 0;
}
