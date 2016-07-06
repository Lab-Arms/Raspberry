#ifndef _RASP_SOCKET_H
#define _RASP_SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>

extern int socket_fd;

extern int server_init (const char* const);

#endif
