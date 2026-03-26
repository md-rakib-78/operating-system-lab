#include <stdio.h>

#define MAX 100

int main() {
    int qt;
    printf("Enter Quantum Time: ");
    scanf("%d", &qt);

    int p;
    printf("Enter number of processes: ");
    scanf("%d", &p);

    int pro[p], BT[p], AT[p], remBT[p], WT[p], CT[p], TAT[p];
    int totalWT = 0, totalTAT = 0;

    printf("Enter Arrival Times: ");
    for (int i = 0; i < p; i++) {
        pro[i] = i + 1;
        scanf("%d", &AT[i]);
    }

    printf("Enter Burst Times: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &BT[i]);
        remBT[i] = BT[i];
    }

    int queue[MAX];
    int front = 0, rear = 0;
    int time = 0, completed = 0;
    int visited[p];
    for (int i = 0; i < p; i++)
    {
        visited[i] = 0;
    }

    // Initially enqueue processes that arrive at time 0
    for (int i = 0; i < p; i++) {
        if (AT[i] == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    printf("\nProcess\tArrival\tBurst\tComp\tTurn\tWait\n");

    while (completed < p) {
        if (front == rear) { // CPU idle
            time++;
            for (int i = 0; i < p; i++) {
                if (!visited[i] && AT[i] <= time) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];
        int execTime = (remBT[idx] < qt) ? remBT[idx] : qt;
        remBT[idx] -= execTime;
        time += execTime;

        // Add newly arrived processes during execution
        for (int i = 0; i < p; i++) {
            if (!visited[i] && AT[i] <= time) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if (remBT[idx] > 0) {
            queue[rear++] = idx; // Re-queue unfinished process
        } else {
            CT[idx] = time;
            TAT[idx] = CT[idx] - AT[idx];
            WT[idx] = TAT[idx] - BT[idx];
            totalWT += WT[idx];
            totalTAT += TAT[idx];
            completed++;
            printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pro[idx], AT[idx], BT[idx], CT[idx], TAT[idx], WT[idx]);
        }
    }

    printf("\nAverage Turnaround Time: %.2f", (float)totalTAT / p);
    printf("\nAverage Waiting Time: %.2f", (float)totalWT / p);
    printf("\nThroughput: %.2f\n", (float)p / time);

    return 0;
}
