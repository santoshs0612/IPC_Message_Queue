/*
 * =====================================================================================
 *
 *       Filename:  recvr.c
 *
 *    Description: Server/receiver file for messaage Q 
 *
 *        Version:  1.0
 *        Created:  19/06/23 09:02:49 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Santosh Kumar santoshs0612@gmail.com, 
 *   Organization:  
 *
 * =====================================================================================
 */

/* Addig the liberary */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>
#include<errno.h>

/*  Define the muffer and Message Specification */
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE  (MAX_MSG_SIZE+10)
#define QUEUE_PERMISSIONS 0660

/* Main program */

int main(int argc,char **argv){
    fd_set_readfds;
    char buffer[MSG_BUFFER_SIZE];
    int msgq_fd =0;

    /* Check afor argument */
    if(argc<=1){
        printf("Provide a reciepiment msgQ name: format </msgq-name>\n");
        return 0;
    }

    /* Set the MsqQ Attributes */
    struct mq_attr attr;
    attr.mq_flag = 0;
    attr.mq-maxmsg= MAX_MESSAGES;
    attr.mq_msgaize = MAX_MSG_SIZE;
    attr.mq_curmsgs =0;


    /* Openig the msgQ in read only or Create Option  */

    if((msgq_fd = mq_open(argv[1],O_RDONLY | O_CREAT, QUEUE_PERMISSIONS,&attr))==-1){
        printf("Server: MQ_open failed, errno = %d", errno);
        exit(1);
    }
    while(1){
        FD_ZERO(&readfds);
        FD_SET(msgq_fd,&readfds);
        printf("Reciever blocked on select() sys Call......\n");
        select(msgq_fd+1,&readfds,NULL,NULL,NULL);
        if(FD_ISSET(msgq_fd,&readfds)){
            printf("Msg recvdMsgQ %s\n",argv[1]);
            memset(buffer,0,MSG_BUFFER_SIZE);

            if(mq_receive(msgq_fd,buffer,MSG_BUFFER_SIZE,NULL)==-1){
                printf("Mq_receive error,errno= %d\n",errno);
                exit(1);
            }
            printf("Msg recieved from Queue= %s", buffer);
        }
    }
}

