#ifndef COMMANDS_H_
#define COMMANDS_H_

typedef enum {
    SEND_MESSAGE = 0x00,
    ACK = 0x01,
    JOIN_NETWORK = 0x02,
} command;

#endif  // COMMANDS_H_