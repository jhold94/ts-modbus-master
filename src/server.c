#include <modbus.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>

const char DOWNSTREAM_DEVICE_IP = 192.168.2.10;
const int DOWNSTREAM_DEVICE_PORT = 1502;

int do_read(int command);
{
        int read_command;
        //put stuff here, called from ts-dnp3
        switch command
        {
                case 1:
                        read_command = 1
                        //stuff goes here
                        break;
                case 2:
                        //stuf goes here
                        break;
                default:
                        //more stuff goes here
                        break;
        }
        return 0;
}

int main(char argc, char **argv)
{
        modbus_t *mb;
        uint8_t tab_bit[32];
        uint8_t tab_inbit[32];
        uint16_t tab_reg[32];
        uint16_t tab_inreg[32];

        mb = modbus_new_tcp(DOWNSTREAM_DEVICE_IP, DOWNSTREAM_DEVICE_PORT);
        modbus_connect(mb);


        
        /* Read 5 bits from address 0 */
        modbus_read_bits(mb, 0, 5, tab_bit);
        
        /* Read 5 input bits from address 0 */
        modbus_read_input_bits(mb, 0, 5, tab_inbit);
        
        /* Read 5 registers from the address 0 */
        modbus_read_registers(mb, 0, 5, tab_reg);

        /* Read 5 input/holding register from the address 0 */
        modbus_read_input_registers(mb, 0, 5, tab_inreg);
        
        modbus_close(mb);
        modbus_free(mb);
}
