#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * P1
 * A && X == Rock
 * B && Y == Paper
 * C && Z == Scissors
 *
 * P2
 * A == Rock, X == Lose
 * B == Paper, Y == Draw
 * C == Scissors, Z == Win
 */

char * winningComp[]= {"C X\n", "A Y\n", "B Z\n"};
char * evenComp[] = {"A X\n", "B Y\n", "C Z\n"};
char * rock[]= {"A Y\n", "B X\n", "C Z\n"};
char * paper[] = {"A Z\n", "B Y\n", "C X\n"};
char * scissors[] = {"A X\n", "B Z\n", "C Y\n"};

int main() {
    int score = 0;
    int score2 = 0;

    FILE* fp;
    char str[10];
    fp = fopen("input.txt", "r");

    if (NULL == fp) {
        printf("file can't be opened \n");
        return(-1);
    }


    while(fgets(str,10,fp)!=NULL){
        if(str[2] == 'X'){
            score += 1;
        }
        else if(str[2] == 'Y'){
            score += 2;
            score2 += 3;
        }
        else{
            score += 3;
            score2 += 6;
        }
        for(int i=0; i<3; i++){
            if(!strcmp(winningComp[i], str)){
                score += 6;
            }
            else if(!strcmp(evenComp[i], str)){
                score += 3;
            }
            if(!strcmp(rock[i], str)){
                score2 += 1;
            }
            else if(!strcmp(paper[i], str)){
                score2 += 2;
            }
            else if(!strcmp(scissors[i], str)){
                score2 += 3;
            }
        }
        printf("Score p1: %d\n",score);
        printf("Score p2: %d\n",score2);
    }

    // Closing the file
    fclose(fp);
    return 0;
}
