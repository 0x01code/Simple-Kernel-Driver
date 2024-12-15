#pragma warning (disable : 4047 4311)

#include "events.h"

#include "message.h"
#include "data.h"

PLOAD_IMAGE_NOTIFY_ROUTINE ImageLoadCallback(PUNICODE_STRING FullImageName, HANDLE ProcessId, PIMAGE_INFO ImageInfo)
{
	//DebugMessage("ImageLoaded: %ls \n", FullImageName->Buffer);

	if (wcsstr(FullImageName->Buffer,L"\\AssaultCube 1.3.0.2\\bin_win32\\ac_client.exe"))
	{
		DebugMessage("AssualtCube found!\n");

		ModuleBaseAddress = ImageInfo->ImageBase;

		ProcessID = (ULONG)ProcessId;

		DebugMessage("ProcessID: %d \n", ProcessId);
	}

	return STATUS_SUCCESS;
}