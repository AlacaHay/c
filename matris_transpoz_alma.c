#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,m;
    int i,j,k;

    scanf("%d%d",&n,&m);
    int matris[n][m];
    int transMatris[m][n];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&matris[i][j]);

        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
           transMatris[j][i]=matris[i][j];
            

        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%4d",transMatris[i][j]);

        }
        printf("\n\n"); 
    }

    return 0;
}

/*void matris_toplami(int arr1[][50],int arr2[][50],int temp[][50],int m,int n){
    int toplam=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            toplam
        }

    }
} */