#include<stdio.h>
#include<stdbool.h>


int main()
{
    printf("Enter the number of blocks: ");
    int b;
    scanf("%d",&b);

    int block[b];
    int sumB=0;
    for(int i=0; i<b; i++)
    {
        printf("Block %d Size -- ",i+1);
        scanf("%d",&block[i]);
        sumB+=block[i];
    }


    printf("Enter the number of process: ");
    int p;
    scanf("%d",&p);

    int pro[p];
    bool visit[p];
    int sumP=0;
    for(int i=0;i<p;i++)
    {
        printf("Enter memory required for process %d -- ",i+1);
        scanf("%d",&pro[i]);
        visit[i]=false;
    }



    int IF[p];
    int totalIF=0;


    int count=0;
    for(int i=0;i<p;i++)
    {
        if(pro[i]<=block[i])
        {
            IF[i]=block[i]-pro[i];
            totalIF+=IF[i];
            visit[i]=true;
            count++;
            sumP+=pro[i];
        }
    }

printf("\n\nPROCESS\tPROCESS SIZE\tBLOCKS\tBLOCKS SIZE\tALLOCATED\tINTERNAL FRAGMENTATION\n");
for(int i=0;i<p;i++)
{
    if(visit[i])
    {
        printf("P%d\t%d\t\t%d\t%d\tYES\t%d\n",i+1,pro[i],i+1,block[i],IF[i]);
    }
    else
    {
         printf("P%d\t%d\t\t%d\t%d\tNO\t--\n",i+1,pro[i],i+1,block[i]);
    }
}

printf("\nMemory is full!");

printf("\nTotal Internal Fragmentation is: %d",totalIF);
printf("\nTotal External Fragmentation is: %d\n",sumB-(sumP+totalIF));

}

