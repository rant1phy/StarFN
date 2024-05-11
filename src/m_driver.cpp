#ifndef DRIVER_CPP
#define DRIVER_CPP
#include "m_defines.hpp"

const bool driver::device_io_control(void* data, requests code)
{
	if (!data || !code)
		return false;

	IO_STATUS_BLOCK block;
	invoke_data request{ 0 };

	request.unique = requests::invoke_unique;
	request.data = data;
	request.code = code;

	return direct_device_control(m_handle, nullptr, nullptr, nullptr, &block, 0, &request, sizeof(request), &request, sizeof(request));
}

const bool driver::initialize_handle()
{
	m_handle = CreateFileA(device_name, GENERIC_READ, 0, 0, 3, 0x00000080, 0);
	if (m_handle == INVALID_HANDLE_VALUE)
		return false;
	return true;
}

const bool driver::update(int a_pid)
{
	if (!a_pid) return false;
	m_pid = a_pid;
	return true;
}


const uintptr_t driver::get_image_base()
{
	base_invoke data{ 0 };

	data.pid = m_pid;
	data.handle = 0;
	//data.name = module_name;

	device_io_control(&data, invoke_base);
	std::cout << "base -> " << data.handle << std::endl;
	return data.handle;
}


const bool driver::read_physical(const uintptr_t address, void* buffer, const size_t size)
{
	read_invoke data{ 0 };

	data.pid = m_pid;
	data.address = address;
	data.buffer = buffer;
	data.size = size;

	return device_io_control(&data, invoke_read);
}

const bool driver::write_physical(const uintptr_t address, void* buffer, const size_t size)
{
	write_invoke data{ 0 };

	data.pid = m_pid;
	data.address = address;
	data.buffer = buffer;
	data.size = size;

	return device_io_control(&data, invoke_write);
}


#endif // ! DRIVER_CPP