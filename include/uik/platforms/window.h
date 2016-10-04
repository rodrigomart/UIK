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
#include "uik/base/standard.h"
#include "uik/debug/log.h"



namespace UIK {
	/**
	 * Window implementation.
	 * @license   - MIT License
	 * @copyright - (C) 2016 Rodrigo Martins
	 * @package   - User Interface Kit
	 * @version   - 1.0
	 */
	class Window {
		public:
			/**
			 * Construct.
			 * The window is not yet opened.
			 */
			Window();

			/**
			 * Destruct.
			 * Close window if open.
			 */
			virtual ~Window(){}


			/**
			 * Set window mode.
			 * @param flag mode - Window mode flag.
			 */
			virtual void SetMode(flag mode) = 0;

			/**
			 * Set window title.
			 * @param char* title - Window title.
			 */
			virtual void SetTitle(char* title) = 0;

			/**
			 * Set window size.
			 * @param uint width  - Window width.
			 * @param uint height - Window height.
			 */
			virtual void SetSize(uint width, uint height) = 0;

			/**
			 * Set window position.
			 * @param int x - Window position x.
			 * @param int y - Window position y.
			 */
			virtual void SetPosition(int x, int y) = 0;


			/**
			 * Get window size.
			 * @param uint width  - Store the width.
			 * @param uint height - Store the height.
			 */
			virtual void GetSize(uint& width, uint& height) const = 0;

			/**
			 * Get window position.
			 * @param int x - Store the position x.
			 * @param int y - Store the position y.
			 */
			virtual void GetPosition(int& x, int& y) const = 0;

			/**
			 * Get window handle.
			 * @return handle
			 */
			handle GetHandle() const;


			/** Window open */
			virtual void Open() = 0;

			/** Window close */
			virtual void Close() = 0;

			/** Window restore */
			virtual void Restore() = 0;

			/** Window minimize */
			virtual void Minimize() = 0;

			/** Window maximize */
			virtual void Maximize() = 0;

			/** Window events */
			virtual void Events() = 0;


			/**
			 * Check whether window is open.
			 * @return bool
			 */
			bool IsOpen() const;

			/**
			 * Check whether window is borderless mode.
			 * @return bool
			 */
			bool IsBorderless() const;

			/**
			 * Check whether window is fullscreen mode.
			 * @return bool
			 */
			bool IsFullscreen() const;

			/**
			 * Check whether window is minimized.
			 * @return bool
			 */
			bool IsMinimized() const;

			/**
			 * Check whether window has resized.
			 * @param bool
			 */
			bool HasResized() const;

			/**
			 * Check whether window has focus.
			 * @return bool
			 */
			bool HasFocus() const;


		protected:
			/** Window handle */
			mutable handle Handle;


			/** Window title */
			mutable char* Title;


			/** Window mode */
			mutable unsigned Mode;


			/** Window borderless flag */
			mutable bool Borderless;

			/** Window fullscreen flag */
			mutable bool Fullscreen;

			/** Window minimized flag */
			mutable bool Minimized;

			/** Window resized flag */
			mutable bool Resized;

			/** Window focused flag */
			mutable bool Focused;


			/** Window position Y */
			mutable int PositionY;

			/** Window position X */
			mutable int PositionX;

			/** Window height */
			mutable uint Height;

			/** Window width */
			mutable uint Width;
	};
}
