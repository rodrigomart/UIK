#ifndef UIK_WINDOWSIMPL
#define UIK_WINDOWSIMPL

#include "include.h"
#include <windows.h>
#include <gdiplus.h>
#include <GL/gl.h>


namespace UIK {
	namespace Platform {
		/**
		 * @class WindowImpl
		 * @ingroup Platform
		 */
		class WindowImpl {
			static HINSTANCE _HINSTANCE;
			static HGLRC     _HGLRC;
			static HWND      _HWND;
			static HDC       _HDC;

			public:
				/** Max height window implementation */
				static unsigned int MaxHeight;

				/** Max width window implementation */
				static unsigned int MaxWidth;

				/** Window implementation style */
				static unsigned int Style;

				/** Height window implementation */
				static unsigned int Height;

				/** Width window implementation */
				static unsigned int Width;

				/** Left window implementation */
				static unsigned int Left;

				/** Top window implementation */
				static unsigned int Top;


				/**
				 * Create or recreate window.
				 *
				 * @param title  Window title.
				 * @param width  Window width.
				 * @param height Window height.
				 * @param style  Window style.
				 */
				static void Create(
					const    std::string& title,
					unsigned         int  width,
					unsigned         int  height,
					unsigned         int  style
				);

				/**
				 * Destroy current window.
				 */
				static void Destroy();

				/**
				 * Change the window title.
				 *
				 * @param title New title.
				 */
				static void SetTitle(const std::string& title);

				/**
				 * Show or hide the window.
				 *
				 * @param visible Show or hide.
				 */
				static void Visible(bool visible);

				/**
				 * Switch to fullscreen.
				 *
				 * @param enable Enable or disable fullscreen.
				 */
				static void Fullscreen(bool enable);

				/**
				 * Checks if the window was created.
				 *
				 * @return boolean
				 */
				static bool IsCreated();

				/**
				 * Internal event processing function.
				 */
				static void PeekEvent();

				/**
				 * Display the window on screen.
				 */
				static void Display();

				/**
				 * Get the OS-specific handle.
				 *
				 * @return HWND
				 */
				static HWND GetSystemHandle();
			private:
				/**
				 * Enable OpenGL context.
				 */
				static void EnableOpenGL();

				/**
				 * Disable OpenGL context.
				 */
				static void DisableOpenGL();

				/**
				 * Function called whenever one of our windows receives a message.
				 */
				static LRESULT CALLBACK GlobalOnEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		};
	}
}

#endif
