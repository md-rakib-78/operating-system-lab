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

    printf("Enter the number of file: ");
    int f;
    scanf("%d",&f);

    int files[b];
    printf("Enter the size of the files: \n");
    for(int i=0;i<f;i++)
    {
        printf("File %d: ",i+1);
        scanf("%d",&files[i]);
    }

    int IF[b];
    bool visitBlock[b];
    bool visitFile[f];

    for(int i=0;i<b;i++)
    {
        visitBlock[i]=false;
        visitFile[i]=false;
    }

    int k=0;

    printf("\nFile_No\tFile_Size\tBlock_No\tBlock_size_\tFragment\n");
    for(int i=0; i<f ; i++)
    {

        for(int j=k; j<b; j++)
        {
            if(!visitBlock[j] && files[i] <= blocks[j])
            {
                IF[j]=blocks[j]-files[i];
                visitBlock[j]=true;
                visitFile[i]=true;
                printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,files[i],j+1,blocks[j],IF[j]);
                k=j+1;
                break;
            }
        }
        if(visitFile[i]==false)
        {
            for(int l=0; l<k-1; l++)
            {
                if(!visitBlock[l] && files[i] <= blocks[l])
                {
                    IF[l]=blocks[l]-files[i];
                    visitBlock[l]=true;
                    visitFile[l]=true;
                    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,files[i],l+1,blocks[l],IF[l]);
                    k=l+1;
                    break;
                }
            }
        }
    }

    for(int i=0; i<f;i++)
    {
        if(visitFile[i]==false)
        {
            printf("File %d not allocate any block!\n",i+1);
            break;
        }

    }


    int totalIF=0;
    int ex=0;
    for(int i=0;i<b;i++)
    {
        totalIF+=IF[i];
        if(visitBlock[i]==false)
        {
           ex+=blocks[i];
        }
    }

    printf("\nTotal Internal Fragmentation: %d",totalIF);
    printf("\nTotal External Fragmentation: %d",ex);

}

