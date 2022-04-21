#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>

int main()
{

    // for holding file descrypters of employee accordingly
    int fd[10][2];

    // for holding the times
    char startAt[5];
    char endAt[5];

    // main as the owner and child as employees
    // taking the input from the onwer
    printf("\n ::::::::::::::::::: Owner ::::::::::::::::::: \n");

    // taking input
    printf("\n Enter The Starting time : ");
    scanf("%[^\n]%*c", startAt);

    // taking input
    printf("\n Enter The Ending time : ");
    scanf("%[^\n]%*c", endAt);

    printf("\n\t The Metting Time is : %s - %s \n", startAt, endAt);
    printf("\n ::::::::::::::::::::::::::::::::::::::::::::: \n");

    printf("\n :::::::::::::::: Employees :::::::::::::::::: \n");
    printf("\n\t The Metting Time is : %s - %s \n", startAt, endAt);
    printf("\n ::::::::::::::::::::::::::::::::::::::::::::: \n\n");

    // creating a single pipe till here so be accessed by both parent and child
    pipe(fd[0]);

    // making 10 employee
    pid_t emp1 = fork();

    if (emp1 == 0)
    {
        // closing pipe reading end here
        close(fd[0][0]);

        // the input
        char inputResponse[2];

        // for making pipes
        // child
        do
        {
            // taking response of the employee
            printf("\n Employee 1 :- Are you available at the above time slot :- (Y/N) : ");
            scanf("%c", inputResponse);

            // removing the input buffer ... same as cin.ignore
            while ((getchar()) != '\n')
                ;

            // validating and not accepting other characters
        } while (!(inputResponse[0] == 'y' || inputResponse[0] == 'Y' || inputResponse[0] == 'n' || inputResponse[0] == 'N'));

        inputResponse[1] = '\0';

        // writing response to pipe
        write(fd[0][1], inputResponse, sizeof(inputResponse));
    }
    else
    {
        wait(NULL);
        
        // making second pipe
        pipe(fd[1]); //the second employee
        // making the second child
        pid_t emp2 = fork();

        if (emp2 == 0)
        {
            // closing pipe reading end here
            close(fd[1][0]);

            // the input
            char inputResponse[2];

            // for making pipes
            // child
            do
            {
                // taking response of the employee
                printf("\n Employee 2 :- Are you available at the above time slot :- (Y/N) : ");
                scanf("%c", inputResponse);

                // removing the input buffer ... same as cin.ignore
                while ((getchar()) != '\n')
                    ;

                // validating and not accepting other characters
            } while (!(inputResponse[0] == 'y' || inputResponse[0] == 'Y' || inputResponse[0] == 'n' || inputResponse[0] == 'N'));

            inputResponse[1] = '\0';

            // writing response to pipe
            write(fd[1][1], inputResponse, sizeof(inputResponse));
        }

        wait(NULL);

      
        // wait(NULL);
        // // for parent closing the writing end only can read
        // close(fd[0][1]);
        // char ansEmp1[2];
        // read(fd[0][0], ansEmp1, sizeof(ansEmp1));
        // printf("n : %s \n", ansEmp1);
    }

    return 0;
}