/***********************************************/ 
/* �rvores Bin�rias                            */
/* objetivo: registro de c�digos               */
/* programador: Daniela Bagatini               */
/* criado em: 11/05/2016                       */
/* data da ultima alteracao: 14/05/2016        */
/***********************************************/ 

#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>


#define FALSE   0      // constante falsa
#define TRUE   !FALSE  // constante verdadeira


/***********************************************/ 
/* Defini��o dos Registros                     */
/***********************************************/ 
typedef struct {          // registro 
       int  codigo;
} INFORMACAO;
       
typedef struct arv {
       INFORMACAO info;   // dados do registro
       struct arv* subd;  // ponteiro para o nodo da direita
       struct arv* sube;  // ponteiro para o nodo da esquerda
} ARVORE; 



/***********************************************/ 
/* Defini��o das Fun��es                       */
/***********************************************/
void    entrada_dados ( ARVORE* aux ); // leitura dos dados de entrada
void    imprime_ARVORE( ARVORE* aux ); // visualizacao da lista em tela
void    cria_ARVORE   ( ARVORE** r );  // inicializa arvore com NULL
void    insere        ( ARVORE** r );  // inclui um novo registro na arvore
void    busca         ( int cod, ARVORE** a); // procura na arvore por uma matricula
void    sucessor      ( ARVORE* p, ARVORE** q, ARVORE** b );
void    antecessor    ( ARVORE* p, ARVORE** q, ARVORE** b );
void    remove_registro        ( ARVORE** r );  // exclui um regitro por matricula
void    imprime_PRE_ORDEM ( ARVORE* aux ); // imprime em pre ordem
void    imprime_IN_ORDEM ( ARVORE* aux ); // imprime em in ordem
void    imprime_POS_ORDEM ( ARVORE* aux ); // imprime em pos ordem 

void    chama_busca(ARVORE** a);   
       
/***********************************************/ 
/* Programa Principal                          */
/***********************************************/
int main( void )
{
    char op;   // opcao do menu                               
    ARVORE* r; // declaracao da ARVORE // variavel do tipo ARVORE = ARVORE de ponteiros

    while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Programa de registros - Menu                         " );
         printf( "\n [1] Cria ARVORE                                      " );
         printf( "\n [2] Insere                                           " );
         printf( "\n [3] Remove                                           " );
         printf( "\n [4] Imprime                                          " );
         printf( "\n [5] Pre Ordem                                        " );
         printf( "\n [6] In Ordem                                         " );
         printf( "\n [7] Pos Ordem                                        " );         
         printf( "\n  [8] Busca                                            " );
         printf( "\n [9] Para sair do programa                            " );
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Opcao: " );
         op = getchar(); // tecla de opcao do menu

        switch( op ) {
           case '1':   // rotina cria ARVORE       
                   cria_ARVORE( &r );
                   break;
                                
           case '2':  // rotina inclui nodo no final da ARVORE
                   insere( &r );    
                   break;
                      
           case '3':  // rotina exclui nodo da ARVORE
                   //remove_registro( &r );
                   break;
           
           case '4':  // rotina exclui nodo da ARVORE
                   imprime_ARVORE( r );
                   break;
           case '5':  // rotina que imprime em PreOrdem
                   imprime_PRE_ORDEM( r );
                   break;
           case '6':  // rotina que imprime em InOrdem
                   imprime_IN_ORDEM( r );
                   break;                                                                                            
           case '7':  // rotina que imprime em InOrdem
                   imprime_POS_ORDEM( r );
                   break;
           case '8':  // rotina que imprime em InOrdem
                   chama_busca( &r );
                   break;                                                                                                    
           case '9': // t�rmino do programa                                                 
                   exit( 1 ); 
                   break;
                
           default : 
                   printf( "\n Digite uma opcao!" );
                   break;
        } // switch( op )
        
        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        getchar();       // parada da tela
        
        printf( "\n" );
     } // fim do while( 1 )
     
 return 0;
} // fim do programa principal



/************************************************ 
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : nodo (ponteiro para o novo espaco) *
 * sa�da   : nodo com dados                      *
 ************************************************/
