#include<stdio.h>
#include<string.h>

int min(int a, int b, int c)
{
    if(a<=b && a<=c)
    return a;
    if(b<=c && b<=a)
    return b;
    else
    return c;
}

int dp[101][101];

int dist(char* a,char* b,int m, int n)
{
    if (m==0)
    return n;
    if(n==0)
    return m;

    if(dp[m][n]>=0)
    return dp[m][n];

    if(a[m-1]==b[n-1])
    {
        dp[m][n]=dist(a,b,m-1,n-1);
        return dp[m][n];
    }
    else
    {
        dp[m][n]=1+min(dist(a,b,m-1,n-1),dist(a,b,m-1,n),dist(a,b,m,n-1));
        return dp[m][n];
    }
}

void main()
{
    memset(dp,-1,10201);
    char a[101],b[101];
    printf("\nEnter Gene1 = ");
    scanf("%s",a);
    printf("Enter Gene2 = ");
    scanf("%s",b);

    int m=strlen(a);
    int n=strlen(b);
    int diff= dist(a,b,m,n);

    printf("\nSimilarity: %d",m+n-diff);
    printf("\nTotal number of operations required = %d\n",diff);
}