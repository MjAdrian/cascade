#ifndef RECEIVER_H_
#define RECEIVER_H_

#include "lora_interface.h"
#include "packet.h"

#include <LoRa.h>

void receiver() {
    while(1) {
        vTaskDelay(1);
        unsigned long Starttime = micros();
        if(has_message()) {
            packet_t message = get_message();
            unsigned long Endtime = micros();
            int rssi = LoRa.packetRssi();
            printf("Received message id %d: %.*s, took %lu us, rssi: %d\n", message.header.message_id, message.header.data_length, message.data + 1, Endtime - Starttime, rssi);
        }
    }
}

#endif // RECEIVER_H_
