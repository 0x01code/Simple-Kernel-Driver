#include <iostream>

#include "kernelinterface.hpp"
#include "offsets.hpp"

int main()
{
	KernelInterface Driver = KernelInterface("\\\\.\\x01code");

	DWORD module_base = Driver.GetModuleBase();
	DWORD ProcessId = Driver.GetProcessId();

	std::cout << "Module Base Address: " << std::hex << module_base << std::endl;


	while (true)
	{
		DWORD localPlayer = Driver.ReadVirtualMemory<DWORD>(ProcessId, module_base + dwLocalPlayer, sizeof(DWORD));
		//std::cout << "localPlayer Address: " << std::hex << localPlayer << std::endl;
		int health = Driver.ReadVirtualMemory<int>(ProcessId, localPlayer + mHealth, sizeof(int));
		std::cout << "Health: " << std::dec << health << std::endl;

		Driver.WriteVirtualMemory(ProcessId, localPlayer + mHealth, 1337, sizeof(1337));
	}
}