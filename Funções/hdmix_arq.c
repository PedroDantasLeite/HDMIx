#include <stdio.h>
#include <string.h>

int login (char *email, char *senha) {
  FILE *arq;
  int fim = 0;

  arq = fopen ("LOGINS.txt", "r");
  rewind(arq);
  char fMail[100], fSenha[100], nome[100], snome[100], idade[100];
  while (fscanf(arq, "%s %s %s %s %s", fMail, fSenha, nome, snome, idade) != EOF) {

    if (strcmp(email, fMail) == 0) {
      
      if (strcmp(senha, fSenha) == 0) {
      
        fim = 1;
      }
    }

  }

  fclose (arq);
  return fim;

}

int exLogin (char *email) {
  int fim = 0;
  FILE *arq;

  arq = fopen ("LOGINS.txt", "r");
  rewind(arq);
  char fMail[100];
  while ( fscanf(arq, "%s", fMail) != EOF) {

    if (strcmp(email, fMail) == 0) {
      fim = 1;
    }

  }
  fclose (arq);
  return fim;

}

void addLogin (char *nome, char *snome, char *senha, char *email, char *idade) {
  FILE *arq;

  arq = fopen ("LOGINS.txt", "at");

  fprintf (arq, "%s %s %s %s %s\n", email, senha, nome, snome, idade);

  fclose (arq);  
  

}


void verPerf (char *email) {
  FILE *arq;

  arq = fopen ("LOGINS.txt", "r");
  char fMail[100], fSenha[100], fNome[100], fSnome[100], fData[100];
  while (fscanf(arq, "%s %s %s %s %s", fMail, fSenha, fNome, fSnome, fData) != EOF ) {

    if (strcmp(email, fMail) == 0) {
      printf("\nEmail: %s\nNome: %s %s\nData de nascimento: %s\n\n", fMail, fNome, fSnome, fData);
    }

  }
  
  fclose (arq);

}

void feedBack (char *email, char *feedback) {
  FILE *arq;

  arq = fopen ("FEEDBACK.txt", "at");

  fprintf (arq, " --- Email: %s --- \n%s \n", email, feedback);

  fclose (arq);

}
