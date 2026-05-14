#include <stdio.h>

int main()
{
    int at[10], bt[10], rt[10];
    int wt[10], tat[10];
    int n, i, time = 0;
    int complete = 0, shortest;
    int min;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);

        scanf("%d %d", &at[i], &bt[i]);

        rt[i] = bt[i];
    }

    while(complete != n)
    {
        min = 9999;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] < min && rt[i] > 0)
            {
                min = rt[i];
                shortest = i;
            }
        }

        rt[shortest]--;
        time++;

        if(rt[shortest] == 0)
        {
            complete++;

            wt[shortest] =
            time - bt[shortest] - at[shortest];

            if(wt[shortest] < 0)
            {
                wt[shortest] = 0;
            }

            tat[shortest] =
            bt[shortest] + wt[shortest];
        }
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               wt[i],
               tat[i]);
    }

    return 0;
}