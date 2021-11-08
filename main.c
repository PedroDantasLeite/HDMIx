#include <stdio.h>
#include "hdmix.h"
void goLogin();

int main(void) {
    int opção = 0;
    while(opção != 1 || opção != 2 || opção != 3){
        printf("### Landing Page ###\n");
        printf("Aqui, você está informado dos eventos e das noticias atuais, além de ficar por dentro das novidades da TVPE\n");
        printf("Digite 1 para ir a tela de login\n");
        printf("Digite 2 para ir a stream (levara para a tela de login, já que sua conta não está logada\n");
        printf("Digite 3 para dar avaliar o site/ sua programação (levará também a tela de login\n");
        scanf("%d", &opção);
        getchar();
        if (opção != 1 && opção != 2 && opção != 3){
            printf("Opção indisponivel, tente novamente\n");
            continue;
        }
        else {
            goLogin();
        }
    }
    opção = 0;
    while(opção != 1 || opção != 2 || opção != 3){
        printf("### Home Page  ###");
        printf("Aqui, você está informado\ndos eventos e das noticias\n atuais, além de ficar por dentro das novidades da TVPE\n");
        printf("Digite 1 para acessar se perfil\n");
        printf("Digite 2 para ir a stream");
        printf("Digite 3 para dar avaliar o site/ sua programação");

    }





  

  return 0;
}

void goLogin(){
    int opção;
    char senha [100];
    char email [100];
    while (opção != 1 || opção != 2){
        printf("Você deseja dar login ou criar uma conta?\n1- Login\n2- Sign in\n");
        scanf("%d", &opção);
        getchar();
        if (opção != 1 && opção != 2){
            printf("Opção invalida, tente novamente!\n");
            continue;
        }
        else if (opção == 1){ //LOGIN
            printf("Digite seu email\n");
            scanf("%s", email);
            getchar();
            printf("Digite sua senha\n");
            scanf("%s",senha);
            if (login (email, senha) == 1){
                printf("Sucesso!");
            }
            else{
                printf("Falha");
                continue;
            }

        }
        else if (opção == 2){ //CADASTRO
        char nome [100];
        char senha [100];
        char data [100];

            printf("Digite seu email\n");
            scanf("%s",email);
            if(exLogin(email) == 0){
                printf("Digite sua senha\n");
                scanf("%s", senha);
                printf("Digite seu nome e sobrenome\n");
                fgets(nome, 100, stdin);
                printf("Digite sua data de nascimento\n");
                scanf("%s",data);
                addLogin (nome, senha, email, data);
                break;
            }
            else{
                printf("Email ja utilizado, tente novamente\n");
                continue;
            }
            
        }
    }

}