#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

void ex01(void);
int primo(int x);
void ex02(void);
void ex03(void);
void ex04(void);
void ex05(void);
void printFile(char* caminho);

int main(int argc, char** argv)
{
    ex01();
    ex02();
    ex03();
    ex04();
    ex05();

    printFile("exercicio1.bin");

    return SUCESSO;
}

void printFile(char* caminho) {
    FILE* arq;
    arq = fopen(caminho, "rb");

    int N = 0;

    if (arq != NULL)
    {
        while (fread(&N, sizeof(int), 1, arq)) {
            printf("%d ", N);
        }

        fclose(arq);
    }

    return;
}

void ex01(void) {
    int n, i, j = 0;
    
    printf("Digite um inteiro: ");
    scanf("%d", &n);

    FILE* arquivo;
    arquivo = fopen("exercicio1.bin", "w+b");

    if (arquivo != NULL)
    {

        for (i = 0;j < n;i++) {
            if (primo(i)) {
                fwrite(&i, sizeof(int), 1, arquivo);
                j++;
            }
        }

        fclose(arquivo);
    }
    else {
        printf("Arquivo não encontrado");
    }

    return;
}

int primo(int x) {
   
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
    
}

void ex02(void) {
    FILE* arquivo_naturais = fopen("NumerosNaturais.txt", "r+");
    if (arquivo_naturais == NULL) {
        printf("Erro: arquivo 'NumerosNaturais.txt' não encontrado.\n");
        return;
    }
    FILE* arquivo_primos = fopen("ResultadoPrimos.txt", "w+");
    if (arquivo_primos == NULL) {
        printf("Erro: não foi possível criar o arquivo 'ResultadoPrimos.txt'.\n");
        fclose(arquivo_naturais);
        return;
    }

    int numero;
    while (fscanf(arquivo_naturais, "%d", &numero) == 1) {
        if (primo(numero)) {
            fprintf(arquivo_primos, "O número % d é primo\n", numero);
        }
        else
        {
            fprintf(arquivo_primos, "O número %d não é primo\n", numero);
        }
    }
    fclose(arquivo_naturais);
    fclose(arquivo_primos);

    printf("Processamento concluído. Verifique o arquivo 'ResultadoPrimos.txt'.\n");
    return;
}

void ex03(void) {
    
    FILE* arquivo_naturais = fopen("NumerosNaturais.txt", "r+");
    if (arquivo_naturais == NULL) {
        printf("Erro: arquivo 'NumerosNaturais.txt' não encontrado.\n");
        return;
    }

    
    FILE* arquivo_primos = fopen("NumerosPrimos.txt", "w+");
    if (arquivo_primos == NULL) {
        printf("Erro: não foi possível criar o arquivo 'NumerosPrimos.txt'.\n");
        fclose(arquivo_naturais);
        return;
    }

    
    FILE* arquivo_outros = fopen("NumerosNaoPrimos.txt", "w+");
    if (arquivo_outros == NULL) {
        printf("Erro: não foi possível criar o arquivo 'NumerosNaoPrimos.txt'.\n");
        fclose(arquivo_naturais);
        fclose(arquivo_primos);
        return;
    }

    
    int numero;

   
    while (fscanf(arquivo_naturais, "%d", &numero) == 1) {
        if (primo(numero)) {
            fprintf(arquivo_primos, "%d\n", numero);
        }
        else {
            fprintf(arquivo_outros, "%d\n", numero);
        }
    }

    
    fclose(arquivo_naturais);
    fclose(arquivo_primos);
    fclose(arquivo_outros);

    printf("Processamento concluído. Verifique os arquivos 'NumerosPrimos.txt' e 'NumerosNaoPrimos.txt'.\n");
    return;
    

}

void ex04(void) {

    FILE* arquivo_reais = fopen("NumerosReais.txt", "r+t");
    if (arquivo_reais == NULL) {
        printf("Erro: arquivo 'NumerosReais.txt' não encontrado.\n");
        return;
    }

    FILE* arquivo_resultados = fopen("ResultadosFuncao.txt", "w+t");
    if (arquivo_resultados == NULL) {
        printf("Erro: não foi possível criar o arquivo 'ResultadosFuncao.txt'.\n");
        fclose(arquivo_reais);
        return;
    }

    fprintf(arquivo_resultados, "Resultados da função f(x) = x² - 5x + 1:\n");

    float numero;

    while (fscanf(arquivo_reais, "%f", &numero) == 1) {
        fprintf(arquivo_resultados, "f(%.2f) = %.2f\n", numero, ((numero * numero) - (5 * numero) + 1));
    }

    fclose(arquivo_reais);
    fclose(arquivo_resultados);

    printf("Processamento concluído. Verifique o arquivo 'ResultadosFuncao.txt'.\n");

    return;
 
}

void ex05(void) {

    FILE* arquivo_reais = fopen("NumerosReais.txt", "r+t");
    if (arquivo_reais == NULL) {
        printf("Erro: arquivo 'NumerosReais.txt' não encontrado.\n");
        return;
    }

    FILE* arquivo_resultados = fopen("ResultadosPolinomio.txt", "w+t");
    if (arquivo_resultados == NULL) {
        printf("Erro: não foi possível criar o arquivo 'ResultadosPolinomio.txt'.\n");
        fclose(arquivo_reais);
        return;
    }

    float a, b, c, d;

    printf("Insira o valor do coeficiente 'a': ");
    scanf("%f", &a);
    printf("Insira o valor do coeficiente 'b': ");
    scanf("%f", &b);
    printf("Insira o valor do coeficiente 'c': ");
    scanf("%f", &c);
    printf("Insira o valor do coeficiente 'd': ");
    scanf("%f", &d);

    fprintf(arquivo_resultados, "f(x) = %.2fx³ + %.2fx² + %.2fx + %.2f:\n", a, b, c, d);

    float numero;

    while (fscanf(arquivo_reais, "%f", &numero) == 1) {
        fprintf(arquivo_resultados, "f(%.2f) = %.2f\n", numero, ((a* numero* numero* numero) + (b * numero * numero) + (c * numero) + d));
    }

    fclose(arquivo_reais);
    fclose(arquivo_resultados);

    printf("Processamento concluído. Verifique o arquivo 'ResultadosPolinomio.txt'.\n");
    return;

}