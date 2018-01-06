#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int matricula;
    char nome[100];
    int nota1;
    int nota2;
}Aluno;
int ContadordeAlunos;
void inicializarListaAlunos(Aluno listaAlunos[], int Tamanho){
    int i;
    for (i = 0; i < Tamanho; i++) {
        listaAlunos[i].matricula = -1;
    }
}
void PreencherVetor(Aluno *A){
    A->matricula = ContadordeAlunos;


    printf("Digite o nome do aluno\n");
    scanf(" %s", A->nome);
    printf("Digite a nota1 do aluno\n");
    scanf("%d", &(A->nota1));
    printf("Digite a nota2 do aluno\n");
    scanf("%d", &(A->nota2));
    printf("\n");
}
int Inserir(Aluno *listaAlunos, int Tamanho, Aluno A){
    int k = 0;
    int i;
    for (i = 0; i < Tamanho; i++) {
        if (listaAlunos[i].matricula == -1) {
            listaAlunos[i] = A;
            k = 1;
            i = Tamanho;
        }
    }
    return k;
}
void Menu(){
    printf("Digite 1 para inserir aluno\n");
    printf("Digite 2 para imprimir lista de alunos\n");
    printf("Digite 3 para editar\n");
    printf("Digite 4 para sair\n");

}
void ImprimirPorMedia(Aluno *Lista, int Tamanho){
    int i, j;
    Aluno Aux;
    for (i = 0; i < Tamanho -1; i++) {
        for (j = 0; j < Tamanho -1; j++) {
            if (((Lista[j].nota1 + Lista[j].nota2) > (Lista[j + 1].nota1 + Lista[j + 1].nota2)) && (Lista[i].matricula != -1) ) {
                Aux = Lista[j];
                Lista[j] = Lista[j + 1];
                Lista[j + 1] = Aux;
            }
        }
    }
    for (i = 0; i < Tamanho; i++) {
        printf("\nMATRICULA %d\n", Lista[i].matricula);
        printf("ALUNO %s\n", Lista[i].nome);
        printf("NOTA1: %d\n", Lista[i].nota1);
        printf("NOTA2: %d\n", Lista[i].nota2);
        printf("MEDIA %.2f\n", ((Lista[i].nota1+Lista[i].nota2) * 1.0)/2);
        printf("---------------\n");
    }
}


void ImprimirNome(Aluno *Lista, int Tamanho){
    int i, j;
    Aluno Aux;
    for (i = 0; i < Tamanho -1; i++) {
        for (j = 0; j < Tamanho -1; j++) {
            if (Lista[i].matricula != -1 && strcmp(Lista[j].nome, Lista[j + 1].nome) > 0) {
                Aux = Lista[j];
                Lista[j] = Lista[j + 1];
                Lista[j + 1] = Aux;
            }
        }
    }
    for (i = 0; i < Tamanho; i++) {
        if (Lista[i].matricula != -1) {
            printf("\nMATRICULA %d\n", Lista[i].matricula);
            printf("ALUNO %s\n", Lista[i].nome);
            printf("NOTA1: %d\n", Lista[i].nota1);
            printf("NOTA2: %d\n", Lista[i].nota2);
            printf("MEDIA %.2f\n", ((Lista[i].nota1+Lista[i].nota2) * 1.0)/2);
            printf("---------------\n");
        }

    }
}
Aluno* buscarAluno(Aluno listaAluno[], int tamanho, int matriculaBuscar){
    int i, k = 0;
    for (i = 0; i < tamanho; i++) {
        if (listaAluno[i].matricula == matriculaBuscar) {
            k = i;
            i = tamanho;
        }
    }
    if (k != 0) {
        return &listaAluno[k];
    }else{
        return NULL;
    }
}
int editarAluno(Aluno listaAlunos[], int Tamanho, int MatriculaEditar){
    int k = 0;
    Aluno *AjudaDeus = buscarAluno(listaAlunos, Tamanho, MatriculaEditar);

    if (&AjudaDeus != NULL) {
        printf("Digite o nome do aluno\n");
        scanf(" %s", listaAlunos[MatriculaEditar].nome);
        printf("Digite a nota1 do aluno\n");
        scanf("%d", &(listaAlunos[MatriculaEditar].nota1));
        printf("Digite a nota2 do aluno\n");
        scanf("%d", &(listaAlunos[MatriculaEditar].nota2));
        printf("\n");
        k = 1;
    }

    return k;
}

int main(void){
    int Tamanho;
    printf("Digite o tamanho do vetor de alunos\n");
    scanf("%d", &Tamanho);

    Aluno *ListaAlunos = (Aluno*) malloc(sizeof(Aluno) * Tamanho);

    ContadordeAlunos = 0;
    inicializarListaAlunos(ListaAlunos, Tamanho);


    int opcao = 10;

    while (opcao != 4) {
        Menu();
        scanf("%d", &opcao);

        if (opcao == 1) {
            Aluno A;
            PreencherVetor(&A);

            int ChamarInserir = Inserir(ListaAlunos, Tamanho, A);

            if (ChamarInserir == 1) {
                printf("\nAluno inserido com sucesso\n");
                ContadordeAlunos++;
            }else{
                printf("\nAluno nao pode ser inserido\n");
            }

        }else if (opcao == 2) {
            int OpI;
            printf("Digite 1 para imprimir por nome\n");
            printf("Digite 2 para imprimir por media\n");
            scanf("%d", &OpI);

            if (OpI == 2) {
                ImprimirPorMedia(ListaAlunos, Tamanho);
                printf("\n");
            }else if (OpI == 1) {
                ImprimirNome(ListaAlunos, Tamanho);
                printf("\n");
            }


        }else if(opcao == 3){
            int OpZ;
            printf("\n");
            printf("Digite o matricula a ser buscada\n");
            scanf("%d", &OpZ);

            int kkk = editarAluno(ListaAlunos, Tamanho, OpZ);
            if (kkk = 1) {
                printf("\nContato editado com sucesso\n");
            }else{
                printf("\nMatricula nao encontrada\n");
            }

        }else if (opcao == 4) {
            printf("Voce saiu hahahh\n");
        }
    }

    return 0;
}

