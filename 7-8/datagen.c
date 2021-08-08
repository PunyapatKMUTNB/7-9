#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int allnum [1000];
    int i;
    FILE * fp;
    for ( i = 0; i < 1000; i++ ) {
        allnum[ i ] = rand() % 1000;
    }
    fp = fopen("data.txt","w");
    for ( i = 0; i < 1000; i++ ) {
        fprintf(fp, "%d\n", allnum[i]);
    }
    fclose(fp);
}