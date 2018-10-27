        #include<stdio.h>
        #include<stdlib.h>
        //----------------------Inicio da estrutura-------------------
      typedef struct list{
        int number;
        struct list *next;
      }start, *node;

        //-------------------Parametro das funcoes---------------------
      void start_list();

      void enter_data(int Num);

      void show_data();

      int add_value();

      void largest_element();

      void divisible_by_two();

      void insert_even_number(int even);

      void enter_ordered_numbers(struct list *new);

        //-----------------------Inicio da main()----------------------
      int main(){
        int Data;
        int sum;
        int Even;
        char y;

        start_list();

        do{
          printf("\n Please enter a number integer:\n");
          scanf("%d",&Data);
          setbuf(stdin,NULL);
          printf(" Do you want add more numbers in the list?\n \t\t\ty,n\n");
          setbuf(stdin,NULL);
          scanf("%c",&y);

          enter_data(Data);
        }while(y =='y');
        
        
        sum = add_value();
        printf("\n The result of adding all the numbers in the list is: %d\n", sum);

        node = start.next;
        show_data(node);

        node = start.next;
        largest_element();

        node = start.next;
        divisible_by_two();

        printf("\n------------FUNCAO QUE ALOCA SOMENTE NUMEROS PARES-----------------\n");
        do{
          printf("\n Please enter a number integer:\n");
          scanf("%d",&Even);
          setbuf(stdin,NULL);
          insert_even_number(Even);
          printf(" Do you want add more numbers in the list?\n \t\t\ty,n\n");
          setbuf(stdin,NULL);
          scanf("%c",&y);

        }while(y =='y');

        printf("\n------------FUNCAO QUE INSERE OS NUMEROS ORDENADOS----------------\n");
        //enter_ordered_numbers();


        getchar();
        return 0;
        }//------------------------Fim da main()-----------------------

        //----------------------------Funcoes--------------------------
        void start_list(){
          start.next = NULL;
        }

        void enter_data(int Num){ 
         node = &start;

         while(node->next != NULL)
           node = node->next;

         node->next = (struct list *) malloc(sizeof(struct list));
         node = node->next;
         
         node->number = Num;
          node = node->next = NULL; //Atribui no->proximo NULL para indicar que o novo final da lista
        }

        void show_data(struct list *x){
        //caso base da recursividade: se a lista esta vazia retorna porque nao existem dados
          if(x == NULL)
            return;

            printf("%d \n",x->number);//lista o dado atual
            show_data(x->next);//lista os outros elementos usando chamadas recursivas
          }

          int add_value(){
            int Sum=0;
            node = &start;
            while(node != NULL){
              Sum = node->number + Sum;
              node = node->next;
            }
            return(Sum);
          }

          void largest_element(){
            int Largest = 0;
            node = &start;
            while(node != NULL){

              if(node->number > Largest)
                Largest = node->number;

              node = node->next;
            }
            printf("\n The largest number on the list %d\n",Largest);
          }
          void divisible_by_two(){
           node = &start;
           while(node != NULL){
            if(node->number %2 == 0)
              printf("\n The numbers divisible by two: %d\n",node->number);

            node = node->next;
          }
        }

        void insert_even_number(int even){
          if(even %2 == 0){
           enter_data(even);
         }
         else
          printf("\n This number is odd and can not be added to the list!\n");

      }
      void enter_ordered_numbers(struct list *new){
        int previous = 0;
        node = &start;

        while(node != NULL && node->number < previous){
          previous = node-> next;
         node = node->new;
       }

       new->next = node;

       if(previous == NULL){
            new->next = NULL;
            node = NULL;
            previous = enter_data(node, new);
          }
          else{
            previous->next = new;
          }
          printf("\n numbers ordered\n",new->number);
      }
      return previous;
      
