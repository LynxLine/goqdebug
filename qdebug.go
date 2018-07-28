package main

/*
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "qdebug.h"
*/
import "C"

func main() {
	C.qdebug_test()
}
