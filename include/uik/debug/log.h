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



namespace UIK {
	/**
	 * Logging.
	 * @author    - Rodrigo Martins
	 * @author    - Rodrigo Martins
	 * @license   - MIT License
	 * @copyright - (C) 2016 Rodrigo Martins
	 * @package   - User Interface Kit
	 * @version   - 1.0
	 */
	class Log {
		public:
			static void Debug (char* message)
			{printf("%s", message);}

			static void Info (char* message)
			{printf("Info: %s", message);}

			static void Error (char* message)
			{printf("Error: %s", message);}

			static void Warning (char* message)
			{printf("Warning: %s", message);}
	};
}



#define LOGDEBUG(message) UIK::Log::Debug(message)
#define LOGINFO(message) UIK::Log::Info(message)
#define LOGWARNING(message) UIK::Log::Warning(message)
#define LOGERROR(message) UIK::Log::Error(message)
