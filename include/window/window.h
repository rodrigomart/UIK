#ifndef UIK_WINDOW
#define UIK_WINDOW

#include <string>


namespace UIK {
	/**
	 * @class Window
	 * @ingroup Window
	 *
	 * Window rendering.
	 */
	class Window {
		public:
			/** Window height */
			static unsigned int Height;

			/** Window width */
			static unsigned int Width;


			/**
			 * Create or recreate window.
			 *
			 * If the window was already created, it closes it first.
			 *
			 * @param title  Window title.
			 * @param width  Window width.
			 * @param height Window height.
			 * @param style  Window style.
			 */
			static void Create(
				const    std::string& title,
				unsigned         int  width,
				unsigned         int  height,
				unsigned         int  style
			);

			/**
			 * Destroy current window.
			 *
			 * All other functions work normally, you do not need test IsCreated()
			 * all the time, and will have no effect on the windows closed.
			 */
			static void Destroy();

			/**
			 * Change the window title.
			 *
			 * @param title New title.
			 */
			static void SetTitle(const std::string& title);

			/**
			 * Show or hide the window.
			 *
			 * The window is shown by default.
			 *
			 * @param visible Show or hide.
			 */
			static void Visible(bool visible);

			/**
			 * Switch to fullscreen.
			 *
			 * @param enable Enable or disable fullscreen.
			 */
			static void Fullscreen(bool enable);

			/**
			 * Checks if the window was created.
			 *
			 * This function returns whether or not the window exists.
			 * Note that a hidden window is still there, so this function should return true.
			 *
			 * @return boolean
			 */
			static bool IsCreated();

			/**
			 * Internal event processing function.
			 */
			static void PeekEvent();

			/**
			 * Display on screen what has been rendered.
			 *
			 * This function is typically called after all OpenGL rendering has
			 * been done for the current frame, in order to show it on screen.
			 */
			static void Display();
	};
}

#endif
