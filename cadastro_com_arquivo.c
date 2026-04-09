#include <stdio.h>

typedef struct
{
    int id;
    char nome[50];
    int idade;
} cliente;

void cadastrar()
{
    FILE *arquivo = fopen("clientes.txt", "a");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    cliente c;

    printf("\nID: ");
    scanf("%d", &c.id);

    printf("Nome: ");
    scanf(" %[^\n]", c.nome); // aceita espaços

    printf("Idade: ");
    scanf("%d", &c.idade);

    // usa ; como separador
    fprintf(arquivo, "%d;%s;%d\n", c.id, c.nome, c.idade);

    fclose(arquivo);

    printf("Cliente cadastrado!\n");
}

void listar()
{
    FILE *arquivo = fopen("clientes.txt", "r");

    if (arquivo == NULL)
    {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }

    cliente c;

    printf("\nLista de clientes:\n");

    // lê até ; (aceita nome com espaço)
    while (fscanf(arquivo, "%d;%49[^;];%d\n", &c.id, c.nome, &c.idade) == 3)
    {
        printf("ID: %d | Nome: %s | Idade: %d\n",
               c.id, c.nome, c.idade);
    }

    fclose(arquivo);
}

int main()
{
    int opcao;

    do
    {
        printf("\n1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrar();
            break;
        case 2:
            listar();
            break;
        case 0:
            printf("Encerrado!\n");
            break;
        default:
            printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}