#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

bool loopstart = true;

int main()
{
    char message[200] = " ";
    bool quit = false;

    pid_t child1, child2, child3, child4, child5;

    // the main chid process
    // all 6 pipes wilm be created here and closed accordingly
    // making file descrypter holders
    int fd[6][2];

    // makig the pipes
    for (int i = 0; i < 6; i++)
    {
        pipe(fd[i]); // making pipes
    }

    printf("\n ::::::::::::::::::::::::::::::::::::::::::::: \n");

    // taking input
    printf("\nEnter The message : ");
    scanf("%[^\n]%*c", message);

    printf("\n ::::::::::::::::::::::::::::::::::::::::::::: \n");

startAgain:

    // looking if quit entered
    quit = !strcmp(message, "quit");

    // if quit is written
    if (quit)
    {
        return 0;
    }

    // making childs accordingly
    if (loopstart)
        child1 = fork();

    if (child1 == 0)
    {

        // making other childs
        // making childs accordingly
        if (loopstart)
            child2 = fork();

        if (child2 == 0)
        {
            // making other childs
            // making childs accordingly
            if (loopstart)
                child3 = fork();

            if (child3 == 0)
            {
                // making other childs
                // making childs accordingly
                if (loopstart)
                    child4 = fork();

                if (child4 == 0)
                {
                    // making other childs
                    // making childs accordingly
                    if (loopstart)
                        child5 = fork();

                    if (child5 == 0)
                    {
                        // making other childs
                        // ------------------------------------------------------------------
                        // -------------------- Child 5 Process --------------------------------
                        // ------------------------------------------------------------------

                        // closing pipes accordingly
                        // will use pipe 4 and pipe 5
                        close(fd[4][1]); // write block
                        close(fd[5][0]); // read block

                        // creating copies of standard output and input
                        int defaultRead = dup(0);
                        int defaultWrite = dup(1);

                        // duplicating
                        dup2(fd[4][0], 0); // reading
                        dup2(fd[5][1], 1); // writing

                        char buff[200] = " ";
                        // reading the before in pipe
                        scanf("%[^\n]%*c", buff);

                        // writing into the pipe
                        printf("%s : %d\n", buff, getpid());

                        // restoring defaults
                        dup2(defaultRead, 0);
                        dup2(defaultWrite, 1);

                        // printing on screen
                        printf("5: %s : %d\n", buff, getpid());

                        if (!quit)
                        {
                            loopstart = false;
                            goto startAgain;
                        }
                    }
                    else
                    {
                        // ------------------------------------------------------------------
                        // -------------------- Child 4 Process --------------------------------
                        // ------------------------------------------------------------------

                        // closing pipes accordingly
                        // will use pipe 3 and pipe 4
                        close(fd[3][1]); // write block
                        close(fd[4][0]); // read block

                        // creating copies of standard output and input
                        int defaultRead = dup(0);
                        int defaultWrite = dup(1);

                        // duplicating
                        dup2(fd[3][0], 0); // reading
                        dup2(fd[4][1], 1); // writing

                        char buff[200] = " ";
                        // reading the before in pipe
                        scanf("%[^\n]%*c", buff);

                        // writing into the pipe
                        printf("%s : %d\n", buff, getpid());

                        // restoring defaults
                        dup2(defaultRead, 0);
                        dup2(defaultWrite, 1);

                        // printing on screen
                        printf("4:%s : %d\n", buff, getpid());
                    }

                    // while (!quit)
                    //     ;
                }
                else
                {
                    // ------------------------------------------------------------------
                    // -------------------- Child 3 Process --------------------------------
                    // ------------------------------------------------------------------

                    // closing pipes accordingly
                    // will use pipe 2 and pipe 3
                    close(fd[2][1]); // write block
                    close(fd[3][0]); // read block

                    // creating copies of standard output and input
                    int defaultRead = dup(0);
                    int defaultWrite = dup(1);

                    // duplicating
                    dup2(fd[2][0], 0); // reading
                    dup2(fd[3][1], 1); // writing

                    char buff[200] = " ";
                    // reading the before in pipe
                    scanf("%[^\n]%*c", buff);

                    // writing into the pipe
                    printf("%s : %d\n", buff, getpid());

                    // restoring defaults
                    dup2(defaultRead, 0);
                    dup2(defaultWrite, 1);

                    // printing on screen
                    printf("3:%s : %d\n", buff, getpid());
                }

                // while (!quit)
                //     ;
            }
            else
            {
                // ------------------------------------------------------------------
                // -------------------- Child 2 Process --------------------------------
                // ------------------------------------------------------------------

                // closing pipes accordingly
                // will use pipe 1 and pipe 2
                close(fd[1][1]); // write block
                close(fd[2][0]); // read block

                // creating copies of standard output and input
                int defaultRead = dup(0);
                int defaultWrite = dup(1);

                // duplicating
                dup2(fd[1][0], 0); // reading
                dup2(fd[2][1], 1); // writing

                char buff[200] = " ";
                // reading the before in pipe
                scanf("%[^\n]%*c", buff);

                // writing into the pipe
                printf("%s : %d\n", buff, getpid());

                // restoring defaults
                dup2(defaultRead, 0);
                dup2(defaultWrite, 1);

                // printing on screen
                printf("2:%s : %d\n", buff, getpid());
            }

            // while (!quit)
            //     ;
        }
        else
        {
            // ------------------------------------------------------------------
            // -------------------- Child 1 Process --------------------------------
            // ------------------------------------------------------------------

            // closing pipes accordingly
            // will use pipe 0 and pipe 1
            close(fd[0][1]); // write block
            close(fd[1][0]); // read block

            // creating copies of standard output and input
            int defaultRead = dup(0);
            int defaultWrite = dup(1);

            // duplicating
            dup2(fd[0][0], 0); // reading
            dup2(fd[1][1], 1); // writing

            char buff[200] = " ";
            // reading the before in pipe
            scanf("%[^\n]%*c", buff);

            // writing into the pipe
            printf("%s : %d\n", buff, getpid());

            // restoring defaults
            dup2(defaultRead, 0);
            dup2(defaultWrite, 1);

            // printing on screen
            printf("1:%s : %d\n", buff, getpid());
        }

        // while (!quit)
        //     ;
    }
    else
    {

        // ------------------------------------------------------------------
        // -------------------- Main Process --------------------------------
        // ------------------------------------------------------------------

        // closing the pipes 0 and 5 the 0 will be used by the c1 and 5 by c5
        // pipe 0 write access in parent
        // pipe 5 read  access in parent
        close(fd[0][0]); // read  closed of pipe 0
        close(fd[5][1]); // write closed of pipe 5

        printf("\n m %s : %d\n", message, getpid());

        // creating copies of standard output and input
        int defaultRead = dup(0);
        int defaultWrite = dup(1);

        // duplicatin
        dup2(fd[0][1], 1); // standard writing
        dup2(fd[5][0], 0); // standard reading

        // writing into the pipe
        printf("%s : %d\n", message, getpid());

        // restoring defaults
        dup2(defaultRead, 0);
        dup2(defaultWrite, 1);

        // while (!quit)
        //     ;
    }

    return 0;
}