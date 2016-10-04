// The MIT License (MIT)
// Copyright (C) 2016, Rodrigo Martins <rodrigo.matins.071090@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "uik/platforms/mswin/mswinwindow.h"

#ifdef MSWIN
#include <windows.h>



namespace {
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static BOOL(WINAPI* setProcessDpiAware)() = nullptr;
	static bool DpiAwareInitialized = false;

	/** Current windows */
	static UIK::MsWinWindow* CurrentWindows = nullptr;

	/** Function always used the window receives a call */
	LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
		bool handled = CurrentWindows->ReactWindowMessage(msg, (unsigned)wParam, (unsigned)lParam);
		return handled? 0 : DefWindowProc(hwnd, msg, wParam, lParam);
	}
}



namespace UIK {
	/**
	 * Construct.
	 * The window is not yet opened.
	 */
	MsWinWindow::MsWinWindow(){
		// DPI aware initialize
		if(!DpiAwareInitialized){
			HMODULE userDll = GetModuleHandle("user32.dll");
			setProcessDpiAware = (BOOL(WINAPI*)())(void*)GetProcAddress(userDll, "SetProcessDPIAware");

			// Cancel automatic DPI scaling
			if(setProcessDpiAware) setProcessDpiAware();

			DpiAwareInitialized = true;
		}

		CurrentWindows = this;
	}

	/**
	 * Destruct.
	 * Close window if open.
	 */
	MsWinWindow::~MsWinWindow()
	{Close();}


	/**
	 * Set window mode.
	 * @param flag mode - Window mode flag.
	 */
	void MsWinWindow::SetMode(flag mode){
		// No register fullscreen mode
		if((mode & 0x0040) == 0) Mode = mode;

		// Window style mode
		flag windowStyle = WS_VISIBLE;
		if((mode & (0x0020|0x0040)) != 0) windowStyle |= WS_POPUP;
		else windowStyle |= WS_OVERLAPPEDWINDOW;

		// Disable fullscreen mode
		if((mode & 0x0040) == 0) Fullscreen = false;

		// Current position and size
		int  y = PositionY;
		int  x = PositionX;
		uint h = Height;
		uint w = Width;

		// Centralize
		if(((mode & 0x0001) != 0) && !Fullscreen){
			HDC hdc = GetDC(nullptr);
			x = (GetDeviceCaps(hdc, HORZRES) - w) / 2;
			y = (GetDeviceCaps(hdc, VERTRES) - h) / 2;
			ReleaseDC(nullptr, hdc);

			PositionX = x;
			PositionY = y;
		}

		// Change to fullscreen
		if((mode & 0x0040) != 0){
			Fullscreen = true;
			x = 0; y = 0;

			HDC hdc = GetDC(nullptr);
			w = (uint)GetDeviceCaps(hdc, HORZRES);
			h = (uint)GetDeviceCaps(hdc, VERTRES);
			ReleaseDC(nullptr, hdc);
		}

		// Change current mode
		if(Handle){
			// Change window style
			SetWindowLong((HWND)Handle, GWL_STYLE, windowStyle);

			// Change position and size
			SetWindowPos((HWND)Handle, nullptr, x, y, w, h, SWP_NOZORDER);

			// Show window
			ShowWindow((HWND)Handle, SW_SHOW);
		}
	}

	/**
	 * Set window title.
	 * @param char* title - Window title.
	 */
	void MsWinWindow::SetTitle(char* title){
		if(Handle) SetWindowText((HWND)Handle, title);
		Title = title;
	}

	/**
	 * Set window size.
	 * @param uint width  - Window width.
	 * @param uint height - Window height.
	 */
	void MsWinWindow::SetSize(uint width, uint height){
		// Change window size
		Width = width; Height = height;

		// Alterate in current mode
		SetMode(Mode);
	}

	/**
	 * Set window position.
	 * @param int x - Window position x.
	 * @param int y - Window position y.
	 */
	void MsWinWindow::SetPosition(int x, int y){
		// Change window position
		PositionX = x; PositionY = y;

		// Change current mode to decentralized
		unsigned mode = (Mode&~0x0001);

		// Alterate mode
		SetMode(mode);
	}


