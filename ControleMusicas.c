/* FATEC | DESAFIO 2 | LP
*/


#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int opcao;

int i = 0, x, y;

struct dm
{
    char musica[33];
    char autor[22];
    int quantidade; /*nunca 10*/ //perguntar
    float preco;
};

void entrada_dados1(struct dm * ptr);
void listagem_dados2(struct dm * ptr);

void pesquisar_musica3(struct dm * ptr);
void pesquisar_autor4(struct dm * ptr);
void pesquisar_preco5(struct dm * ptr);
void alterar_quantidade6(struct dm * ptr);
void alterar_preco7(struct dm *ptr);

void alterar_dados8(struct dm * ptr);
void excluir_dados9(struct dm * ptr);
void saida10();

FILE *file;
int main()
{
    struct dm dados;
    struct dm *p;
    p = &dados;
    do
    {
        printf("\n                                     MENU DA LOJA");
        printf("\n\t-------------------------------------------------------------------------");
        printf("\n\t|  Digite o numero da opcao desejada:\t\t\t\t\t|");
        printf("\n\t|  1 - Entra dados da musica.\t\t\t\t\t\t|");
        printf("\n\t|  2 - Listar musicas na tela.\t\t\t\t\t\t|");
        printf("\n\t|  3 - Pesquisar musica pelo nome completo.\t\t\t\t|");
        printf("\n\t|  4 - Pesquisar autor pelo nome completo.\t\t\t\t|");
        printf("\n\t|  5 - Pesquisar musica por faixa de preco.\t\t\t\t|");
        printf("\n\t|  6 - Alterar quantidade (entrada e saida) pesquisando pelo nome.\t|");
        printf("\n\t|  7 - Alterar valor da musica pesquisando pelo nome completo.\t\t|");
        printf("\n\t|  8 - Alterar dados (pesquisando pelo nome completo).\t\t\t|");
        printf("\n\t|  9 - Exclui dados (pesquisando pelo nome completo).\t\t\t|");
        printf("\n\t| 10 - Saida pelo usuario.\t\t\t\t\t\t|");
        printf("\n\t-------------------------------------------------------------------------\n\t");
        printf("\n\t-------------------------------------------------------------------------\t");
        printf("\n\t|OBS:                                                                   |");
        printf("\n\t|+ Nao digitar virgulas e acentos;                                      |");
        printf("\n\t|+ Para pesquisar digite os dados da mesma forma que foi cadastrado.    |");
        printf("\n\t-------------------------------------------------------------------------");
        printf("\n\n\tOpcao: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
        {
            system("cls");
            entrada_dados1(p);
            break;
        }
        case 2:
        {
            system("cls");
            listagem_dados2(p);
            break;
        }
        case 3:
        {
            system("cls");
            pesquisar_musica3(p);
            break;
        }
        case 4:
        {
            system("cls");
            pesquisar_autor4(p);
            break;
        }
        case 5:
        {
            system("cls");
            pesquisar_preco5(p);
            break;
        }
        case 6:
        {
            system("cls");
            alterar_quantidade6(p);
            break;
        }
        case 7:
        {
            system("cls");
            alterar_preco7(p);
            break;
        }
        case 8:
        {
            system("cls");
            alterar_dados8(p);
            break;
        }
        case 9:
        {
            system("cls");
            excluir_dados9(p);
            break;
        }
        case 10:
        {
            system("cls");
            saida10();
            break;
        }
        default:
        {
            printf("\n\tOpcao invalida!\n");
            break;
        }
        }
    }
    while (opcao != 10);
}

void entrada_dados1(struct dm * ptr)
{
    file = fopen("desafio02", "a");

    printf("\n\t\t1 - ENTRADA DE DADOS\n");
    printf("\n\t-------------------------------------------------------------------------");
    if (file != NULL)
    {
        printf("\n\tInforme os dados da musica\n");
        printf("\n\tNome: ");
        gets(&ptr->musica[0]);
        printf("\tAutor: ");
        gets(&ptr->autor[0]);

        printf("\tQuantidade: ");
        scanf("%d", &ptr->quantidade);
        getchar();

        while (ptr->quantidade == 10)
        {
            printf("\n\tDigite um valor diferente de 10 para a quantidade!\n\t");
            scanf("%d", &ptr->quantidade);
            getchar();
            printf("\n");
        }

        printf("\tPreco: R$ ");
        scanf("%f", &ptr->preco);
        getchar();

        fwrite(ptr, sizeof(*ptr), 1, file);
        fclose(file);
    }
    else
    {
        printf("\n\tERRO! Problemas com a arbertura do arquivo!\n");
    }
}

