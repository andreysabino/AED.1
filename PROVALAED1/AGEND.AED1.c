#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void exportacontato();
void listarsonome();
void listarnomeetelefone();
void listarporinicial();
void listarporindice(int ident);
void listarporprofissao(char prof);
void formata();
void editacontato();
void editanome();
void cabecalho();

typedef struct pessoa {
    int ID;
    char nome[80];
    char profissao[26];
    long long int telefone;
} contato;

int main() {
    contato c;
    char letra;
    int ident, id1, id2;
    char profi;
    setlocale(LC_ALL, "Portuguese");
    int op, oplistar, opeditar;
  

    while (op != 6){
        cabecalho();
        scanf("%d", &op);
        int id;
        switch (op) {
            case 1:
                while (0xC0FFEE) {
                    printf("Informe o ID que deseja exportar: ");
                    scanf("%i", &id);
                    if (id == 0 || id >= 7 || id <= 49) {
                        exportacontato(id);
                        break;
                    } else printf("ID inválido \n");
                }
            break;
            
            case 2:
                printf("1 - Listar todos por nome.\n");
                printf("2 - Listar todos por telefone \n");
                printf("3 - Listar todos os iniciados por uma letra específica \n");
                printf("4 - Listar um contato através do ID \n");
                printf("5 - Listar todos por uma profissão específica \n");
                
                printf("Escolha uma opção:\n");
                scanf("%d", &oplistar);

                switch (oplistar) {
                    case 1:
                        listarsonome();
                    break;
                
                    case 2:
                        listarnomeetelefone();
                    break;
                
                    case 3:
                        listarporinicial();
                    break;
                
                    case 4:
                        printf("Insira o id:\n");
                        scanf("%d", &ident);
                        listarporindice(ident);
                    break;
                
                    case 5:
                        printf("Insira a profissão desejada:\n");
                        scanf("%s", &profi);
                        listarporprofissao(profi);
                    break;
                
                    default:
                        printf("Opcao invalida!");
                    break;
                }
                break;
            
            case 3:
                printf("1 - Editar nome.\n");
                printf("2 - Editar telefone \n");
                printf("Escolha uma opção:\n");
                scanf("%d", &opeditar);

                switch (opeditar) {
                    case 1:
                        printf("Insira o id: \n");
                        scanf("%i", &id1);
                        editanome(id1);
                    break;
                
                    case 2:
                        printf("Insira o id:\n");
                        scanf("%d", &id2);
                        editacontato(id2);
                    break;
                }
            break;
            
            case 5:
              formata();
            break;
        }
    }
    
    return 0;
}

void cabecalho() {
  printf("---------------\n");
  printf("AGENDA\n");
  printf("---------------\n");
  printf("1 - Exportar\n");
  printf("2 - Listar \n");
  printf("3 - Editar \n");
  printf("4 - Excluir um contato (Inexistente) \n");
  printf("5 - Limpar Agenda \n");
  printf("6 - Sair \n");
  printf("Escolha uma opção:\n");
}

void listarsonome() {
    int ID;
    char nome[80];
    char profissao[26];
    long long int telefone;

    FILE *f = fopen("agenda.dat", "r");
    if (!f) printf("Impossivel abrir o arquivo\n");
    
    while (!feof(f)) {
        fscanf(f, "%d %s %s %lld", &ID, nome, profissao, &telefone);
        printf("(%d) (%s)\n", ID, nome);
    }
}

void listarnomeetelefone() {
    int ID;
    char nome[80];
    char profissao[26];
    long long int telefone = 0;

    FILE *f = fopen("agenda.dat", "r");
    if (!f) printf("Impossivel abrir o arquivo\n");

    while (!feof(f)) {
        fscanf(f, "%d %s %s %lld", &ID, nome, profissao, &telefone);
        printf("(%d) (%s) (%lli)\n", ID, nome, telefone);
    }
}

void listarporinicial() {
    int ID;
    char nome[80];
    char profissao[26];
    long long int telefone;
    char letra = ' ';

    printf("Insira a letra desejada:\n");
    scanf("%c", &letra);
    
    FILE *f = fopen("agenda.dat", "r");
    if (!f) printf("Impossível abrir o arquivo\n");

    while (!feof(f)) {
        fscanf(f, "%d %s %s %lld", &ID, nome, profissao, &telefone);
        if (toupper(nome[0]) == toupper(letra)) {
            printf("(%d) (%s) (%s) (%lld)\n", ID, nome, profissao, telefone);
        }
    }
}

