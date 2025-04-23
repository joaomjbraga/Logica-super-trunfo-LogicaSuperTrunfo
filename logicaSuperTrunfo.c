#include <stdio.h>
#include <string.h>

// Função auxiliar para exibir atributos
void exibirAtributos() {
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
}

// Função para obter valor de um atributo
float obterValor(int atributo, unsigned long pop, float area, float pib, int pt, float densidade) {
    switch (atributo) {
        case 1: return (float)pop;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pt;
        case 5: return densidade;
        default: return -1;
    }
}

int main() {
    // Dados da Carta 1
    char nome1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;
    float densidade1;

    // Dados da Carta 2
    char nome2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontosTuristicos2;
    float densidade2;

    // Entrada das Cartas
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", nome1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);
    densidade1 = populacao1 / area1;

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", nome2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);
    densidade2 = populacao2 / area2;

    int escolha1, escolha2;

    // Primeiro atributo
    printf("\nEscolha o primeiro atributo:\n");
    exibirAtributos();
    printf("Escolha: ");
    scanf("%d", &escolha1);

    // Segundo atributo com menu dinâmico
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    exibirAtributos();
    printf("Escolha: ");
    do {
        scanf("%d", &escolha2);
        if (escolha2 == escolha1)
            printf("Atributo repetido! Escolha outro: ");
    } while (escolha2 == escolha1);

    float val1_attr1 = obterValor(escolha1, populacao1, area1, pib1, pontosTuristicos1, densidade1);
    float val2_attr1 = obterValor(escolha1, populacao2, area2, pib2, pontosTuristicos2, densidade2);

    float val1_attr2 = obterValor(escolha2, populacao1, area1, pib1, pontosTuristicos1, densidade1);
    float val2_attr2 = obterValor(escolha2, populacao2, area2, pib2, pontosTuristicos2, densidade2);

    // Lógica da comparação
    int pontos1 = 0, pontos2 = 0;

    // Comparação do atributo 1
    if (escolha1 == 5) { // densidade (menor vence)
        pontos1 += (val1_attr1 < val2_attr1) ? 1 : (val1_attr1 > val2_attr1 ? 0 : 0);
        pontos2 += (val2_attr1 < val1_attr1) ? 1 : (val1_attr1 > val2_attr1 ? 0 : 0);
    } else {
        pontos1 += (val1_attr1 > val2_attr1) ? 1 : (val1_attr1 < val2_attr1 ? 0 : 0);
        pontos2 += (val2_attr1 > val1_attr1) ? 1 : (val1_attr1 < val2_attr1 ? 0 : 0);
    }

    // Comparação do atributo 2
    if (escolha2 == 5) { // densidade (menor vence)
        pontos1 += (val1_attr2 < val2_attr2) ? 1 : (val1_attr2 > val2_attr2 ? 0 : 0);
        pontos2 += (val2_attr2 < val1_attr2) ? 1 : (val1_attr2 > val2_attr2 ? 0 : 0);
    } else {
        pontos1 += (val1_attr2 > val2_attr2) ? 1 : (val1_attr2 < val2_attr2 ? 0 : 0);
        pontos2 += (val2_attr2 > val1_attr2) ? 1 : (val1_attr2 < val2_attr2 ? 0 : 0);
    }

    float soma1 = val1_attr1 + val1_attr2;
    float soma2 = val2_attr1 + val2_attr2;

    // Exibição dos resultados
    printf("\n=== Resultado ===\n");
    printf("País 1: %s | Atributos: %.2f + %.2f = %.2f\n", nome1, val1_attr1, val1_attr2, soma1);
    printf("País 2: %s | Atributos: %.2f + %.2f = %.2f\n", nome2, val2_attr1, val2_attr2, soma2);

    if (soma1 > soma2)
        printf("Vencedor: %s\n", nome1);
    else if (soma2 > soma1)
        printf("Vencedor: %s\n", nome2);
    else
        printf("Empate!\n");

    return 0;
}
