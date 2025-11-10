#include <stdio.h>

int main() {
    int pages[30], frames[10];
    int n, f, i, j, k = 0, hit, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++) {
        hit = 0;
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                hit = 1;
                break;
            }
        }

        if (hit == 0) {
            frames[k] = pages[i];
            k = (k + 1) % f;
            faults++;
        }

        printf("%d\t", pages[i]);
        for (j = 0; j < f; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}


#include <stdio.h>

int main() {
    int pages[30], frames[10];
    int n, f, i, j, k, faults = 0, recent[10];

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frames[i] = -1;
        recent[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++) {
        int hit = 0;

        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                hit = 1;
                recent[j] = i + 1; // update recent use
                break;
            }
        }

        if (hit == 0) {
            int lru = 0;
            for (j = 1; j < f; j++)
                if (recent[j] < recent[lru])
                    lru = j;

            frames[lru] = pages[i];
            recent[lru] = i + 1;
            faults++;
        }

        printf("%d\t", pages[i]);
        for (k = 0; k < f; k++) {
            if (frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
