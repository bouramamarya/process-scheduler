#include <stdio.h>

int main() {
    int n;
    int arrival[100], burst[100];
    int finish[100], turnaround[100], waiting[100];
    float avg_wait = 0, avg_turn = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nTask %d\n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &arrival[i]);
        printf("Enter burst time: ");
        scanf("%d", &burst[i]);
    }

    // FCFS calculations
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            finish[i] = arrival[i] + burst[i];
        } else {
            if (finish[i - 1] > arrival[i])
                finish[i] = finish[i - 1] + burst[i];
            else
                finish[i] = arrival[i] + burst[i];
        }

        turnaround[i] = finish[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];

        avg_wait += waiting[i];
        avg_turn += turnaround[i];
    }

    avg_wait /= n;
    avg_turn /= n;

    // Output table
    printf("\n-----------------------------------------------------------\n");
    printf("Task\tArrival\tDuration\tFinish\tTotal Time\tWait Time\n");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\t\t%d\n",
               i + 1, arrival[i], burst[i],
               finish[i], turnaround[i], waiting[i]);
    }

    printf("-----------------------------------------------------------\n");
    printf("Average Total Time: %.2f\n", avg_turn);
    printf("Average Wait Time: %.2f\n", avg_wait);

    return 0;
}