#include <stdio.h>

int main() {

    int i,j,k,n,frameno,page[50],frame[10],flag,count=0,count1[10]={0};

    printf("Enter number of pages: ");
    scanf("%d",&n);

    printf("Enter page reference string: ");

    for(i=0;i<n;i++)
        scanf("%d",&page[i]);

    printf("Enter number of frames: ");
    scanf("%d",&frameno);

    for(i=0;i<frameno;i++)
        frame[i]=-1;

    printf("Page reference string\tFrames\n");

    for(i=0;i<n;i++) {

        printf("%d\t\t\t",page[i]);

        flag=0;

        for(j=0;j<frameno;j++) {

            if(page[i]==frame[j]) {

                flag=1;
                count1[j]++;
                break;
            }
        }

        if(flag==0) {

            for(j=0;j<frameno;j++) {

                if(frame[j]==-1) {

                    frame[j]=page[i];
                    count1[j]++;
                    count++;
                    break;
                }
            }

            if(j==frameno) {

                int min=0;

                for(k=1;k<frameno;k++)

                    if(count1[k]<count1[min])
                        min=k;

                frame[min]=page[i];
                count1[min]=1;
                count++;
            }
        }

        for(j=0;j<frameno;j++)
            printf("%d\t",frame[j]);

        printf("\n");
    }

    printf("Total Page Faults: %d\n",count);

    return 0;
}