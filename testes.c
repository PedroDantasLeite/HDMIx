#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "unity.h"
#include "Funções/hdmix_ui.h"

void setUp(){};
void tearDown(){};

int Log (const char *email) {
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

void test_email_valido () {
  int teste_valido = Log(goLogin());

  TEST_ASSERT_EQUAL(1, teste_valido);

}

int principal(void) {

  UNITY_BEGIN();
  RUN_TEST(test_email_valido);
  
  return UNITY_END();

}
