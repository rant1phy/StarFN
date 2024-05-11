#include "m_overlay.hpp"
#include <TlHelp32.h>

INT32 find_process(LPCTSTR process_name) {


	PROCESSENTRY32 pt;
	HANDLE hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	pt.dwSize = sizeof(PROCESSENTRY32);
	if (Process32First(hsnap, &pt)) {
		do {
			if (!lstrcmpi(pt.szExeFile, process_name)) {
				CloseHandle(hsnap);
				module::process_id = pt.th32ProcessID;
				return pt.th32ProcessID;
			}
		} while (Process32Next(hsnap, &pt));
	}
	CloseHandle(hsnap);

	return { NULL };
}
uintptr_t pid;

auto main( ) -> int {

	g_hooking->init();

	driver::initialize_handle( );
	Beep(500, 500);
	MessageBoxA(NULL, "Starting injection!", "SMV", MB_OK);
	//std::cout << "1" << std::endl;
	system("color 3");

	screen_width = GetSystemMetrics(SM_CXSCREEN), screen_height = GetSystemMetrics(SM_CYSCREEN);

	while (windows == NULL)
	{
		XorS(wind, "Fortnite  ");
		windows = FindWindowA(0, wind.decrypt());
	}

	pid = find_process(("FortniteClient-Win64-Shipping.exe"));

	if (!driver::update(pid)) {
		MessageBoxA(NULL, "Couldn't Find Game. Contact support with error: {0x001}", "SMV", ALERT_SYSTEM_CRITICAL);
	}
	//std::cout << "2" << std::endl;
	std::cout << "pid -> " << pid << std::endl;
	module::image_base = driver::get_image_base();
	if (!module::image_base) {
		MessageBoxA(NULL, "Failed Find Image. Contact support with error: {0x002}", "SMV", ALERT_SYSTEM_CRITICAL);
	}
	//std::cout << "3" << std::endl;
	//std::cout << "base -> " << module::image_base << std::endl;
	//if (!driver::initialize(module::image_base)) {
	//	MessageBoxA(NULL, "Failed To Initalize Driver. Contact support with error: {0x003}", "SMV", ALERT_SYSTEM_CRITICAL);
	//}
	//std::cout << "4" << std::endl;

	m_cache -> actors_call( );
	//std::cout << "5" << std::endl;

	floot->levels_call();
	//std::cout << "6" << std::endl;

	m_render -> render_call( );
	//std::cout << "7" << std::endl;


	return 0;
}

//DWORD WINAPI MainThread( LPVOID ) {
//	main2( );
//
//	return TRUE;
//}
