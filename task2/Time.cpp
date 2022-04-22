#include "Time.hpp"
#include <iostream>

#define modulo(n, m) ((n % m) + m) % m

Time::Time(int s, int m, int h): sec(s), min(m), hrs(h){

}

void display_options(){
    printf("Select increment target:\n\
1 --- seconds\n\
2 --- minutes\n\
3 --- hours\n>>");
}

Time &operator++(Time &t){
    int chrono;
    display_options();
    scanf("%d", &chrono);
    if(chrono == 1){
        t.sec = (t.sec + 1) % 60;
        t.min = (t.min + (t.sec == 0)) % 60;
        t.hrs = (t.hrs + (t.min == 0 && t.sec == 0)) % 24;
    }else if(chrono == 2){
        t.min = (t.min + 1) % 60;
        t.hrs = (t.hrs + (t.min == 0)) % 24;
    }else if(chrono == 3){
        t.hrs = (t.hrs + 1) % 24;
    }else{
        printf("No such option\n");
    }
    return t;
}

Time &operator--(Time &t){
    int chrono;
    display_options();
    scanf("%d", &chrono);
    if(chrono == 1){
        t.sec = modulo(t.sec - 1, 60);
        t.min = modulo((t.min - (t.sec == 59)), 60);
        t.hrs = modulo((t.hrs - (t.min == 59 && t.sec == 59)), 24);
    }else if(chrono == 2){
        t.min = modulo((t.min - 1), 60);
        t.hrs = modulo((t.hrs - (t.min == 59)), 24);
    }else if(chrono == 3){
        t.hrs = modulo((t.hrs - 1), 24);
    }else{
        printf("No such option\n");
    }
    return t;
}

Time &operator++(Time &t, int ignore){
    int chrono;
    display_options();
    scanf("%d", &chrono);
    if(chrono > 3 || chrono < 1){
        printf("No such option");
        return t;
    }
    int val;
    printf("Increment value:");
    scanf("%d", &val);
    if(chrono == 1){
        int total_sec = (t.hrs*3600 + t.min*60 + t.sec + val) % 86400;
        t.hrs = total_sec / 3600;
        t.min = (total_sec % 3600) / 60;
        t.sec = total_sec % 3600 % 60;
    }else if(chrono == 2){
        int total_min = (t.hrs * 60 + 60 + val) % 1440;
        t.hrs = total_min / 60;
        t.min = total_min % 60;
    }else{
        t.hrs = (t.hrs + val) % 24;
    }
    return t;
}

Time &operator--(Time &t, int ignore){
    int chrono;
    display_options();
    scanf("%d", &chrono);
    if(chrono > 3 || chrono < 1){
        printf("No such option");
        return t;
    }
    int val;
    printf("Decrement value:");
    scanf("%d", &val);
    if(chrono == 1){
        int total_sec = modulo((t.hrs*3600 + t.min*60 + t.sec - val), 86400);
        t.hrs = total_sec / 3600;
        t.min = (total_sec % 3600) / 60;
        t.sec = total_sec % 3600 % 60;
    }else if(chrono == 2){
        int total_min = (t.hrs * 60 + 60 + val) % 1440;
        t.hrs = total_min / 60;
        t.min = total_min % 60;
    }else{
        t.hrs = (t.hrs + val) % 24;
    }
    return t;
}

void Time::display(){
    printf("%d:%d:%d\n", hrs, min, sec);
}