#include <iostream>
#include "Time.hpp"

void display_help(){
    printf("1 --- Prefix increment\n2 --- Postfix decrement\n3 --- Display timer\n\
4 --- Prefix increment\n\
5 --- Postfix decrement\n\
6 --- Display help\n");
}

int main(){
    Time t(0, 0, 0);
    display_help();
    printf(">>");
    while(1){
        char cmd;
        scanf("%c", &cmd);
        if(cmd == '\n'){
            printf(">>");
            continue;
        }
        if(cmd == '1'){
            ++t;
        }else if(cmd == '2'){
            --t;
        }else if(cmd == '3'){
            t.display();
        }else if(cmd == '4'){
            t++;
        }else if(cmd == '5'){
            t--;
        }else if(cmd == '6'){
            display_help();
        }else{
            printf("No such option\n");
        }
    }
    return 0;
}