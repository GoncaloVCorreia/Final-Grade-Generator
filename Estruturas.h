#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define NumDiscp 10
#define NumAlunosMax 20
/*ESTRUTURA QUE VAI CONTER A NOTA DE UMA DISCIPLINA DE UM ALUNO*/
typedef struct Discp{
    int indiceAux;
    char *discp;
    float prova1;
    float prova2;
    int notaf;
}t_disciplinas;

/* VAI SER USADO PARA ARMAZENAR AS NOTAS POR DISCIPLINA*/

typedef struct NotasPorDisciplina{
    int nota;
    char *nome;
}N_P_D;

/*ARRAY QUE VAI SER USADO PARA GERAR PAUTA POR DISCIPLINA*/

typedef struct DscpExistentes{
    int indice;
    char *discp;
    N_P_D arrayNotas[NumAlunosMax];
    struct DscpExistentes *next;
}Dexistentes;

/*ESTRUTRA DE UM ALUNO COM OS SEUS DADOS TODOS*/

typedef struct nodeNN{
    char *Nome;
    int NumAln;
    int countD;
    int Dpassadas;

    t_disciplinas arrayDiscp[NumDiscp];
    struct nodeNN *next;
    struct nodeNN *prev;
}N_numero;

N_numero *head=NULL;
Dexistentes *headD=NULL;
