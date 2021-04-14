#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define TRUE 1 //Constante;

//prototypes;
char homeScreen(char menu);
void read(void); //OK.
void append(void); //OK.
void write(void); //OK
void help(void); //OK.
void screenDataTime(void); //OK.

void main(void) {
    setlocale(LC_ALL, "Portuguese"); //Passando o idioma - Portugu�s;

    system("title Author Archivery"); //Passando o t�tulo da janela;
    system("mode con cols=102 lines=40"); //Passando as dimens�es da janela;

    //author specifications;
    char menu;
    //const int true = 1;

    while (TRUE)
    {
        homeScreen(menu);
    }

    getch();
    return;
}

void screenDataTime (void) {

    struct tm *timer; //Criando variavel ponteiro;

    time_t seconds; //Variavel para armazenar os segundos;

    time(&seconds); //Obtendo o tempo em segundos;

    timer = localtime(&seconds);

    //Imprimindo a Data e o Rel�gio:
    printf("\n %.2d/%.2d/%d &", timer->tm_mday, timer->tm_mon+1, timer->tm_year+1900);
    printf("& %.2d:%.2d:%.2d", timer->tm_hour, timer->tm_min, timer->tm_sec);

    return ;
}

char homeScreen(char menu) {

        system("color 0A"); //Mudando a cor;
        screenDataTime();
        printf("\n\n\n\n\n\t\t\t\t\t     Author Archivery\n\n");
        printf("\t\t\t\t    ���������������������������������");

        printf("\n\n\t\t\t\t\t[1] Ler Arquivo.");
        printf("\n\n\t\t\t\t\t[2] Escrever em Arquivo.");
        printf("\n\n\t\t\t\t\t[3] Sobrescrever Arquivo.");

        printf("\n\n\t\t\t\t    - - - - - - - - - - - - - - - - -\n");
        printf("\n\t\t\t\t\t   [9] Ajuda \t [0] Sair");

        printf("\n\n\t\t\t\t\t >>> ");

        setbuf(stdin, NULL); //Limpar o Buffer;
        scanf("%c", &menu); //L� a op��o selecionada;

        system("color 07"); //Voltando com a cor padr�o;

        switch (menu) { //Escolhe um caso com base na op��o selecionada;
        case '1' :
            system("cls");
            read();
            break;
        case '2':
            system("cls");
            append();
            break;
        case '3':
            system("cls");
            write();
            break;

        case '9':
            system("cls");
            help();
            break;
        case '0':
            //close();
            exit(0);
            break;
        default:
            system("cls");

            printf("\t\t\t      _____________________________________________");
            printf("\n\t\t\t     | Ops! Por favor, selecione uma op��o v�lida! |\n");
            printf("\t\t\t     �����������������������������������������������\n");

            break;
        }

    return 0;
}


void help(void) {

    char menu;

    while (TRUE)
    {
        printf("\n\n\n\n\n\t\t\t\t\t     Author Archivery\n\n");
        printf("\t\t\t\t    ���������������������������������\n");
        printf("\t\t\t\t\t       Informa��es");

        printf("\n\n\t\t\t\t[:] Ler Arquivo:\n");
        printf("\n\t\t\t - Permiss�o de abertura somente para leitura.\n\t\t\t � necess�rio que o arquivo j� esteja criado.");

        printf("\n\n\n\t\t\t\t[:] Escrever em Arquivo:\n");
        printf("\n\t\t\t - Permiss�o para abrir um arquivo texto para escrita (grava��o),");
        printf("\n\t\t\t permite acrescentar novos dados ao final do arquivo.");
        printf("\n\t\t\t Caso n�o exista, ele ser� criado.");

        printf("\n\n\n\t\t\t\t[:] Sobrescrever Arquivo:\n");
        printf("\n\t\t\t - Permiss�o de abertura para escrita (grava��o). ");
        printf("\n\t\t\tEsta fun��o cria o arquivo caso ele n�o exista, ");
        printf("\n\t\t\te caso o mesmo exista ele recria o arquivo novamente\n\t\t\tfazendo com que o conte�do seja perdido. ");
        printf("\n\t\t\tPortanto tome muito cuidado ao usar esse tipo de abertura.");

        printf("\n\n\t\t\t\t    - - - - - - - - - - - - - - - - -\n");
        printf("\n\t\t\t\t\t       [9] Voltar");

        printf("\n\n\t\t\t\t\t >>> ");

        setbuf(stdin, NULL);
        scanf("%c", &menu);

        if (menu == '9') {
            system("cls");
            return;
        } else {
            system("cls");
            continue;
        }
    }

    return;
}