void listagem_dados2(struct dm * ptr)
{
    int a, z = 0;
    file = fopen("desafio02", "r");

    printf("\n\t\t2 - LISTAGEM DE DADOS\n");
    printf("\n\t-------------------------------------------------------------------------");
    if (file != NULL)
    {
        for ( ; ; )
        {
            a = fread(ptr, sizeof(* ptr), 1, file);

            if (a == 0)
            {
                if (z == 0)
                {
                    printf("\nMusica nao encontrada!\n");
                }
                break;
            }
            if (ptr->musica[0] != '*')
            {
                z = 1;
                printf("\n\tNome: %s", ptr->musica);
                printf("\n\tAutor: %s", ptr->autor);
                printf("\n\tQuantidade: %d", ptr->quantidade);
                printf("\n\tPreco: %.2f", ptr->preco);
                printf("\n\t-------------------------------------------------------------------------");

            }
        }
        fclose(file);
    }
    else
    {
        printf("\n\tERRO! Problemas com a arbertura do arquivo!\n");
    }
}

void pesquisar_musica3(struct dm * ptr)
{
    int a, z = 0;
    char procurar[33];
    file = fopen("desafio02", "r");

    printf("\n\t\t3 - PESQUISAR POR MUSICA\n");
    printf("\n\t-------------------------------------------------------------------------");

    printf("\n\tInforme o nome da musica que deseja procurar: ");
    gets(procurar);

    if (file != NULL)
    {
        for ( ; ; )
        {
            a = fread(ptr,sizeof(*ptr),1, file);
            if (a == 0)
            {
                if(z == 0)
                {
                    printf("\n\tNenhuma musica encontrada!\n");
                }
                break;
            }

            for(i = 0; procurar[i] != '\0'; i++)
            {
                if(procurar[i] != ptr->musica[i])
                {
                    break;
                }
            }

            if (procurar[i] == '\0' && ptr->musica[i] =='\0')
            {
                z = 1;
                printf("\n\tNome: %s", ptr->musica);
                printf("\n\tAutor: %s", ptr->autor);
                printf("\n\tQuantidade: %d", ptr->quantidade);
                printf("\n\tPreco: %.2f", ptr->preco);
                printf("\n\t-------------------------------------------------------------------------");
            }
        }
        fclose(file);
    }

    else
    {
        printf("\n\tERRO! Problemas com a arbertura do arquivo!\n");
    }
}

void pesquisar_autor4(struct dm *ptr)
{
    int a,z=0;
    char procurar[22];
    file = fopen("desafio02","r");

    printf("\n\t\t4 - PESQUISAR POR AUTOR\n");
    printf("\n\t-------------------------------------------------------------------------");
    printf("\n\tInforme o nome do autor que procura: ");
    gets(procurar);

    if (file != NULL)
    {
        for( ; ; )
        {
            a = fread(ptr,sizeof(*ptr),1,file);
            if (a == 0)
            {
                if(z == 0)
                {
                    printf("\n\tNenhuma musica encontrada!\n");
                }
                break;
            }

            for(i = 0; procurar[i] != '\0'; i++)
            {
                if(procurar[i] != ptr->autor[i])
                {
                    break;
                }
            }

            if (procurar[i] == '\0' && ptr->autor[i] =='\0')
            {
                printf("\n\tNome: %s", ptr->musica);
                printf("\n\tAutor: %s", ptr->autor);
                printf("\n\tQuantidade: %d", ptr->quantidade);
                printf("\n\tPreco: %.2f", ptr->preco);
                printf("\n\t-------------------------------------------------------------------------");

                z = 1;
            }
        }
        fclose(file);
    }

    else
    {
        printf("\n\tERRO! Problemas com a arbertura do arquivo!\n");
    }
}

