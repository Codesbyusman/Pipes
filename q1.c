#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{

    // for making the unnamed pipes
    int fd[2]; // the file descrypter

    // making the pipe -- will be inherited to child
    pipe(fd);

    // for making the child
    pid_t pid = fork(); // creating the child

    if (pid < 0)
    {
        printf("\n\t :::: Error --- child Unsuccessful :::: \n");
    }
    else
    {

        // the child has been created successfully
        if (pid == 0)
        {

            // redirecting the output to the pipe
            // creating duplicate to the standard input to pipe
            // by default writing to screen will write in pipe
            dup2(fd[1], 1);
            dup2(fd[0], 0);

            // the exec comand -- execp will find path automaticallay and l showing list of parameters
            execlp("ls", "ls", "-l", "/", NULL);
        }
        else
        {

            wait(NULL);

            // now buff will be as an input of next as | implementation
            pid_t secondChild = fork();

            if (secondChild == 0)
            {
                // child

                // reading output
                char buff[2000] = " ";
                read(fd[0], buff, sizeof(buff));

                // the temp file as grep deals with files
                creat("temp.txt", 0777);

                // opening and writing the output int the file
                int fdFile = open("temp.txt", O_WRONLY);
                write(fdFile, buff, strlen(buff));
                close(fdFile);

                // also duplicated the reading the grep will read automaticallay
                dup2(fd[1], 1);
                dup2(fd[0], 0);
                execlp("grep", "grep", "a", "temp.txt", NULL);
            }
            else
            {
                // parent
                wait(NULL);

                // removing the earlier made
                system("rm temp.txt");

                // making another child
                // now buff will be as an input of next as | implementation
                pid_t thirdChild = fork();

                if (thirdChild == 0)
                {

                    // child
                    // reading output
                    char buff[2000] = " ";
                    read(fd[0], buff, sizeof(buff));

                    // the temp file as grep deals with files
                    creat("temp.txt", 0777);

                    // opening and writing the output int the file
                    int fdFile = open("temp.txt", O_WRONLY);
                    write(fdFile, buff, strlen(buff));
                    close(fdFile);

                    // straems are duplicated
                    dup2(fd[1], 1);
                    dup2(fd[0], 0);

                    execlp("sort", "sort", "-r", "temp.txt", NULL);
                }
                else
                {
                    // parent
                    wait(NULL);

                    // removing the earlier made
                    system("rm temp.txt");

                    // making another child
                    // now buff will be as an input of next as | implementation
                    pid_t fourthChild = fork();

                    if (fourthChild == 0)
                    {
                        // child
                        // reading output
                        char buff[2000] = " ";
                        read(fd[0], buff, sizeof(buff));

                        // the temp file as grep deals with files
                        creat("temp.txt", 0777);

                        // opening and writing the output int the file
                        int fdFile = open("temp.txt", O_WRONLY);
                        write(fdFile, buff, strlen(buff));
                        close(fdFile);

                        dup2(fd[1], 1);
                        dup2(fd[0], 0);
                        execlp("wc", "wc", "temp.txt", NULL);
                    }
                    else
                    {
                        // parent
                        wait(NULL);

                        // removing the earlier made
                        system("rm temp.txt");

                        // making another child
                        // now buff will be as an input of next as | implementation
                        pid_t fifthChild = fork();

                        if (fifthChild == 0)
                        {
                            // child

                            // reading output
                            char buff[2000] = " ";
                            read(fd[0], buff, 12);

                            // the temp file as grep deals with files
                            creat("count.txt", 0777);

                            // opening and writing the output int the file
                            int fdFile = open("count.txt", O_WRONLY);
                            write(fdFile, buff, strlen(buff));
                            close(fdFile);
                        }
                        else
                        {
                            // parent
                            wait(NULL);

                            // making another child
                            printf("\n    :::::::::::: See the output file \"count.txt\" in directory ::::::::::: \n\n");
                        }
                    }
                }
            }
        }
    }

    return 0;
}