#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DEBUG true
#define MAX_ELEMENTS 9
#define MAX_LENGTH 256
int len = 256;

int strcut(char** pre_allocated){
    int counter = 0;

    while ((*pre_allocated)[counter] != '\0')
        counter++;    

    void* temp = realloc(*pre_allocated, counter + 1);

    if (temp == NULL)
        return -1;

    *pre_allocated = temp;

    return counter; 
}

void show(char* str){
    if (!DEBUG)
        return;

    for (int i = 0; i < len; i++){
        if (str[i] == '\0'){
            printf("%5d.%5s ", i + 1, "END");
        }else {
            printf("%5d.%5c ", i + 1,str[i]);
        }
        if ((i + 1) % MAX_ELEMENTS == 0) {
            printf("\n\r");
        }
    }
    printf("\n");
}

int translate(char number){
    if (number >='0' &&  number <= '9')  
        return number - '0';
    else if(number >= 'A' && number <= 'F'){
        return number - 'A' + 10;
    }else{
        return -1;
    }
}

int conversion_to10(int base, char* str ){
    int result = 0;
    for (int i =0; i < len; i++){
        int dig = translate(str[i]);
        result += pow(base, len - i - 1 ) * dig;
    }
    return result;
}

int conversion_from10(int base, int in, char* out){
    char* result = calloc(MAX_LENGTH, sizeof(char));
    int index = 0;

    while(in > 0){
        if (index > MAX_LENGTH)
            return -1; 

        result[index] = in % base - '0';
        in = in / base;
        index++; 
    }
    int size = strcut(&result);  

    if (size < 0){
        return -1;
    }
    out = result;

    return size;
}

int main(void){
    char* octal = calloc(len, sizeof(char));

    if (octal == NULL){
        printf("Memory allocation failed");
        return 1;
    }

    scanf("%255s", octal);
/*
    show(octal);
    len = strcut(&octal); 
    show(octal);

    int result = conversion_to10(16,octal);
*/
    int i = 256;
    char* result; 
    conversion_from10(2,base, result); 

    printf("%s\n",result);
    
    free(octal);
    octal = NULL;

    return 0;
}
