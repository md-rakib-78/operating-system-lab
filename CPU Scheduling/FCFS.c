#include<stdio.h>
#include <stdbool.h>
int main()
{

    printf("Enter number of process: ");
    int p;

    scanf("%d",&p);

       int pro[p];

    printf("Enter Arraival Time: ");
    int AT[p];
    for(int i=0;i<p;i++)
    {
        pro[i]=i+1;
        scanf("%d",&AT[i]);
    }

    printf("Enter Brust Time: ");
    int BT[p];
    for(int i=0;i<p;i++)
    {
        scanf("%d",&BT[i]);
    }

    int totalTAT=0;
    int totalWT=0;

    int WT[p],CT[p],TAT[p];


    int time=0;

   int min;

    for(int i=0;i<p;i++)
    {
        min=i;
        for(int j=i+1;j<p;j++)
        {
            if(AT[j]<AT[min])
            {
                min=j;

            }
        }

        int temp=AT[i];
        AT[i]=AT[min];
        AT[min]=temp;

        int temp1=BT[i];
        BT[i]=BT[min];
        BT[min]=temp1;

        int temp2=pro[i];
        pro[i]=pro[min];
        pro[min]=temp2;

    }


    bool complete=true;
    int track[p];
    for(int i=0;i<p;i++)
    {
        track[i]=0;
    }
    int i=0;

    while(complete)
    {
        if(time>=AT[i])
        {
            CT[i]=time+BT[i];
            TAT[i]=CT[i]-AT[i];
            WT[i]=TAT[i]-BT[i];
            track[i]=1;
            time=time+BT[i];
            totalTAT+=TAT[i];
            totalWT+=WT[i];
            i++;
            if(i>=p)
            {
                break;
            }
        }else
        {
            complete=false;
            for(int j=0;j<p;j++)
            {
                if(track[j]==1)
                {
                    complete=false;
                }
                else
                {
                    complete=true;
                }
            }
            if(complete==true)
            {
                time++;
            }
        }
    }


    printf("\nProcess_No\tArriv Time\tBrustT\tComT\tTrunAT\tWaitingT\n");
    for(int j=0;j<p;j++)
    {
        printf("%d\t\t%d\t\t%d\t%d\t%d\t%d\n",pro[j],AT[j],BT[j],CT[j],TAT[j],WT[j]);
    }

    printf("\nTotal average trunaround time: %d",totalTAT/p);
    printf("\nTotal average waiting time: %d",totalWT/p);
    printf("\nThrouput: %d percent",time);



}
