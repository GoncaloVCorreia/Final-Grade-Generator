#include "Estruturas.h"
/* CRIA UM NOVO NODE */

N_numero *Cria_Node (char *nome,int NumAluno){

    N_numero *NovoNode = (N_numero*)malloc(sizeof(N_numero));
    NovoNode->Nome=strdup(nome);
    NovoNode->NumAln=NumAluno;
    NovoNode->countD=0;
    NovoNode->Dpassadas=0;
    NovoNode->next=NULL;
    NovoNode->prev=NULL;

    return NovoNode;
}

/* ADICIONA O NODE À LISTA */

void InsertAtHead(char *nome,int NumAluno){
    N_numero * temp= Cria_Node(nome, NumAluno);
    if (head==NULL){
        head=temp;
        return;
    }
    head->prev=temp;
    temp->next=head;
    head=temp;
}

/*RETORNA O NODE PRETENDIDO*/

N_numero  *ReturnPosicaoNode(int NumAluno){
   N_numero *Posicao=head;
    while(Posicao!=NULL){
        if(Posicao->NumAln==NumAluno){
            return Posicao;
        }
        Posicao=Posicao->next;
    }
    return 0;
}

/*RETORNA O INDICE DA DISCIPLINA DENTRO DO ARRAY DAS DISCIPLINAS*/

int RetornaIndiceDscp(char *disciplina,N_numero *Node){
    int i=0;
    while(i!=10){
        if(Node->arrayDiscp[i].discp != NULL) {
            if (strcmp(Node->arrayDiscp[i].discp, disciplina) == 0) {
                return i;
            }
        }
        i++;
    }
    return -1;
}

/*COLOCA A NOTA NA ESTRUTURA DA RESPETIVA DISCIPLINA*/

void AtualizaNota(int NumProva,int nDiscp,float Nota,N_numero *Node){
    if(NumProva==1) {
        Node->arrayDiscp[nDiscp].prova1 = Nota;
    }
    if(NumProva==2) {
        Node->arrayDiscp[nDiscp].prova2 = Nota;
    }
}

/*CALCULA AS NOTAS FINAIS*/

void NotasFinais() {
    N_numero *Node = head;
    while (Node != NULL) {
        int i = 0;
        while (i != 10) {
            float nf = (Node->arrayDiscp[i].prova1 + Node->arrayDiscp[i].prova2)/2;
            int notafinal=round(nf);
            Node->arrayDiscp[i].notaf = notafinal;
            i++;
        }
        Node = Node->next;
    }
}

/*INSERES AS DISCIPLINAS QUE CADA ALUNO FREQUENTA E AS NOTAS DOS TESTES*/

void AcrescentaNodeDisciplinas(int NumAluno,char *disciplina,int NumProva,float Nota) {

    N_numero *Node;
    Node=ReturnPosicaoNode(NumAluno);

    int nDiscp= Node->countD;

    int aux=RetornaIndiceDscp(disciplina,Node);

    if(aux==-1) {
        Node->arrayDiscp[nDiscp].discp = strdup(disciplina);
        AtualizaNota(NumProva,nDiscp,Nota,Node);

        Node->countD += 1;
    }
    if(aux!=-1){
        AtualizaNota(NumProva,aux,Nota,Node);
    }
}

/*CALCULA O NÚMERO TOTAL DE DISCIPLINAS PASSADOS DE CADA DE ALUNO*/

void DisciplinasPassadas(){

    N_numero *Node = head;
    while (Node != NULL) {
        int i = 0;
        while (i != 10) {
          if(Node->arrayDiscp[i].notaf>=10){
              Node->Dpassadas+=1;
        }
          i++;
    }
        Node = Node->next;
}

}

/*GERA UM FICHEIRO COM OS ALUNOS QUE PASSARAM DE ANO*/

void GeraPautaFinal() {
    N_numero *aux = head;
    char nomefich[50];
    printf("Como quer chamar o seu ficheiro da pauta final: ");
    scanf("%s", nomefich);
    FILE *file;
    file = fopen(nomefich, "w");

    while (aux != NULL) {
        if (aux->Dpassadas >= 8) {
            fprintf(file, "%s#%d#%d \n", aux->Nome, aux->NumAln,aux->Dpassadas);
        }
        aux = aux->next;
    }
    fclose(file);
}

/* vai criar um lista ligada com as todas as disciplinas diferentes existentes*/

void nodeDiscp(char *disciplina){

    Dexistentes *nodeD = (Dexistentes *)malloc(sizeof(Dexistentes));
    nodeD->discp=strdup(disciplina);
    nodeD->next = headD;
    nodeD->indice=0;
    headD=nodeD;
}

/*Averigua se a disciplina é repetida*/

int verificaDiscpRep(char *disciplina){
    Dexistentes *aux=headD;
    while(aux!=NULL){
        if (strcmp(aux->discp,disciplina)==0){
            return 0;
        }
        aux=aux->next;
    }
}

/*Adiciona as disciplinas à lista ligada de disciplinas*/

