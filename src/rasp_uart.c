#include "rasp_uart.h"

int uart_init (const char* device)
{
	struct stat dev_status;

	if ((uart0_filestream = open (device, O_RDWR | O_NOCTTY)) < 0)
	{
		perror (strerror(errno));
		return errno;
	}

	if (fstat (uart0_filestream, &dev_status) < 0)
	{
		perror (strerror(errno));
		return errno;
	}

	if ((dev_status.st_mode & 0444) != 0444)
	{
		fprintf (stderr, "O dispositivo %s não possui as permissões necessárias.\n", device);
		fprintf (stderr, "Permissões: %lo.\n", (unsigned long) dev_status.st_mode);

		close (uart0_filestream);

		return -1;
	}

	tcgetattr (uart0_filestream, &oldtio);

	bzero (&newtio, sizeof(newtio));
	newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
	newtio.c_iflag = IGNPAR | ICRNL;
	newtio.c_oflag = 0;
	newtio.c_lflag = ICANON;

	newtio.c_cc[VINTR]    = 0;     /* Ctrl-c */
	newtio.c_cc[VQUIT]    = 0;     /* Ctrl-\ */
	newtio.c_cc[VERASE]   = 0;     /* del */
	newtio.c_cc[VKILL]    = 0;     /* @ */
	newtio.c_cc[VEOF]     = 4;     /* Ctrl-d */
	newtio.c_cc[VTIME]    = 0;     /* inter-character timer unused */
	newtio.c_cc[VMIN]     = 1;     /* blocking read until 1 character arrives */
	newtio.c_cc[VSWTC]    = 0;     /* '\0' */
	newtio.c_cc[VSTART]   = 0;     /* Ctrl-q */
	newtio.c_cc[VSTOP]    = 0;     /* Ctrl-s */
	newtio.c_cc[VSUSP]    = 0;     /* Ctrl-z */
	newtio.c_cc[VEOL]     = 0;     /* '\0' */
	newtio.c_cc[VREPRINT] = 0;     /* Ctrl-r */
	newtio.c_cc[VDISCARD] = 0;     /* Ctrl-u */
	newtio.c_cc[VWERASE]  = 0;     /* Ctrl-w */
	newtio.c_cc[VLNEXT]   = 0;     /* Ctrl-v */
	newtio.c_cc[VEOL2]    = 0;     /* '\0' */

	tcflush (uart0_filestream, TCIFLUSH);
	tcsetattr (uart0_filestream, TCSANOW, &newtio);

	return 0;
}

int uart_end ()
{
	tcflush (uart0_filestream, TCIOFLUSH);
	tcsetattr (uart0_filestream, TCSANOW, &oldtio);
	close (uart0_filestream);
	return 0;
}
