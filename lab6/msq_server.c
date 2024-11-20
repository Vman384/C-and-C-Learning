/* msq_server.c */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
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
  int n, msqid;
  struct msgbuf mbuf;

  key = MSQKEY;

  /************************************************************************ 
  * YOUR TASK:                                                            *
  * Create a new message queue.                                           *
  * Assume that the key defined in MSQKEY isn't in use by another process.*
  ************************************************************************/
  msqid = msgget(key, IPC_CREAT | 0666);


  /*
  * Receive messages from the queue. 
  * Messages of type 1 are to be printed on the standard output; 
  * a message of type 2 indicates that no more data.
  */
  while ((n = msgrcv(msqid, &mbuf, MSQSIZE, 0, 0)) > 0)
  {
    /************************************************************************ 
    * YOUR TASK:                                                            *
    * Write messages of type 1 to standard output.                          *
    ************************************************************************/
    if (mbuf.mtype == 1){
      printf("The text is: %s\n", mbuf.mtext); 
    }
    else if (mbuf.mtype == 2)
    {
      msgctl(msqid, IPC_RMID, (struct msqid_ds *)0);
      printf("No more messages\n");

    }
    printf("Message type %ld\n", mbuf.mtype);
  }

  exit(0);
}
