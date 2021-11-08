#include <stdio.h>

int login (char *email, char *senha) {
  int fim = 0;
  char *linha;
  FILE *arq;

  arq = fopen ("logins.txt", "r");
  while (fgets (linha, 50, arq) != NULL) {
    char *fMail, *fSenha;
    
    sscanf (linha, "%s %s", fMail, fSenha);

    if (email == fMail) {
      if (senha == fSenha) {
        fim = 1;
      }
    }

  }

  fclose (arq);

  return fim;

}

int exLogin (char *email) {
  char *linha;
  int fim = 0;
  FILE *arq;

  arq = fopen ("logins.txt", "r");
  while (fgets (linha, 50, arq) != NULL) {
    char *fMail;

    sscanf (linha, "%s", fMail);

    if (email == fMail) {
      fim = 1;
    }

  }
  fclose (arq);
  return fim;

}

void addLogin (char *nome, char *senha, char *email, char *idade) {
  char *linha;
  FILE *arq;

  arq = fopen ("logins.txt", "at");

  fprintf (arq, "%s %s %s %s\n", email, senha, nome, idade);

  fclose (arq);  
  

}