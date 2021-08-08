#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qsort.c"

int countline(FILE *fp){
    int linecount = 0;
    char cha;
    if(fp == NULL){
        return 0;
    }
    while(!feof(fp)){
        cha = getc(fp);
        if(cha == '\n'){
            linecount++;
        }
    }
    return linecount;
}

int *getnumtoarr(int *arr, FILE *fp){
    int index = 0;
    int num;
    char cha;
    char fullcha[10] = "";
    rewind(fp);
    while(!feof(fp)){
        cha = getc(fp);
        if(cha == '\n'){
            num = atoi(fullcha);
            arr[index] = num;
            index++;
            memset(fullcha,0,3);
        }else{
            strncat(fullcha,&cha,1);
        }
    }
    return arr;
}

int main(int argc, char *argv[]){
    int i;
    FILE * fp;
    fp = fopen("data.txt","r");
    int lines = countline(fp);
    if(lines == 0){
        printf("Error: File Not Found or The File is Empty.");
        exit(-1);
    }
    int numarr[lines];
    getnumtoarr(numarr, fp);
    quicksort(numarr, 0, lines-1);
    fclose(fp);
    fp = fopen("data_sorted.txt", "w");
    for (int index = 0; index < lines; index++){
        fprintf(fp,"%d\n", numarr[index]);
    }
    fclose(fp);
    return 0;
}