	/**
	 * Get window size.
	 * @param uint width  - Store the width.
	 * @param uint height - Store the height.
	 */
	void MsWinWindow::GetSize(uint& width, uint& height) const {
		if(Handle){
			RECT rect = {0, 0, 0, 0};
			GetClientRect((HWND)Handle, &rect);
			height = rect.bottom - rect.top;
			width = rect.right - rect.left;
		} else {width=0; height=0;}
	}

	/**
	 * Get window position.
	 * @param int x - Store the position x.
	 * @param int y - Store the position y.
	 */
	void MsWinWindow::GetPosition(int& x, int& y) const {
		if(Handle){
			RECT rect = {0, 0, 0, 0};
			GetWindowRect((HWND)Handle, &rect);
			x = rect.left; y = rect.top;
		} else {x=0; y=0;}
	}


	/** Window open */
	void MsWinWindow::Open(){
		if(Handle) return;

		// Handle module instance
		HINSTANCE hInstance = GetModuleHandle(nullptr);

		// Register window class
		WNDCLASS wndClass;
		wndClass.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wndClass.cbClsExtra    = 0;
		wndClass.cbWndExtra    = 0;
		wndClass.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
		wndClass.hInstance     = hInstance;
		wndClass.hCursor       = LoadCursor(0, IDC_ARROW);
		wndClass.hIcon         = LoadIcon(0, IDI_APPLICATION);
		wndClass.lpfnWndProc   = WindowProc;
		wndClass.lpszClassName = "USERINTERFACEKIT";
		wndClass.lpszMenuName  = nullptr;

		if(!RegisterClass(&wndClass)){
			LOGERROR("Register window failed!");
			return;
		}

		// Create window
		Handle = CreateWindow(
			"USERINTERFACEKIT",
			Title,
			WS_DISABLED,
			0, 0, 0, 0,
			nullptr, nullptr,
			hInstance,
			nullptr
		);

		if(!Handle){
			LOGERROR("Could not create the window");
			return;
		}

		// Apply window style
		if(Fullscreen) SetMode(0x0040);
		else SetMode(Mode);
	}

	/** Window close */
	void MsWinWindow::Close(){
		if(!Handle) return;

		// Destroy the window
		DestroyWindow((HWND)Handle);
		Handle = nullptr;

		// Unregister window class
		UnregisterClass(
			"USERINTERFACEKIT",
			GetModuleHandle(nullptr)
		);
	}

	/** Window restore */
	void MsWinWindow::Restore()
	{if(Handle) ShowWindow((HWND)Handle, SW_RESTORE);}

	/** Window minimize */
	void MsWinWindow::Minimize()
	{if(Handle) ShowWindow((HWND)Handle, SW_MINIMIZE);}

	/** Window maximize */
	void MsWinWindow::Maximize()
	{if(Handle) ShowWindow((HWND)Handle, SW_MAXIMIZE);}

	/** Window events */
	void MsWinWindow::Events(){
		if(!Handle) return;

		Resized = false;

		MSG msg;
		while(PeekMessage(&msg, (HWND)Handle, 0, 0, PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}


	/** React to a window message */
	bool MsWinWindow::ReactWindowMessage(unsigned msg, unsigned wParam, unsigned lParam) const {
		bool handled = false;

		switch(msg){
			case WM_LBUTTONDOWN:
			case WM_MBUTTONDOWN:
			case WM_RBUTTONDOWN: break;
			case WM_LBUTTONUP:
			case WM_MBUTTONUP:
			case WM_RBUTTONUP: break;
			case WM_SYSKEYDOWN:
			case WM_KEYDOWN: break;
			case WM_SYSKEYUP:
			case WM_KEYUP: break;
			case WM_MOUSEMOVE: break;
			case WM_MOUSELEAVE: break;
			case WM_MOUSEWHEEL: break;
			case WM_SYSCOMMAND:
				break;
			case WM_ACTIVATE:
				Focused = (LOWORD(wParam) != WA_INACTIVE);
				break;
			case WM_DESTROY:
			case WM_CLOSE:
				// Destroy the window
                DestroyWindow((HWND)Handle);
                Handle = nullptr;

                // Unregister window class
                UnregisterClass(
                    "USERINTERFACEKIT",
                    GetModuleHandle(nullptr)
                );
				break;
			case WM_SIZE:
				Minimized = (wParam == SIZE_MINIMIZED);
				if(!Minimized) Resized = true;
				break;
		}

		return handled;
	}
}
#endif
