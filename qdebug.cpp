
#define protected public
#define private public

#include "qdebug.h"
#include "_cgo_export.h"

#include <QCoreApplication>
#include <QDebug>

const int cQtDebugMsg = QtDebugMsg;

void
goqdebug_call_MessageHandler(
    goqdebug_func_MessageHandler func
    , struct QtCore_PackedString msg
    , long long int type) {
    func(msg, type);
}

void
goqdebug_pass_MessageHandler(
    struct QtCore_PackedString msg
    , long long int type) {
    goqdebug_call_MessageHandler(&goqdebug_GoMessageHandler, msg, type);
}

void goqdebug_MessageHandler(
    QtMsgType type
    , const QMessageLogContext &context
    , const QString &msg)
{
    long long int itype = type;
    QByteArray bytes = msg.toUtf8();
    QtCore_PackedString packed = {
        const_cast<char*>(bytes.prepend("WHITESPACE").constData()+10)
        , bytes.size()-10
    };
    goqdebug_pass_MessageHandler(packed, itype);
}

void goqdebug_InstallMessageHandler() {
    qInstallMessageHandler(goqdebug_MessageHandler);
}

void goqdebug_test()
{
    qDebug() << "Probing qDebug message from goqdebug_test()";
}
