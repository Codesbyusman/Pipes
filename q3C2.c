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

    pid_t emp1, emp2, emp3, emp4, emp5, emp6, emp7, emp8, emp9, emp10;
    // for holding file descrypters of employee accordingly
    int fd[10][2];

    // for holding the times
    char startAt[5];
    char endAt[5];

    int loopCount = 0;

    bool timeSelected = false;

    while (1 && !timeSelected)
    {

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

        // making pipes
        for (int i = 0; i < 10; i++)
        {
            pipe(fd[i]);
        }

        // making 10 employee
        // if (loopCount == 0)
        emp1 = fork();

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
            timeSelected = true;

            // writing response to pipe
            write(fd[0][1], inputResponse, sizeof(inputResponse));
        }
        else
        {
            wait(NULL);

            // making the second child
            // if (loopCount == 0)
            emp2 = fork();

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

                timeSelected = true;

                // writing response to pipe
                write(fd[1][1], inputResponse, sizeof(inputResponse));
            }
            else
            {
                wait(NULL);

                // making the third  child
                // if (loopCount == 0)
                emp3 = fork();

                if (emp3 == 0)
                {
                    // closing pipe reading end here
                    close(fd[2][0]);

                    // the input
                    char inputResponse[2];

                    // for making pipes
                    // child
                    do
                    {
                        // taking response of the employee
                        printf("\n Employee 3 :- Are you available at the above time slot :- (Y/N) : ");
                        scanf("%c", inputResponse);

                        // removing the input buffer ... same as cin.ignore
                        while ((getchar()) != '\n')
                            ;

                        // validating and not accepting other characters
                    } while (!(inputResponse[0] == 'y' || inputResponse[0] == 'Y' || inputResponse[0] == 'n' || inputResponse[0] == 'N'));

                    inputResponse[1] = '\0';

                    timeSelected = true;

                    // writing response to pipe
                    write(fd[2][1], inputResponse, sizeof(inputResponse));
                }
                else
                {
                    wait(NULL);

                    // if (loopCount == 0)
                    emp4 = fork();

                    if (emp4 == 0)
                    {
                        // closing pipe reading end here
                        close(fd[3][0]);

                        // the input
                        char inputResponse[2];

                        // for making pipes
                        // child
                        do
                        {
                            // taking response of the employee
                            printf("\n Employee 4 :- Are you available at the above time slot :- (Y/N) : ");
                            scanf("%c", inputResponse);

                            // removing the input buffer ... same as cin.ignore
                            while ((getchar()) != '\n')
                                ;

                            // validating and not accepting other characters
                        } while (!(inputResponse[0] == 'y' || inputResponse[0] == 'Y' || inputResponse[0] == 'n' || inputResponse[0] == 'N'));

                        inputResponse[1] = '\0';

                        timeSelected = true;

                        // writing response to pipe
                        write(fd[3][1], inputResponse, sizeof(inputResponse));
                    }
                    else
                    {
                        wait(NULL);

                        // making the fifth  child
                        // if (loopCount == 0)
                        emp5 = fork();

                        if (emp5 == 0)
                        {
                            // closing pipe reading end here
                            close(fd[4][0]);

                            // the input
                            char inputResponse[2];

                            // for making pipes
                            // child
                            do
                            {
                                // taking response of the employee
                                printf("\n Employee 5 :- Are you available at the above time slot :- (Y/N) : ");
                                scanf("%c", inputResponse);

                                // removing the input buffer ... same as cin.ignore
                                while ((getchar()) != '\n')
                                    ;

                                // validating and not accepting other characters
                            } while (!(inputResponse[0] == 'y' || inputResponse[0] == 'Y' || inputResponse[0] == 'n' || inputResponse[0] == 'N'));

                            inputResponse[1] = '\0';
                            timeSelected = true;
                            // writing response to pipe
                            write(fd[4][1], inputResponse, sizeof(inputResponse));
                        }
                        else
                        {
                            wait(NULL);

                            // if (loopCount == 0)
                            emp6 = fork();

                            if (emp6 == 0)
                            {
                                // closing pipe reading end here
                                close(fd[5][0]);

                                // the input
                                char inputResponse[2];

                                // for making pipes
                                // child
                                do
                                {
                                    // taking response of the employee
                                    printf("\n Employee 6 :- Are you available at the above time slot :- (Y/N) : ");
                                    scanf("%c", inputResponse);

                                    // removing the input buffer ... same as cin.ignore
                                    while ((getchar()) != '\n')
                                        ;

                                    // validating and not accepting other characters
                                } while (!(inputResponse[0] == 'y' || inputResponse[0] == 'Y' || inputResponse[0] == 'n' || inputResponse[0] == 'N'));

                                inputResponse[1] = '\0';

                                // writing response to pipe
                                write(fd[5][1], inputResponse, sizeof(inputResponse));
                                timeSelected = true;
                            }
                            else
                            {
                                wait(NULL);

                                // making the seventh  child
                                // if (loopCount == 0)
                                emp7 = fork();

                                if (emp7 == 0)
                                {
                                    // closing pipe reading end here
                                    close(fd[6][0]);

                                    // the input
                                    char inputResponse[2];

                                    // for making pipes
                                    // child
                                    do
                                    {
                                        // taking response of the employee
                                        printf("\n Employee 7 :- Are you available at the above time slot :- (Y/N) : ");
                                        scanf("%c", inputResponse);

                                        // removing the input buffer ... same as cin.ignore
                                        while ((getchar()) != '\n')
                                            ;

                                        // validating and not accepting other characters
                                    } while (!(inputResponse[0] == 'y' || inputResponse[0] == 'Y' || inputResponse[0] == 'n' || inputResponse[0] == 'N'));

                                    inputResponse[1] = '\0';

                                    // writing response to pipe
                                    write(fd[6][1], inputResponse, sizeof(inputResponse));
                                    timeSelected = true;
                                }
                                else
                                {
                                    wait(NULL);

                                    // making the eigth  child
                                    // if (loopCount == 0)
                                    emp8 = fork();

                                    if (emp8 == 0)
                                    {
                                        // closing pipe reading end here
                                        close(fd[7][0]);

                                        // the input
                                        char inputResponse[2];

                                        // for making pipes
                                        // child
                                        do
                                        {
                                            // taking response of the employee
                                            printf("\n Employee 8 :- Are you available at the above time slot :- (Y/N) : ");
                                            scanf("%c", inputResponse);

                                            // removing the input buffer ... same as cin.ignore
                                            while ((getchar()) != '\n')
                                                ;

                                            // validating and not accepting other characters
                                        } while (!(inputResponse[0] == 'y' || inputResponse[0] == 'Y' || inputResponse[0] == 'n' || inputResponse[0] == 'N'));

                                        inputResponse[1] = '\0';

                                        // writing response to pipe
                                        write(fd[7][1], inputResponse, sizeof(inputResponse));
                                        timeSelected = true;
                                    }
                                    else
                                    {
                                        wait(NULL);

                                        // making the ninth  child
                                        // if (loopCount == 0)
                                        emp9 = fork();

                                        if (emp9 == 0)
                                        {
                                            // closing pipe reading end here
                                            close(fd[8][0]);

                                            // the input
                                            char inputResponse[2];

                                            // for making pipes
                                            // child
                                            do
                                            {
                                                // taking response of the employee
                                                printf("\n Employee 9 :- Are you available at the above time slot :- (Y/N) : ");
                                                scanf("%c", inputResponse);

                                                // removing the input buffer ... same as cin.ignore
                                                while ((getchar()) != '\n')
                                                    ;

                                                // validating and not accepting other characters
                                            } while (!(inputResponse[0] == 'y' || inputResponse[0] == 'Y' || inputResponse[0] == 'n' || inputResponse[0] == 'N'));

                                            inputResponse[1] = '\0';

                                            // writing response to pipe
                                            write(fd[8][1], inputResponse, sizeof(inputResponse));
                                            timeSelected = true;
                                        }
                                        else
                                        {
                                            wait(NULL);

                                            // making the tenth  child
                                            // if (loopCount == 0)
                                            emp10 = fork();

                                            if (emp10 == 0)
                                            {
                                                // closing pipe reading end here
                                                close(fd[9][0]);

                                                // the input
                                                char inputResponse[2];

                                                // for making pipes
                                                // child
                                                do
                                                {
                                                    // taking response of the employee
                                                    printf("\n Employee 10 :- Are you available at the above time slot :- (Y/N) : ");
                                                    scanf("%c", inputResponse);

                                                    // removing the input buffer ... same as cin.ignore
                                                    while ((getchar()) != '\n')
                                                        ;

                                                    // validating and not accepting other characters
                                                } while (!(inputResponse[0] == 'y' || inputResponse[0] == 'Y' || inputResponse[0] == 'n' || inputResponse[0] == 'N'));

                                                inputResponse[1] = '\0';

                                                // writing response to pipe
                                                write(fd[9][1], inputResponse, sizeof(inputResponse));
                                                timeSelected = true;
                                            }
                                            else
                                            {
                                                // the parent
                                                wait(NULL);
                                                printf("\n\n");

                                                // checking the pipes result and parent is close for writing in all pipes
                                                for (int i = 0; i < 10; i++)
                                                {
                                                    close(fd[i][1]);
                                                }

                                                // now reading childs input and deciding the future
                                                char ansEmp[2] = " ";
                                                int i = 0; // counter
                                                while (!(ansEmp[0] == 'n' || ansEmp[0] == 'N') && i <= 9)
                                                {
                                                    read(fd[i][0], ansEmp, sizeof(ansEmp));
                                                    i++;
                                                }

                                                // checking if last was Y then breaking as all said yes
                                                if (ansEmp[0] == 'Y' || ansEmp[0] == 'y')
                                                {
                                                    // also displaying the time
                                                    printf("\n ::::::::::::::::::::::::::::::::::::::::::::: \n\n");
                                                    printf("\n\t The Metting Time is : %s - %s \n", startAt, endAt);
                                                    printf("\n ::::::::::::::: Confirmed ::::::::::::::::::: \n");
                                                    printf("\n ::::::::::::::::::::::::::::::::::::::::::::: \n\n");

                                                    break; // breaking as time slot selected
                                                }

                                                loopCount++;

                                                printf("\n\n\t ::::::::::::::::: Aigan ::::::::::::::::::::: \n\n");
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}