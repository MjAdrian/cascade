#include <stdlib.h>
#include "esp_log.h"
#include "esp_random.h"
#include "lora_interface.h"
#include "freertos/task.h"

// Adrian work
#include "sender.h"
#include "receiver.h"

#define SEND_ID 37
#define REC_ID  47

extern "C" void app_main() {
    esp_log_level_set("*", ESP_LOG_NONE);
    int32_t result = init_lora();
    if (result != 0) {
        ESP_LOGE("sx127x", "ERROR: Cannot initialize lora");
        return;
    }
    LoRa.setTxPower(20,1);
    LoRa.setSignalBandwidth(125E3);
    LoRa.setSpreadingFactor(9);
    LoRa.setCodingRate4(8);

    srand(esp_random());
    // sender code
    set_device_id(SEND_ID);
    sender(REC_ID);

    // receiver code
    // set_device_id(REC_ID);
    // receiver();
}
