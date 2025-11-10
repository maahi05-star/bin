zombie 

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
pid_t pid;
if((pid=fork())<0)
printf("\tfork error\n");
else
if(pid==0)
printf("child process id %d\n",getpid());
else
{
sleep(10);
printf("****parent\n");
system("ps -axj | tail");
}
exit(0);
}

orphan 

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
int pid=fork();
  if(pid > 0)
  {
    printf("parent process id\t%d\n",getpid());
    printf("child process id\t%d\n",pid);
    }
  else if(pid == 0)
        {
        sleep(10);
                printf("child process id\t%d\n",getpid());
          printf("parent process id\t%d\n",getpid());
        }
        return 0;
}
