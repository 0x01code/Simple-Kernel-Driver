#include "memory.h"

NTSTATUS KernelReadVirtualMemory(PEPROCESS Process, PVOID SourceProcess, PVOID TargetAddress, SIZE_T Size)
{
	PSIZE_T Bytes;

	return MmCopyVirtualMemory(Process, SourceProcess, PsGetCurrentProcess(), TargetAddress, Size, KernelMode, &Bytes);
}

NTSTATUS KernelWriteVirtualMemory(PEPROCESS Process, PVOID SourceProcess, PVOID TargetAddress, SIZE_T Size)
{
	PSIZE_T Bytes;

	return MmCopyVirtualMemory(PsGetCurrentProcess(), SourceProcess, Process, TargetAddress, Size, KernelMode, &Bytes);
}