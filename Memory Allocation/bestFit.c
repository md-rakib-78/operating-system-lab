#include<stdio.h>
#include<stdbool.h>
int main()
{
    printf("Enter the number of blocks: ");
    int b;
    scanf("%d",&b);

    int blocks[b];
    printf("Enter the size of the blocks: \n");
    for(int i=0;i<b;i++)
    {
        printf("Block %d: ",i+1);
        scanf("%d",&blocks[i]);
    }

    printf("Enter the number of files: ");
    int f;
    scanf("%d",&f);

    int files[f];
    printf("Enter the size of the files: \n");
    for(int i=0;i<f;i++)
    {
        printf("File %d: ",i+1);
        scanf("%d",&files[i]);
    }

    int IF[b];
    for(int i=0;i<b;i++) IF[i]=0;

    bool visitBlock[b];
    bool visitFile[f];

    for(int i=0;i<b;i++) visitBlock[i]=false;
    for(int i=0;i<f;i++) visitFile[i]=false;

    printf("\nFile_No\tFile_Size\tBlock_No\tBlock_size\tFragment\n");
    for(int i=0; i<f ; i++)
    {
        int min = -1;
        for(int k=0; k<b; k++)
        {
            if(!visitBlock[k] && files[i] <= blocks[k])
            {
                if(min == -1 || blocks[k] < blocks[min])
                {
                    min = k;
                }
            }
        }

        if(min != -1)
        {
            IF[min] = blocks[min] - files[i];
            visitBlock[min] = true;
            visitFile[i] = true;
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,files[i],min+1,blocks[min],IF[min]);
        }
    }

    for(int i=0; i<f; i++)
    {
        if(!visitFile[i])
        {
            printf("File %d not allocate any block!\n",i+1);
        }
    }

    int totalIF=0;
    int totalBS=0;
    for(int i=0;i<b;i++)
    {
        totalBS+=blocks[i];
        totalIF+=IF[i];
    }

    int totalEF = totalBS - totalIF;

    printf("\nTotal Internal Fragmentation: %d", totalIF);
    printf("\nTotal External Fragmentation: %d\n", totalEF);

    return 0;
}
