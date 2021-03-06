#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int n;
bool used[500][500];
int arr[500][500];
int minMoney=1e9, atLeastNPersons;
int actualPersons, actualMoney;
int actualMaxPersons;

bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int ax, int ay){
    int nx, ny;
    if(!used[ax][ay]){
        actualPersons++;
        used[ax][ay]=1;
        for(int i=0; i<4; i++){
            nx = ax+dx[i], ny = ay+dy[i];
            if(isValid(nx, ny)){
                if(abs(arr[ax][ay]-arr[nx][ny])<=actualMoney){
                    dfs(nx, ny);
                }
            }
        }
    }
}

bool isPosible(int x){
    actualMoney=x;
    actualPersons=0;
    actualMaxPersons=0;
    memset(used, 0, sizeof(used));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!used[i][j]){
                actualPersons=0;
                dfs(i, j);
                if(actualPersons>actualMaxPersons) actualMaxPersons=actualPersons;
            }
        }
    }
    return actualMaxPersons>=atLeastNPersons;
}

int main(){
    int i, j;
    scanf("%d", &n);
    atLeastNPersons=((n*n)/2)+(n%2!=0 ? 1 : 0);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int left = 1;
    int right = 1e6;
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        ///printf("%d?\n", mid);
        if(isPosible(mid)){
            if(minMoney>mid){
                minMoney=mid;
            }
            right=mid-1;
        }
        else left=mid+1;
    }
    printf("%d", minMoney);
return 0;
}
