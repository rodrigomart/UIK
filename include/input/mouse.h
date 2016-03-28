#ifndef UIK_MOUSE
#define UIK_MOUSE

#include "include.h"
#include "point.h"


namespace UIK {
	/**
	 * @class Mouse
	 * @ingroup Input
	 *
	 * UIK::Mouse lets you query the status of the mouse
	 * at any time and directly, without having to deal
	 * with a window and its events.
	 */
	class Mouse {
		public:
			/** Mouse button */
			enum Button {
				Left,
				Right,
				Middle,
				XButton1,
				XButton2
			};


			/**
			 * Check if a mouse button is pressed.
			 *
			 * @param button Button to check.
			 * @return boolean
			 */
			static bool ButtonPressed(Button button);

			/**
			 * Get mouse point from current window.
			 *
			 * This function return the current position of
			 * the mouse in window.
			 *
			 * @return Point
			 */
			static Point GetPosition();

			/**
			 * Set mouse point from current window.
			 *
			 * This function sets the current position of the mouse in window.
			 *
			 * @param point Sets the cursor position.
			 */
			static void SetPosition(const Point point);
	};
}

#endif
