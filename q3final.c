#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{

    // for holding the times
    char timeSlot[10] = " ";

    // making the pipes 20 unmed pipes
    int fd[20][2];

    // making 20 unmmed pipes
    for (int i = 0; i < 20; i++)
    {
        // making pipes
        pipe(fd[i]);
    }

    // will use 1 for the writing date and other for taking the response
    // main as the owner and child as employees
    // taking the input from the onwer
    printf("\n ::::::::::::::::::: Owner ::::::::::::::::::: \n");

    // taking input
    printf("\n Enter The meeting time : ");
    scanf("%[^\n]%*c", timeSlot);

    printf("\n\t The Metting Time is : %s \n", timeSlot);
    printf("\n ::::::::::::::::::::::::::::::::::::::::::::: \n");

    printf("\n :::::::::::::::: Employees :::::::::::::::::: \n");
    printf("\n\t The Metting Time is : %s \n", timeSlot);
    printf("\n ::::::::::::::::::::::::::::::::::::::::::::: \n\n");

    //------------------------------------

    // writing times into the pipe
    // these will be access by childs these pipes are only write for the parent
    for (int i = 0; i < 10; i++)
    {
        // closing
        close(fd[i][0]);
        // writing in the pipes
        write(fd[i][1], timeSlot, sizeof(timeSlot));
    }

    // these will be access by childs these pipes are only write for the parent
    for (int i = 10; i < 20; i++)
    {
        // closing
        close(fd[i][1]); // closing writing
        // writing in the pipes
        // will use for reading
    }

    // creating the childs and then will read response from that pipes
    pid_t pid[10];

    // creating childs
    pid[0] = fork(); // first child

    if (pid[0] == 0)
    {

        // closing the writing
        close(fd[0][1]);  // close writing
        close(fd[10][0]); // closing reading

        // child
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
        write(fd[10][1], inputResponse, sizeof(inputResponse));
    }
    else
    {
        // wait(NULL);
        // // parent
        // char buff[2];
        // read(fd[10][0], buff , sizeof(buff));
        // printf("\n%s\n" , buff);
        
        // // another child
        // pid[1] = fork();
        // if (pid[1] == 0)
        // {
        //     // closing the writing
        //     close(fd[1][1]);  // close writing
        //     close(fd[11][0]); // closing reading
        // }

        

        // // else
        // // {
        // //     // parent

        // //     // another child
        // //     pid[2] = fork();
        // //     if (pid[2] == 0)
        // //     {
        // //     }
        // //     else
        // //     {
        // //         // parent

        // //         // another child
        // //         pid[3] = fork();
        // //         if (pid[3] == 0)
        // //         {
        // //         }
        // //         else
        // //         {
        // //             // parent

        // //             // another child
        // //             pid[4] = fork();
        // //             if (pid[4] == 0)
        // //             {
        // //             }
        // //         }
        // //     }
        // // }
    }

    return 0;
}