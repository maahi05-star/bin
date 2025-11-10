#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include <stdlib.h>  
#include<unistd.h>
#define MAX 20

int main()
{
int filedes[2],n;
char string[MAX];
char line[MAX];
pid_t pid;

printf("enter the string to be given to the parent:");
fflush(stdin);

scanf("%s",string);

if((pipe(filedes))<0)
{
printf("\n pipe creation error");
exit(0);
}

if((pid=fork())<0)
{
printf("\n fork error");
exit(0);
}

if(pid>0)
{
close(filedes[0]);
write(filedes[1],string,MAX);
}

if(pid==0)
{
close(filedes[1]);
n=read(filedes[0],line,MAX);
line[n]='\0';
printf("\n\n Data read by child is : %s",line);
}

exit(0);
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int main()
{
    int filesdes[2], filesdes2[2];
    int n;
    char string[MAX];
    char line[MAX];
    pid_t pid;

    printf("enter the string to be given to the parent ");
    fflush(stdin);

    fgets(string, MAX, stdin);
    string[strcspn(string, "\n")] = '\0';

    if (pipe(filesdes) < 0)
    {
        printf("\n pipe creation error");
        exit(0);
    }

    if (pipe(filesdes2) < 0)
    {
        printf("\n second pipe creation error");
        exit(0);
    }

    if ((pid = fork()) < 0)
    {
        printf("\n fork error");
        exit(0);
    }

    if (pid > 0)
    {
        close(filesdes[0]);
        close(filesdes2[1]);

        write(filesdes[1], string, MAX);

        n = read(filesdes2[0], line, MAX);
        printf("\n\n Data read by parent from child is: %s\n", line);
    }

    if (pid == 0)
    {
        close(filesdes[1]);
        close(filesdes2[0]);

        n = read(filesdes[0], line, MAX);
        printf("\n\n Data read by child is: %s", line);

        write(filesdes2[1], line, MAX);
    }

    exit(0);
}
