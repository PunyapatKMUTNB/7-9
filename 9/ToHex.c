#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char *to_hex(int64_t value){
    int64_t st = 1;
    char *s = malloc(sizeof(char)*10);
    char *hexchar = "0123456789abcdef";
    int limit = 0;
    if(value < 0){
        value+=(st<<32);
    }
    while(1){
        char *d[1] = {hexchar[value & 0xf]};
        char *tempd = strdup(d);
        strcat(tempd,s);
        strcpy(s,tempd);
        value>>=4;
        limit++;
        if(value == 0||limit == 8){
            break;
        }
    }
    char *tempfinal = strdup(s);
    memset(s,0,sizeof(char)*10);
    strncpy(s,"0x",2);
    strncat(s,tempfinal,8);
    return s;
}

int main(int argc, char *argv[]){
    printf("%s\n",to_hex(33));
    printf("%s\n",to_hex(-1));
}
