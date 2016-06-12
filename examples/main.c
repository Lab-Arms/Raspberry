#include "../include/rasp_uart.h"

int main (int argc, char* argv[])
{
	unsigned char texto[] = "Pedro Guilherme";
	struct uart_data buffer_send = {texto, strlen(texto)};
	struct uart_data buffer_recv = {(char*) malloc (strlen(texto) * sizeof (char)), strlen(texto)};
	char* device = (argc < 2) ? MODEMDEVICE : argv[1];

	uart_init(device);

	printf ("Sending data: %s\n", buffer_send.data);
	uart_send(&buffer_send);

	uart_recv (&buffer_recv);
	buffer_recv.data[buffer_recv.length] = 0;
	printf ("Received data: %s\n", buffer_recv.data);

	uart_end();

	return 0;
}
