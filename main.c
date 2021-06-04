#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>



struct cadastro
{
    char Numero[100];
    char Valor[100];
    char Marca[100];
    char Quantidade[100];
    char data[100];
    int vazio,cod;


//Funçoes
}log[100];
int verifica_pos(void);
int verifica_cod( int cod );
int opt;
void cadastroP(int cod,int pos);
void list();
void consultaCod(void);
void excluirC (void);



//Começo do main(parte principal)
int main(void){
setlocale(LC_ALL, "Portuguese");

    int i,Opcao,OpcaoC,posicao,retorno;
    int codaux;
    do
    {
        //Menu
        printf("=====================================================================================================\n");
        printf("=====================================================================================================\n");
        printf("                                        SAPATO SHOW\n"                                                 );
        printf("=====================================================================================================\n");
        printf("=====================================================================================================\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("                                        Seja Bem vindo a nossa Loja                                  \n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("////                                       1 - Cadastrar calçado                                 ////\n");
        printf("////                                       2 - Estoque                                           ////\n");
        printf("////                                       3 - Excluir Calçado                                   ////\n");
        printf("////                                       4 - Sair                                              ////\n");
        printf("/////////////////////////////////////////////////////////////////////////////////////////////////////\n");
        printf(" Escolha uma das 5 opções por favor: ");
        scanf("%d", &Opcao);


        getchar();
        if (Opcao == 1)
        {
            printf("Voce Escolheu a opcao 1 - Cadastrar calçado\n");
            posicao=verifica_pos();

                if ( posicao != -1 )
                {
                    printf("\nEntre com um codigo para cadastrar o produto: \n");
                    scanf("%d",&codaux);fflush(stdin);

                    retorno = verifica_cod( codaux );

                    if ( retorno == 1 )
                        cadastroP( codaux, posicao );
                    else{
                        printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
                        getchar();
                        system("cls");
                        main();
                    }

                }
                else
                    printf("\nNao foi possivel realizar mais cadastros!\n");

                break;

        }
        else if (Opcao == 2)
        {
            system("cls");
            do{
            printf("Voce Escolheu a opcao 2 - Estoque\n\n");
            printf("1 - Pesquisar Calçado por codigo\n");
            printf("2 - Listar todos os Calçados\n");
            printf("3 - Voltar ao menu principal\n");
            printf("Escolha uma opcao por favor: ");
            scanf("%d", &OpcaoC);
            getchar();
                 if(OpcaoC == 1){
                    consultaCod();
                }
                else if(OpcaoC == 2){
                    list();
                }
                else if(OpcaoC == 3){
                    printf("Voce Escolheu voltar ao menu principal, pressione ENTER para continuar");
                    getchar();
                    system("cls");
                }
                else
                    printf("Opcao Invalida\n\n");
    }while(OpcaoC =!3 || OpcaoC > 3 || OpcaoC < 0 || OpcaoC == 0);
        }
        else if (Opcao == 3)
        {
            printf("Voce Escolheu a opcao 3 - Excluir Calçado\n");
            excluirC();
        }
        else if (Opcao == 4)
        {
            printf("Voce Escolheu a opcao 4 - Sair\n");
        }
        else{
            printf("Opcao invalida, favor pressione enter para voltar ao menu principal");
            getchar();
            system("cls");
        }
        }    while (Opcao != 4 || Opcao < 4);

}
//usuarios cadastrados.
void list(){
    int i,j;
    for(i=0;i<100;i++){
        if(log[i].cod!=NULL){
            printf("\nCodigo: %d \nMarca: %s\nNumero: %s\nQuantidade: %s\nValor: %s\n\n", log[i].cod,log[i].Marca,log[i].Numero,log[i].Quantidade,log[i].Valor);
    }
}
    printf("Pressione enter para volta ao menu principal");
    getchar();
    system("cls");

}

//Cadastro das pessoas
void cadastroP(int cod, int pos){
    int i;
    do{
    pos = verifica_pos();
    log[pos].cod = cod;
        printf("\nDigite o nome da Marca: ");
        gets(log[pos].Marca);
        printf("\nDigite seu Numero: ");
        gets(log[pos].Numero);
        printf("\nDigite a Quantidade de pares: ");
        gets(log[pos].Quantidade);
        printf("\nDigite o Valor: ");
        gets(log[pos].Valor);
        log[pos].vazio = 1;
        opt ==1;
        getchar();
    }while(opt==1);
    system("cls");
    main();
}


int verifica_pos( void )
{
    int cont = 0;

    while ( cont <= 100 )
    {

        if ( log[cont].vazio == 0 )
            return(cont);

        cont++;

    }

    return(-1);

}
int verifica_cod( int cod )
{
    int cont = 0;

    while ( cont <= 100 )
    {
        if ( log[cont].cod == cod )
            return(0);

        cont++;
    }

    return(1);
} // FIM DO VERIFICADOR

void consultaCod (void) // CONSULTAR 1 CADASTRADO QUALQUER VIA CÓDIGO DADO POR USUÁRIO.
{
    int cont = 0, cod;

    printf("\nEntre com o codigo\n");
    scanf("%d",&cod);
    fflush(stdin);
    system("cls");

    while ( cont <= 100 )
    {

        if (log[cont].cod==cod)
        {
            if (log[cont].vazio==1)
            {

                printf("\nCodigo: %d \nMarca: %s\nNumero: %s\nQuantidade: %s\nValor: %s\n\n", log[cont].cod,log[cont].Marca,log[cont].Numero,log[cont].Quantidade,log[cont].Valor);


                system ("pause");

                system("cls");

                break;

            }
        }

        cont++;

        if ( cont > 100 ){
            printf("\nCodigo nao encontrado, pressione enter para voltar ao menu principal\n");
            getchar();
            system("cls");
        }

    }
} // FIM DA FUNÇÃO CONSULTAR

void excluirC(void)  // EXCLUI CLIENTE
{
    int cod, cont = 0;
    char resp;
    printf("\nEntre com o codigo do registro que deseja excluir: \n");
    scanf("%d", &cod );

    while ( cont <= 100 )
    {

        if ( log[cont].cod == cod )
        {

            if (log[cont].vazio == 1 )
            {
                printf("\nCodigo: %d \nMarca: %s\nNumero: %s\nQuantidade: %s\nValor: %s\n\n", log[cont].cod,log[cont].Marca,log[cont].Numero,log[cont].Quantidade,log[cont].Valor);
                getchar();
                printf("\nDeseja realmente excluir? s/n: ");
                scanf("%s",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    log[cont].vazio=0;
                    log[cont].cod = NULL;
                    printf("\nExclusao feita com sucesso\n");
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if ( cont > 100 )
            printf("\nCodigo nao encontrado\n");

    }

    system("pause");
    system("cls");

}








