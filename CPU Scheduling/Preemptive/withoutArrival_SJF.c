#include <stdio.h>
#include <stdbool.h>

int main() {
    int qt;
    printf("Enter Quantum Time: ");
    scanf("%d", &qt);

    int p;
    printf("Enter number of processes: ");
    scanf("%d", &p);

    int pro[p], BT[p],AT[p], remBT[p];

    printf("Enter Burst Times: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &BT[i]);
        remBT[i] = BT[i];
        AT[i]=0;
    }

    int WT[p], CT[p], TAT[p];
    int totalWT = 0, totalTAT = 0;
    int time = 0, completed = 0;

    bool track[p];
    for (int i = 0; i < p; i++) track[i] = false;

    printf("\nProcess\tBurst\tComp\tTurn\tWait\n");

    while (completed < p) {
        int readyQ[p], idx = 0;

        // Build ready queue
        for (int i = 0; i < p; i++) {
            if (remBT[i] > 0) {
                readyQ[idx++] = i;
            }
        }

        if (idx == 0) {
            time++;
            continue;
        }

        // Select highest priority process (lowest PT value)
        int minIdx = readyQ[0];
        for (int i = 1; i < idx; i++) {
            if (remBT[readyQ[i]] < remBT[minIdx]) {
                minIdx = readyQ[i];
            }
        }

        // Execute for quantum or remaining burst time
        int execTime = (remBT[minIdx] < qt) ? remBT[minIdx] : qt;
        remBT[minIdx] -= execTime;
        time += execTime;

        if (remBT[minIdx] == 0 && !track[minIdx]) {
            CT[minIdx] = time;
            TAT[minIdx] = CT[minIdx] - AT[minIdx];
            WT[minIdx] = TAT[minIdx] - BT[minIdx];
            totalWT += WT[minIdx];
            totalTAT += TAT[minIdx];
            track[minIdx] = true;
            completed++;

            printf("P%d\t\t%d\t%d\t%d\t%d\n", pro[minIdx], BT[minIdx], CT[minIdx], TAT[minIdx], WT[minIdx]);
        }
    }

    printf("\nAverage Turnaround Time: %.2f", (float)totalTAT / p);
    printf("\nAverage Waiting Time: %.2f", (float)totalWT / p);
    printf("\nThroughput: %.2f\n", (float)p / time);

    return 0;
}


