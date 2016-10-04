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

/// Application definitions
#define APP_EXIT_SUCCESS 0
#define APP_EXIT_FAILURE 1



namespace UIK {
	/// Dependencies
	class Window;



	/**
	 * Application.
	 * @author    - Rodrigo Martins
	 * @license   - MIT License
	 * @copyright - (C) 2016 Rodrigo Martins
	 * @package   - User Interface Kit
	 * @version   - 1.0
	 */
	class App {
		public:
			/**
			 * Construct.
			 * The window is not yet opened.
			 */
			App();

			/**
			 * Destruct.
			 * Close window if open.
			 */
			~App();


			/**
			 * Set window mode.
			 * @param flag mode - Window mode flag.
			 */
			void SetMode(flag mode);

			/**
			 * Set window title.
			 * @param char* title - Window title.
			 */
			void SetTitle(char* title);

			/**
			 * Set window size.
			 * @param uint width  - Window width.
			 * @param uint height - Window height.
			 */
			void SetSize(uint width, uint height);

			/**
			 * Set window position.
			 * @param int x - Window position x.
			 * @param int y - Window position y.
			 */
			void SetPosition(int x, int y);


			/**
			 * Get window size.
			 * @param uint width  - Store the width.
			 * @param uint height - Store the height.
			 */
			void GetSize(uint& width, uint& height) const;

			/**
			 * Get window position.
			 * @param int x - Store the position x.
			 * @param int y - Store the position y.
			 */
			void GetPosition(int& x, int& y) const;

			/**
			 * Get window handle.
			 * @return handle
			 */
			handle GetHandle() const;


			/** Window open */
			void Open();

			/** Window close */
			void Close();

			/** Window restore */
			void Restore();

			/** Window minimize */
			void Minimize();

			/** Window maximize */
			void Maximize();

			/** Window events */
			void Events();


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


			/// CONSTANTS
			static const flag HIDDEN;
			static const flag WINDOWED;
			static const flag BORDERLESS;
			static const flag FULLSCREEN;
			static const flag CENTERED;


		private:
			/** Window implementation */
			Window* WindowImplement;
	};
}
