
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

    int frame[f];
    int countMiss = 0, countHit = 0;
    int track[f];

    for (int i = 0; i < f; i++) {
        frame[i] = -1;
        track[i] = -1;
    }

    for (int i = 0; i < p; i++) {
        printf("\nFOR %d: ", page[i]);
        int hit = 0;


        for (int j = 0; j < f; j++) {
            if (frame[j] == page[i]) {
                hit = 1;
                countHit++;
                printf("Hit the page! ");
                break;
            }
        }


        if (!hit) {
            int placed = 0;

            for (int j = 0; j < f; j++) {
                if (frame[j] == -1) {
                    frame[j] = page[i];
                    countMiss++;
                    placed = 1;
                    break;
                }
            }

            if (!placed) {
                int infinit = -1;

                for (int j = 0; j < f; j++) {

                    track[j] = -1;

                    for (int k = i - 1; k >= 0; k--) {

                        if (frame[j] == page[k]) {

                            track[j] = k;
                            break;
                        }
                    }
                    if (track[j] == -1) {
                        infinit = frame[j];
                    }
                }


                if (infinit != -1) {
                    for (int j = 0; j < f; j++) {
                        if (frame[j] == infinit) {
                            frame[j] = page[i];
                            break;
                        }
                    }
                } else {
                    int min = 0;
                    for (int j = 1; j < f; j++) {
                        if (track[j] < track[min]) {
                            min = j;
                        }
                    }
                    frame[min] = page[i];
                }
                countMiss++;
            }

            for (int j = 0; j < f; j++)
            {
                printf(" %d ", frame[j]);
            }
        }
    }

    printf("\n\nTotal Hits: %d", countHit);
    printf("\nTotal Misses: %d\n", countMiss);
}
