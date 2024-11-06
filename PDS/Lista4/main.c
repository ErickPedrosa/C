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
int primo(int num, int divisor);
int ehPrimo(int num);
void decrescente(int num);
int resto(int num, int num2);
int form(int num);
int mmc(int a, int b);
int div_(int a, int b);
float sqrt_(float num);
float raiz(float num, float chute);
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
    if (num == 0)
    {
        return 1;
    }else{

        return num * fat(num - 1);
    }
}

int mdc(int n, int n2){
    if (n%n2 == 0)
    {
        return n2;
    }else{
        return mdc(n2, n%n2);
    }
    
}

int mdc3(int n, int n2, int n3){
    return (mdc(mdc(n, n2), n3));

}

int fib(int num){
    if ((num == 1) || (num == 2))
    {
        return 1;
    }
    
    return ( fib(num - 1) + fib(num -2) );

}

int ehPrimo(int num){
    
    return primo(num, (num - 1));

}

int primo(int num, int divisor){
    if (divisor == 1)
    {
        return VERDADEIRO;
    }
    if ((num % divisor) == 0)
    {
        return FALSO;
    }
    return primo( num, (divisor - 1) );
}

void decrescente(int num){
    if (num == 1)
    {
        return;
    }
    
    printf( " %d ", (num - 1) );

    return decrescente( num - 1 );

}

int resto(int num, int num2){
    if ((num - num2) < 0)
    {
        return num;
    }
    if ((num - num2) == 0)
    {
        return 0;
    }
    resto((num - num2), num2);
    
}

int form(int num){
    if (num == 1)
    {
        return 1;
    }
    return ((num * num) + ( form(num-1) ));
    
}

int mmc(int a, int b){

    return ((a * b) / (mdc(a, b)));

}

int div_(int a, int b){
    if (a < b)
    {
        return 0;
    }
    return (1 + div_((a - b), b));
}

float sqrt_(float num){
    
    return raiz(num, (num/2));
}

float raiz(float num, float chute){

    if ( ((chute*chute) <= (num+0.0001))  &&  ((chute*chute) >= (num-0.0001)) )
    {
        return chute;
    }
    
    if ( ((chute*chute) < (num)) )
    {
        return raiz(num, (1.5 * chute));
    }

    if ( ((chute*chute) > (num)) )
    {
        return raiz(num, (0.5 * chute));
    }
}

int dig(int num){
    if(num == 0){
        return 0;
    }
    return (num % 10) + dig(num / 10);
}

int exp_(int k, int n){
    if (n == 1)
    {
        return k;
    }
    return k * exp_(k, (n-1));
    
}

void crescente(int num){
    if (num == 0)
    {
        return;
    }
    
    crescente( num - 1 );

    printf( " %d ", (num) );

    return;
}