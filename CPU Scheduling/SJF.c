#include <stdio.h>
#include <stdbool.h>

int main() {
    int p;
    printf("Enter number of processes: ");
    scanf("%d", &p);

    int pro[p], AT[p], BT[p];
    printf("Enter Arrival Times: ");
    for (int i = 0; i < p; i++) {
        pro[i] = i + 1;
        scanf("%d", &AT[i]);
    }

    printf("Enter Burst Times: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &BT[i]);
    }

    int WT[p], CT[p], TAT[p];
    int totalWT = 0, totalTAT = 0;
    int time = 0;

    // Sort by arrival time
    for (int i = 0; i < p - 1; i++)
    {
        for (int j = i + 1; j < p; j++)
        {
            if (AT[j] < AT[i])
            {
                int temp = AT[i];
                AT[i] = AT[j];
                AT[j] = temp;

                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;
                temp = pro[i];
                pro[i] = pro[j];
                pro[j] = temp;
            }
        }
    }

    bool complete = false;
    int track[p];
    for (int i = 0; i < p; i++) track[i] = 0;

    while (!complete) {
        int readyQ[p], idx = 0;

        // Build ready queue from uncompleted processes
        for (int i = 0; i < p; i++) {
            if (AT[i] <= time && track[i] == 0) {
                readyQ[idx++] = i;
            }
        }

        if (idx == 0) {
            time++;
            continue;
        }

        // Find process with shortest burst time
        int minIdx = readyQ[0];
        for (int i = 1; i < idx; i++) {
            if (BT[readyQ[i]] < BT[minIdx]) {
                minIdx = readyQ[i];
            }
        }

        CT[minIdx] = time + BT[minIdx];
        TAT[minIdx] = CT[minIdx] - AT[minIdx];
        WT[minIdx] = TAT[minIdx] - BT[minIdx];

        totalWT += WT[minIdx];
        totalTAT += TAT[minIdx];
        track[minIdx] = 1;
        time += BT[minIdx];

        // Check if all processes are completed
        complete = true;
        for (int i = 0; i < p; i++) {
            if (track[i] == 0) {
                complete = false;
                break;
            }
        }
    }

    printf("\nProcess\tArrival\tBurst\tComp\tTurn\tWait\n");
    for (int i = 0; i < p; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pro[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", (float)totalTAT / p);
    printf("\nAverage Waiting Time: %.2f", (float)totalWT / p);
    printf("\nThroughput: %.2f\n", (float)p / time);

    return 0;
}
