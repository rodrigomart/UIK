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

#include "uik/platforms/linux/linuxwindow.h"



#ifdef LINUX
namespace UIK {
	/**
	 * Construct.
	 * The window is not yet opened.
	 */
	LinuxWindow::LinuxWindow(){}

	/**
	 * Destruct.
	 * Close window if open.
	 */
	LinuxWindow::~LinuxWindow(){}


	/**
	 * Set window mode.
	 * @param flag mode - Window mode flag.
	 */
	void LinuxWindow::SetMode(flag mode){}

	/**
	 * Set window title.
	 * @param char* title - Window title.
	 */
	void LinuxWindow::SetTitle(char* title){}

	/**
	 * Set window size.
	 * @param uint width  - Window width.
	 * @param uint height - Window height.
	 */
	void LinuxWindow::SetSize(uint width, uint height){}

	/**
	 * Set window position.
	 * @param int x - Window position x.
	 * @param int y - Window position y.
	 */
	void LinuxWindow::SetPosition(int x, int y){}


	/**
	 * Get window size.
	 * @param uint width  - Store the width.
	 * @param uint height - Store the height.
	 */
	void LinuxWindow::GetSize(uint& width, uint& height) const {}

	/**
	 * Get window position.
	 * @param int x - Store the position x.
	 * @param int y - Store the position y.
	 */
	void LinuxWindow::GetPosition(int& x, int& y) const {}


	/** Window open */
	void LinuxWindow::Open(){}

	/** Window close */
	void LinuxWindow::Close(){}

	/** Window restore */
	void LinuxWindow::Restore(){}

	/** Window minimize */
	void LinuxWindow::Minimize(){}

	/** Window maximize */
	void LinuxWindow::Maximize(){}

	/** Window events */
	void LinuxWindow::Events(){}
}
#endif