void listarporindice(int ident) {
    int ID;
    char nome[80];
    char profissao[26];
    long long int telefone;

    FILE *f = fopen("agenda.dat", "r");
    if (!f) printf("Impossível abrir o arquivo\n");

    while (!feof(f)) {
        fscanf(f, "%d %s %s %lld", &ID, nome, profissao, &telefone);
        if (ID == ident) {
            printf("(%d) (%s) (%s) (%lld)\n", ID, nome, profissao, telefone);
        }
    }
}

void listarporprofissao(char prof) {
    int ID;
    char nome[80];
    char profissao[26];
    int telefone;

    FILE *f = fopen("agenda.dat", "r");
    if (!f) printf("Impossível abrir o arquivo\n");
    
    while (!feof(f)) {
        fscanf(f, "%d %s %s %d", &ID, nome, profissao, &telefone);
        if (toupper(profissao[0]) == toupper(prof)) {
            printf("(%d) (%s) (%s) (%d)\n", ID, nome, profissao, telefone);
        }
    }
}

void exportacontato(int ident) {
    FILE *f2 = fopen("Auxiliar.txt", "w");
    int ID;
    char nome[80];
    char profissao[26];
    int telefone;
    FILE *f1 = fopen("agenda.dat", "r");

    if (!f1) printf("Impossível abrir o arquivo\n");
    while (!feof(f1)) {
        fscanf(f1, "%d %s %s %d", &ID, nome, profissao, &telefone);
        if (ID == ident) {
            fprintf(f2, "%i %s %s %d \n", ID, nome, profissao, telefone);
            strcat(nome, ".txt");
            fclose(f2);
            rename("Auxiliar.txt", nome);
        }
    }
    fclose(f1);
    remove("Auxiliar.txt");
}

void formata() {
    FILE *f2 = fopen("agenda.dat", "w+");
    printf("\n\tLista limpa!\n ");
    fclose(f2);
}

void editanome(int ident) {

    FILE *f2 = fopen("auxiliar.dat", "w+");
    int ID;
    char nome[80];
    char profissao[26];
    int telefone;
    char novonome[80];
    FILE *f1 = fopen("agenda.dat", "r");

    if (!f1) printf("Impossível abrir o arquivo\n");
    while (!feof(f1)) {
        fscanf(f1, "%d %s %s %d", &ID, nome, profissao, &telefone);
        if (ID == ident) {
            printf("Qual vai ser o novo nome?\n");
            scanf("%s", novonome);
            fprintf(f2, "%i %s %s %d \n", ID, novonome, profissao, telefone);
            printf("Nome alterado.\n");
            printf("%i, %s, %s, %d \n", ID, novonome, profissao, telefone);
        } else fprintf(f2, "%i %s %s %d \n", ID, nome, profissao, telefone);
    }
    fclose(f1);
    fclose(f2);
    remove("agenda.dat");
    rename("auxiliar.dat", "agenda.dat");
}

void editacontato(int ident) {

    FILE *f2 = fopen("auxiliar.dat", "w+");
    int ID;
    char nome[80];
    char profissao[26];
    int telefone;
    int novocontato;
    FILE *f1 = fopen("agenda.dat", "r");

    if (!f1) printf("Impossível abrir o arquivo\n");
    while (!feof(f1)) {
        fscanf(f1, "%d %s %s %d", &ID, nome, profissao, &telefone);
        if (ID == ident) {
            printf("Qual vai ser o novo contato?\n");
            scanf("%d", &novocontato);
            fprintf(f2, "%i %s %s %d \n", ID, nome, profissao, novocontato);
            printf("Nome alterado.\n");
            printf("%i, %s, %s, %d \n", ID, nome, profissao, novocontato);
        } else fprintf(f2, "%i %s %s %d \n", ID, nome, profissao, telefone);
    }
    fclose(f1);
    fclose(f2);
    remove("agenda.dat");
    rename("auxiliar.dat", "agenda.dat");
}
