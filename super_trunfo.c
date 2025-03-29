#include <stdio.h>
#include <string.h>

// Definição da estrutura da carta
typedef struct
{
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

// Função para calcular densidade e PIB per capita
void calcular_metricas(Carta *carta)
{
    carta->densidade = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta carta)
{
    printf("\nDados da Carta:\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
}

int main()
{
    // Cadastro das duas cartas (pré-definidas)
    Carta carta1 = {
        .estado = "SP",
        .codigo = "SP001",
        .cidade = "São Paulo",
        .populacao = 12300000,
        .area = 1521.11,
        .pib = 1.8e6, // 1.8 trilhões
        .pontos_turisticos = 50};

    Carta carta2 = {
        .estado = "RJ",
        .codigo = "RJ001",
        .cidade = "Rio de Janeiro",
        .populacao = 6748000,
        .area = 1200.27,
        .pib = 0.8e6, // 0.8 trilhões
        .pontos_turisticos = 45};

    // Calcular métricas para ambas as cartas
    calcular_metricas(&carta1);
    calcular_metricas(&carta2);

    // Exibir dados das cartas
    exibir_carta(carta1);
    exibir_carta(carta2);

    // Escolher o atributo para comparação (definido no código)
    // Opções: "populacao", "area", "pib", "densidade", "pib_per_capita"
    char atributo_escolhido[] = "populacao"; // Podemos mudar este valor para testar diferentes atributos

    printf("\nComparação de cartas (Atributo: %s):\n", atributo_escolhido);

    // Variáveis para armazenar os valores comparados
    float valor1, valor2;

    // Determinar qual atributo será comparado
    if (strcmp(atributo_escolhido, "populacao") == 0)
    {
        valor1 = carta1.populacao;
        valor2 = carta2.populacao;
        printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);
    }
    else if (strcmp(atributo_escolhido, "area") == 0)
    {
        valor1 = carta1.area;
        valor2 = carta2.area;
        printf("Carta 1 - %s (%s): %.2f km²\n", carta1.cidade, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f km²\n", carta2.cidade, carta2.estado, carta2.area);
    }
    else if (strcmp(atributo_escolhido, "pib") == 0)
    {
        valor1 = carta1.pib;
        valor2 = carta2.pib;
        printf("Carta 1 - %s (%s): %.2f milhões\n", carta1.cidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): %.2f milhões\n", carta2.cidade, carta2.estado, carta2.pib);
    }
    else if (strcmp(atributo_escolhido, "densidade") == 0)
    {
        valor1 = carta1.densidade;
        valor2 = carta2.densidade;
        printf("Carta 1 - %s (%s): %.2f hab/km²\n", carta1.cidade, carta1.estado, carta1.densidade);
        printf("Carta 2 - %s (%s): %.2f hab/km²\n", carta2.cidade, carta2.estado, carta2.densidade);
    }
    else if (strcmp(atributo_escolhido, "pib_per_capita") == 0)
    {
        valor1 = carta1.pib_per_capita;
        valor2 = carta2.pib_per_capita;
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.pib_per_capita);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.pib_per_capita);
    }
    else
    {
        printf("Atributo inválido para comparação.\n");
        return 1;
    }

    // Comparar os valores e determinar o vencedor
    if (strcmp(atributo_escolhido, "densidade") == 0)
    {
        // Para densidade, o menor valor vence
        if (valor1 < valor2)
        {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        }
        else if (valor2 < valor1)
        {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        }
        else
        {
            printf("Resultado: Empate!\n");
        }
    }
    else
    {
        // Para outros atributos, o maior valor vence
        if (valor1 > valor2)
        {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        }
        else if (valor2 > valor1)
        {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        }
        else
        {
            printf("Resultado: Empate!\n");
        }
    }

    return 0;
}