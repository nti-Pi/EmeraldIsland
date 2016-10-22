#include "ConsoleManager.hpp"

#include <Windows.h>
#include <iostream>

#include "Engine.hpp"


namespace ei {
namespace engine {

	ConsoleManager::ConsoleManager(Engine *parent_engine) 
		: BaseManager(parent_engine),
		  m_WinCSBHandle(INVALID_HANDLE_VALUE),
		  m_TargetSurface() { }


	ConsoleManager::~ConsoleManager() { }


	void ConsoleManager::init() {
		m_WinCSBHandle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
												   0,								// Console cannot be shared!
												   nullptr,							// Cannot be inherited
												   CONSOLE_TEXTMODE_BUFFER,
												   NULL);
		if (m_WinCSBHandle == INVALID_HANDLE_VALUE) {
			std::cerr << "Failed to create Console Screen Buffer!" << std::endl;
			return;
		}

		if (!SetConsoleActiveScreenBuffer(m_WinCSBHandle)) {
			std::cerr << "Failed to set the console screen buffer as active!" << std::endl;
			return;
		}
		
		// Computing the console size:
		unsigned int con_width,
					 con_height;
		{
			CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;

			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &console_screen_buffer_info);
			con_width = console_screen_buffer_info.srWindow.Right - console_screen_buffer_info.srWindow.Left + 1;
			con_height = console_screen_buffer_info.srWindow.Bottom - console_screen_buffer_info.srWindow.Top + 1;
		}

		// Allocating the Render Target:
		m_TargetSurface.init(con_width, con_height);

		// Setting the cursor properties:
		{
			CONSOLE_CURSOR_INFO console_cursor_info;
			console_cursor_info.bVisible = 0x00;
			console_cursor_info.dwSize = 1;

			SetConsoleCursorInfo(m_WinCSBHandle, &console_cursor_info);
		}

		clear();
	}


	void ConsoleManager::de_init() {
		CloseHandle(m_WinCSBHandle);
		m_TargetSurface.de_init();
	}


	void ConsoleManager::render() {
		COORD buffer_size;
		buffer_size.X = m_TargetSurface.width();
		buffer_size.Y = m_TargetSurface.height();

		COORD origin_tl;
		origin_tl.X = 0;
		origin_tl.Y = 0;

		SMALL_RECT write_area;
		write_area.Top = 0;
		write_area.Left = 0;
		write_area.Bottom = buffer_size.Y;
		write_area.Right = buffer_size.X;
		
		CHAR_INFO *native_target = m_TargetSurface.export_native_windows_map();

		BOOL success = WriteConsoleOutput(
			m_WinCSBHandle,
			native_target,
			buffer_size,
			origin_tl,
			&write_area
		);

		delete native_target;

		if (!success)
			std::cerr << "Failed to write to console!" << std::endl;
	}


	void ConsoleManager::clear() {
		m_TargetSurface.fill(WChar(' ', CharColor(false, false, false, false), CharColor(false, false, false, false)));
	}

}	// namespace engine
}	// namespace ei
