#include <stdio.h>
#include <stdlib.h>
typedef struct {
  char crp[2];
  int tam[2]; // tamnanho da matriz
  int reso; //numero de resolucao limite da matriz
  int **m;

}matriz_alfa;
typedef struct{
  int pos[2];
  int R;
  int G;
  int B;
}cor_p;
typedef struct {
  int n_sementes;
  int T;
  cor_p *cor;
}aux_p;
int ** Aloca_Matriz(int Linhas,int Colunas);

matriz_alfa * abre_arquivo(){
    matriz_alfa *alfa;
    alfa = (matriz_alfa *) malloc(sizeof(matriz_alfa));
    FILE *fp;
    fp = fopen("imagem.pgm","r");
    if (fp == NULL){
      printf("Impossivel abrir o arquivo!");
    }
    for(int i=0;i<3;i++){
      if (i==0)  fscanf(fp, "%s", alfa->crp); // pula um linha
      fscanf(fp,"%d",&alfa->tam[i]);
     // printf("%d\n", img_dados[i]);
    }
    alfa->m = Aloca_Matriz(alfa->tam[1],alfa->tam[0]);
    for (int i=0;i<alfa->tam[1];i++){
      for(int j=0;j<alfa->tam[0];j++){
        fscanf(fp,"%d",&alfa->m[i][j]);
      }
    }
    fclose(fp);
    return alfa;
                      // o primeiro e o segundo numero do array são respectivamente
                      // colunas e linhas da matriz
                      // o  terceiro numero refere-se a níveis de intensidade que existem na imagem.
}
int ** Aloca_Matriz(int Linhas,int Colunas){ //Recebe a quantidade de Linhas e Colunas como Parâmetro

  int i,j; //Variáveis Auxiliares

  int **m = (int**)malloc(Linhas * sizeof(int*)); //Aloca um Vetor de Ponteiros

  for (i = 0; i < Linhas; i++){ //Percorre as linhas do Vetor de Ponteiros
       m[i] = (int*) malloc(Colunas * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
       for (j = 0; j < Colunas; j++){ //Percorre o Vetor de Inteiros atual.
            m[i][j] = 0; //Inicializa com 0.
       }
  }
return m; //Retorna o Ponteiro para a Matriz Alocada
}
aux_p * abre_auxiliar(){
  FILE *fp;
  fp = fopen("imagem.txt","r");
  aux_p * aux;
  aux = (aux_p *) malloc(sizeof(aux_p));
  if(fp == NULL) printf("Impossivel abri o arquivo\n");
  fscanf(fp,"%d",&aux->n_sementes); //quantidade de sementes
  fscanf(fp,"%d",&aux->T); //valor do limiar
  aux->cor = (cor_p *) malloc(aux->n_sementes*sizeof(cor_p));
  for(int i=0;i<aux->n_sementes;i++){
    fscanf(fp,"%d,%d <%d,%d,%d>",&aux->cor[i].pos[0],&aux->cor[i].pos[1],&aux->cor[i].R,&aux->cor[i].G,&aux->cor[i].B);
  }
  fclose(fp);
  return aux;
}

int main (int argc,char* argv[]){
  matriz_alfa * alfa = abre_arquivo();
  aux_p * aux = abre_auxiliar();
//  int * vet = abre_arquivo();

  for (int i=0;i<3;i++){
    if(i==0) printf("%s\n",alfa->crp);
    printf("%d\n", alfa->tam[i]);
    }
  for (int i=0;i<alfa->tam[1];i++){
    for(int j=0;j<alfa->tam[0];j++){
      printf("%d ",alfa->m[i][j]);
    }
    putchar('\n');
  }
//
    putchar('\n');
    putchar('\n');
    printf("%d\n",aux->n_sementes);
    printf("%d\n",aux->T);
    for(int i=0;i<aux->n_sementes;i++){
      printf("%d , %d <%d,%d,%d>\n",aux->cor[i].pos[0],aux->cor[i].pos[1],aux->cor[i].R,aux->cor[i].G,aux->cor[i].B);
    }
//
  free(alfa->m);
  free(alfa);
  free(aux);
  return '0';
}
