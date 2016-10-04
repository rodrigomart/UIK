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

#pragma once
#include "uik/app/app.h"

#ifdef LINUX
#include "uik/platforms/linux/linuxwindow.h"
#endif

#ifdef MSWIN
#include "uik/platforms/mswin/mswinwindow.h"
#endif



namespace UIK {
	/**
	 * Construct.
	 * The window is not yet opened.
	 */
	App::App(){
		#ifdef LINUX
		WindowImplement = new LinuxWindow;
		LOGINFO("Window to Linux platform");
		#endif

		#ifdef MSWIN
		WindowImplement = new MsWinWindow;
		LOGINFO("Window to Microsoft Windows platform");
		#endif
	}

	/**
	 * Destruct.
	 * Close window if open.
	 */
	App::~App(){
		WindowImplement->Close();
		delete WindowImplement;
		WindowImplement = nullptr;
	}


	/**
	 * Set window mode.
	 * @param flag mode - Window mode flag.
	 */
	void App::SetMode(flag mode)
	{WindowImplement->SetMode(mode);}

	/**
	 * Set window title.
	 * @param char* title - Window title.
	 */
	void App::SetTitle(char* title)
	{WindowImplement->SetTitle(title);}

	/**
	 * Set window size.
	 * @param uint width  - Window width.
	 * @param uint height - Window height.
	 */
	void App::SetSize(uint width, uint height)
	{WindowImplement->SetSize(width, height);}

	/**
	 * Set window position.
	 * @param int x - Window position x.
	 * @param int y - Window position y.
	 */
	void App::SetPosition(int x, int y)
	{WindowImplement->SetPosition(x, y);}


	/**
	 * Get window size.
	 * @param uint width  - Store the width.
	 * @param uint height - Store the height.
	 */
	void App::GetSize(uint& width, uint& height) const
	{WindowImplement->GetSize(width, height);}

	/**
	 * Get window position.
	 * @param int x - Store the position x.
	 * @param int y - Store the position y.
	 */
	void App::GetPosition(int& x, int& y) const
	{WindowImplement->GetPosition(x, y);}

	/**
	 * Get window handle.
	 * @return handle
	 */
	handle App::GetHandle() const
	{return WindowImplement->GetHandle();}


	/** Window open */
	void App::Open()
	{WindowImplement->Open();}

	/** Window close */
	void App::Close()
	{WindowImplement->Close();}

	/** Window restore */
	void App::Restore()
	{WindowImplement->Restore();}

	/** Window minimize */
	void App::Minimize()
	{WindowImplement->Minimize();}

	/** Window maximize */
	void App::Maximize()
	{WindowImplement->Maximize();}

	/** Window events */
	void App::Events()
	{WindowImplement->Events();}


	/**
	 * Check whether window is open.
	 * @return bool
	 */
	bool App::IsOpen() const
	{return WindowImplement->IsOpen();}

	/**
	 * Check whether window is borderless mode.
	 * @return bool
	 */
	bool App::IsBorderless() const
	{return WindowImplement->IsBorderless();}

	/**
	 * Check whether window is fullscreen mode.
	 * @return bool
	 */
	bool App::IsFullscreen() const
	{return WindowImplement->IsFullscreen();}

	/**
	 * Check whether window is minimized.
	 * @return bool
	 */
	bool App::IsMinimized() const
	{return WindowImplement->IsMinimized();}

	/**
	 * Check whether window has resized.
	 * @param bool
	 */
	bool App::HasResized() const
	{return WindowImplement->HasResized();}

	/**
	 * Check whether window has focus.
	 * @return bool
	 */
	bool App::HasFocus() const
	{return WindowImplement->HasFocus();}


	/// CONSTANTS
	const flag App::HIDDEN     (0x0000);
	const flag App::WINDOWED   (0x0010);
	const flag App::BORDERLESS (0x0020);
	const flag App::FULLSCREEN (0x0040);
	const flag App::CENTERED   (0x0001);
}
