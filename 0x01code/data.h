#pragma once
#include <ntifs.h>

ULONG ModuleBaseAddress, ProcessID;
PDEVICE_OBJECT pDeviceObject;
UNICODE_STRING dev, dos;