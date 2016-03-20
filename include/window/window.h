#ifndef UIK_WINDOW
#define UIK_WINDOW

#include <string>


namespace UIK {
	/**
	 * Window rendering.
	 */
	class Window {
		public:
			/**
			 * Create or recreate the window.
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
			 * Close the window and destroy.
			 *
			 * All other functions work normally, you do not need test IsOpen()
			 * all the time, and will have no effect on the windows closed.
			 */
			static void Close();
			
			/**
			 * Change the title of the window.
			 *
			 * @param title New window title.
			 */
			static void Title(
				const std::string& title
			);
			
			/**
			 * It says if the window is open or not.
			 *
			 * This function returns whether or not the window exists.
			 * Note that a hidden window is open therefore this function would
			 * return true.
			 *
			 * @return boolean
			 */
			static bool IsOpen();
			
			/**
			 * Internal event processing function.
			 */
			static void PeekEvent(); 
			
			/**
			 * Show or hide the window.
			 *
			 * The window is shown by default.
			 *
			 * @param visible Show or hide.
			 */
			static void Visible(bool visible);
			
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
