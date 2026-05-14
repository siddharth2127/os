#include <stdio.h>

int main()
{
    int at[10], bt[10], pr[10], rt[10];
    int wt[10], tat[10];
    int n, i, time = 0;

    int complete = 0;
    int highest;
    int min;
    int check;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time, Burst Time and Priority for P%d: ", i + 1);

        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);

        rt[i] = bt[i];
    }

    while(complete != n)
    {
        min = 9999;
        check = 0;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && pr[i] < min && rt[i] > 0)
            {
                min = pr[i];
                highest = i;
                check = 1;
            }
        }

        if(check == 0)
        {
            time++;
            continue;
        }

        printf("P%d ", highest + 1);

        rt[highest]--;

        if(rt[highest] == 0)
        {
            complete++;

            wt[highest] =
            time + 1 - bt[highest] - at[highest];

            if(wt[highest] < 0)
            {
                wt[highest] = 0;
            }

            tat[highest] =
            bt[highest] + wt[highest];
        }

        time++;
    }

    printf("\n\nProcess\tAT\tBT\tPR\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               pr[i],
               wt[i],
               tat[i]);
    }

    return 0;
}