void entrada_dados( ARVORE* aux )
{ 
    printf( "\n\n Codigo: ");
    scanf("%d",&aux->info.codigo); 
   
   /* 
    printf( "\n Digite o nome: " );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    gets( aux->info.nome );
  */
    aux->subd = NULL;    // n�o aponta
    aux->sube = NULL;    // n�o aponta

}



/*************************************************
 * imprime_ARVORE                                 *
 * objetivo: rotina para imprimir dados          *
 * entrada : ARVORE                               *
 * sa�da   : nenhuma                             *
 *************************************************/ 
void imprime_ARVORE( ARVORE* aux )
{    
    
    if( aux != NULL ){ // verifica se a raiz e diferente de vazio
        printf( "\n Nome.....: %d", aux->info.codigo );
        getchar();
        printf( "\n >> sube" );
        imprime_ARVORE( aux->sube );
        printf( "\n >> subd" );
        imprime_ARVORE( aux->subd );
    }
    else
       printf("\n Arvore vazia!");
}

/*****************************************************
 * imprime_PRE_ORDEM                                 *
 * objetivo: rotina para imprimir dados em pos ordem *
 * entrada : ARVORE                                  *
 * sa�da   : nenhuma                                 *
******************************************************/ 
void imprime_PRE_ORDEM( ARVORE* aux )
{    
    
    if( aux != NULL ){ // verifica se a raiz e diferente de vazio
        printf( "\n%d", aux->info.codigo );        
        imprime_PRE_ORDEM( aux->sube );
        imprime_PRE_ORDEM( aux->subd );
    }
}

/*****************************************************
 * imprime_IN_ORDEM                                  *
 * objetivo: rotina para imprimir dados em IN ordem *
 * entrada : ARVORE                                  *
 * sa�da   : nenhuma                                 *
******************************************************/ 
void imprime_IN_ORDEM( ARVORE* aux)
{    
    
    if( aux != NULL ){ // verifica se a raiz e diferente de vazio
        imprime_IN_ORDEM( aux->sube );
        printf( "\n%d", aux->info.codigo );
        imprime_IN_ORDEM( aux->subd );
    }
}  

/*****************************************************
 * imprime_POS_ORDEM                                  *
 * objetivo: rotina para imprimir dados em POS ordem *
 * entrada : ARVORE                                  *
 * sa�da   : nenhuma                                 *
******************************************************/ 
void imprime_POS_ORDEM( ARVORE* aux)
{    
    
    if( aux != NULL ){ // verifica se a raiz e diferente de vazio
        imprime_POS_ORDEM( aux->sube );
        imprime_POS_ORDEM( aux->subd );
        printf( "\n%d", aux->info.codigo );
    }
}


/************************************************
 * cria_ARVORE                                   *
 * objetivo: rotina para inicializar a ARVORE    *
 * entrada : nenhuma                             *
 * sa�da   : NULL (inicializa ARVORE)            *
 ************************************************/ 
void cria_ARVORE( ARVORE** r )
{
    *r = NULL; // arvore criada, raiz nao aponta
}



/************************************************* 
 * insere                                        *
 * objetivo: rotina para inserir no fim da ARVORE*
 * entrada : ARVORE                              *
 * sa�da   : ARVORE com mais um registro         *
 *************************************************/ 
