#include "input/mouse.h"


namespace UIK {
	/** Check if a mouse button is pressed */
	bool Mouse::ButtonPressed(Button button){
		return false;
	}

	/** Get mouse point from current window */
	Point Mouse::GetPosition(){
		return Point(.0f, .0f);
	}

	/** Set mouse point from current window */
	void Mouse::SetPosition(const Point point){}
}
