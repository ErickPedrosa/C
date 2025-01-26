#include <stdio.h>
#include <stdbool.h>

void ler_matriz_arquivo(const char* nome_arquivo, int* linhas, int* colunas, float matriz[100][100]);
float media_matriz(int n, float mat[][100]);
void identidade(int n, float A[][100]);
void transposta(int n, float A[][100], float T[][100]);
bool simetrica(int n, float A[][100]);
void soma_matriz(int n, float A[][100], float B[][100], float S[][100]);
void mult_matriz(int n, float A[][100], float B[][100], float P[][100]);

void mostrar_matriz(int linhas, int colunas, float matriz[100][100]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Ler matriz de arquivo\n");
        printf("2. Calcular média dos elementos da matriz\n");
        printf("3. Transformar matriz em identidade\n");
        printf("4. Obter matriz transposta\n");
        printf("5. Testar se a matriz é simétrica\n");
        printf("6. Somar duas matrizes\n");
        printf("7. Multiplicar duas matrizes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        int n, linhas, colunas;
        float A[100][100], B[100][100], R[100][100];
        char nome_arquivo[100];

        switch (opcao) {
        case 1:
            printf("Digite o nome do arquivo: ");
            scanf("%s", nome_arquivo);
            ler_matriz_arquivo(nome_arquivo, &linhas, &colunas, A);
            printf("Matriz lida:\n");
            mostrar_matriz(linhas, colunas, A);
            break;

        case 2:
            printf("Digite a dimensão da matriz quadrada: ");
            scanf("%d", &n);
            printf("Digite os elementos da matriz:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    scanf("%f", &A[i][j]);
                }
            }
            printf("Média dos elementos: %.2f\n", media_matriz(n, A));
            break;

        case 3:
            printf("Digite a dimensão da matriz quadrada: ");
            scanf("%d", &n);
            identidade(n, A);
            printf("Matriz identidade:\n");
            mostrar_matriz(n, n, A);
            break;

        case 4:
            printf("Digite a dimensão da matriz quadrada: ");
            scanf("%d", &n);
            printf("Digite os elementos da matriz:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    scanf("%f", &A[i][j]);
                }
            }
            transposta(n, A, R);
            printf("Matriz transposta:\n");
            mostrar_matriz(n, n, R);
            break;

        case 5:
            printf("Digite a dimensão da matriz quadrada: ");
            scanf("%d", &n);
            printf("Digite os elementos da matriz:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    scanf("%f", &A[i][j]);
                }
            }
            if (simetrica(n, A)) {
                printf("A matriz é simétrica.\n");
            }
            else {
                printf("A matriz não é simétrica.\n");
            }
            break;

        case 6:
            printf("Digite a dimensão das matrizes quadradas: ");
            scanf("%d", &n);
            printf("Digite os elementos da matriz A:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    scanf("%f", &A[i][j]);
                }
            }
            printf("Digite os elementos da matriz B:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    scanf("%f", &B[i][j]);
                }
            }
            soma_matriz(n, A, B, R);
            printf("Matriz soma:\n");
            mostrar_matriz(n, n, R);
            break;

        case 7:
            printf("Digite a dimensão das matrizes quadradas: ");
            scanf("%d", &n);
            printf("Digite os elementos da matriz A:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    scanf("%f", &A[i][j]);
                }
            }
            printf("Digite os elementos da matriz B:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    scanf("%f", &B[i][j]);
                }
            }
            mult_matriz(n, A, B, R);
            printf("Matriz produto:\n");
            mostrar_matriz(n, n, R);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}

void ler_matriz_arquivo(const char* nome_arquivo, int* linhas, int* colunas, float matriz[100][100]) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fscanf(arquivo, "%d %d", linhas, colunas);
    for (int i = 0; i < *linhas; i++) {
        for (int j = 0; j < *colunas; j++) {
            fscanf(arquivo, "%f", &matriz[i][j]);
        }
    }
    fclose(arquivo);
}

float media_matriz(int n, float mat[][100]) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            soma += mat[i][j];
        }
    }
    return soma / (n * n);
}

void identidade(int n, float A[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = (i == j) ? 1 : 0;
        }
    }
}

void transposta(int n, float A[][100], float T[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[j][i] = A[i][j];
        }
    }
}

bool simetrica(int n, float A[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i][j] != A[j][i]) {
                return false;
            }
        }
    }
    return true;
}

void soma_matriz(int n, float A[][100], float B[][100], float S[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            S[i][j] = A[i][j] + B[i][j];
        }
    }
}

void mult_matriz(int n, float A[][100], float B[][100], float P[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            P[i][j] = 0;
            for (int k = 0; k < n; k++) {
                P[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
