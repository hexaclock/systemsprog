#ifndef _SUCKIT_H_

#define _SUCKIT_H_
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include "my.h"
#define MSGMAX 2048
#define NICKMAX 32
#define CMDMAX 16

#ifdef _CLIENT_
#include <netdb.h>
#endif

#endif
