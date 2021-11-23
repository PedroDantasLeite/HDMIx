#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Funções/hdmix_arq.h"
#include "Funções/hdmix_ui.h"

void setUp(){};
void tearDown(){};

int main(void) {

    int opcao = 0,pag = 0;

    while (1) {
        opcao = 0;
        pag = 0;
        while(opcao != 1 && opcao != 2 && opcao != 3){
            printf("### Landing Page ###\n");
            printf("Aqui, você está informado dos eventos e das noticias atuais, além de ficar por dentro das novidades da TVPE\n");
            printf("Digite 1 para ir a tela de login\n");
            printf("Digite 2 para ir a stream \n");
            printf("Digite 3 para dar avaliar o site/ sua programação\n");
            scanf("%d", &opcao);
            getchar();
            if (opcao != 1 && opcao != 2 && opcao != 3){
                printf("opcao indisponivel, tente novamente\n");
                continue;
            }
            else if  (opcao == 1){
                const char* email = goLogin();
                break;
            }
            else if(opcao == 2){
                goStream(pag);
                opcao = 0;
            }
            else if(opcao == 3){
              char auxEmail[100];
              printf("Primeiro, digite seu email antes de avaliar a programação:\n");
              scanf("%s",auxEmail);
              getchar();
              goFeedback(auxEmail);
              opcao = 0;
            }
        }
        opcao = 1;
        pag = 1;
        while(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4){
            printf("### Home Page  ###\n");
            printf("Aqui, você está informado\ndos eventos e das noticias\n atuais, além de ficar por dentro das novidades da TVPE\n");
            printf("Digite 1 para acessar se perfil\n");
            printf("Digite 2 para ir a stream\n");
            printf("Digite 3 para dar avaliar o site/ sua programação\n");
            printf("Digite 4 para sair de sua conta (logout)\n");
            scanf("%d", &opcao);
            getchar();
            if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4){
                printf("opcao invalida. tente novamente.\n");
                opcao = 1;
                continue;
            }
            else if(opcao == 1){
                goPerfil(email);
                continue;
            }
            else if (opcao == 2){
                goStream(pag);
                continue;
            }
            else if (opcao == 3){
                goFeedback(email);
                continue;
            }
            else if (opcao == 4){
                opcao = 0;
                printf("Você saiu da sua conta\n");
            }
        }
    }
    

  return 0;
}
