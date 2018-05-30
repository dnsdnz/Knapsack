#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b; }  

int totalbenefit=0, totalweight=0;

void printknapSack(int W, int wt[], int val[], int n)  
{
    int i, w;
    int K[n + 1][W + 1];
    
    for (i = 0; i <= n; i++) {   
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                              K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    
    int res = K[n][W];  
    
    printf("Best Solution is: %d\n", res);
    
    printf("Selected Item Weight Benefit\n");
    
    w = W;
    
    for (i = n; i > 0 && res > 0; i--) {
        
        
        if (res == K[i - 1][w])
            
            continue;
        
        else {
            totalbenefit+=val[i - 1];
            
            totalweight+=wt[i - 1];
            
            printf("           %d     %d     %d\n",i, wt[i - 1],val[i - 1]);
            
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
}


int main() {
    
    int i=0,W,item;
    
    printf("How many items(n)?");
    scanf("%d",&item);
    
    printf("Enter the capacity(W):");
    scanf("%d",&W);
    
    int bnf[item], wgt[item];
    
    for ( ; i < item; i++) {
        
        printf("Enter the benefit:");
        scanf("%d",&bnf[i]);
        
        printf("Enter the weight:");
        scanf("%d",&wgt[i]);
    }
    
    int n = sizeof(bnf)/sizeof(bnf[0]);
    
    printknapSack(W, wgt, bnf, n);
    
    printf("Total Weight of Selected Items:%d \nTotal Benefit of Selected Items:%d ",totalweight,totalbenefit);
    
    return 0;
}
