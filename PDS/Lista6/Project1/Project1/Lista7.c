#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define TAMANHO_MAX 1000

// Funcao 1: Ler numeros de um arquivo
void lerArquivo(const char* nomeArquivo, double vetor[], int* tamanho) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    double numero;
    *tamanho = 0;

    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fscanf(arquivo, "%lf", &numero) == 1) {
        if (*tamanho < TAMANHO_MAX) {
            vetor[(*tamanho)++] = numero;
        }
        else {
            printf("Limite de elementos excedido.\n");
            break;
        }
    }

    fclose(arquivo);
}

// Funcao 2: Calcular a media
double calcularMedia(double vetor[], int n) {
    if (n == 0) return 0.0;

    double soma = 0.0;
    for (int i = 0; i < n; ++i) {
        soma += vetor[i];
    }

    return soma / n;
}

// Funcao 3: Calcular a variancia
double calcularVariancia(double vetor[], int n) {
    if (n <= 1) return 0.0;

    double media = calcularMedia(vetor, n);
    double variancia = 0.0;

    for (int i = 0; i < n; ++i) {
        variancia += (vetor[i] - media) * (vetor[i] - media);
    }

    return variancia / (n - 1);
}

// Funcao 4: Encontrar o maior elemento
double encontrarMaior(double vetor[], int n) {
    if (n == 0) return -DBL_MAX;

    double maior = vetor[0];
    for (int i = 1; i < n; ++i) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    return maior;
}

// Funcao 5: Encontrar o menor elemento
double encontrarMenor(double vetor[], int n) {
    if (n == 0) return DBL_MAX;

    double menor = vetor[0];
    for (int i = 1; i < n; ++i) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    return menor;
}

// Funcao 6: Produto escalar de dois vetores
double produtoEscalar(double u[], double v[], int n) {
    if (n == 0) return 0.0;

    double produto = 0.0;
    for (int i = 0; i < n; ++i) {
        produto += u[i] * v[i];
    }

    return produto;
}

// Menu principal
int main() {
    double vetor1[TAMANHO_MAX], vetor2[TAMANHO_MAX];
    int tamanho1 = 0, tamanho2 = 0, n;
    int escolha;

    do {
        printf("\nMenu:\n");
        printf("1. Ler numeros de um arquivo\n");
        printf("2. Calcular a media\n");
        printf("3. Calcular a variancia\n");
        printf("4. Encontrar o maior elemento\n");
        printf("5. Encontrar o menor elemento\n");
        printf("6. Calcular o produto escalar\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
        case 1: {
            char nomeArquivo[256];
            printf("Digite o nome do arquivo: ");
            scanf("%s", nomeArquivo);
            lerArquivo(nomeArquivo, vetor1, &tamanho1);
            printf("Numeros lidos com sucesso.\n");
            break;
        }
        case 2:
            printf("Digite o numero de elementos (n): ");
            scanf("%d", &n);
            if (n > tamanho1) n = tamanho1;
            printf("Media: %.2lf\n", calcularMedia(vetor1, n));
            break;
        case 3:
            printf("Digite o numero de elementos (n): ");
            scanf("%d", &n);
            if (n > tamanho1) n = tamanho1;
            printf("Variancia: %.2lf\n", calcularVariancia(vetor1, n));
            break;
        case 4:
            printf("Digite o numero de elementos (n): ");
            scanf("%d", &n);
            if (n > tamanho1) n = tamanho1;
            printf("Maior elemento: %.2lf\n", encontrarMaior(vetor1, n));
            break;
        case 5:
            printf("Digite o numero de elementos (n): ");
            scanf("%d", &n);
            if (n > tamanho1) n = tamanho1;
            printf("Menor elemento: %.2lf\n", encontrarMenor(vetor1, n));
            break;
        case 6:
            printf("Digite o numero de elementos (n): ");
            scanf("%d", &n);
            if (n > tamanho1) n = tamanho1;
            printf("Digite os elementos do segundo vetor:\n");
            for (int i = 0; i < n; ++i) {
                scanf("%lf", &vetor2[i]);
            }
            printf("Produto escalar: %.2lf\n", produtoEscalar(vetor1, vetor2, n));
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}
