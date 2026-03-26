#include <stdio.h>
#include <stdbool.h>

int main() {
    int qt;
    printf("Enter Quantum Time: ");
    scanf("%d", &qt);

    int p;
    printf("Enter number of processes: ");
    scanf("%d", &p);

    int pro[p], BT[p], AT[p], remBT[p];
    for (int i = 0; i < p; i++) {
        pro[i] = i + 1;
        AT[i] = 0;
    }

    printf("Enter Burst Times: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &BT[i]);
        remBT[i] = BT[i];
    }

    int WT[p], CT[p], TAT[p];
    int totalWT = 0, totalTAT = 0;
    int time = 0, completed = 0;

    bool track[p];
    for (int i = 0; i < p; i++) track[i] = false;

    printf("\nProcess\tBurst\tComp\tTurn\tWait\n");

    while (completed < p) {
        bool idle = true;
        for (int i = 0; i < p; i++) {
            if (remBT[i] > 0) {
                idle = false;
                int execTime = (remBT[i] < qt) ? remBT[i] : qt;
                remBT[i] -= execTime;
                time += execTime;

                if (remBT[i] == 0 && !track[i]) {
                    CT[i] = time;
                    TAT[i] = CT[i] - AT[i];
                    WT[i] = TAT[i] - BT[i];
                    totalWT += WT[i];
                    totalTAT += TAT[i];
                    track[i] = true;
                    completed++;

                    printf("P%d\t\t%d\t%d\t%d\t%d\n", pro[i], BT[i], CT[i], TAT[i], WT[i]);
                }
            }
        }
        if (idle){
            time++;
        }
             // If no process is ready, increment time
    }

    printf("\nAverage Turnaround Time: %.2f", (float)totalTAT / p);
    printf("\nAverage Waiting Time: %.2f", (float)totalWT / p);
    printf("\nThroughput: %.2f\n", (float)p / time);

    return 0;
}