void pesquisar_preco5(struct dm *ptr)
{
    int a = 1, z = 0, i;
    float p1, p2;
    float procurar;
    file = fopen("desafio02","r");


    printf("\n\t\t5 - PESQUISAR POR FAIXA DE PRECO\n");
    printf("\n\t-------------------------------------------------------------------------");

    printf("\n\tInforme o valor minimo para filtrar: R$ ");
    scanf("%f", &p1);

    printf("\n\tInforme o valor maximo para filtrar: R$ ");
    scanf("%f", &p2);
    printf("\n\t-------------------------------------------------------------------------");


    if (file != NULL)
    {
        for(i=0; a == 1; i++)
        {
            a = fread(ptr, sizeof(*ptr), 1, file);
            if(a == 0)
            {
                if(z == 0)
                {
                    printf("\n\tNenhuma musica encontrada!\n");
                }
                break;
            }


            if(ptr->preco >= p1 && ptr->preco <= p2)
            {
                printf("\n\tNome: %s", ptr->musica);
                printf("\n\tAutor: %s", ptr->autor);
                printf("\n\tQuantidade: %d", ptr->quantidade);
                printf("\n\tPreco: %.2f", ptr->preco);
                printf("\n\t-------------------------------------------------------------------------");
                i = 1;
                z = 1;
            }
        }
        if(i==0)
        {
            printf("\n N�o constam musicas nessa faixa de pre�o.");
        }

        fclose(file);
    }

    else
    {
        printf("\n\tERRO! Problemas com a arbertura do arquivo!\n");
    }
}

void alterar_quantidade6(struct dm *ptr)
{
    int a, o, q, pos, cont = 0,z = 0;
    file = fopen("desafio02","r");
    char alterar[33];

    printf("\n\t\t6 - ALTERAR QUANTIDADE (ENTRADA/SAIDA)\n");
    printf("\n\t-------------------------------------------------------------------------");
    printf("\n\tInforme o nome da musica que deseja procurar: ");
    gets(alterar);

    if (file != NULL)
    {
        for( ; ; )
        {
            a = fread(ptr,sizeof(*ptr),1,file);
            if (a == 0)
            {
                if(z == 0)
                {
                    printf("\n\tNenhuma musica encontrada!\n");
                }
                break;
            }

            for(i = 0; alterar[i] != '\0'; i++)
            {
                if(alterar[i] != ptr->musica[i])
                {
                    break;
                }
            }

            if (alterar[i] == '\0' && ptr->musica[i] =='\0')
            {
                printf("\n\tQuantidade de musicas armazenadas: %d\n", ptr->quantidade);
                z = 1;
                printf("\n\tDigite 1 para a entrada e 2 para a saida: ");
                scanf("%d", &o);

                fclose(file);
                file = fopen("desafio02","r+");

                if(o == 1)
                {
                    printf("\n\tInforme quantidade de entrada: ");
                    scanf("%d", &q);

                    ptr->quantidade = ptr->quantidade + q;
                    pos = cont * sizeof(*ptr);

                    fseek(file, pos, 0);
                    fwrite(ptr, sizeof(*ptr), 1, file);
                    fclose(file);

                    break;
                }
                else
                {
                    printf("\n\tInforme quantidade vendida: ");
                    scanf("%d",&q);

                    ptr->quantidade = ptr->quantidade - q;
                    pos = cont * sizeof(*ptr);

                    fseek(file, pos, 0);
                    fwrite(ptr, sizeof(*ptr), 1, file);
                    fclose(file);
                    break;
                }
            }
            cont++;
        }
    }

    else
    {
        printf("\n\tERRO! Problemas com a arbertura do arquivo!\n");
    }
}

