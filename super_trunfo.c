#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_ATRIBUTOS 5

typedef struct {
    char pais[50];
    char codigo[10];
    char capital[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

typedef struct {
    int codigo;
    char nome[30];
    bool disponivel;
} Atributo;

void calcular_densidade(Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
}

void exibir_carta(Carta carta) {
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

void inicializar_atributos(Atributo atributos[]) {
    Atributo pop = {1, "População", true};
    Atributo area = {2, "Área", true};
    Atributo pib = {3, "PIB", true};
    Atributo pontos = {4, "Pontos Turísticos", true};
    Atributo dens = {5, "Densidade Demográfica", true};
    
    atributos[0] = pop;
    atributos[1] = area;
    atributos[2] = pib;
    atributos[3] = pontos;
    atributos[4] = dens;
}

void exibir_menu_atributos(Atributo atributos[], char* mensagem) {
    printf("\n%s\n", mensagem);
    for(int i = 0; i < NUM_ATRIBUTOS; i++) {
        if(atributos[i].disponivel) {
            printf("%d - %s\n", atributos[i].codigo, atributos[i].nome);
        }
    }
    printf("0 - Cancelar\n");
    printf("Digite sua opção: ");
}

float obter_valor_atributo(Carta carta, int atributo) {
    switch(atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontos_turisticos;
        case 5: return carta.densidade;
        default: return 0;
    }
}

void comparar_atributo(Carta c1, Carta c2, int atributo, int* pontos_c1, int* pontos_c2) {
    float valor1 = obter_valor_atributo(c1, atributo);
    float valor2 = obter_valor_atributo(c2, atributo);
    
    printf("\n--- Comparação de %s ---\n", 
           (atributo == 1) ? "População" :
           (atributo == 2) ? "Área" :
           (atributo == 3) ? "PIB" :
           (atributo == 4) ? "Pontos Turísticos" : "Densidade Demográfica");
    
    printf("%s: %.2f\n", c1.pais, valor1);
    printf("%s: %.2f\n", c2.pais, valor2);
    
    if(atributo == 5) { // Densidade (menor vence)
        if(valor1 < valor2) {
            printf("%s vence neste atributo!\n", c1.pais);
            (*pontos_c1)++;
        } else if(valor2 < valor1) {
            printf("%s vence neste atributo!\n", c2.pais);
            (*pontos_c2)++;
        } else {
            printf("Empate neste atributo!\n");
        }
    } else { // Demais atributos (maior vence)
        if(valor1 > valor2) {
            printf("%s vence neste atributo!\n", c1.pais);
            (*pontos_c1)++;
        } else if(valor2 > valor1) {
            printf("%s vence neste atributo!\n", c2.pais);
            (*pontos_c2)++;
        } else {
            printf("Empate neste atributo!\n");
        }
    }
}

int main() {
    // Cadastro das cartas
    Carta carta1 = {
        .pais = "Brasil",
        .codigo = "BR001",
        .capital = "Brasília",
        .populacao = 213000000,
        .area = 8515767.049,
        .pib = 1.609e6,
        .pontos_turisticos = 25
    };
    
    Carta carta2 = {
        .pais = "Argentina",
        .codigo = "AR001",
        .capital = "Buenos Aires",
        .populacao = 45380000,
        .area = 2780400,
        .pib = 0.445e6,
        .pontos_turisticos = 18
    };
    
    calcular_densidade(&carta1);
    calcular_densidade(&carta2);
    
    printf("=== SUPER TRUNFO - NÍVEL MESTRE ===\n");
    printf("=== CARTAS DISPONÍVEIS ===\n");
    exibir_carta(carta1);
    exibir_carta(carta2);
    
    Atributo atributos[NUM_ATRIBUTOS];
    inicializar_atributos(atributos);
    
    int atributo1 = 0, atributo2 = 0;
    int pontos_c1 = 0, pontos_c2 = 0;
    
    // Seleção do primeiro atributo
    do {
        exibir_menu_atributos(atributos, "Escolha o PRIMEIRO atributo para comparação:");
        scanf("%d", &atributo1);
        
        if(atributo1 == 0) {
            printf("Jogo cancelado.\n");
            return 0;
        }
        
        if(atributo1 < 1 || atributo1 > NUM_ATRIBUTOS || !atributos[atributo1-1].disponivel) {
            printf("Opção inválida! Tente novamente.\n");
            atributo1 = 0;
        }
    } while(atributo1 == 0);
    
    atributos[atributo1-1].disponivel = false;
    
    // Seleção do segundo atributo
    do {
        exibir_menu_atributos(atributos, "Escolha o SEGUNDO atributo para comparação:");
        scanf("%d", &atributo2);
        
        if(atributo2 == 0) {
            printf("Jogo cancelado.\n");
            return 0;
        }
        
        if(atributo2 < 1 || atributo2 > NUM_ATRIBUTOS || !atributos[atributo2-1].disponivel) {
            printf("Opção inválida! Tente novamente.\n");
            atributo2 = 0;
        }
    } while(atributo2 == 0);
    
    // Comparação dos atributos
    comparar_atributo(carta1, carta2, atributo1, &pontos_c1, &pontos_c2);
    comparar_atributo(carta1, carta2, atributo2, &pontos_c1, &pontos_c2);
    
    // Resultado final
    printf("\n=== RESULTADO FINAL ===\n");
    printf("Pontuação %s: %d\n", carta1.pais, pontos_c1);
    printf("Pontuação %s: %d\n", carta2.pais, pontos_c2);
    
    if(pontos_c1 > pontos_c2) {
        printf("\n%s VENCEU A RODADA!\n", carta1.pais);
    } else if(pontos_c2 > pontos_c1) {
        printf("\n%s VENCEU A RODADA!\n", carta2.pais);
    } else {
        printf("\nEMPATE!\n");
    }
    
    return 0;
}