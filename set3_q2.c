#include <stdio.h>

int main() {
    int n, i, j, temp;
    int bt[20], wt[20], tat[20], p[20];
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20) {
        printf("Invalid number of processes\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter burst time for P%d: ", p[i]);
        scanf("%d", &bt[i]);

        if (bt[i] < 0) {
            printf("Invalid burst time\n");
            return 1;
        }
    }

    // Sort processes by burst time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate waiting time
    wt[0] = 0;

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];

        printf("P%d\t%d\t%d\t%d\n",
               p[i], bt[i], wt[i], tat[i]);

        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", avgwt / n);
    printf("Average Turnaround Time = %.2f\n", avgtat / n);

    return 0;
}
