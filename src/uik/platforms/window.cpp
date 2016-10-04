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

#include "uik/platforms/window.h"



namespace UIK {
	/**
	 * Construct.
	 * The window is not yet opened.
	 */
	Window::Window():
		Handle     (nullptr),
		Title      (u8"User Interface Kit"),
		Mode       (0x0010|0x0001),
		Borderless (false),
		Fullscreen (false),
		Minimized  (false),
		Resized    (false),
		Focused    (false),
		PositionY  (0),
		PositionX  (0),
		Height     (500u),
		Width      (900u)
	{}


	/**
	 * Get window handle.
	 * @return handle
	 */
	handle Window::GetHandle() const
	{return Handle;}


	/**
	 * Check whether window is open.
	 * @return bool
	 */
	bool Window::IsOpen() const
	{return (Handle != nullptr);}

	/**
	 * Check whether window is borderless mode.
	 * @return bool
	 */
	bool Window::IsBorderless() const
	{return Borderless;}

	/**
	 * Check whether window is fullscreen mode.
	 * @return bool
	 */
	bool Window::IsFullscreen() const
	{return Fullscreen;}

	/**
	 * Check whether window is minimized.
	 * @return bool
	 */
	bool Window::IsMinimized() const
	{return Minimized;}

	/**
	 * Check whether window has resized.
	 * @param bool
	 */
	bool Window::HasResized() const
	{return Resized;}

	/**
	 * Check whether window has focus.
	 * @return bool
	 */
	bool Window::HasFocus() const
	{return Focused;}
}
