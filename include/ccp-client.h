//
// Created by tumap on 2/17/23.
//

#ifndef DASHBOARD_GATEWAY_CCP_CLIENT_H
#define DASHBOARD_GATEWAY_CCP_CLIENT_H

#include <stdbool.h>
#include <stdint.h>
#include "profile.h"

typedef unsigned (*rCCPKeyGenerator)();

struct tagCCPConfiguration {
    // CAN addressing
    unsigned can_interface;
    uint32_t can_rx_id;
    bool can_rx_id_extended;
    uint32_t can_tx_id;
    bool can_tx_id_extended;

    // CCP addressing
    uint16_t station_address;

    // Key generator
    rCCPKeyGenerator key_generator;

};

typedef struct tagCCPConfiguration tCCPConfiguration;

struct tagCCPClientContext {
    // configuration
    const tCCPConfiguration* const config;

    // session context
    tTime session_timeout;
    bool connected;
    uint8_t resource_status;

    // address counters
    uint32_t mta0;
    uint32_t mta1;

    // message to be sent

};

typedef struct tagCCPClientContext tCCPClientContext;


void ccp_client_init(tCCPClientContext* ctx);

bool ccp_client_handle(tCCPClientContext* ctx);



#endif //DASHBOARD_GATEWAY_CCP_CLIENT_H
