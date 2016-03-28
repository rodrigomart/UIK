#ifndef PLATFORM_MSWIN_INPUTIMPL_H
#define PLATFORM_MSWIN_INPUTIMPL_H

#include "input/mouse.h"
#include "input/keyboard.h"


namespace UIK {
	namespace Platform {
		/**
		 * @class InputImpl
		 * @ingroup Platform
		 */
		class InputImpl {
			public:
				/**
				 * Check if a key is pressed.
				 *
				 * @param key Key to check.
				 * @return boolean
				 */
				static bool isKeyPressed(Keyboard::Key key);

				/**
				 * Check if a mouse button is pressed.
				 *
				 * @param button Button to check.
				 * @return boolean
				 */
				static bool isButtonPressed(Mouse::Button button);

				/**
				 * Get mouse point from current window.
				 *
				 * This function return the current position of
				 * the mouse in window.
				 *
				 * @return Point
				 */
				static Point GetMousePosition();

				/**
				 * Set mouse point from current window.
				 *
				 * This function sets the current position of the mouse in window.
				 *
				 * @param point Sets the cursor position.
				 */
				static void SetMousePosition(const Point point);
		};
	}
}

#endif