void read(void) {

    char archive_name[20];
    char menu;
    FILE *archive;


    while (TRUE)
    {
        do {
            system("cls");

            printf("\n\n\n\t\t\t\t\t     Leitura\n");
            printf("\t\t\t\t    �������������������������");

            printf("\n\n\t Nome do Arquivo: ");

            //Lendo o nome do arquivo;
            setbuf(stdin, NULL);
            fgets(archive_name, 20, stdin);

        } while (archive_name[0] == '\n');

        //Passando a extens�o para o arquivo;
        archive_name[strlen(archive_name) - 1] = '\0'; //Elimina a quebra de linha
        strcat( archive_name, ".txt"  ); //Concatenando;

        //Abrindo o arquivo, se existir;
        archive = fopen(archive_name, "r");

        //Caso o arquivo n�o exista:
        if (archive == NULL) {
            do {
                system("cls");

                printf("\n\n\t::: Arquivo n�o encontrado! :::\n");
                printf("\n\t[1] Tentar Novamente  [0] Voltar");
                printf("\n\n\t >>> ");

                setbuf(stdin, NULL);
                //scanf(" %c", &menu);
                menu = getchar();

            } while ( menu != '1' && menu != '0');

            switch (menu) { //Selecionando;
                case '1':
                    continue; //Tentando pegar nome novamente;
                    break;
                case '0':
                    system("cls");
                    return; //Saindo da fun��o;
                    break;
                default:
                    break;
            }

        }


        //long pos = ftell(archive); //Verificando a posi��o inicial;
        //printf("primeiro: %ld", pos);

        //Verificando se o arquivo est� vazio:
        if (fgets(archive_name, 20, archive) == NULL) {
            printf("\n\n\n\t >> [Arquivo Vazio] << \n\n");
        }

        //pos = ftell(archive); //Posi��o ap�s verifica��o anterior;
        //printf("segundo: %ld", pos);

        //Voltando para o inicio do arquivo:
        rewind(archive);


        //Caso exista:
        printf("\n");
        while(fgets(archive_name, 20, archive) != NULL) {
            printf("%s", archive_name);
        }


        //pos = ftell(archive);
        //printf("terc: %ld", pos);


        //Fechando o arquivo ap�s termino de leitura:
        fclose(archive);


        //Capturando proxima a��o;
        do {
            printf("\n\t[1] Ler Outro Arquivo   [0] Voltar\n");
            printf("\n\t>>> ");

            setbuf(stdin, NULL);
            menu = getchar();

            system("cls");

        } while (menu != '1' && menu != '0');

        //Realizando a a��o escolhida:
        switch (menu) {
            case '1':
                continue;
                break;
            case '0':
                return;
                break;
            default:
                break;
        }

    }

    return;
}


