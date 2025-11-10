#include <stdio.h>

int main()
{
int n, i, completed_processes = 0, time = 0, shortest = -1;
float total_tat = 0, total_wt = 0;

printf("Enter the number of processes: ");
scanf("%d", &n);

int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], pid[n];
int is_completed[n];
int gantt_chart[1000];

for (i = 0; i < n; i++)
{
pid[i] = i + 1;
is_completed[i] = 0;
}

for (i = 0; i < n; i++) {
printf("Enter the arrival time for process %d: ", i + 1);
scanf("%d", &at[i]);
printf("Enter the burst time for process %d: ", i + 1);
scanf("%d", &bt[i]);
rt[i] = bt[i];
}

while (completed_processes < n) {
shortest = -1;
for (i = 0; i < n; i++) {
if (at[i] <= time && !is_completed[i]) {
if (shortest == -1 || rt[i] < rt[shortest]) {
shortest = i;
}
}
}

if (shortest != -1) {
gantt_chart[time] = pid[shortest];
rt[shortest]--;
time++;

if (rt[shortest] == 0) {
completed_processes++;
is_completed[shortest] = 1;
ct[shortest] = time;
tat[shortest] = ct[shortest] - at[shortest];
wt[shortest] = tat[shortest] - bt[shortest];
}
} else {
gantt_chart[time] = 0;
time++;
}
}

printf("\nGantt Chart:\n|");
for (i = 0; i < time; i++) {
if (gantt_chart[i] == 0)
printf(" Idle |");
else
printf(" P%d |", gantt_chart[i]);
}
printf("\n0");
for (i = 1; i <= time; i++) {
printf(" %d", i);
}
printf("\n");

for (i = 0; i < n; i++) {
total_tat += tat[i];
total_wt += wt[i];
}

printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
for (i = 0; i < n; i++) {
printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
}

printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
printf("Average Waiting Time: %.2f\n", total_wt / n);

return 0;
}
