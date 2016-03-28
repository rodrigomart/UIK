#include "window/window.h"
#include "platform/mswin/windowimpl.h"


namespace UIK {
	/** Window height */
	unsigned int Window::Height = 0;

	/** Window width */
	unsigned int Window::Width = 0;


	/** Create or recreate window */
	void Window::Create(
		const    std::string& title,
		unsigned         int  width,
		unsigned         int  height,
		unsigned         int  style
	){
		// Create window.
		Platform::WindowImpl::Create(
			title, width, height, style
		);
	}

	/** Destroy current window */
	void Window::Destroy(){
		Platform::WindowImpl::Destroy();
	}

	/** Change the window title */
	void Window::SetTitle(const std::string& title){
		Platform::WindowImpl::SetTitle(title);
	}

	/** Show or hide the window */
	void Window::Visible(bool visible){
		Platform::WindowImpl::Visible(visible);
	}

	/** Switch to fullscreen */
	void Window::Fullscreen(bool enable){
		Platform::WindowImpl::Fullscreen(enable);
	}

	/** Checks if the window was created */
	bool Window::IsCreated(){
		return Platform::WindowImpl::IsCreated();
	}

	/** Internal event processing function */
	void Window::PeekEvent(){
		Platform::WindowImpl::PeekEvent();

		// Window size.
		Height = Platform::WindowImpl::Height;
		Width  = Platform::WindowImpl::Width;
	}

	/** Display on screen what has been rendered */
	void Window::Display(){
		Platform::WindowImpl::Display();
	}
}
