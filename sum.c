#include <stdio.h>
#include <stdlib.h>
//#include "CTime.h"

#define SUM 60
#define MAXNUMsSIZE 100

#define PRINT 1


long long CountAddToSum(int,int[],int,const int[],int);
void printr(const int[], int);
long long table1[SUM][MAXNUMsSIZE];

int main()
{
    int Nums[]={3,6};
    int sum=SUM;
    int size=sizeof(Nums)/sizeof(int);
    int i,j,a[]={0};
    long long N=0;
    //CTime timer1;

    for(i=0;i<SUM;++i) 
        for(j=0;j<MAXNUMsSIZE;++j) 
            table1[i][j]=-1;

    N = CountAddToSum(sum,Nums,size,a,0); //algorithm
    //timer1.Get_Passd();

    //printf("\nN=%lld time=%.1f ms\n", N,timer1.Get_Passd());
    printf("\nN=%lld \n", N);
    getchar();
    return 1;
}

long long CountAddToSum(int s, int arr[],int arrsize, const int r[],int rsize)
{
    static int totalmem=0, maxmem=0;
    int i,*rnew;
    long long result1=0,result2=0;

    if(s<0) return 0;
    if (table1[s][arrsize]>0 && PRINT==0) return table1[s][arrsize];
    if(s==0)
    {
        if(PRINT) printr(r, rsize);
        return 1;
    }
    if(arrsize==0) return 0;

    //else
    rnew=(int*)malloc((rsize+1)*sizeof(int));

    for(i=0;i<rsize;++i) rnew[i]=r[i]; 
    rnew[rsize]=arr[arrsize-1];

    result1 =  CountAddToSum(s,arr,arrsize-1,rnew,rsize);
    result2 =  CountAddToSum(s-arr[arrsize-1],arr,arrsize,rnew,rsize+1);
    table1[s][arrsize]=result1+result2;
    free(rnew);

    return result1+result2;

}

void printr(const int r[], int rsize)
{
    int lastr=r[0],count=0,i;
    for(i=0; i<rsize;++i) 
    {
        if(r[i]==lastr)
            count++;
        else
        {
            printf(" %d*%d ",count,lastr);
            lastr=r[i];
            count=1;
        }
    }
    if(r[i-1]==lastr) printf(" %d*%d ",count,lastr);

    printf("\n");

}