/*
 * =====================================================================================
 *
 *       Filename:  sender.c
 *
 *    Description: Sender file for Message Q 
 *
 *        Version:  1.0
 *        Created:  19/06/23 08:27:37 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Santosh Kumar santoshs0612@gmail.com, 
 *   Organization:  
 *
 * =====================================================================================
 */

/* Including the various liberary */
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>
#include<errno.h>

/* Define the Buffer size and Msg size */

#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE (MAX_MSG_SIZE +10)

/*  main function  */

int main(int argc,char **argv){
    char buffer[MSG_BUFFER_SIZE];
    int recvr_msgq_fd=0;
    /* argument check */
    if(argv<=1){
        printf("Provide a recepient msgQ name : format </msgq-name>\n");
        return 0;
    }
    // Initialize the buffer
    memset(buffer,0,MSG_BUFFER_SIZE);
    printf("Enter the msg to you want to send to receiver %s", argv[1]);
    // Enter the msg
    scanf("%s",buffer);
    
    // opening the msgQ in write mode

    if((recvr_msgq_fd = mq_open(argv[1],O_WRONLY | O_CREAT,0,0))==1)
    {
        printf("Client : Msgq Not able to open , errno =%d",errno);
        exit(1);
    }
    // send the msq to msgq provided
    
}

