//Inclusoes
#include <stdio.h>
#include <stdlib.h>


//Definicoes de constante e tipos;
#define FALSE 0
#define VERDADEIRO 1
#define ERRO 1
#define SUCESSO 0

typedef unsigned int uint;


float max(float a, float b, float c);
float min(float a, float b, float c);
int par(int x);
int dentro(int x, int y, int z);
int fora(int x, int y, int z);
int bissexto(int ano);

int main(int argc, char** argv)
{
    float num1, num2, num3;

    printf("\n");

    printf("Digite três numeros reais (Digite enter, entre cada entrada): ");
    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);

    printf("\n");

    printf("1-a) %.4f \n", max(num1, num2, num3) );
    printf("1-b) %.4f \n", min(num1, num2, num3) );

    if (par(num1)){
        printf("2-a) Eh par \n");
    } else {
        printf("2-a) Eh impar \n");
    }

    if (dentro(num1, num2, num3)){
        printf("2-b) Esta dentro \n");
    } else {
        printf("2-b) Esta fora \n");
    }

    if (fora(num1, num2, num3)){
        printf("2-c) Esta fora \n");
    } else {
        printf("2-c) Esta dentro \n");
    }

    if (bissexto(num1)){
        printf("2-a) Eh bissexto \n");
    } else {
        printf("2-a) Nao eh bissexto \n");
    }

    printf("\n");


    return SUCESSO;
}

float max(float a, float b, float c){

    if(a > b){

        if(a > c){
            return a;
        } else {
            return c;
        }

    } else{
        if(b > c){
            return b;
        } else {
            return c;
        }

    }
}
float min(float a, float b, float c){
    if(a < b){

        if(a < c){
            return a;
        } else {
            return c;
        }

    } else{
        if(b < c){
            return b;
        } else {
            return c;
        }

    }
}

int par(int x){

    if((x%2) == 0){
        return VERDADEIRO;
    } else {
        return FALSE;
    }
}

int dentro(int x, int y, int z){
    return ((x>=y) && (x<=z));
}
int fora(int x, int y, int z){
    return ((x<y) || (x>z));
}

int bissexto(int ano){
    return (((ano%400) == 0) || (((ano%4) == 0) && ((ano%100) != 0) ) );
}
