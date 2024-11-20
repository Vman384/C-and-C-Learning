#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSQKEY 34858
#define MSQSIZE 32

struct msgbuf
{
  long mtype;
  char mtext[MSQSIZE];
};

int main(int argc, char *argv[])
{
  key_t key;
  int msqid;
  struct msgbuf mbuf;

  // Get a message queue. The server must have created it.
  key = MSQKEY;
  if ((msqid = msgget(key, 0666)) < 0)
  {
    perror("client: msgget");
    exit(1);
  }

  /**************************************************************************************
  * YOUR TASK:                                                                          *
  * Continuously read data from standard input and send the data as messages of type 1. *
  ***************************************************************************************/
  char input[MSQSIZE];
  while (1)
  {
    printf("Enter the data: ");
    
    if (fgets(input, MSQSIZE, stdin) == NULL)
    {
      break;
    }

    input[strcspn(input, "\n")] = 0;

    struct msgbuf dataSend;
    strncpy(dataSend.mtext, input, MSQSIZE);
    dataSend.mtype = 1;

    msgsnd(msqid, &dataSend, sizeof(dataSend.mtext), 0);
    
  }

  /**************************************************************************************
  * YOUR TASK:                                                                          *
  * When an empty message is read, send a message of type 2 to indicate no more data.   *
  ***************************************************************************************/

  struct msgbuf endMessage;
  endMessage.mtype = 2;
  memset(endMessage.mtext, 0, MSQSIZE);

  if (msgsnd(msqid, &endMessage, sizeof(endMessage.mtext), 0) == -1)
  {
    perror("msgsnd");
    exit(1);
  }

  exit(0);
}
