#include <iostream>
#include <time.h>
#include <math.h>
#include "Queue.hpp"

int get_int(){
    int ans;
    printf("Value: ");
    scanf("%d", &ans);
    return ans;
}

void display_help(){
    printf("1 --- Push to q1\n2 --- Push to q2\n3 --- Pop from q1\n\
4 --- Pop from q2\n\
5 --- q1 + q2\n\
6 --- q1 - q2\n\
7 --- q1 * q2\n\
8 --- Divide q1 by value\n\
9 --- Exit programm\n");
}


int main(){
    srand( (unsigned)time(NULL) );

    Queue q1;
    printf("q1: ");
    q1.display();
    Queue q2;
    printf("q2: ");
    q2.display();



    while(1){
        char c = getchar();
        if(c == '\n')
            printf(">>");
        if(c == '1'){
            q1.enqueue(get_int());
            q1.display();
        }else if(c == '2'){
            q2.enqueue(get_int());
            q2.display();
        }else if(c == '3'){
            printf("Dequeue value: %d\n", q1.dequeue());
            q1.display();
        }else if(c == '4'){
            printf("Dequeue value: %d\n", q2.dequeue());
            q2.display();
        }else if(c == '5'){
            q1.display();
            q2.display();
            (q1 + q2).display();
        }else if(c == '6'){
            q1.display();
            q2.display();
            (q1 - q2).display();
        }else if(c == '7'){
            q1.display();
            q2.display();
            (q1 * q2).display();
        }else if(c == '8'){
            q1 / get_int();
            q1.display();
        }else if(c == '9'){
            q1.dealloc_nodes();
            q2.dealloc_nodes();
            break;
        }
    }

    return 0;
}