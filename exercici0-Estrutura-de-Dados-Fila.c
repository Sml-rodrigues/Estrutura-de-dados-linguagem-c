 /*
    * Exercicio FILA 

    1º criar uma funçao para: inicializaLista
    2º Criar uma funcao para: inserir_Comeco
    3º Criar uma funcao para: inserir_Final
    4º Criar uma funcao para: inserir_Ordenado
    5º Criar uma funcao para: buscar
    6º Criar uma funcao para: remover
    7º criar uma funcao para: liber
    
    * Data da criacao: 27/10/2018
    * Autor samuel Rodrigues
    * RA: 05215-030
    * Curso: Engenharia de Computacao 2º Ano
    * Disciplina: Estrutura de Dados
    * Professor: Jose Eduardo Ribeiro

 */ 


  #include<stdio.h>
  #include<stdlib.h>
  #include<stdbool.h>

  struct lista{
         int info;
         struct lista * prox;       
  };

  typedef struct lista Lista;
   
   //----------------------------PARAMETROS  DAS FUNCOES-----------------------------------
  Lista* inicializaLista();

  bool vazia(Lista * pL);

  Lista * inserirComeco(Lista * pL, int valor);

  Lista * inserirFinal(Lista * pL, int valor);

  Lista * inserirOrdenado(Lista * pL, int valor);

  void imprimir(Lista * pL);

  Lista * buscar(Lista *pL, int valor);

  Lista * remover(Lista * pL, int valor);

  void libera(Lista * pL);

  //-----------------------MAIN-----------------------------------------------
  int main(){

       // declara uma lista n?o inicializada 
       Lista * L;
       Lista * Q;
       
       // inicializa lista como vazia                 
       L = inicializaLista();     
       
       // Checa se a lista est? vazia 
       if(vazia(&L)){
           printf("Lista Vazia! \n");                        
       }
       else{
            printf("Lista com elementos! \n");     
       }
       
       printf("\n---Inserindo numeros no comeco da fila---"); 
       L = inserirComeco(L, 1000);  
       L = inserirComeco(L, 100);  
       L = inserirComeco(L, 10);    
       L = inserirComeco(L, 7);

       printf("\n---Inserindo numeros no fim da fila---"); 
       L = inserirFinal(L, 18);
       L = inserirFinal(L, 33);
       
       printf("\n---Inserindo numeros ordenados na fila---"); 
       L = inserirOrdenado(L, 100000);
       L = inserirOrdenado(L, 110);
       L = inserirOrdenado(L, 59);
       L = inserirOrdenado(L, 401);
       L = inserirOrdenado(L, 81);
       L = inserirOrdenado(L, 1);
       L = inserirOrdenado(L, 6);
       L = inserirOrdenado(L, 666);
       L = inserirOrdenado(L, 88);
       L = inserirOrdenado(L, 50);
       L = inserirOrdenado(L, 39);


       
       // imprime os elementos da lista 
       printf("Imprimindo a Lista... \n\n");
       imprimir(L);
       
       // verifica se o elemento est? na lista encadeada
       Q = buscar(L, 10);
       if(Q != NULL){
            printf("\nElemento %d encontrado! \n", Q->info);     
       }
       else{
            printf("\nElemento nao encontrado! \n\n");     
       }
       
       // retira um elemento da lista encadeada       
       printf("Removendo um valor da Lista! \n");
       L = remover(L, 10);
       
       // imprime os elementos da lista 
       printf("Imprimindo a Lista... \n\n");
       imprimir(L);
       
       // libera as listas da mem?ria     
       libera(L);
       
       getchar();
  }

  //------------------------------FUNCOES-------------------------------------
  Lista* inicializaLista(){
         return NULL;       
  }

  bool vazia(Lista * pL){
       if(pL->info == NULL)
          return true;             
       else
           return false;
  }

  Lista * inserirComeco(Lista * pL, int valor){
        Lista * novo = (Lista *) malloc(sizeof(Lista));
        if(novo != NULL){
           novo->info = valor;
           novo->prox = pL;
           printf("Lista[%d] \n", novo->info);
           return novo;        
        } 
  }

  Lista * inserirFinal(Lista * pL, int valor){
        Lista * novo = (Lista *) malloc(sizeof(Lista));
        Lista * p = pL;
        while(p != NULL) {
            p = p->prox;
        }
        if(novo != NULL){
           novo->info = valor;
           novo->prox = pL;
           printf("Lista[%d] \n", novo->info);
           return novo;        
        }             
  }

  Lista * inserirOrdenado(Lista * pL, int valor){
        Lista * novo = (Lista *) malloc(sizeof(Lista));
        Lista * p = pL;
        Lista * ant = NULL;
        
        novo->info = valor;

        if (p == NULL){
            novo->prox = NULL;
            p = novo;
            return p;

        } else{

            while(p != NULL && p->info < valor){
                ant = p;
                p = p->prox;  
           }
           novo->prox = p;
           if(ant == NULL){
              pL = inserirFinal(p, valor);
           } else{
              ant->prox = novo;
           }
           printf("Lista[%d] \n", novo->info);
           return pL;
        }

  }

  void imprimir(Lista * pL){
       
       while(pL != NULL){
               printf(" %d ", pL->info);
               pL = pL->prox;         
       }     
       printf("\n\nFim da Lista Encadeada! \n\n");
  }

  Lista * buscar(Lista *pL, int valor){
        while(pL != NULL){
              if(pL->info == valor)
                 return pL;  
              else
                  pL=pL->prox;
        }    
        return pL;  
  }

  Lista * remover(Lista * pL, int valor){
       Lista * p = pL; 
       Lista * ant = NULL;   
       
        // procura elemento na lista, guardando anterior 
        while(p != NULL && p->info != valor){
             ant = p;
             p = p->prox;  
       }
       
       // verifica se encontrou elemento         
       if(p == NULL){ 
            return pL; 
       
       //retira elemento

       if(ant == NULL){                                   
          pL = p->prox;   
       }
       else{
            ant->prox = p->prox;           
       }
       free(p);
       return pL;     
  }

  void libera(Lista * pL){
       
       Lista * p = pL;
       Lista * t;
       
       while(p != NULL){
             t = p->prox; // guarda refer?ncia para o pr?ximo elemento 
             free(p);    // libera a mem?ria apontada por p 
             p = t;     // faz p apontar para o pr?ximo 
       }
  }
