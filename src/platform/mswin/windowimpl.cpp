#include "platform/mswin/windowimpl.h"


namespace UIK {
	namespace Platform {
		HINSTANCE WindowImpl::_HINSTANCE = NULL;
		HGLRC     WindowImpl::_HGLRC     = NULL;
		HWND      WindowImpl::_HWND      = NULL;
		HDC       WindowImpl::_HDC       = NULL;

		/** Max height window implementation */
		unsigned int WindowImpl::MaxHeight = 0;

		/** Max width window implementation */
		unsigned int WindowImpl::MaxWidth = 0;

		/** Window implementation style */
		unsigned int WindowImpl::Style = 0xFF00;

		/** Height window implementation */
		unsigned int WindowImpl::Height = 600;

		/** Width window implementation */
		unsigned int WindowImpl::Width = 900;

		/** Left window implementation */
		unsigned int WindowImpl::Left = 0;

		/** Top window implementation */
		unsigned int WindowImpl::Top = 0;


		/** Create or recreate window */
		void WindowImpl::Create(
			const    std::string& title,
			unsigned         int  width,
			unsigned         int  height,
			unsigned         int  style
		){
			// Definitions.
			Height = height; Width = width; Style = style;

			// Destroy current window.
			Destroy();

			// Window style.
			DWORD windowStyle = WS_VISIBLE;
			if(Style == 0xFF00) windowStyle |= WS_CAPTION | WS_POPUPWINDOW;
			if(Style != 0xFF00) windowStyle |= WS_POPUP;

			// Device context.
			HDC hDC = GetDC(NULL);
			if(hDC){
				// Fullscreen.
				if(Style == 0xFFFF){
					MaxHeight = GetDeviceCaps(hDC, VERTRES);
					MaxWidth  = GetDeviceCaps(hDC, HORZRES);
					Height = MaxHeight;
					Width  = MaxWidth;
					Left   = 0;
					Top    = 0;
				} else {
					// Centralize window.
					Left = (GetDeviceCaps(hDC, HORZRES) - Width) / 2;
					Top  = (GetDeviceCaps(hDC, VERTRES) - Height) / 2;
				}

				ReleaseDC(NULL, hDC);
			} else {
				std::cout << "Failed to get device context.";
				return;
			}

			// Handle module.
			_HINSTANCE = GetModuleHandle(NULL);

			// Register window class.
			WNDCLASS wndClass;
			wndClass.style         = CS_OWNDC;
			wndClass.cbClsExtra    = 0;
			wndClass.cbWndExtra    = 0;
			wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
			wndClass.hInstance     = _HINSTANCE;
			wndClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
			wndClass.hIcon         = LoadIcon(_HINSTANCE, IDI_APPLICATION);
			wndClass.lpfnWndProc   = &WindowImpl::GlobalOnEvent;
			wndClass.lpszClassName = "USERINTERFACEKIT";
			wndClass.lpszMenuName  = NULL;
			RegisterClass(&wndClass);

			// Create window.
			_HWND = CreateWindow(
				"USERINTERFACEKIT",
				title.c_str(),
				windowStyle,
				Left, Top, Width, Height,
				NULL, NULL, _HINSTANCE, NULL
			);

			if(!_HWND){
				std::cout << "Failed to create window.";
				return;
			}

			// Show window.
			ShowWindow(_HWND, SW_SHOW);

			// Create OpenGL context.
			EnableOpenGL();
		}

		/** Destroy current window */
		void WindowImpl::Destroy(){
			if(_HWND == NULL) return;

			// Destroy OpenGL context.
			DisableOpenGL();

			// Destroy window.
			if(_HWND){
				DestroyWindow(_HWND);
				delete _HWND;
				_HWND = NULL;
			}

			// Unregister window class.
			UnregisterClass(
				"USERINTERFACEKIT",
				_HINSTANCE
			);
		}

		/** Change the window title */
		void WindowImpl::SetTitle(const std::string& title){
			if(_HWND == NULL) return;

			SetWindowText(_HWND, title.c_str());
		}

		/** Show or hide the window */
		void WindowImpl::Visible(bool visible){
			if(_HWND == NULL) return;

			ShowWindow(_HWND, (visible? SW_SHOWNORMAL : SW_HIDE));
		}

		/** Switch to fullscreen */
		void WindowImpl::Fullscreen(bool enable){
			if(_HWND == NULL) return;

			// Resize screen.
			if(!enable){
				ChangeDisplaySettings (NULL, 0);
			} else {
				DEVMODE newSettings;

				EnumDisplaySettings (NULL, 0, &newSettings);

				newSettings.dmPelsWidth  = MaxWidth;
				newSettings.dmPelsHeight = MaxHeight;
				newSettings.dmBitsPerPel = 16;

				newSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

				ChangeDisplaySettings (&newSettings, CDS_FULLSCREEN );
			}

			ShowWindow(_HWND, SW_SHOWNORMAL);
		}

		/** Checks if the window was created */
		bool WindowImpl::IsCreated(){
			return (_HWND != NULL);
		}

		/** Internal event processing function */
		void WindowImpl::PeekEvent(){
			if(_HWND == NULL) return;

			// We process the window events only if we own it
			MSG message;
			while(PeekMessage(&message, _HWND, 0, 0, PM_REMOVE)){
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
		}

		/** Display the window on screen */
		void WindowImpl::Display(){
			if(_HWND == NULL) return;

			SwapBuffers(_HDC);
		}

		/** Get the OS-specific handle */
		HWND WindowImpl::GetSystemHandle(){
			return _HWND;
		}

		/** Enable OpenGL context */
		void WindowImpl::EnableOpenGL(){
			// Device context.
			_HDC = GetDC(_HWND);

			// Pixel format descriptor.
			PIXELFORMATDESCRIPTOR PFD;
			ZeroMemory(&PFD, sizeof(PFD));
			PFD.nSize      = sizeof(PFD);
			PFD.nVersion   = 1;
			PFD.cColorBits = 24;
			PFD.cDepthBits = 16;
			PFD.iLayerType = PFD_MAIN_PLANE;
			PFD.iPixelType = PFD_TYPE_RGBA;
			PFD.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;

			int format = ChoosePixelFormat(_HDC, &PFD);
			SetPixelFormat(_HDC, format, &PFD);

			// Create and enable the render context (HGLRC).
			_HGLRC = wglCreateContext(_HDC);
			wglMakeCurrent(_HDC, _HGLRC);
		}

		/** Disable OpenGL context */
		void WindowImpl::DisableOpenGL(){
			wglMakeCurrent(NULL, NULL);
			wglDeleteContext(_HGLRC);
			ReleaseDC(_HWND, _HDC);
		}

		/** Function called whenever one of our windows receives a message */
		LRESULT CALLBACK WindowImpl::GlobalOnEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
			// Resize current window.
			if(message == WM_SIZE){
				RECT rect;
				GetClientRect(_HWND, &rect);
				Height = rect.bottom - rect.top;
				Width  = rect.right - rect.left;
				Left   = rect.left;
				Top    = rect.top;
			}

			// Don't forward the menu system command.
			if((message == WM_SYSCOMMAND) && (wParam == SC_KEYMENU)) return 0;

			// We don't forward the WM_CLOSE message.
			if(message == WM_CLOSE){
				Destroy();
				return 0;
			}

			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
}
