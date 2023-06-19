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
    char buffer[MSG_BUFFER_SIZE]
}