void append(void) {

    char archive_name[20];
    char text[200];
    char menu;
    FILE *archive;


    while (TRUE)
    {
        do {
            system("cls");

            printf("\n\n\n\t\t\t\t\t     Escrever\n");
            printf("\t\t\t\t    �������������������������");

            printf("\n\n\t Nome do Arquivo: ");

            //Lendo o nome do arquivo;
            setbuf(stdin, NULL);
            fgets(archive_name, 20, stdin);

        } while (archive_name[0] == '\n');

        //Passando a extens�o para o arquivo;
        archive_name[strlen(archive_name) - 1] = '\0'; //Elimina a quebra de linha
        strcat( archive_name, ".txt"  ); //Concatenando;

        //Abrindo o arquivo, se existir - sen�o: cria um;
        archive = fopen(archive_name, "a");

        system("cls");
        printf("\n\t\t :: Tecle [ENTER] e [ESC] para finalizar escrita.\n\n");


        //Caso exista:
        char escape;

        //printf("\t"); //Tabula��o - apenas est�tica;
        while (TRUE) {

            setbuf(stdin, NULL); //Limpar buffer;
            fgets(text, 200, stdin); //Lendo o que for digitado;

            setbuf(stdin, NULL);
            escape = getch(); //Verifica se o usu�rio quer sair;

            //printf("\t"); //Tabula��o - apenas est�tica;
            fprintf(archive, "%s", text); //Escreve no arquivo o que foi digitado;

            printf("%c", escape); //Escreve o caratacter digitado pego pelo getch();

            //Encerra caso o usu�rio queira, pelo cont�rio imprime na tela a continua��o;
            if (escape == 27) {
                break;
            }
            else {
                fprintf(archive, "%c", escape);
            }

        }


        //Fechando arquivo ap�s escrita finalizada:
        fclose(archive);


        //Capturando proxima a��o;
        do {
            printf("\n\t[1] Escrever em Outro Arquivo   [0] Voltar\n");
            printf("\n\t>>> ");

            setbuf(stdin, NULL);
            menu = getchar();

            system("cls");

        } while (menu != '1' && menu != '0');


        //Realizando a a��o escolhida:
        switch (menu) {
            case '1':
                continue;
                break;
            case '0':
                return;
                break;
            default:
                break;
        }

    }


    return;
}


void write(void) {

    char archive_name[20];
    char text[200];
    char menu;
    FILE *archive;


    while (TRUE)
    {
        do {
            system("cls");

            printf("\n\n\n\t\t\t\t\t  Sobrescrever\n");
            printf("\t\t\t\t    ������������������������");

            printf("\n\n\t Nome do Arquivo: ");

            //Lendo o nome do arquivo;
            setbuf(stdin, NULL);
            fgets(archive_name, 20, stdin);

        } while (archive_name[0] == '\n');

        //Passando a extens�o para o arquivo;
        archive_name[strlen(archive_name) - 1] = '\0'; //Elimina a quebra de linha
        strcat( archive_name, ".txt"  ); //Concatenando;

        //Abrindo o arquivo, se existir - sen�o: cria um;
        //Ao abrir um arquivo existente, ele escreve por cima do que j� existe, assim apagando o que existia;
        archive = fopen(archive_name, "w");

        system("cls");
        printf("\n\t\t :: Tecle [ENTER] e [ESC] para finalizar escrita.\n\n");


        //Caso exista:
        char escape;
        //printf("\t"); //Tabula��o - apenas est�tica;
        while (TRUE) {

            setbuf(stdin, NULL); //Limpar buffer;
            fgets(text, 200, stdin); //Lendo o que for digitado;

            setbuf(stdin, NULL);
            escape = getch(); //Verifica se o usu�rio quer sair;

            //printf("\t"); //Tabula��o - apenas est�tica;
            fprintf(archive, "%s", text); //Escreve no arquivo o que foi digitado;

            printf("%c", escape); //Escreve o caratacter digitado pego pelo getch();

            //Encerra caso o usu�rio queira, pelo cont�rio imprime na tela a continua��o;
            if (escape == 27) {
                break;
            }
            else {
                fprintf(archive, "%c", escape);
            }

        }


        //Fechando arquivo ap�s escrita finalizada:
        fclose(archive);


        //Capturando proxima a��o;
        do {
            printf("\n\t[1] Sobrescrever em Outro Arquivo   [0] Voltar\n");
            printf("\n\t>>> ");

            setbuf(stdin, NULL);
            menu = getchar();

            system("cls");

        } while (menu != '1' && menu != '0');


        //Realizando a a��o escolhida:
        switch (menu) {
            case '1':
                continue;
                break;
            case '0':
                return;
                break;
            default:
                break;
        }

    }


    return;
}


//####################################################;