void insere( ARVORE** r )
{
  // ALOCANDO MEMORIA PARA O NOVO NODO
  ARVORE *nodo = (ARVORE *) malloc(sizeof(ARVORE));
  
  ARVORE *atu = *r; //PONTEIRO QUE VAI ANDAR PE ARVORE
  ARVORE *ant; //PONTEIRO QUE GUARDARÁ A POSIÇÃO ANTERIOR A atu(ATUAL)

  //VERIFICAR SE TEMOS MEMORIA;
  if (nodo != NULL)
  {
    //INSERE DADOS NO NODO
    entrada_dados(nodo);

    // VERIFICA SE ARVORE ESTÁ VAZIA
    if (*r == NULL)
    {
      //RAIZ APONTA PARA O PRIMEIRO NODO
      *r = nodo;
    }else{

      printf("\n ARVORE NAO VAZIA!" );
      
      //VAI ANDAR PARA ESQ OU DIR ATE ENCONTRAR O NULL
      while(atu != NULL){
        printf("\n Entrou while!" );

        //ANTERIOR RECEBE O VALOR DE ATU(atual)
        ant = atu;

        //VERIFICA QUEM É MAIOR
        if (nodo->info.codigo < atu->info.codigo)
        { 
          printf("\n ESQUERDA!" );
          //VAI PARA A ESQUERDA
          atu = atu->sube;

        }else{
          printf("\n DIREITA!" );
          //VAI PARA A DIREITA
          atu = atu->subd;
        }
      }

      //VERIFICA EM QUAL LADO DA ARVORE O atu(ATUAL) PAROU E INSERE O DADO.
      if (ant->sube == atu)
            {
              ant->sube = nodo;
            }else{
              ant->subd = nodo;
            }     
    }

  }else{
    printf("\n Nao ha memoria disponivel");
  }
  
}



/************************************************ 
 * busca                                        *
 * objetivo: achar nodo                         *
 * entrada : ARVORE e c�digo a ser excluido     *
 * sa�da   : posicao ou NULL (n�o encontrou)    *
 ************************************************/ 
void busca(int cod, ARVORE** a)
{
  ARVORE *aux = *a;
    
  if (aux == NULL)
  {
    printf("\n VALOR NAO ENCONTRADO!");
  }else if(cod < aux->info.codigo)
    {
      busca(cod, &aux->sube);
      
    }else if (cod > aux->info.codigo){
      busca(cod, &aux->subd);
    }else{
      printf("\n Dado Encontrado");
    }
}



/*************************************************** 
 * remove                                          *
 * objetivo: rotina para excluir nodo da ARVORE    *
 * entrada : ARVORE                                *
 * sa�da   : ARVORE                                *
 ***************************************************/ 
/*
void remove_registro( ARVORE** r )
{
    ARVORE* p;    // ponteiro auxiliar
    ARVORE* q;    // ponteiro auxiliar
    ARVORE* b;    // ponteiro auxiliar
    ARVORE* a;    // ponteiro auxiliar para anterior
    int cod, achou; // cod = dado de entrada; achou = informa se c�digo j� existe na estrutura
    
    if ( *r == NULL )
         printf("\n Arvore vazia!");
    else
       {    
        printf("\n Codigo de referencia: ");
        fflush( stdin ); // limpa buffer do teclado e faz a entrada de dados
        scanf( "%d", &cod ); 

        p = *r; // posiciona ponteiro auxiliar
        achou = busca( cod, &a, &p ); // verifica se c�digo a ser inserida j� existe na �rvore
        if( achou ){ // se achou o c�digo, remove
            //....
       }
   }
}
*/

/*************************************************** 
 * sucessor                                        *
 * objetivo: rotina para descobrir nodos filhos    *
 * entrada : ARVORE, ponteiros auxiliares q e b    *
 * sa�da   : ponteiros auxiliares q e b            *
 ***************************************************/ 
void sucessor( ARVORE* p, ARVORE** q, ARVORE** b )
{
 *b= p;
 *q= p->subd;
 while( (*q)->sube != NULL )
        {
           *b= *q;
           *q= (*q)->sube;
        }
}
 
 
 
/*************************************************** 
 * antecessor                                      *
 * objetivo: rotina para descobrir nodos filhos    *
 * entrada : ARVORE, ponteiros auxiliares q e b    *
 * sa�da   : ponteiros auxiliares q e b            *
 ***************************************************/ 
void antecessor( ARVORE* p, ARVORE** q, ARVORE** b )
{
 *b= p;
 *q= p->sube;
 while( (*q)->subd != NULL )
        {
           *b= *q;
           *q= (*q)->subd;
        }
}

// TESTE DE BUSCA

void chama_busca(ARVORE** a){
  
  int valor;

  printf("\nDigite o cod a ser buscado: ");
  
  fflush(stdin);
  __fpurge(stdin);

  scanf("%d", &valor);

  busca(valor, a);
}       