void alterar_preco7(struct dm *ptr)
{
    int a, b, c, pos, cont = 0,z = 0;
    char alterar[33];
    file = fopen("desafio02","r");

    printf("\n\t\t7 - ALTERAR PRECO\n");
    printf("\n\t-------------------------------------------------------------------------");
    printf("\n\tInforme o nome da musica que procura: ");
    gets(alterar);

    if (file != NULL)
    {
        for( ; ; )
        {
            a = fread(ptr, sizeof(*ptr), 1, file);
            if (a == 0)
            {
                if(z == 0)
                {
                    printf("\n\tNenhuma musica encontrada!\n");
                }
                break;
            }

            for(i = 0; alterar[i] != '\0'; i++)
            {
                if(alterar[i] != ptr->musica[i])
                {
                    break;
                }
            }

            if (alterar[i] == '\0' && ptr->musica[i] =='\0')
            {
                z = 1;
                fclose(file);
                file = fopen("desafio02","r+");

                printf("\n\tInforme o novo valor: R$ ");
                scanf("%f", &ptr->preco);


                pos = cont * sizeof(*ptr);

                fseek(file, pos, 0);
                fwrite(ptr, sizeof(*ptr), 1, file);
                fclose(file);
                break;
            }
            cont++;
        }
    }
    else
    {
        printf("\n\tERRO! Problemas com a arbertura do arquivo!\n");
    }
}

void alterar_dados8(struct dm *ptr)
{
    int a, b, c, pos, cont = 0, z = 0;
    char alterar[33];
    file = fopen("desafio02","r");

    printf("\n\t\t8 - ALTERAR DADOS\n");
    printf("\n\t-------------------------------------------------------------------------");
    printf("\n\tInforme o nome completo da musica que deseja alterar: ");
    gets(alterar);

    if (file != NULL)
    {
        for( ; ; )
        {
            a = fread(ptr, sizeof(*ptr), 1, file);
            if (a == 0)
            {
                if(z == 0)
                {
                    printf("\n\tNenhuma musica encontrada!\n");
                }
                break;
            }

            for(i = 0; alterar[i] != '\0'; i++)
            {
                if(alterar[i] != ptr->musica[i])
                {
                    break;
                }
            }

            if (alterar[i] == '\0' && ptr->musica[i] =='\0')
            {
                z = 1;
                fclose(file);
                file = fopen("desafio02","r+");

                printf("\n\tInforme o novo nome da musica: ");
                gets(&ptr->musica[0]);
                printf("\n\tInforme o novo nome do autor: ");
                gets(&ptr->autor[0]);
                printf("\n\tInforme a nova quantidade: ");
                scanf("%d", &ptr->quantidade);
                getchar();

                while (ptr->quantidade == 10)//conferir
                {
                    printf("\n\tDigite um valor diferente de 10 para a quantidade!\n\t");
                    scanf("%d", &ptr->quantidade);
                    getchar();
                }

                printf("\n\tInforme o novo preco: R$ ");
                scanf("%f", &ptr->preco);
                getchar();

                pos = cont * sizeof(*ptr);

                fseek(file, pos, 0);
                fwrite(ptr, sizeof(*ptr), 1, file);
                fclose(file);
                break;
            }
            cont++;
        }
    }

    else
    {
        printf("\n\tERRO! Problemas com a arbertura do arquivo!\n");
    }
}

void excluir_dados9(struct dm *ptr)
{
    int a, b, c, pos, cont = 0,z = 0;
    char excluir[33];
    file = fopen("desafio02","r");

    printf("\n\t\t9 - EXCLUIR DADOS\n");
    printf("\n\t-------------------------------------------------------------------------");
    printf("\n\tInforme o nome completo da musica que deseja excluir: ");
    gets(excluir);

    if (file != NULL)
    {
        for( ; ; )
        {
            a = fread(ptr,sizeof(*ptr),1, file);
            if (a == 0)
            {
                if(z == 0)
                {
                    printf("\n\tNenhuma musica encontrada!\n");
                }
                break;
            }

            for(i=0; excluir[i] != '\0'; i++)
            {
                if(excluir[i] != ptr->musica[i])
                {
                    break;
                }
            }

            if (excluir[i] == '\0' && ptr->musica[i] =='\0')
            {
                z = 1;
                fclose(file);
                file = fopen("desafio02","r+");

                ptr->musica[0] = '*';
                ptr->autor[0] = 0;
                ptr->quantidade = 0;
                ptr->preco = 0;

                pos = cont*sizeof(*ptr);

                fseek(file, pos, 0);
                fwrite(ptr, sizeof(*ptr), 1, file);
                fclose(file);
                break;
            }
            cont++;
        }
    }

    else
    {
        printf("\n\tERRO! Problemas com a arbertura do arquivo!\n");
    }
}

void saida10()
{
    printf("\n\tPrograma encerrado. Ate mais!\n");
    exit(0);
}




