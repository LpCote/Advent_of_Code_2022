#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fp;
    char str[15];
    fp = fopen("input.txt", "r");
    int countp1=0, countp2=0;

    while(fgets(str,15,fp)!=NULL) {
        int n[4] = {0,0,0,0};
        sscanf(str, "%i-%i,%i-%i",&n[0],&n[1],&n[2],&n[3]);
        if(n[0]>=n[2] && n[1]<=n[3] || n[2]>=n[0] && n[3]<=n[1]){
            countp1 ++;
        }
        if(n[0]>=n[2] && n[0]<=n[3] || n[0]<=n[2] && n[1]>=n[2]){
            countp2 ++;
        }
        printf("strlen%i: N1:%i,N2:%i, N3:%i, N4:%i\n",strlen(str),n[0],n[1],n[2],n[3]);
        printf("Countp1: %i, Countp2: %i\n\n",countp1, countp2);
    }
    fclose(fp);    // Closing the file
    return 0;
}