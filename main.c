#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENTS 9

int len = 256;

bool DEBUG = true;

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
    //8^len * number[i] + 8^len-1 * number[i]  
    for (int i =0; i < len; i++){
        int dig = translate(str[i]);
        result += pow(base, len - i) * dig;
    }

    return result;
}

void strcut(char** pre_allocated){
    int counter = 0;

    while ((*pre_allocated)[counter] != '\0')
        counter++;    

    void* temp = realloc(*pre_allocated, counter + 1);

    if (temp == NULL)
        return;

    *pre_allocated = temp;
    len = counter + 1;
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


int main(void){
    char* octal = calloc(len, sizeof(char));

    if (octal == NULL){
        printf("Memory allocation failed");
        return 1;
    }

    scanf("%255s", octal);

    show(octal);
    strcut(&octal); 
    show(octal);


    int result= conversion_to10(16,octal);

    printf("%d\n",result);

    free(octal);
    octal = NULL;

    return 0;
}
