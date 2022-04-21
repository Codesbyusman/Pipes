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
        pipe(fd[1]); // the second employee
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
        else
        {
            wait(NULL);

            // making third  pipe
            pipe(fd[2]); // the third  employee
            // making the third  child
            pid_t emp3 = fork();

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

                // writing response to pipe
                write(fd[2][1], inputResponse, sizeof(inputResponse));
            }
            else
            {
                wait(NULL);

                // making fourth  pipe
                pipe(fd[3]); // the fourth  employee
                // making the fourth  child
                pid_t emp4 = fork();

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

                    // writing response to pipe
                    write(fd[3][1], inputResponse, sizeof(inputResponse));
                }
                else
                {
                    wait(NULL);

                    // making fifth  pipe
                    pipe(fd[4]); // the fifth  employee
                    // making the fifth  child
                    pid_t emp5 = fork();

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

                        // writing response to pipe
                        write(fd[4][1], inputResponse, sizeof(inputResponse));
                    }
                    else
                    {
                        wait(NULL);

                        // making sixth  pipe
                        pipe(fd[5]); // the sixth  employee
                        // making the sixth  child
                        pid_t emp6 = fork();

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
                        }
                        else
                        {
                            wait(NULL);

                            // making seventh  pipe
                            pipe(fd[6]); // the seventh  employee
                            // making the seventh  child
                            pid_t emp7 = fork();

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
                            }
                            else
                            {
                                wait(NULL);

                                // making eigth  pipe
                                pipe(fd[7]); // the eigth  employee
                                // making the eigth  child
                                pid_t emp8 = fork();

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
                                }
                                else
                                {
                                    wait(NULL);

                                    // making ninth  pipe
                                    pipe(fd[8]); // the ninth  employee
                                    // making the ninth  child
                                    pid_t emp9 = fork();

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
                                    }
                                    else
                                    {
                                        wait(NULL);

                                        // making tenth  pipe
                                        pipe(fd[9]); // the tenth  employee
                                        // making the tenth  child
                                        pid_t emp9 = fork();

                                        if (emp9 == 0)
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
                                            char ansEmp[2];
                                            int i = 0; //counter
                                            while (!(ansEmp[0] == 'n' || ansEmp[0] == 'N') && i <= 9)
                                            {
                                                read(fd[i][0], ansEmp, sizeof(ansEmp));
                                                i++;
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