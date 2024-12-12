#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//Struct para armazenar os dados dos Clientes
struct cliente{   
    char phone_num[15];
    char username[50];
    float value;
};

//Funçoes de Exibiçao
void head(){
    printf("\n\t\t========================================================================");
    printf("\n\t\t  ****Sistema de Gerenciamento de Faturamento de Telecomonicação****");
    printf("\n\t\t========================================================================");
    printf("\n\t\t");
    system("pause");
}

void Menu(){
    system("cls");

    printf("=====   SISTEMA DE FATURAMENTO DE TELECOM   =====");
    printf("\n================================================");
    printf("\n|| 1 : Adicionar novo Registro de Fatura");
    printf("\n|| 2 : Exibir os Registros de Contas");
    printf("\n|| 3 : Modificar um Registro de Fatura");
    printf("\n|| 4 : Gerenciar a transação de pagamento");
    printf("\n|| 5 : Buscar Registro de Fatura do Cliente");
    printf("\n|| 6 : Sair");
    printf("\n======================");
    printf("\nDigite sua escolha: ");
}
//---------------------------------------------------------------------------------------------

//Funçao para validaçao de Login
bool user_login(bool *validacao){
    system("cls");

    char login_nama[15] = "ADM";
    char password[15] = "12345";

    char login_temp[15];
    char password_temp[15];

    printf("\n*********************************** LOGIN DE USUARIO ***********************************");
    printf("\n\t\tDigite o Usuario: ");
    scanf(" %s", login_temp);
    printf("\n\t\tDigite a Senha: ");
    scanf(" %s", password_temp);
    if(strcmp(login_nama, login_temp) == 0 && strcmp(password, password_temp) == 0){
        printf("\n\tBem Vindo ao nosso Sistema!! Login realizado com Sucesso!");
        printf("\n\t\t\t");
        system("pause");
        *validacao = true;
    }else{
        printf("\n\tUsuario ou senha Incorretos, entrada Bloqueada!! Tente Novamente!");
        printf("\n\t\t\t");
        system("pause");
        *validacao = false;
    }
}
//---------------------------------------------------------------------------------------------------

//Funçao para Adicionar Registro
void add_record(struct cliente *clientes, int *count){
    system("cls");

    printf("Digite o Numero de Telefone: ");
    scanf(" %s", clientes[*count].phone_num);
    printf("Digite o Nome do Cliente: ");
    scanf(" %s", clientes[*count].username);
    printf("Digite a quantia da Fatura: ");
    scanf("%f", &clientes[*count].value);
    (*count)++; //Altera o indice da Struct

    printf("\nFatura Registrada com Sucesso! ");
    system("pause");
}
//---------------------------------------------------------------------------------------------------

//Funçao para imprimir todos os Registro de Fatura
void show_records(struct cliente *clientes, int count){
    system("cls");
    printf("Num.Telefone             Nome                 Quantia");
    printf("\n=========================================================================================");
    for(int i = 0; i < count; i++){
        printf("\n%s           %s           R$ %.2f", clientes[i].phone_num, clientes[i].username, clientes[i].value);
    }
    printf("\n=========================================================================================");
    printf("\n\n\t\t");
    system("pause");
}
//---------------------------------------------------------------------------------------------------

//Funçao auxiliar para busca do numero de Telefone
int search_num(struct cliente *clientes, int count, char *num_buscado){
    for(int i = 0; i < count; i++){
        if(strcmp(num_buscado, clientes[i].phone_num) == 0){
            return i; //retorna o Indice caso ache o registro
            break;
        }
    }

    return -1;
}
//---------------------------------------------------------------------------------------------------

//Funçao para buscar um registro de fatura
void search_record(struct cliente *clientes, int count){
    char num_buscado[15];
    printf("Digite o Numero do Cliente que deseja Buscar: ");
    scanf(" %s", num_buscado);
    int indice = search_num(clientes, count, num_buscado);

    if(indice != -1){
        system("cls");
        printf("\nRegistro Encontrado:");
        printf("\n-----------------------");
        printf("\nNum.Telefone : %s", clientes[indice].phone_num);
        printf("\nNome do Cliente : %s", clientes[indice].username);
        printf("\nQuantia : %f", clientes[indice].value);
        printf("\n\n\t");
        system("pause");
    }else{
        printf("\nNenhum Registro com esse Numero de Telefone.");
        printf("\n\t");
        system("pause");
    }
}
//---------------------------------------------------------------------------------------------------

//Funçao para Modificar um Registro de Fatura 
void modify_record(struct cliente *clientes, int count){
    system("cls");
    char num_buscado[15];
    
    printf("Digite o Numero do Cliente que deseja Modificar: ");
    scanf(" %s", num_buscado);
    int indice = search_num(clientes, count, num_buscado);

    if(indice != -1){
        char num_novo[15];
        char nome_novo[15];
        float valor_novo;

        printf("\nNumero de Cliente encontrado.");
        printf("\n");
        system("pause");

        system("cls");

        printf("Digite o Numero de Telefone novo: ");
        scanf(" %s", num_novo);
        printf("Digite o Nome novo do Cliente: ");
        scanf(" %s", nome_novo);
        printf("Digite a nova quantia da Fatura: ");
        scanf("%f", &valor_novo);

        strcpy(clientes[indice].phone_num, num_novo);
        strcpy(clientes[indice].username, nome_novo);
        clientes[indice].value = valor_novo;
    }else{
        printf("\nRegistro nao encontrado.");
        printf("\n");
        system("pause");
    }
}
//---------------------------------------------------------------------------------------------------

//Funçao para realizar o pagamento da Fatura
void payment_transaction(struct cliente *clientes, int count){
    system("cls");

    char num_buscado[15];
    printf("Digite o Numero do Cliente que deseja Buscar: ");
    scanf(" %s", num_buscado);
    int indice = search_num(clientes, count, num_buscado);

    if(indice != -1){
        float value_pagamento;
        printf("\n****Detalhes***");
        printf("\nNum.Telefone : %s", clientes[indice].phone_num);
        printf("\nNome do Cliente : %s", clientes[indice].username);
        printf("\nQuantia : %f", clientes[indice].value);
        printf("\n--------------------------------------------------------");
        printf("\nDigite a Quantia do Pagamento: ");
        scanf("%f", &value_pagamento);
        if(value_pagamento <= clientes[indice].value && value_pagamento > 0){
            clientes[indice].value -= value_pagamento;
            printf("\nObrigado %s pelo pagamento pontual", clientes[indice].username);
            printf("\n\t");
            system("pause");
        }else{
            printf("\nValor inserido Invalido.  ");
            system("pause");
        }
    }else{
        printf("\nRegistro nao encontrado.");
        printf("\n");
        system("pause");
    }
}
//---------------------------------------------------------------------------------------------------

//Funçao Principal
int main(){

    head();

    bool validacao = false;
    while (!validacao){
        user_login(&validacao);
    }

    int escolha, count = 0;
    struct cliente clientes[10];

    while (true){
        Menu();
        scanf("%d", &escolha);

        if(escolha == 6){
            printf("\n\tEncerrado.");
            break;
        }

        switch (escolha){
        case 1:
            add_record(clientes, &count);
            break;
        case 2:
            show_records(clientes, count);
            break;
        case 3:
            modify_record(clientes, count);
            break;
        case 4:
            payment_transaction(clientes, count);
            break;
        case 5:
            search_record(clientes, count);
            break;
        default:
            printf("\n\tOpçao Invalida.");
            break;
        }
    }

    return 0;
}
//---------------------------------------------------------------------------------------------------