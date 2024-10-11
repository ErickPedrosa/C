//Inclusoes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Definicoes de constante e tipos;
#define ERRO 1
#define SUCESSO 0
#define PI 3.1415

typedef unsigned int uint;


void ex1(void);
void ex2(void);
void ex3(void);


float media(float a, float b, float c);
float mediaP(float a, float b, float c, int pesoA, int pesoB, int pesoC);
float perimetroC(float raio);
float areaCirculo(float raio);
float areaT(float base, float altura);
float hipotenusa(float ladoA, float ladoB);
void raizes(float a, float b, float c);

int main(int argc, char** argv)
{
    ex1();
    ex2();
    ex3();
    

    return 0;
}


void ex1(void){

    printf("Exercicio 1: \n");
    printf("\n");

    printf("1-a) %d \n", (3 + 4) );
    printf("1-b) %d \n", (7 / 4) );
    printf("1-c) %f \n", pow(3, 2) );
    printf("1-d) %f \n", (5.3 * 2.1) );
    printf("1-e) %d \n", (2 * 5 - 2) );
    printf("1-f) %d \n", (2 + 2 * 5) );
    printf("1-g) %d \n", ((2 + 5) * 3) );
    printf("1-h) %f \n", sin(3.141502) );
    printf("1-i) %f \n", sqrt(5) );
    printf("1-j) %d \n", (1 + 2 + 3) );
    printf("1-k) %d \n", (1 * 2 * 3) );
    printf("1-l) %f \n", ((1 + 2 + 3) / 3.0) );
    printf("1-m) %d \n", ((2 + 4) * (3 - 1)) );
    printf("1-n) %d \n", ((9 / 3) + (3 * 2)) );
    printf("1-o) %f \n", sin(4.5) + cos(3.7) );
    printf("1-p) %f \n", log(2.3) - log(3.1));
    printf("1-q) %f \n", log(7) + (log(7) * log(7) - cos(log(7))) );
    printf("1-r) %f \n", (10.3 + 8.4) / 50.3 - (10.3 + 8.4) );
    printf("1-s) %f \n", (cos(0.8) + sin(0.8)) * (cos(0.8) - sin(0.8)) );

    printf("\n");

    return;
}


void ex2(void){

    float num1, num2, num3, num4;

    printf("Exercicio 2: \n");

    printf("Digite quatro numeros reais (Digite enter, entre cada entrada): ");
    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);
    scanf("%f", &num4);

    printf("\n");

    printf("2-a) %.4f \n", (num1 + num2) );
    printf("2-b) %.4f \n", (num1 / num3) );
    printf("2-c) %.4f \n", pow(num1, 2) );
    printf("2-d) %.4f \n", (num2 * num3) );
    printf("2-e) %.4f \n", (num1 * num2 - num3) );
    printf("2-f) %.4f \n", (num1 + num2 * num3) );
    printf("2-g) %.4f \n", ((num1 + num2) * num3) );
    printf("2-h) %.4f \n", sin(num1) );
    printf("2-i) %.4f \n", sqrt(num2) );
    printf("2-j) %.4f \n", (num1 + num2 + num3) );
    printf("2-k) %.4f \n", (num1 * num2 * num3) );
    printf("2-l) %.4f \n", ((num1 + num2 + num3) / num4) );
    printf("2-m) %.4f \n", ((num1 + num2) * (num1 - num4)) );
    printf("2-n) %.4f \n", ((num2 / num3) + (num1 * num4)) );
    printf("2-o) %.4f \n", sin(num2) + cos(num3) );
    printf("2-p) %.4f \n", log(num1) - log(num3));
    printf("2-q) %f \n", log(num1) + (log(num2) * log(num4) - cos(log(num3))) );
    printf("2-r) %f \n", (num2 + num1) / num3 - (num4 + num1) );
    printf("2-s) %f \n", (cos(num4) + sin(num3)) * (cos(num2) - sin(num1)) );

    printf("\n");

    return;
}


void ex3(void){


    float num1, num2, num3;

    printf("Exercicio 3: \n");

    printf("Digite três numeros reais (Digite enter, entre cada entrada): ");
    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);

    printf("\n");

    printf("3-a) %.4f \n", media(num1, num2, num3) );
    printf("3-b) %.4f \n", mediaP(num1, num2, num3, 3, 4, 5) );
    printf("3-c) %.4f \n", perimetroC(num1) );
    printf("3-d) %.4f \n", areaCirculo(num1) );
    printf("3-e) %.4f \n", areaT(num2, num3) );
    printf("3-f) %.4f \n", hipotenusa(num2, num3) );
    raizes(num1, num2, num3);
    
    printf("\n");

    return;
}


//Funções do Exercício 3

float media(float a, float b, float c){
    float media;

    media = (a + b + c) / 3;

    return media;
}

float mediaP(float a, float b, float c, int pesoA, int pesoB, int pesoC){
    float media, produto, pesoTotal;

    produto = (a * pesoA) + (b * pesoB) + (c * pesoC);
    pesoTotal = pesoA + pesoB + pesoC;
    media  = produto / pesoTotal;

    return media;
}

float perimetroC(float raio){
    float perimetro;

    perimetro = 2 * PI * raio;

    return perimetro;
}

float areaCirculo(float raio){
    float area;

    area = PI * (pow(raio, 2));

    return area;
}
float areaT(float base, float altura){
    float area;

    area = (base * altura) / 2;

    return area;
}
float hipotenusa(float ladoA, float ladoB){
    float hip;
    
    hip = sqrt( pow(ladoA, 2) + pow(ladoB, 2) );

    return hip;
}


void raizes(float a, float b, float c){
    float discriminante;
    float raiz[2];

    discriminante = (pow(b, 2)) - (4*a*c);

    if (discriminante < 0)
    {
        printf("3-g) A expressão não possui raízes reais. \n");
    }else if(discriminante == 0){
        raiz[0] = ((-b))/ (2*a);
        
        printf("3-g) A raiz da equação é: %.4f \n", raiz[0]);

    }else{
        raiz[0] = ((-b) + sqrt(discriminante))/ (2*a);
        raiz[1] = ((-b) - sqrt(discriminante))/ (2*a);
        
        printf("3-g) As raizes da equação são: %.4f e %.4f \n", raiz[0], raiz[1] );

    }        


    return;
}