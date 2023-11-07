#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);
    findTurnaroundTime(processes, n, bt, wt, tat);

    printf("Process  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    float average_wt = (float)total_wt / n;
    float average_tat = (float)total_tat / n;
    printf("\nAverage Waiting Time = %.2f\n", average_wt);
    printf("Average Turnaround Time = %.2f\n", average_tat);
}

int main() {
    int processes[] = {1, 2, 3, 4}; // Process IDs
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {6, 8, 7, 3}; // Burst time for each process

    findAverageTime(processes, n, burst_time);

    return 0;
}

