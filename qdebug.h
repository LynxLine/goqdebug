
#pragma once

#ifndef GO_QTDEBUGADDON_H
#define GO_QTDEBUGADDON_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct QtCore_PackedString { char* data; long long len; };

typedef void(*goqdebug_func_MessageHandler)(
    struct QtCore_PackedString msg
    , long long int type
);

void goqdebug_test();
void goqdebug_InstallMessageHandler();

#ifdef __cplusplus
}
#endif

#endif
