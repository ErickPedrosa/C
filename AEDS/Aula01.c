#define SUCESSO 0
#define TAM_MAX_AL 50

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    char nome[TAM_MAX_AL];
    float* notas;
    float media;
    int numAl;
    int numNotas;

} fichaAluno;

fichaAluno* leStruct(fichaAluno*);
void imprimeStruct(fichaAluno*);
void mediaStruct(fichaAluno*);


int main(int argc, char const* argv[]) {

    fichaAluno* turma;
    int i;

    turma = (fichaAluno*)malloc(1 * sizeof(fichaAluno));

    turma = leStruct(turma);
    imprimeStruct(turma);


    for (i=0; i < turma[0].numAl; i++){
        free(turma[i].notas);
    }

    free(turma);

    return SUCESSO;
}



fichaAluno* leStruct(fichaAluno* a) {

    int numAlunos, numNotas;

    printf("Digite o numero de alunos que serao digitados:");
    scanf("%i", &numAlunos);

    printf("Digite o numero de notas que serao digitadas:");
    scanf("%i", &numNotas);

    a = (fichaAluno*)realloc(a, numAlunos * sizeof(fichaAluno));

    for (int i = 0; i < numAlunos; i++)
    {

        printf("Digite o nome do aluno %i:", i + 1);
        getchar();
        fgets(a[i].nome, TAM_MAX_AL, stdin);


        a[i].notas = (float*)malloc(numNotas * sizeof(float));

        for (int j = 0; j < numNotas; j++)
        {
            printf("Digite a nota %i do aluno %i: ", i + 1, j + 1);
            scanf("%f", &a[i].notas[j]);
        }
    }

    a[0].numAl = numAlunos;
    a[0].numNotas = numNotas;


    mediaStruct(a);


    return a;
}

void imprimeStruct(fichaAluno* a) {

    for (int i = 0; i < a[0].numAl; i++)
    {
        printf("\nALUNO %i\n", i + 1);

        printf("Nome: ");
        fputs(a[i].nome, stdout);

        for (int j = 0; j < a[0].numNotas; j++)
        {
            printf("Nota %i: %f\n", j + 1, a[i].notas[j]);

        }
        printf("Media: %f\n", a[i].media);
    }

    return;
}

void mediaStruct(fichaAluno* a) {

    float med;

    for (int i = 0; i < a[0].numAl; i++)
    {
        med = 0;

        for (int j = 0; j < a[0].numNotas; j++)
        {
            med += a[i].notas[j];
        }

        med = med / (float)a[0].numNotas;

        a[i].media = med;
    }

    return;
}
