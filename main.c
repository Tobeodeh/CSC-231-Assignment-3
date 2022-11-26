#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

int main()
{
    //Open the file
    FILE*str=fopen("files.txt","r");
    if(str == NULL)
    {
        printf("The file is empty");
        exit(0);
    }

    int t, n, i;
    //read number of test cases
    fscanf(str,"%d",&t);
    for(int i=0;i<t;i++)
    {
        fscanf(str,"%d",&n);
        int ids[n];
        char names[n];
        // perform insertion sort according to the id
        fscanf(str,"%s %d", names[0],&ids[0]);
        int current = 0, j;
        for(j=1; j<n; j++)
        {
            int k = j-1;
            int id;
            char name;
            fscanf(str,"%s %d",name,&id);
            while(k>=0 && ids[k] > id)
            {
                ids[k+1] = ids[k];
                names[k+1] = names[k];
                k--;
            }
            ids[k+1] = id;
            names[k+1] = name;
        }
        // remove any duplicate file
        int k;
        for(j=0; j<n; j++)
        {
            for(k=j+1; k<n; k++)
            {
                if(names[j] == names[k])
                ids[k] = -1;
            }
        }
        // display non deleted file
        for(j=0; j<n; j++)
        {
            int count;
            if(ids[j] != -1){
                printf("%d", &ids[j], " ");
            }
        printf("%d",&count);
        }

    }
}


    //return 0;

