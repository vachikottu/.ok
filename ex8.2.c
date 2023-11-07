#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sjf(int n, int burst_time[], int waiting_time[], int turnaround_time[]) {
    int completion_time[n];
    int remaining_time[n];

    for (int i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
    }

    int min_index, min_value;
    int time = 0;
    int completed = 0;

    while (completed < n) {
        min_index = -1;
        min_value = 9999; // A large value to find the minimum

        // Find the process with the shortest remaining time
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && remaining_time[i] < min_value && time >= burst_time[i]) {
                min_index = i;
                min_value = remaining_time[i];
            }
        }

        if (min_index == -1) {
            time++;
            continue;
        }

        // Update waiting time and completion time
        waiting_time[min_index] = time - burst_time[min_index];
        completion_time[min_index] = time + burst_time[min_index];
        turnaround_time[min_index] = completion_time[min_index];

        // Mark the process as completed
        remaining_time[min_index] = 0;
        completed++;
        time = completion_time[min_index];
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n];
    int waiting_time[n];
    int turnaround_time[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    sjf(n, burst_time, waiting_time, turnaround_time);

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    return 0;
}