void DExistentes(){
    N_numero *Posicao=head;
    int QuantAluno=0;
    while(Posicao!=NULL){

        for(int i=0;i<NumDiscp;i++){
            if (QuantAluno==0){
                nodeDiscp(Posicao->arrayDiscp[i].discp);
                }
            else {
                if(verificaDiscpRep(Posicao->arrayDiscp[i].discp)!=0){
                    nodeDiscp(Posicao->arrayDiscp[i].discp);
                }
            }
        }
        QuantAluno+=1;
        Posicao=Posicao->next;
    }
}

/*ESTA FUNCAO VAI PERCORRER AS NOTAS DO NODE DO ALUNO QUE FOI PASSADO COLOCANDO AS NAS RESPETIVAS DISCIPLINAS BEM COMO O NOME DO ALUNO*/

int AdicionaNotaNome(N_numero *Notas) {

    Dexistentes *AddNotas = headD;
    while (AddNotas != NULL) {
        for (int i = 0; i < NumDiscp; i++) {
            if (strcmp(Notas->arrayDiscp[i].discp, AddNotas->discp) == 0) {
                AddNotas->arrayNotas[AddNotas->indice].nome=strdup(Notas->Nome);
                AddNotas->arrayNotas[AddNotas->indice].nota=Notas->arrayDiscp[i].notaf;
                AddNotas->indice+=1;
            }
        }
        AddNotas=AddNotas->next;
    }
}

/*PERCORRE A LISTA DUPLAMENTE LIGADA, OU SEJA, TODOS OS ALUNOS, CHAMANDO PARA CADA ALUNO A FUNCAO QUE VAI COLOCAR AS SUAS NOTAS NA RESPETIVA DISCIPLINA*/

void AdcNotasDisc(){
    N_numero *Notas=head;
    while(Notas!=NULL){
      AdicionaNotaNome(Notas);
      Notas=Notas->next;
    }
}

/*ORDENA AS NOTAS DE CADA DISCIPLINA POR ORDEM ALFABÉTICA*/

int Ordena(N_P_D *alunoUm, N_P_D *alunoDois){
    if (strlen(alunoUm->nome)<= strlen(alunoDois->nome)) {
        for (int i=0;i<strlen(alunoUm->nome);i++) {
            if ((alunoUm->nome)[i] > (alunoDois->nome)[i]) {
                return 1;
            }
            if ((alunoUm->nome)[i] < (alunoDois->nome)[i]) {
                return -1;
            }
        }
    }
    if (strlen(alunoUm->nome)> strlen(alunoDois->nome)) {
        for (int i = 0; i < strlen(alunoDois->nome); i++) {
            if ((alunoUm->nome)[i] < (alunoDois->nome)[i]) {
                return -1;
            }
            if ((alunoUm->nome)[i] > (alunoDois->nome)[i]) {
                return 1;
            }
        }
    }
}

/*GERA AS PAUTAS FINAIS DE CADA DISCILPINA*/

void GeraPautaPorDisciplina(){

    Dexistentes *aux = headD;

    while(aux != NULL){

        char nomefich[500];

        printf("Esta disciplina é: %s\n", aux->discp);

        printf("Como quer chamar o seu ficheiro: ");
        scanf("%s", nomefich);

        FILE *file;
        file = fopen(nomefich, "w");

        int i=0;
        while(aux->arrayNotas[i].nome!=NULL){
            qsort(aux->arrayNotas, sizeof(aux->arrayNotas) / sizeof(aux->arrayNotas[0]), sizeof(aux->arrayNotas[0]), Ordena);
            fprintf(file,"%s#%d\n",aux->arrayNotas[i].nome,aux->arrayNotas[i].nota);
            i++;
        }
        fclose(file);

        aux=aux->next;

    }
}

/* RECEBE O FICHEIRO COM NOME E NÚMERO DOS ALUNOS E SEPARA A INFORMÇÃO ENTRE OS # */

void RecebeFileNN() {
    //printf("ola\n");
    FILE *file;
    file = fopen("NomeAlunos.txt", "r");

    char *linha = malloc(100 * sizeof(char));
    char *nome;
    int NumAluno;

    fgets(linha, 150, file);
    while (strcmp(linha, "final\n") != 0) {

        nome = strtok(linha, "#");
        NumAluno = atoi(strtok(NULL, "#"));


        InsertAtHead(nome,NumAluno);


        fgets(linha, 150, file);

    }
}

/* RECEBE O FICHEIRO DAS CLASSIFICAÇÕES DOS ALUNOS E SEPARA A INFORMÇÃO ENTRE OS # */

void RecebeFileClass(){
    FILE *file;
    file = fopen("ClassificacoesAlunos.txt", "r");

    char *linha =(char*)malloc(100 * sizeof(char));
    char *disciplina;
    int NumAluno;
    int NumProva;
    float Nota;
    fgets(linha, 150, file);

    while (strcmp(linha, "final\n") != 0) {

        NumAluno = atoi(strtok(linha, "#"));
        disciplina=strtok(NULL, "#");
        NumProva=atoi(strtok(NULL, "#"));
        Nota=(float)strtod(strtok(NULL, "#"),NULL);

        AcrescentaNodeDisciplinas(NumAluno,disciplina,NumProva,Nota);

        fgets(linha, 150, file);

    }

}



