#include "xparameters.h"
#include "xil_printf.h"
#include <stdio.h>

int main(void)
{
    char rx_char;

    print("Welcome to UART Communication\r\n");

    while (1)
    {
        print("Enter a Character:\r\n");

        rx_char = inbyte();

        xil_printf("Received Character : %c\r\n", rx_char);
    }

    return 0;
}
