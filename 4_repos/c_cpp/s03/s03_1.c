#include <stdio.h>

int main(){

    int time;
    int hour, minutes, sec;

    scanf("%d", &time);

    // hora // minutos // segundos
    hour = time/(60*60);
    time = time%(60*60);
    minutes = time/(60);
    time = time%(60);
    sec = time;
    printf("%d:%d:%d", hour, minutes, sec);
    
    return 0;
}