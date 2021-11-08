#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hdmix.h"
void goLogin();
void goFeedback();
void goStream();
void goPerfil();

int main(void) {
    int opção = 0;
    while (1){
        opção = 0;
        while(opção != 1 && opção != 2 && opção != 3){
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
        while(opção != 1 && opção != 2 && opção != 3 && opção != 4){
            printf("### Home Page  ###\n");
            printf("Aqui, você está informado\ndos eventos e das noticias\n atuais, além de ficar por dentro das novidades da TVPE\n");
            printf("Digite 1 para acessar se perfil\n");
            printf("Digite 2 para ir a stream\n");
            printf("Digite 3 para dar avaliar o site/ sua programação\n");
            printf("Digite 4 para sair de sua conta (logout)\n");
            scanf("%d", &opção);
            if(opção != 1 && opção != 2 && opção != 3 && opção != 4){
                printf("Opção invalida. tente novamente.\n");
                continue;
            }
            else if(opção == 1){
                goPerfil();
                continue;
            }
            else if (opção == 2){
                goStream();
                continue;
            }
            else if (opção == 3){
                goFeedback();
                continue;
            }
            else if (opção == 4){
                opção = 1;
                printf("Você saiu da sua conta\n");
            }
        }
    }
    

  return 0;
}

void goLogin(){
    int opção;
    char senha [100];
    char email [100];
    while (opção != 1 || opção != 2){
        printf("### Login/Cadastro ###\n");
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
            getchar();
            if (login (email, senha) == 1){
                printf("Sucesso!");
            }
            else{
                printf("Falha");
                continue;
            }

        }
        else if (opção == 2){ //CADASTRO
        char pnome [50], snome [50];
        char senha [100];
        char data [100];

            printf("Digite seu email\n");
            scanf("%s",email);
            if(exLogin(email) == 0){
                printf("Digite sua senha\n");
                scanf("%s", senha);
                printf("Digite seu nome e sobrenome\n");
                //fgets(nome, 100, stdin);
                scanf("%s %s", pnome, snome);
                printf("Digite sua data de nascimento\n");
                scanf("%s",data);
                addLogin (pnome, snome, senha, email, data);
                break;
            }
            else{
                printf("Email ja utilizado, tente novamente\n");
                continue;
            }
            
        }
    }

}

void goFeedback(){
    int opção;
    printf("Aqui, o usuario poderia comentar e especificar as suas queixas ou seus elogias ao conteudo apresentado pela TVPE. Além disso, podeira também sugerir mudanças que ele gostaria de ver acontecer no canal.\nDigite:\n1- Para voltar a pagina principal");
    scanf("%d",&opção);
    getchar();
}
void goStream(){
    int opção;
    printf("Aqui o usuario poderia assistir a um catagolo de programas apresentando pela TVPE, além de ter sua programação sendo apresentanda ao vivo pelo site. O usuario também pode apresenter feedback ao canal caso se sinta confortavel em avaliar o conteudo da programação\nDigite:\n1- Para voltar a pagina principal\n2- Para ir a pagina de feedback");
    scanf("%d",&opção);
    getchar();
    if ( opção == 2){
        goFeedback();
    }
}
void goPerfil(){
    printf("a");
}
