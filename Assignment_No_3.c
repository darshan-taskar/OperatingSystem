#include <stdio.h>
void SRTF(int n, int BT[], int AT[])
{
    printf("*********SRTF***************\n");
    int temp[n];
    float TAT = 0;
    float WT = 0;
    int sum = 0;
    int count = 0;
    int smallest;
    int exittime;
    int index;
    for (int i = 0; i < n; i++)
    {
        temp[i] = BT[i];
    }
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for (sum = 0; count != n; sum++)
    {
        smallest = 9999;
        for (int i = 0; i < n; i++)
        {
            if (AT[i] <= sum && temp[i] < smallest && temp[i] > 0)
            {
                smallest = temp[i];
                index = i;
            }
        }
        temp[index]--;
        if (temp[index] == 0)
        {
            count++;
            exittime = sum + 1;
            TAT = TAT + exittime - AT[index];
            WT = WT + exittime - AT[index] - BT[index];
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", index + 1, BT[index], exittime - AT[index], exittime - AT[index] - BT[index]);
        }
    }
    printf("\n");
    double avg_wt = WT / n;
    double avg_tat = TAT / n;
    printf("Average waiting time is: %lf\n", avg_wt);
    printf("Average Turn Around Time: %lf", avg_tat);
}
void Round_Robin(int n, int BT[], int AT[])
{
    printf("*********Round_Robin***************\n");
    int temp[n];
    float TAT = 0;
    float WT = 0;
    int count = 0;
    int exittime = 0;
    int i = 0;
    int y = n;

    for (int i = 0; i < n; i++)
    {
        temp[i] = BT[i];
    }
    int quant;
    printf("Enter time quantum: ");
    scanf("%d", &quant);
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for (exittime = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0)
        {
            exittime = exittime + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            exittime = exittime + quant;
            temp[i] = temp[i] - quant;
        }
        if (count == 1 && temp[i] == 0)
        {
            y--;
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, BT[i], exittime - AT[i],
                   exittime - AT[i] - BT[i]);
            TAT += exittime - AT[i];
            WT += exittime - AT[i] - BT[i];
            count = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (AT[i + 1] <= exittime)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    printf("\n");
    float avg_wt = WT / n;
    float avg_tat = TAT / n;
    printf("Average waiting time is: %f\n", avg_wt);
    printf("Average Turn Around Time: %f", avg_tat);
}
int main()
{
    int n;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    int BT[n];
    int AT[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Arival time and bust time of process %d\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &AT[i]);
        printf("Bust time: ");
        scanf("%d", &BT[i]);
    }
    int choice = 0;
    printf("1.Round_Robin\n2.SRTF\n");
    printf("Enter: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        Round_Robin(n, BT, AT);
    }
    else
    {
        SRTF(n, BT, AT);
    }
    return 0;
}
