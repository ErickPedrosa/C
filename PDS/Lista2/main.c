//Inclusoes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Definicoes de constante e tipos;
#define ERRO 1
#define SUCESSO 0
#define PI 3.1415

typedef unsigned int uint;

float media(float a, float b, float c);
float mediaP(float a, float b, float c, int pesoA, int pesoB, int pesoC);
float perimetroC(float raio);
float areaCirculo(float raio);
float areaT(float base, float altura);
float areaCaixa(float a, float b, float c);
float volumeCaixa(float a, float b, float c);
float areaCilindro(float raio, float altura);
float volumeCilindro(float raio, float altura);
float hipotenusa(float ladoA, float ladoB);
void raizes(float a, float b, float c);



int main(int argc, char** argv)
{
    float num1, num2, num3;

    printf("\n");

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
    printf("3-f) %.4f \n", areaCaixa(num1, num2, num3) );
    printf("3-g) %.4f \n", volumeCaixa(num1, num2, num3) );
    printf("3-h) %.4f \n", areaCilindro(num2, num3) );
    printf("3-i) %.4f \n", volumeCilindro(num2, num3) );
    printf("3-j) %.4f \n", hipotenusa(num2, num3) );
    raizes(num1, num2, num3);
    
    printf("\n");
    

    return SUCESSO;
}



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

float areaCaixa(float a, float b, float c){
    float area;

    area = (2*a*b) + (2*a*c) + (2*b*c);

    return area;
}

float volumeCaixa(float a, float b, float c){
    float volume;

    volume = a*b*c;

    return volume;
}

float areaCilindro(float raio, float altura){
    float area;

    area = (2 * ( PI * pow(raio, 2) )) + (2 * PI * raio * altura);

    return area;
}

float volumeCilindro(float raio, float altura){
    float volume;

    volume = (PI * pow(raio, 2) * altura);

    return volume;
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
        printf("k) A expressão não possui raízes reais. \n");
    }else if(discriminante == 0){
        raiz[0] = ((-b))/ (2*a);
        
        printf("k) A raiz da equação é: %.4f \n", raiz[0]);

    }else{
        raiz[0] = ((-b) + sqrt(discriminante))/ (2*a);
        raiz[1] = ((-b) - sqrt(discriminante))/ (2*a);
        
        printf("k) As raizes da equação são: %.4f e %.4f \n", raiz[0], raiz[1] );

    }        


    return;
}