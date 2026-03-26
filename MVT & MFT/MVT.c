#include <stdio.h>

int main() {
    int totalM, p;

    printf("Enter total memory available: ");
    scanf("%d", &totalM);

    printf("Enter number of processes: ");
    scanf("%d", &p);

    int pro[p], memAllo[p];

    for (int i = 0; i < p; i++) {
        printf("Enter memory required for process %d: ", i + 1);
        scanf("%d", &pro[i]);
        memAllo[i] = 0;
    }

    int allocated = 0;
    for (int i = 0; i < p; i++) {
        if (allocated + pro[i] <= totalM) {
            memAllo[i] = pro[i];
            allocated += pro[i];
        } else {
            memAllo[i] = 0;
        }
    }

    int exF = totalM - allocated;

    printf("\nMemory is FULL\n");
    printf("Total memory available = %d\n", totalM);
    printf("\nProcess\tMemory Allocated\n");
    for (int i = 0; i < p; i++) {
        if (memAllo[i] > 0)
            printf("%d\t%d\n", i + 1, memAllo[i]);
        else
            printf("%d\tNot Allocated\n", i + 1);
    }

    printf("\nTotal memory allocated = %d\n", allocated);
    printf("Total external fragmentation = %d\n", exF);

    return 0;
}

