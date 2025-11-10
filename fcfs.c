#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    int total_wt = 0, total_tat = 0;
    int time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i+1);
        scanf("%d", &at[i]);
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
    }
    
    for (i = 0; i < n; i++) {
        if (time < at[i])   // CPU is idle
            time = at[i];
        time += bt[i];
        ct[i] = time;                  // completion time
        tat[i] = ct[i] - at[i];        // turnaround time
        wt[i] = tat[i] - bt[i];        // waiting time
        total_wt += wt[i];
        total_tat += tat[i];
    }
    // Output Table
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Waiting Time = %.2f", (float)total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat/n);

    // Gantt Chart
    printf("\nGantt Chart:\n");
    int current_time = 0;
    for (i = 0; i < n; i++) {
        if (current_time < at[i]) {
            printf("| Idle ");
            current_time = at[i];
        }
        printf("| P%d ", i+1);
        current_time += bt[i];
    }
    printf("|\n");
    current_time = 0;
    printf("0");
    
    for (i = 0; i < n; i++) {
        if (current_time < at[i]) {
            current_time = at[i];
            printf("   %d", current_time);
        }
        current_time += bt[i];
        printf("   %d", current_time);
    }
    printf("\n");

    return 0;
}
