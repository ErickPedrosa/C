//Inclusoes
#include <stdio.h>
#include <stdlib.h>


//Definicoes de constante e tipos;
#define ERRO 1
#define SUCESSO 0
#define VERDADEIRO (1 == 1)
#define FALSO (!VERDADEIRO)
#define PI 3.1415

typedef unsigned int uint;


int fat(int num);
int mdc(int n, int n2);
int mdc3(int n, int n2, int n3);
int fib(int num);
int ehPrimo(int num);
void decrescente(int num);
int resto(int num, int num2);
int form(int num);
int mmc(int a, int b);
int div_(int num, int num2);
float sqrt_(float num);
int dig(int num);
int exp_(int k, int n);
void crescente(int num); 

int main(int argc, char ** argv) {

  float num1, num2, num3;

    printf("\n");

    printf("Digite três numeros reais (Digite enter, entre cada entrada): ");
    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);

    printf("\n");

    printf("a) %.4f \n", (float)fat(num1) );
    printf("b) %.4f \n", (float)mdc(num1, num2) );
    printf("c) %.4f \n", (float)mdc3(num1, num2, num3) );
    printf("d) %.4f \n", (float)fib(num1) );
    printf("e) %.4f \n", (float)ehPrimo(num2) );
    printf("f) ");
    decrescente(num1);
    printf("\ng) %.4f \n", (float)resto(num1, num2) );
    printf("h) %.4f \n", (float)form(num1) );
    printf("i) %.4f \n", (float)mmc(num2, num3) );
    printf("j) %.4f \n", (float)div_(num1, num2) );
    printf("k) %.4f \n", sqrt_(num1) );
    printf("l) %.4f \n", (float)dig(num1) );
    printf("m) %.4f \n", (float)exp_(num1, num2) );
    printf("n) ");
    crescente(num1);
    
    printf("\n");
}


int fat(int num){
    int fatorial = 1;

    for(int i = 1; i <= num; i++){
        fatorial *= i;
    }
    
    return fatorial;
}

int mdc(int n, int n2){
    int divisor;

    if (n > n2)
    {
        for (int i = 1; i <= n2; i++)
        {
            if ((n%i == 0) && (n2%i == 0))
            {
                divisor = i;
            }
            
        }
        
    }else{

        for (int i = 1; i <= n; i++)
        {
            if ((n%i == 0) && (n2%i == 0))
            {
                divisor = i;
            }
            
        }

    }
    
    return divisor;
    
}

int mdc3(int n, int n2, int n3){
    return (mdc(mdc(n, n2), n3));

}

int fib(int num){
    int f1 = 1, f2 = 1, f3 = 1;

    for (int i = 2; i < num; i++)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3; 
    }
    
    return f3;

}

int ehPrimo(int num){
    
    int divisor;

    for (int i = 2; i < num; i++)
    {
        divisor = i;
        if ((num % divisor) == 0)
        {
            return FALSO;
        }
    }
    
    return VERDADEIRO;
}

void decrescente(int num){
    
    for (int i = num; i > 0; i--)
    {
        printf( " %d ", i );
    }

    printf("\n");

    return;

}

int resto(int num, int num2){
    
    while ((num-num2) >= 0)
    {
        num = num - num2;
    }

    return num;
    
}

int form(int num){
    
    int soma = 0;

    for (int i = 1; i <= num; i++)
    {
        soma += (num * num);    
    }
    
    return soma;
}

int mmc(int a, int b){

    return ((a * b) / (mdc(a, b)));

}

int div_(int num, int num2){
    
    int div = 0;

    while ((num-num2) >= 0)
    {
        num = num - num2;
        div++;
    }

    return div;

}

float sqrt_(float num){

    float chute = (num/2);
    
    while ( ((chute*chute) > (num+0.0001))  ||  ((chute*chute) < (num-0.0001)) )
    {
        if ( ((chute*chute) < (num)) )
        {
            chute *= 1.5;
        }

        if ( ((chute*chute) > (num)) )
        {
            chute *= 0.5;
        }

    }
    
    return chute;
}


int dig(int num){
    int soma = 0, resto = 0;

    do
    {
        soma += (num % 10);
        resto = num/10;
        num = resto;

    } while (resto != 0);
    
    return soma;
}

int exp_(int k, int n){
    int total = 1;
    
    for (int i = 0; i < n; i++)
    {
        total  = total * k;
    }
    
    return total;
    
}

void crescente(int num){
    
    for (int i = 1; i <= num; i++)
    {
        printf( " %d ", (i) );
    }
    

    printf("\n");

    return;
}
