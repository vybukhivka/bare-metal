#include "comms.h"
#include "core/uart.h"
#include <stdint.h>

typedef enum comms_state_t {
    CommsState_Length,
    CommsState_Data,
    CommsState_CRC,
} comms_state_t;

static comms_state_t state = CommsState_Length;
static uint8_t data_byte_count = 0;

static comms_packet_t temp_packet = {.length = 0, .data = {0}, .crc = 0};

void comms_setup(void) {}

void comms_update(void) {
	while (uart_data_available()) {
		switch (state) {
			case CommsState_Length: {
				temp_packet.length = uart_read_byte();
				state = CommsState_Data;
			} break;
			case CommsState_Data: {
				temp_packet.data[data_byte_count++] = uart_read_byte();
				if (data_byte_count >= PACKET_DATA_LENGTH) {
					data_byte_count = 0;
					state = CommsState_CRC;
				}
			} break;
			case CommsState_CRC: {
				temp_packet.crc = uart_read_byte();
			} break;
			default: {
				state = CommsState_Length;
			}
		}
	}
}

bool comms_packets_available(void) {}

void comms_write(comms_packet_t *packet) {}
void comms_read(comms_packet_t *packet) {}
