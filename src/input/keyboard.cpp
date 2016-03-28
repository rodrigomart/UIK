#include "input/keyboard.h"
#include "platform/mswin/inputimpl.h"


namespace UIK {
	/** Check if a key is pressed */
	bool Keyboard::KeyPressed(Key key){
		return Platform::InputImpl::isKeyPressed(key);
	}
}
