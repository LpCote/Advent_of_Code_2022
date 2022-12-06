#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fp;
    char str[100];
    fp = fopen("input.txt", "r");
    char stack[9][100] = {"","","","","","","","",""};
    int stackLen[9] = {8,8,8,8,8,8,8,8,8};
    char stack9001[9][100] = {"","","","","","","","",""};
    int stackLen9001[9] = {8,8,8,8,8,8,8,8,8};
    int line=0,n,a,b;   //Line we're reading, number of boxes to move, departure stack, arrival stack
    char dump[10];

    //Parsing de l'entrepot d'origine
    while(fgets(str,100,fp)!=NULL && str[1]!='1') {     //Tant que le string n'arrive pas a la ligne avec les chiffres
        for(int i = 0; i<9; i++){
            if(str[i*4+1] == ' '){
                stackLen[i] = 7-line;
                stackLen9001[i] = 7-line;
            }
            stack[i][line] = str[i*4+1];
            stack9001[i][line] = str[i*4+1];
        }
        line ++;
    }
    for(int i = 0; i<9; i++) {
        printf("\nStack[%i]: %s\n", i, stack[i]);
        strrev(stack[i]);
        stack[i][stackLen[i]] = '\0';
        printf("\nStack[%i]R: %s\n", i, stack[i]);
        strcpy(stack9001[i], stack[i]);
    }
    while(fscanf(fp,"%s %i %s %i %s %i",dump, &n, dump , &a, dump, &b)!=EOF){
        //Part 1
        a --, b --;
        printf("\n%i %i %i lenA %i lenB %i lenA9001 %i lenB9001 %i\n",n ,a, b, stackLen[a], stackLen[b], stackLen9001[a], stackLen9001[b]);
        for(int i=0; i<n; i++){
            //printf("%c ", stack[a][stackLen[a]-1]);
            stack[b][stackLen[b]] = stack[a][stackLen[a]-1];              //Transfert de la box
            stack[a][stackLen[a]-1] = '\0';        //Effacer le caractere
            stackLen[b]++;
            stackLen[a]--;
            printf("%c ", stack9001[a][stackLen9001[a]-n+i*2]);
            stack9001[b][stackLen9001[b]] = stack9001[a][stackLen9001[a]-n+i*2];              //Transfert de la box
            stack9001[a][stackLen9001[a]-n+i*2] = '\0';        //Effacer le caractere
            stackLen9001[b]++;
            stackLen9001[a]--;
        }
        for(int i = 0; i<9; i++) {
            printf("\nStack[%i]: P1: %s // P2: %s", i, stack[i], stack9001[i]);
        }
    }
    puts("\n");
    for(int i = 0; i<9; i++) {
        printf("%c", stack[i][stackLen[i]-1]);
    }
    puts("\n");
    for(int i = 0; i<9; i++) {
        printf("%c", stack9001[i][stackLen9001[i]-1]);
    }

    fclose(fp);    // Closing the file
    return 0;
}
