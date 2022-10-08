#define SUCESSO 0;
#include <time.h>
#include <stdio.h>

void counter(int n){
    float a = 10.0, b = 5.0, c;

    for (int i = 0; i < n; i++)
    {
        c = a - b;
        c = a + b;
        c = a * b;
        c = a / b;
    }
    
}

int main(int argc, char** argv){

    clock_t t;
    
    t = clock();
    counter(100000000000);
    t = clock() - t;
    printf("%f", ((float)t)/CLOCKS_PER_SEC);

    return SUCESSO;
}
