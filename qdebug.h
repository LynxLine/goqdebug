// +build !minimal

#pragma once

#ifndef GO_QTDEBUGADDON_H
#define GO_QTDEBUGADDON_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void qdebug_test();
void* QCoreApplication_qInstallMessageHandler(void *ptr);

#ifdef __cplusplus
}
#endif

#endif
