
#define protected public
#define private public

#include "qdebug.h"
#include "_cgo_export.h"

#include <QCoreApplication>
#include <QDebug>

void qdebug_test()
{
    qDebug() << "Test from qdebug_test()";
}

void* QCoreApplication_qInstallMessageHandler(void *ptr)
{
	//return qInstallMessageHandler(static_cast<QtMessageHandler>(ptr));
    return NULL;
}
