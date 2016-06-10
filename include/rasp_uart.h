#ifndef _UART_H
#define _UART_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#ifndef BAUDRATE
#	define BAUDRATE B9600
#endif

#ifndef MODEMDEVICE
#	define MODEMDEVICE "/dev/ttyACM0"
#endif

struct uart_data {
	size_t length;
	char *data;
};

int uart0_filestream = -1;
struct termios oldtio, newtio;

extern int uart_init (const char*);
extern int uart_end ();

#endif
