/*
Dados do aluno
Nome Completo: Rafael Correa de Melo
E-mail: 202501709354@alunos.estacio.br
Formação em: Ciência da Computação
Modelo de Ensino: Digital(EaD)
*/

#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

typedef struct {
    int codigo_cidade;
    char nome[100];
    int populacao;
    float area;
    float pib;
    int numero_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Cidade;

#define MAX_CIDADES 100

// Cadastro das Cartas:
// Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
// Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
void adicionarCidade(Cidade cidades[], int *quantidade) {
    if (*quantidade >= MAX_CIDADES) {
        printf("Limite de cidades atingido!\n");
        return;
    }

    Cidade novaCidade;

    printf("Código da cidade: ");
    scanf("%d", &novaCidade.codigo_cidade);

    printf("Nome da cidade: ");
    scanf(" %99[^\n]", novaCidade.nome);

    printf("População: ");
    scanf("%d", &novaCidade.populacao);

    printf("Área (km2): ");
    scanf("%f", &novaCidade.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &novaCidade.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &novaCidade.numero_pontos_turisticos);

    novaCidade.densidade_populacional = novaCidade.populacao / novaCidade.area;
    novaCidade.pib_per_capita = novaCidade.pib / novaCidade.populacao;

    cidades[*quantidade] = novaCidade;
    (*quantidade)++;
}

// Exibição dos Dados das Cartas:
// Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
// Exiba os valores inseridos para cada atributo da cidade, um por linha.
void listarCidades(Cidade cidades[], int quantidade) {
    printf("\nLista de Cidades Cadastradas:\n");
    printf("==================================\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Cidade: %s\n", cidades[i].nome);
        printf("Código: %d\n", cidades[i].codigo_cidade);
        printf("População: %d habitantes\n", cidades[i].populacao);
        printf("Área: %.2f km²\n", cidades[i].area);
        printf("PIB: %.2f bilhões\n", cidades[i].pib);
        printf("Pontos turísticos: %d\n", cidades[i].numero_pontos_turisticos);
        printf("Densidade Populacional: %f\n", cidades[i].densidade_populacional);
        printf("PIB Per Capita: %f\n", cidades[i].pib_per_capita);
        printf("==================================\n");
    }
}

void calcularSuperPoder(Cidade cidades[], int quantidade) {
    int codCidadeA;
    int codCidadeB;

    printf("Ensira os códigos das cidades que devem ser comparadas\n\n");

    printf("Código da cidade A: ");
    scanf("%d", &codCidadeA);

    printf("Código da cidade B: ");
    scanf("%d", &codCidadeB);

    printf("Comparando...\n\n");

    printf("==================================\n");

    Cidade cidadeA;
    Cidade cidadeB;

    for (int i = 0; i < quantidade; i++) {
        if(cidades[i].codigo_cidade == codCidadeA)
        {
            cidadeA = cidades[i];
        }

        if(cidades[i].codigo_cidade == codCidadeB)
        {
            cidadeB = cidades[i];
        }
    }


    int superPoderA = 0;
    int superPoderB = 0;

    if(cidadeA.populacao > cidadeB.populacao)
    {
        printf("Melhor população: %s\n", cidadeA.nome);
        superPoderA++;
    }
    else if(cidadeA.populacao < cidadeB.populacao)
    {
        printf("Melhor população: %s\n", cidadeB.nome);
        superPoderB++;
    }

    if(cidadeA.area > cidadeB.area)
    {
        printf("Melhor área: %s\n", cidadeA.nome);
        superPoderA++;
    }
    else if(cidadeA.area < cidadeB.area)
    {
        printf("Melhor área: %s\n", cidadeB.nome);
        superPoderB++;
    }

    if(cidadeA.pib > cidadeB.pib)
    {
        printf("Melhor PIB: %s\n", cidadeA.nome);
        superPoderA++;
    }
    else if(cidadeA.pib < cidadeB.pib)
    {
        printf("Melhor PIB: %s\n", cidadeB.nome);
        superPoderB++;
    }

    if(cidadeA.numero_pontos_turisticos > cidadeB.numero_pontos_turisticos)
    {
        printf("Maio qtd de pontos turísticos: %s\n", cidadeA.nome);
        superPoderA++;
    }
    else if(cidadeA.numero_pontos_turisticos < cidadeB.numero_pontos_turisticos)
    {
        printf("Maio qtd de pontos turísticos: %s\n", cidadeB.nome);
        superPoderB++;
    }

    if(cidadeA.densidade_populacional < cidadeB.densidade_populacional)
    {
        printf("Melhor densidade demográfica: %s\n", cidadeA.nome);
        superPoderA++;
    }
    else if(cidadeA.densidade_populacional > cidadeB.densidade_populacional)
    {
        printf("Melhor densidade demográfica: %s\n", cidadeB.nome);
        superPoderB++;
    }

    if(cidadeA.pib_per_capita > cidadeB.pib_per_capita)
    {
        printf("Melhor pib per capita: %s\n", cidadeA.nome);
        superPoderA++;
    }
    else if(cidadeA.pib_per_capita < cidadeB.pib_per_capita)
    {
        printf("Melhor pib per capita: %s\n", cidadeB.nome);
        superPoderB++;
    }

    printf("SuperPoder de %s é %d\n", cidadeA.nome, superPoderA);
    printf("SuperPoder de %s é %d\n", cidadeB.nome, superPoderB);
}

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    Cidade cidades[MAX_CIDADES];
    int quantidade = 0;
    int opcao;

    while(opcao != 4)
    {
        printf("\n\nTotal de cidades cadastradas %d. \n\n[SUPER TRUNFO MENU]\n\nO que você deseja fazer? \n[1] Adicionar nova cidade\n[2] Listar cidades\n[3] Calcular Super Poder\n[4] Sair\n\n>>", quantidade);
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarCidade(cidades, &quantidade);
                break;
            case 2:
                listarCidades(cidades, quantidade);
                break;
            case 3:
                calcularSuperPoder(cidades, quantidade);
                break;
            case 4:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
