#ifndef SENDER_H_
#define SENDER_H_

#include <stdint.h>
#include "freertos/portmacro.h"
#include "packet.h"
#include "lora_interface.h"

/* void sender() { */
/*     while(1) { */
/*         vTaskDelay(200 / portTICK_PERIOD_MS); */
/*         send_directed_message((uint8_t*)"hello world", 11, 2); */
/*     } */
/* } */

void sender(const uint8_t id) {
    while(1) {
        vTaskDelay(10 / portTICK_PERIOD_MS);
        send_directed_message((uint8_t*) "3701", 4,  id);
    }
}

#endif // SENDER_H_
