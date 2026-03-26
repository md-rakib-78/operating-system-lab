#include <stdio.h>

int main() {
    int p;
    printf("Enter number of processes: ");
    scanf("%d", &p);

    int pro[p], BT[p], WT[p], TAT[p];
    float totalWT = 0, totalTAT = 0;

    // Input burst times
    for (int i = 0; i < p; i++) {
        pro[i] = i + 1;
        printf("Enter Burst Time for Process P%d: ", pro[i]);
        scanf("%d", &BT[i]);
    }

    // Sort processes by burst time (SJF logic)
    for (int i = 0; i < p - 1; i++) {
        for (int j = i + 1; j < p; j++) {
            if (BT[i] > BT[j]) {
                // Swap burst times
                int temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;

                // Swap process IDs
                temp = pro[i];
                pro[i] = pro[j];
                pro[j] = temp;
            }
        }
    }

int CT[p];
int time=0;
for(int i=0;i<p;i++)
{
    CT[i]=0;
}


    for (int i = 0; i < p; i++) {

        time+=BT[i];
        CT[i]=time;
    }

    for(int i=0;i<p;i++)
    {
        TAT[i]=CT[i];
        WT[i]=TAT[i]-BT[i];
        totalTAT+=TAT[i];
        totalWT+=WT[i];
    }



    // Output results
    printf("\nProcess\tBurst\tWait\tTurn\n");
    for (int i = 0; i < p; i++) {
        printf("P%d\t\t%d\t%d\t%d\n", pro[i], BT[i], TAT[i], WT[i]);
    }

    printf("\nAverage Waiting Time: %.2f", totalWT / p);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / p);

    return 0;
}

