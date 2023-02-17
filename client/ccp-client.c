//
// Created by tumap on 2/17/23.
//
#include "ccp-client.h"

void ccp_client_init(tCCPClientContext *ctx) {
    // clear session
    ctx->connected = false;

}

bool ccp_client_handle(tCCPClientContext *ctx) {
    // not connected?
    if (!ctx->connected)
        return false;

    // check timeout
    if (ctx->session_timeout <= TIME_GET) {
        // timed out
        ctx->connected = false;
        return true;
    }

    return false;
}



