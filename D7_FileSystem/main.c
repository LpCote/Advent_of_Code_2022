#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATHSIZE 50
#define MAXFILES 10

typedef struct {
    int path[PATHSIZE];
    struct dir *directory[MAXFILES];
} dir;



int main() {
    FILE* fp;
    char buffer[100];
    fp = fopen("input.txt", "r");
    int i = 0;
    int flag = 0;

    while(fgets(buffer,100,fp)!=NULL){
        char* token = strtok(buffer, "$");

        while (token != NULL) {
            printf("///////%i//////\n",i);
            printf("%s", token);
            if(token[1] == 'c' && token[2] == 'd'){
                printf("do something with cd\n");
                flag = 1;
            }
            if(flag == 1){
                struct your_struct *s = malloc(sizeof(*s));
            }
            token = strtok(NULL, "$");
            i++;
        }

    }

    // Closing the file
    fclose(fp);
    return 0;
}
