#include <stdio.h>

int main() {
    int p, f;
    printf("Enter number of pages: ");
    scanf("%d", &p);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int page[p];
    printf("Enter the pages: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &page[i]);
    }

    int pm[f][p];   // Page matrix to track frame states over time
    int frame[f];   // Current frames
    int countMiss = 0, countHit = 0;
    int index = 0;  // FIFO index

    // Initialize frames and matrix with -1
    for (int i = 0; i < f; i++) {
        frame[i] = -1;
        for (int j = 0; j < p; j++) {
            pm[i][j] = -1;
        }
    }

    for (int i = 0; i < p; i++) {
        int hit = 0;

        // Check for hit
        for (int j = 0; j < f; j++) {
            if (frame[j] == page[i]) {
                countHit++;
                hit = 1;
                break;
            }
        }

        // Miss - Replace using FIFO
        if (!hit) {
            frame[index] = page[i];
            index = (index + 1) % f;
            countMiss++;
        }

        // Store current frame state into matrix
        for (int j = 0; j < f; j++) {
            pm[j][i] = frame[j];
        }
    }

    // Print page matrix
    printf("\nPage Replacement Table:\n");
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < p; j++) {
            if (pm[i][j] == -1) printf("  - ");
            else printf("%3d ", pm[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal Hits: %d", countHit);
    printf("\nTotal Misses: %d\n", countMiss);

    return 0;
}
