#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int a[5];
    printf("Enter numbers to be sorted\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Enter: ");
        scanf("%d", &a[i]);
    }
    printf("The unsorted integers\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", a[i]);
        printf("\n");
    }
    int pid_t = fork();
    if (pid_t > 0)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4 - i; j++)
            {
                if (a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        printf("****Parent Process*****");
        printf("The process id is: %d\n", getpid());
        printf("The integers in ascending order are:\n");
        for (int i = 0; i < 5; i++)
        {
            printf("%d", a[i]);
            printf("\n");
        }
        wait(NULL);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4 - i; j++)
            {
                if (a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        printf("****Child Process*****");
        printf("The process id is: %d\n", getpid());
        printf("The parent process id is: %d\n", getppid());
        printf("The sorted integers in descending order are:\n");
        for (int i = 4; i >= 0; i--)
        {
            printf("%d", a[i]);
            printf("\n");
        }
    }
}