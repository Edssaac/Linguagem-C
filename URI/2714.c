#include <stdio.h> //Entrada e sa�da padr�o;
#include <string.h> //Usando strlen().
#include <ctype.h> //Usando isalpha() e islower();

int main() {

    //Variaveis Necessarias:
    int casos, i, validador, indice;
    char ra[105], *parte;


    scanf("%d", &casos); //Lendo a quantidade de casos;
    while (casos--)
    {
        scanf("%s", ra); //Lendo os RA's que forem digitados;
        validador = 0; // 0 Significa que est� apto para continuar;

        if( strlen(ra)!=20 ) //nossa string precisa ter exatamento 20 caracteres;
        {
            printf("INVALID DATA\n"); //Se n�o tiver ent�o esta errado;
            continue;
        }

        //verificando os dois primeiros caracteres:
        for ( i=0; i<2; i++ )
            if ( !isalpha(ra[i]) || islower(ra[i]) ) //nosso RA deve LETRA e ser MAIUSCULO;
            {
                printf("INVALID DATA\n");
                validador = 1; // 1 Significa que n�o est� apto para continuar;
                break;
            }

        if ( validador==0 ) //Se estiver apto para continuar ent�o...
        {
            indice=0; //Variavel que dir� a partir de onde copiaremos nossos numeros;
            for ( i=2; i<strlen(ra); i++ ) //For para descobrir onde esta o �ltimo zero antes do numero que devemos pegar;
                if ( ra[i] != '0')
                {
                    indice = i;
                    break;
                }

            memcpy( ra, &ra[indice], strlen(ra) ); //memcpy( quemRecebe, quemPassa[aPartirDeOnde], quantidadeQueVaiPegar );
            printf("%s\n", ra); //E por fim dando o resultado;
        }

    }


    return 0;
}
