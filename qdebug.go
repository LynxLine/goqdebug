package main

/*
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "qdebug.h"
*/
import "C"
import (
	"log"
)

const (
	QtDebugMsg    = 0
	QtInfoMsg     = 1
	QtWarningMsg  = 2
	QtCriticalMsg = 3
	QtFatalMsg    = 4
	QtSystemMsg   = QtCriticalMsg
)

func init() {
	C.goqdebug_InstallMessageHandler()
}

func goqdebug_cGoUnpackString(s C.struct_QtCore_PackedString) string {
	if int(s.len) == -1 {
		return C.GoString(s.data)
	}
	return C.GoStringN(s.data, C.int(s.len))
}

//export goqdebug_GoMessageHandler
func goqdebug_GoMessageHandler(cmsg C.struct_QtCore_PackedString, msg_type int) {
	msg := goqdebug_cGoUnpackString(cmsg)
	msg_mark := "DEBUG"
	if msg_type == QtDebugMsg {
		msg_mark = "DEBUG"
	} else if msg_type == QtInfoMsg {
		msg_mark = "INFO"
	} else if msg_type == QtWarningMsg {
		msg_mark = "WARNING"
	} else if msg_type == QtCriticalMsg {
		msg_mark = "CRITICAL"
	} else if msg_type == QtFatalMsg {
		msg_mark = "FATAL"
	}
	log.Println(msg_mark, msg)
}

func main() {
	C.goqdebug_test()
}
