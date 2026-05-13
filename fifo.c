#include <stdio.h>
#include <stdlib.h>

int pagefault(int a[],int frame[],int n,int no) {

    int i,j=0,count=0,k;

    for(i=0;i<no;i++) 
        frame[i]=-1;

    for(i=0;i<n;i++) {

        int avail=0;

        for(k=0;k<no;k++)
            if(frame[k]==a[i])
                avail=1;

        if(avail==0) {

            frame[j]=a[i];
            j=(j+1)%no;
            count++;
        }
    }

    return count;
}

int main() {

    int n,no,fault,i;
    int *a,*frame;

    printf("ENTER THE NUMBER OF PAGES: ");
    scanf("%d",&n);

    a=(int*)malloc(n*sizeof(int));

    printf("ENTER THE PAGE NUMBER: ");

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("ENTER THE NUMBER OF FRAMES: ");
    scanf("%d",&no);

    frame=(int*)malloc(no*sizeof(int));

    fault=pagefault(a,frame,n,no);

    printf("Page Faults: %d\n",fault);

    return 0;
}