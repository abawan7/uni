#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int vowel_check(char a){
    a = tolower(a); 
    if( a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U'){
        return a;
    }
}
int main(int argc , char* argv[]){
    char data[100];
	FILE* input=fopen(argv[1], "r");
	FILE* output=fopen(argv[2], "w+");
    while(fscanf(input_file, "%s", data) != EOF){
    int i= 0;
    int j= strlen(data) - 1;
    while(i< j){
        if(!vowel_check(data[i])){
            i++;
        }
        else if(!vowel_check(data[j])){
            j++;
        }
        else{
            char temp = data[i];
            data[i] = data[j];
            i++;
            data[j] = temp;
            j--;
        }
    }
        fprintf(output, "%s", data);
    }
}