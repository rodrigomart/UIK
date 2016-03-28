#include "input/mouse.h"
#include "platform/mswin/inputimpl.h"


namespace UIK {
	/** Check if a mouse button is pressed */
	bool Mouse::ButtonPressed(Button button){
		return Platform::InputImpl::isButtonPressed(button);
	}

	/** Get mouse point from current window */
	Point Mouse::GetPosition(){
		return Platform::InputImpl::GetMousePosition();
	}

	/** Set mouse point from current window */
	void Mouse::SetPosition(const Point& point){
		Platform::InputImpl::SetMousePosition(point);
	}
}
