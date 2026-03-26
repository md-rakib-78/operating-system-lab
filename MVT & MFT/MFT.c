#include<stdio.h>
#include<stdbool.h>


int main()
{
    printf("Enter the total memory available (in bytes): ");
    int totalM;
    scanf("%d",&totalM);

    printf("Enter the block size (in bytes): ");
    int bSize;
    scanf("%d",&bSize);

    printf("Enter the number of process: ");
    int p;
    scanf("%d",&p);

    int pro[p];
    bool visit[p];
    for(int i=0;i<p;i++)
    {
        printf("Enter memory required for process (in Bytes) -- ");
        scanf("%d",&pro[i]);
        visit[i]=false;
    }

    printf("No. of blocks available in memory -- %d",totalM/bSize);

    int IF[p];
    int totalIF=0;


    int count=0;
    for(int i=0;i<p;i++)
    {
        if(pro[i]<=bSize && count<(totalM/bSize))
        {
            IF[i]=bSize-pro[i];
            totalIF+=IF[i];
            visit[i]=true;
            count++;
        }
    }

printf("\n\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION\n");
for(int i=0;i<p;i++)
{
    if(visit[i])
    {
        printf("P%d\t\t%d\t\tYES\t\t%d\n",i+1,pro[i],IF[i]);
    }
    else
    {
        printf("P%d\t\t%d\t\tNO\t\t--\n",i+1,pro[i]);
    }
}

printf("\nMemory is full!");

printf("\nTotal Internal Fragmentation is: %d",totalIF);
printf("\nTotal External Fragmentation is: %d\n",totalM-(count*bSize));

}
