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
#include "uik/platforms/window.h"



#ifdef MSWIN
namespace UIK {
	/**
	 * Window implementation Microsoft Windows.
	 * @author    - Rodrigo Martins
	 * @license   - MIT License
	 * @copyright - (C) 2016 Rodrigo Martins
	 * @package   - User Interface Kit
	 * @version   - 1.0
	 */
	class MsWinWindow : public Window {
		public:
			/**
			 * Construct.
			 * The window is not yet opened.
			 */
			MsWinWindow();

			/**
			 * Destruct.
			 * Close window if open.
			 */
			~MsWinWindow();


			/**
			 * Set window mode.
			 * @param flag mode - Window mode flag.
			 */
			virtual void SetMode(flag mode);

			/**
			 * Set window title.
			 * @param char* title - Window title.
			 */
			virtual void SetTitle(char* title);

			/**
			 * Set window size.
			 * @param uint width  - Window width.
			 * @param uint height - Window height.
			 */
			virtual void SetSize(uint width, uint height);

			/**
			 * Set window position.
			 * @param int x - Window position x.
			 * @param int y - Window position y.
			 */
			virtual void SetPosition(int x, int y);


			/**
			 * Get window size.
			 * @param uint width  - Store the width.
			 * @param uint height - Store the height.
			 */
			virtual void GetSize(uint& width, uint& height) const;

			/**
			 * Get window position.
			 * @param int x - Store the position x.
			 * @param int y - Store the position y.
			 */
			virtual void GetPosition(int& x, int& y) const;


			/** Window open */
			virtual void Open();

			/** Window close */
			virtual void Close();

			/** Window restore */
			virtual void Restore();

			/** Window minimize */
			virtual void Minimize();

			/** Window maximize */
			virtual void Maximize();

			/** Window events */
			virtual void Events();


			/** React to a window message */
			bool ReactWindowMessage(unsigned msg, unsigned wParam, unsigned lParam) const;
	};
}
#endif
