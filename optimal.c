#include <stdio.h>

int main()
{
    int pages[50], fifo[10], optimal[10];
    int n, frames;
    int i, j, k;

    int fifoFault = 0, optimalFault = 0;
    int index = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
    {
        fifo[i] = -1;
        optimal[i] = -1;
    }

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < frames; j++)
        {
            if(fifo[j] == pages[i])
            {
                found = 1;
            }
        }

        if(found == 0)
        {
            fifo[index] = pages[i];

            index = (index + 1) % frames;

            fifoFault++;
        }
    }

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < frames; j++)
        {
            if(optimal[j] == pages[i])
            {
                found = 1;
            }
        }

        if(found == 0)
        {
            int pos = 0;
            int far = -1;

            for(j = 0; j < frames; j++)
            {
                int next = 999;

                for(k = i + 1; k < n; k++)
                {
                    if(optimal[j] == pages[k])
                    {
                        next = k;
                        break;
                    }
                }

                if(next > far)
                {
                    far = next;
                    pos = j;
                }
            }

            optimal[pos] = pages[i];

            optimalFault++;
        }
    }

    printf("\nFIFO Page Faults = %d", fifoFault);

    printf("\nOptimal Page Faults = %d\n", optimalFault);

    return 0;
}