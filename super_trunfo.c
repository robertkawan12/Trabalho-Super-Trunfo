#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Definição da estrutura da carta
typedef struct
{
    char pais[50];
    char codigo[10];
    char capital[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

// Função para calcular densidade demográfica
void calcular_densidade(Carta *carta)
{
    carta->densidade = carta->populacao / carta->area;
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta carta)
{
    printf("\nDados da Carta:\n");
    printf("País: %s\n", carta.pais);
    printf("Código: %s\n", carta.codigo);
    printf("Capital: %s\n", carta.capital);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões de dólares\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidade);
}

// Função para exibir o menu de opções
void exibir_menu()
{
    printf("\nMENU - SUPER TRUNFO\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("0 - Sair do jogo\n");
    printf("Digite sua opção: ");
}

// Função para comparar as cartas
void comparar_cartas(Carta c1, Carta c2, int opcao)
{
    printf("\n--- RESULTADO DA COMPARAÇÃO ---\n");

    switch (opcao)
    {
    case 1: // População
        printf("Atributo: População\n");
        printf("%s: %d habitantes\n", c1.pais, c1.populacao);
        printf("%s: %d habitantes\n", c2.pais, c2.populacao);

        if (c1.populacao > c2.populacao)
        {
            printf("Vencedor: %s\n", c1.pais);
        }
        else if (c2.populacao > c1.populacao)
        {
            printf("Vencedor: %s\n", c2.pais);
        }
        else
        {
            printf("Empate!\n");
        }
        break;

    case 2: // Área
        printf("Atributo: Área\n");
        printf("%s: %.2f km²\n", c1.pais, c1.area);
        printf("%s: %.2f km²\n", c2.pais, c2.area);

        if (c1.area > c2.area)
        {
            printf("Vencedor: %s\n", c1.pais);
        }
        else if (c2.area > c1.area)
        {
            printf("Vencedor: %s\n", c2.pais);
        }
        else
        {
            printf("Empate!\n");
        }
        break;

    case 3: // PIB
        printf("Atributo: PIB\n");
        printf("%s: %.2f milhões de dólares\n", c1.pais, c1.pib);
        printf("%s: %.2f milhões de dólares\n", c2.pais, c2.pib);

        if (c1.pib > c2.pib)
        {
            printf("Vencedor: %s\n", c1.pais);
        }
        else if (c2.pib > c1.pib)
        {
            printf("Vencedor: %s\n", c2.pais);
        }
        else
        {
            printf("Empate!\n");
        }
        break;

    case 4: // Pontos Turísticos
        printf("Atributo: Pontos Turísticos\n");
        printf("%s: %d pontos\n", c1.pais, c1.pontos_turisticos);
        printf("%s: %d pontos\n", c2.pais, c2.pontos_turisticos);

        if (c1.pontos_turisticos > c2.pontos_turisticos)
        {
            printf("Vencedor: %s\n", c1.pais);
        }
        else if (c2.pontos_turisticos > c1.pontos_turisticos)
        {
            printf("Vencedor: %s\n", c2.pais);
        }
        else
        {
            printf("Empate!\n");
        }
        break;

    case 5: // Densidade Demográfica (regra invertida)
        printf("Atributo: Densidade Demográfica (menor valor vence)\n");
        printf("%s: %.2f hab/km²\n", c1.pais, c1.densidade);
        printf("%s: %.2f hab/km²\n", c2.pais, c2.densidade);

        if (c1.densidade < c2.densidade)
        {
            printf("Vencedor: %s\n", c1.pais);
        }
        else if (c2.densidade < c1.densidade)
        {
            printf("Vencedor: %s\n", c2.pais);
        }
        else
        {
            printf("Empate!\n");
        }
        break;

    default:
        printf("Opção inválida para comparação!\n");
    }
}

int main()
{

    // Cadastro das duas cartas (países)
    Carta carta1 = {
        .pais = "Brasil",
        .codigo = "BR001",
        .capital = "Brasília",
        .populacao = 213000000,
        .area = 8515767.049,
        .pib = 1.609e6, // 1.609 trilhões de dólares
        .pontos_turisticos = 25};

    Carta carta2 = {
        .pais = "Argentina",
        .codigo = "AR001",
        .capital = "Buenos Aires",
        .populacao = 45380000,
        .area = 2780400,
        .pib = 0.445e6, // 0.445 trilhões de dólares
        .pontos_turisticos = 18};

    // Calcular métricas
    calcular_densidade(&carta1);
    calcular_densidade(&carta2);

    // Exibir dados das cartas
    printf("=== CARTAS DISPONÍVEIS ===\n");
    exibir_carta(carta1);
    exibir_carta(carta2);

    int opcao;
    do
    {
        exibir_menu();
        scanf("%d", &opcao);

        // Limpar buffer do teclado
        while (getchar() != '\n')
            ;

        switch (opcao)
        {
        case 1: // População
        case 2: // Área
        case 3: // PIB
        case 4: // Pontos Turísticos
        case 5: // Densidade
            comparar_cartas(carta1, carta2, opcao);
            break;

        case 0:
            printf("Saindo do jogo...\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }

        if (opcao != 0)
        {
            printf("\nPressione Enter para continuar...");
            while (getchar() != '\n')
                ;
        }

    } while (opcao != 0);

    return 0;
}