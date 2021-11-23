#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hdmix_arq.h"

char email[100];
int pag;

const char* goLogin(){
    int opcao;
    char senha [100];
    while (opcao != 1 || opcao != 2){
        printf("### Login/Cadastro ###\n");
        printf("Você deseja dar login ou criar uma conta?\n1- Login\n2- Sign in\n");
        scanf("%d", &opcao);
        getchar();
        if (opcao != 1 && opcao != 2){
            printf("opcao invalida, tente novamente!\n");
            continue;
        }
        else if (opcao == 1){ //LOGIN
            printf("Digite seu email\n");
            scanf("%s", email);
            getchar();
            printf("Digite sua senha\n");
            scanf("%s",senha);
            getchar();
            if (login (email, senha) == 1){
                printf("Sucesso!\n");
                return email;
            }
            else{
                printf("Falha, conta não encontrada\n");
                continue;
            }

        }
        else if (opcao == 2){ //CADASTRO
        char pnome [50], snome [50];
        char senha [100];
        char data [100];

            printf("Digite seu email\n");
            scanf("%s",email);
            getchar();
            if(exLogin(email) == 0){
                printf("Digite sua senha\n");
                scanf("%s", senha);
                getchar();
                printf("Digite seu nome e sobrenome\n");
                scanf("%s %s", pnome, snome);
                getchar();
                printf("Digite sua data de nascimento\n");
                scanf("%s",data);
                getchar();
                addLogin (pnome, snome, senha, email, data);
                return email;
            }
            else{
                printf("Email ja utilizado, tente novamente\n");
                continue;
            }
            
        }
    }

}

void goFeedback(char *email){
    char feedback[100];
    printf("Aqui, o usuario poderá comentar e especificar as suas queixas ou seus elogios ao conteudo apresentado pela TVPE. Além disso, poderá também sugerir mudanças que ele gostaria de ver implementadas no canal.\nDigite seu feedback quanto a programção:\n");
    fgets(feedback,100,stdin);
    feedBack(email, feedback);
}
void goStream(pag){
    char email[100];
    int opcao;
    printf("Aqui o usuario poderá assistir a um catagolo de programas apresentando pela TVPE, além de ter sua programação sendo apresentanda ao vivo pelo site. O usuario também pode apresenter feedback ao canal caso se sinta confortavel em avaliar o conteudo da programação\nDigite:\n1- Para voltar a pagina principal\n2- Para ir a pagina de feedback\n");
    scanf("%d",&opcao);
    getchar();
    if (opcao == 2){
        if (pag == 1){
        goFeedback(email);
        }
        else{
          char auxEmail[100];
          printf("Primeiro, digite seu email antes de avaliar a programação:\n");
          scanf("%s",auxEmail);
          getchar();
          goFeedback(auxEmail);
        }
    }

}
void goPerfil(char *email){
    verPerf (email);
}
