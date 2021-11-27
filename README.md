
 **Projeto do segundo período dos estudantes da Cesar School**\
 \
Equipe: HDMIx (Grupo 3)\
Cliente: TVPE - Thiago Costa\
Membros:\
  CC:\
    Luiz Fernando Paes de Barros Presta\
    Pedro Dantas Leite\
  Design:\
    Justine Cavalcanti Santos\
    Maria Julia Wendy Parente Soares\
    Maria Clara Cavalcanti de Oliveira\
    Gabriel Vasconcelos Corrêa Gondim\
Coordenador: Guilherme Pereira\
\
Documentação:
Programa feito em C para emular o funcionamento de um site. 

main.c: é o arquivo que puxa os restante das funções e bibliotecas para o uso do programa. Ele é regido principalmente por um loop infinito principal até que o usuario pare de roda-lo, assim como em um site.\

hdmix_ui.c: É a biblioteca que guia o funcionamento do Ui do site. Suas funções tem a template de goX, sendo X a pagina no qual o usuario estaria entrando.\
Suas funções:\
const char* goLogin() - Login/cadastro\
void goFeedback(char *email); - Feedback\
void goStream(int pag) - Streaming\
void goPerfil(char *email) - Perfil\

hdmix_arq.c: É a biblioteca que guia o funcimento da organização de arquivos do codigo. Tudo que utilizar o email/login da pessoa está descrito aqui.\
Suas funções:\
void addLogin (char *nome, char *snome, char *senha, char *email, char *idade) - Criar um conta\
int login (char *email, char *senha) - Verifica se o email existe e se a senha está correta\
void feedBack (char *email, char *feedback) - Adiciona o feedback no FEEDBACK.txt\
int exLogin (char *email) - Verifica se já existe um login durante a criação da conta.\
void verPerf (char *email) - Verifica se o perfil da pessoa existe e imprime seu contéudo.\

Arquivos txt: Utilizamos de 4 arquivos de texto, 2 para documentação e os outros para armazenamento de dados adquiridos na execução do código.\

Bugs.txt -- Uma forma de registrar os bugs que estão aparecendo no código\
FEEDBACK.txt -- Arquivo que vai registrar o email e feedback do usuario\
LOGINS.txt -- Registro dos dados de todos os usuários registrados na plataforma, organizados por email, senha, nome, sobrenome e data respectivamente\
Testes.txt -- Documentação dos testes elaborados para a construção do código\

