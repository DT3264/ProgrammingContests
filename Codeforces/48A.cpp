#include<stdio.h>
#include<string.h>
char str[3][10];

bool winner[3];

void rockKiller(int n){
    bool canDie = false;
    for(int i=0; i<3; i++){
        if(i==n) continue;
        if(strcmp(str[i], "paper")==0) canDie = true;
    }
    if(!canDie)winner[n]=true;
}
void papperKiller(int n){
    bool canDie = false;
    for(int i=0; i<3; i++){
        if(i==n) continue;
        if(strcmp(str[i], "scissors")==0) canDie = true;
    }
    if(!canDie)winner[n]=true;
}
void scissorsKiller(int n){
    bool canDie = false;
    for(int i=0; i<3; i++){
        if(i==n) continue;
        if(strcmp(str[i], "rock")==0) canDie = true;
    }
    if(!canDie)winner[n]=true;
}
char findWinner(){
    int contWinner=0, lastPosWinner=0;
    for(int i=0; i<3; i++){
        if(winner[i]){
            contWinner++;
            lastPosWinner=i;
        }
    }
    if(contWinner==1){
        if(lastPosWinner==0) return 'F';
        else if(lastPosWinner==1) return 'M';
        else if(lastPosWinner==2) return 'S';
    }
    return '?';
}

int main (){
    int i;
    ///F->M->S
    for(i=0; i<3; i++){
        scanf("%s", str[i]);
    }
    for(i=0; i<3; i++){
        if(strcmp(str[i], "rock")==0) rockKiller(i);
        else if(strcmp(str[i], "paper")==0) papperKiller(i);
        else if(strcmp(str[i], "scissors")==0) scissorsKiller(i);
    }
    printf("%c", findWinner());
    return 0;
}
