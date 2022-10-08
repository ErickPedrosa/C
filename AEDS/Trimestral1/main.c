/*
* Integrantes da dupla: Erick Pedrosa e Gabriele Maia;
* Turma: 203;
*/

#include "estruturas.h"


int main (int argc, char** argv){

    int s, file_size = 0; //Declaração da variável que conterá a resposta de usuário e a que conterá o "tamanho do arquivo";
    
    Input *ipt; //Declaração da estrutura que terá as informações de entrada;

    Stack *stack_v;  //
    Queue *queue_v;  //Declaração das estruturas de dados;
    Queue *pqueue_v; //

    int comp_stack, comp_queue, comp_pqueue, st_ctrl, qu_ctrl, pqu_ctrl; //Declaração das variáveis de comparação e de controle;

    do{
        printf("\nDigite a operação:\n(1)-Gerar o arquivo de entrada\n(2)-Gerar o arquivo de saída\n(0)-Sair do programa\n");
        scanf("%d",&s); //Lê a resposta do usuário;
        switch (s)
        {
        case 1:
            input_file(); //Caso seja 1, cria um arquivo de entrada;
            break;

        case 2: //Caso seja 2;

            output_file("", 'c'); // Cria ou sobrescreve o arquivo de saída;

            stack_v = stack_create();    //
            queue_v = queue_create();    // Cria as estruturas de dados;
            pqueue_v = queue_create_p(); //
            
            
            file_size = fsize(); // Chama a função que calcula a quantidade de estruturas que serão avaliadas;
            
            ipt = ipt_var(file_size); // Chama a função que retorna a variável que contém todas as informações 
                                      //que estão no arquivo  de entrada.

            for(int i = 0; i < file_size; i++){ //Laço de 0 até o número de estruturas que serão avaliadas pelo programa;

                comp_stack = 0, comp_queue = 0, comp_pqueue = 0, st_ctrl = 0, qu_ctrl = 0, pqu_ctrl = 0; //Inicializa as variáveis de comparação e de controle com 0;

                for(int j=0; j<ipt[i].n; j++){ //Laço até o número de comandos que serão executados;
                    
                    if(ipt[i].comando[j] == 1){ //Verifica se o comando é 1, ou seja, inserir;

                        stack_push(stack_v, ipt[i].x[j]);     //
                        queue_push(queue_v, ipt[i].x[j]);     // Insere nas determinadas estruturas de dados;
                        queue_push_p(pqueue_v, ipt[i].x[j]);  //


                    }else if (ipt[i].comando[j] == 2){ //Verifica se o comando é 2, ou seja, retirar;

                        comp_stack = stack_pop(stack_v);      //
                        comp_queue = queue_pop(queue_v);      // Retira das determinadas estruturas de dados e atribui as variáveis de comparação iniciadas por comp;
                        comp_pqueue = queue_pop_p(pqueue_v);  //

                        if(comp_stack != ipt[i].x[j]){ // Compara entre o resultado esperado e a variável de comparação;
                            st_ctrl++;  // Caso o resultado seja diferente soma 1 a variável de controle, o que demonstra que não corresponde aquela estrutura de dados;
                        }
                        if(comp_queue != ipt[i].x[j]){ // Compara entre o resultado esperado e a variável de comparação;
                            qu_ctrl++;  // Caso o resultado seja diferente soma 1 a variável de controle, o que demonstra que não corresponde aquela estrutura de dados;
                        }
                        if(comp_pqueue != ipt[i].x[j]){ // Compara entre o resultado esperado e a variável de comparação;
                            pqu_ctrl++; // Caso o resultado seja diferente soma 1 a variável de controle, o que demonstra que não corresponde aquela estrutura de dados;
                        }

                    }
                    
                }

                if(st_ctrl != 0 && qu_ctrl != 0 && pqu_ctrl != 0){ // Verifica se todas as variáveis de controle são diferentes de 0, ou seja, não é nenhuma das estruturas de dados;
                    output_file("Impossible\n", 'a');
                }else if (st_ctrl == 0 && qu_ctrl != 0 && pqu_ctrl != 0){ // Verifica se somente a variável de controle referente a pilha é igual a 0, ou seja, a estrutura de dado é uma pilha;
                    output_file("Stack\n", 'a');
                }else if (st_ctrl != 0 && qu_ctrl == 0 && pqu_ctrl != 0){ // Verifica se somente a variável de controle referente a fila é igual a 0, ou seja, a estrutura de dado é uma fila;
                    output_file("Queue\n", 'a');
                }else if (st_ctrl != 0 && qu_ctrl != 0 && pqu_ctrl == 0){ // Verifica se somente a variável de controle referente a fila de prioridade é igual a 0, ou seja, a estrutura de dado é uma fila de prioridade;
                    output_file("Priority Queue\n", 'a');
                }else{   // Caso não seja nenhum acima, indica que pode ser duas ou mais estruturas de dados;
                    output_file("Not sure\n", 'a');
                }


            }

            free_stack(stack_v);    //
            free_queue(queue_v);    //Libera as estruturas alocadas;
            free_queue_p(pqueue_v); //
            free(ipt);              //

            break;

        case 0:
            break;   
        default: //Caso a pessoa digite algo inválido;
            printf("Operação inválida!\n");
            break;
        }
    }while(s != 0); //Faz ficar em um looping até que a resposta do usuário seja 0;


    return SUCESSO;
}

