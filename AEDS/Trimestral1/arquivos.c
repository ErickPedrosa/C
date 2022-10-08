#include "estruturas.h"

//Função que cria o arquivo de entrada;
void input_file(void){
    int n = 0, comando, x;

    FILE *i = fopen("entrada.bin","wb"); //Abre o arquivo binário;
    printf("Digite 0 para parar de inserir a entrada\n");

    do{
        
        scanf("%d",&n);//Lê o número de instruções;

        if(n != 0){
            fwrite(&n, sizeof(int), 1, i); //Grava o número de instruções no arquivo;

            for(int a=0; a<n; a++){
                scanf("%d %d", &comando, &x); //Lê o comando e o valor;
                fwrite(&comando, sizeof(int), 1, i); //Grava o comando no arquivo;
                fwrite(&x, sizeof(int), 1, i); //Grava o valor no arquivo;
            }
        }

    }while (n != 0);
    
    fclose(i); //Fecha o arquivo; 
}

//Função que cria o arquivo de saída;
void output_file(char* s, char mode){
    if(mode == 'c'){ //Abre o arquivo em modo de escrita, usado no main para sobrescrever o arquivo antigo;
        FILE *i = fopen("saida.txt","w");
        fprintf(i, "");
        fclose(i);
    }else if(mode == 'a'){ //Abre o arquivo em modo append;
        FILE *i = fopen("saida.txt","a");
        fputs(s, i);
        fclose(i);
    }
}

/*Função que retorna a variável que contém
* todas as informações que estão no arquivo 
* de entrada. */ 
Input *ipt_var(int file_size){
    
    FILE *in;
    in = fopen("entrada.bin", "rb"); //Abre o arquivo em modo de leitura;
    Input *input_s; //Cria um ponteiro que irá conter os dados de entrada;
    
    input_s = (Input *) malloc(sizeof(Input) * file_size); //Aloca o ponteiro para o número de estruturas que serão avaliadas pelo programa;

    for(int b = 0; b < file_size; b++){ //Laço de 0 até o número de estruturas que serão avaliadas pelo programa;
        
        fread(&input_s[b].n, sizeof(int), 1, in);//Lê o número de instruções que a primeira estrutura realiza;
        
        input_s[b].comando = (int*)malloc(sizeof(int) * input_s[b].n); //Aloca o espaço para o número de comandos que será realizado;
        input_s[b].x = (int*)malloc(sizeof(int) * input_s[b].n); //Aloca o espaço para o número de valores que será guardado;

        for(int a=0; a<input_s[b].n; a++){ //Laço para atribuir os comandos e os valores à variável que será retornada;
            fread(&input_s[b].comando[a], sizeof(int), 1, in);
            fread(&input_s[b].x[a], sizeof(int), 1, in);
        }
       
    }

    fclose(in); //Fecha o arquivo e salva;

    return input_s; //Retorna a variável contendo todos os dados de entrada;
}

//Função que retorna o tamanho do arquivo, no caso a quantidade de estruturas que serão avaliadas;
int fsize(void){
    int file_size = 0, buf;
    FILE *in;

    in = fopen("entrada.bin", "rb"); //Abre o arquivo em modo de leitura;

    while (!feof(in))//Laço para ler até no final do arquivo;
    {
        fread(&buf, sizeof(int), 1, in);

        if(buf != 0){ //Aumenta um a variável que será retornada caso o número lido seja diferente de 0;
            file_size++; 
        }
        for (int i = buf; i > 0; i--)
        {
        fread(&buf, sizeof(int), 1, in);
        fread(&buf, sizeof(int), 1, in);
        }
    }
    file_size--; //Diminui em um a variável que será retornada;

    fclose(in); //Fecha o arquivo e salva;
    return file_size; //Retorna a variável contendo a quantidade de estruturas que serão avaliadas;
}
