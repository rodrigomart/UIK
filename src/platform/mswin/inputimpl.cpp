#include "platform/mswin/inputimpl.h"
#include "platform/mswin/windowimpl.h"

#ifndef VK_XBUTTON1
#define VK_XBUTTON1 0x0001
#endif
#ifndef VK_XBUTTON2
#define VK_XBUTTON2 0x0002
#endif
#ifndef VK_OEM_COMMA
#define VK_OEM_COMMA 0xBC
#endif
#ifndef VK_OEM_PERIOD
#define VK_OEM_PERIOD 0xBE
#endif
#ifndef VK_OEM_PLUS
#define VK_OEM_PLUS 0xBB
#endif
#ifndef VK_OEM_MINUS
#define VK_OEM_MINUS 0xBD
#endif


namespace UIK {
	namespace Platform {
		/** Check if a key is pressed */
		bool InputImpl::isKeyPressed(Keyboard::Key key){
			int vKey = 0;

			switch(key){
				default:                  vKey = 0;             break;
				case Keyboard::A:         vKey = 'A';           break;
				case Keyboard::B:         vKey = 'B';           break;
				case Keyboard::C:         vKey = 'C';           break;
				case Keyboard::D:         vKey = 'D';           break;
				case Keyboard::E:         vKey = 'E';           break;
				case Keyboard::F:         vKey = 'F';           break;
				case Keyboard::G:         vKey = 'G';           break;
				case Keyboard::H:         vKey = 'H';           break;
				case Keyboard::I:         vKey = 'I';           break;
				case Keyboard::J:         vKey = 'J';           break;
				case Keyboard::K:         vKey = 'K';           break;
				case Keyboard::L:         vKey = 'L';           break;
				case Keyboard::M:         vKey = 'M';           break;
				case Keyboard::N:         vKey = 'N';           break;
				case Keyboard::O:         vKey = 'O';           break;
				case Keyboard::P:         vKey = 'P';           break;
				case Keyboard::Q:         vKey = 'Q';           break;
				case Keyboard::R:         vKey = 'R';           break;
				case Keyboard::S:         vKey = 'S';           break;
				case Keyboard::T:         vKey = 'T';           break;
				case Keyboard::U:         vKey = 'U';           break;
				case Keyboard::V:         vKey = 'V';           break;
				case Keyboard::W:         vKey = 'W';           break;
				case Keyboard::X:         vKey = 'X';           break;
				case Keyboard::Y:         vKey = 'Y';           break;
				case Keyboard::Z:         vKey = 'Z';           break;
				case Keyboard::Num0:      vKey = '0';           break;
				case Keyboard::Num1:      vKey = '1';           break;
				case Keyboard::Num2:      vKey = '2';           break;
				case Keyboard::Num3:      vKey = '3';           break;
				case Keyboard::Num4:      vKey = '4';           break;
				case Keyboard::Num5:      vKey = '5';           break;
				case Keyboard::Num6:      vKey = '6';           break;
				case Keyboard::Num7:      vKey = '7';           break;
				case Keyboard::Num8:      vKey = '8';           break;
				case Keyboard::Num9:      vKey = '9';           break;
				case Keyboard::Escape:    vKey = VK_ESCAPE;     break;
				case Keyboard::LControl:  vKey = VK_LCONTROL;   break;
				case Keyboard::LShift:    vKey = VK_LSHIFT;     break;
				case Keyboard::LAlt:      vKey = VK_LMENU;      break;
				case Keyboard::LSystem:   vKey = VK_LWIN;       break;
				case Keyboard::RControl:  vKey = VK_RCONTROL;   break;
				case Keyboard::RShift:    vKey = VK_RSHIFT;     break;
				case Keyboard::RAlt:      vKey = VK_RMENU;      break;
				case Keyboard::RSystem:   vKey = VK_RWIN;       break;
				case Keyboard::Menu:      vKey = VK_APPS;       break;
				case Keyboard::LBracket:  vKey = VK_OEM_4;      break;
				case Keyboard::RBracket:  vKey = VK_OEM_6;      break;
				case Keyboard::SemiColon: vKey = VK_OEM_1;      break;
				case Keyboard::Comma:     vKey = VK_OEM_COMMA;  break;
				case Keyboard::Period:    vKey = VK_OEM_PERIOD; break;
				case Keyboard::Quote:     vKey = VK_OEM_7;      break;
				case Keyboard::Slash:     vKey = VK_OEM_2;      break;
				case Keyboard::BackSlash: vKey = VK_OEM_5;      break;
				case Keyboard::Tilde:     vKey = VK_OEM_3;      break;
				case Keyboard::Equal:     vKey = VK_OEM_PLUS;   break;
				case Keyboard::Dash:      vKey = VK_OEM_MINUS;  break;
				case Keyboard::Space:     vKey = VK_SPACE;      break;
				case Keyboard::Return:    vKey = VK_RETURN;     break;
				case Keyboard::BackSpace: vKey = VK_BACK;       break;
				case Keyboard::Tab:       vKey = VK_TAB;        break;
				case Keyboard::PageUp:    vKey = VK_PRIOR;      break;
				case Keyboard::PageDown:  vKey = VK_NEXT;       break;
				case Keyboard::End:       vKey = VK_END;        break;
				case Keyboard::Home:      vKey = VK_HOME;       break;
				case Keyboard::Insert:    vKey = VK_INSERT;     break;
				case Keyboard::Delete:    vKey = VK_DELETE;     break;
				case Keyboard::Add:       vKey = VK_ADD;        break;
				case Keyboard::Subtract:  vKey = VK_SUBTRACT;   break;
				case Keyboard::Multiply:  vKey = VK_MULTIPLY;   break;
				case Keyboard::Divide:    vKey = VK_DIVIDE;     break;
				case Keyboard::Left:      vKey = VK_LEFT;       break;
				case Keyboard::Right:     vKey = VK_RIGHT;      break;
				case Keyboard::Up:        vKey = VK_UP;         break;
				case Keyboard::Down:      vKey = VK_DOWN;       break;
				case Keyboard::Numpad0:   vKey = VK_NUMPAD0;    break;
				case Keyboard::Numpad1:   vKey = VK_NUMPAD1;    break;
				case Keyboard::Numpad2:   vKey = VK_NUMPAD2;    break;
				case Keyboard::Numpad3:   vKey = VK_NUMPAD3;    break;
				case Keyboard::Numpad4:   vKey = VK_NUMPAD4;    break;
				case Keyboard::Numpad5:   vKey = VK_NUMPAD5;    break;
				case Keyboard::Numpad6:   vKey = VK_NUMPAD6;    break;
				case Keyboard::Numpad7:   vKey = VK_NUMPAD7;    break;
				case Keyboard::Numpad8:   vKey = VK_NUMPAD8;    break;
				case Keyboard::Numpad9:   vKey = VK_NUMPAD9;    break;
				case Keyboard::F1:        vKey = VK_F1;         break;
				case Keyboard::F2:        vKey = VK_F2;         break;
				case Keyboard::F3:        vKey = VK_F3;         break;
				case Keyboard::F4:        vKey = VK_F4;         break;
				case Keyboard::F5:        vKey = VK_F5;         break;
				case Keyboard::F6:        vKey = VK_F6;         break;
				case Keyboard::F7:        vKey = VK_F7;         break;
				case Keyboard::F8:        vKey = VK_F8;         break;
				case Keyboard::F9:        vKey = VK_F9;         break;
				case Keyboard::F10:       vKey = VK_F10;        break;
				case Keyboard::F11:       vKey = VK_F11;        break;
				case Keyboard::F12:       vKey = VK_F12;        break;
				case Keyboard::F13:       vKey = VK_F13;        break;
				case Keyboard::F14:       vKey = VK_F14;        break;
				case Keyboard::F15:       vKey = VK_F16;        break;
				case Keyboard::Pause:     vKey = VK_PAUSE;      break;
			}

			return (GetAsyncKeyState(vKey) & 0x8000) != 0;
		}

		/** Check if a mouse button is pressed */
		bool InputImpl::isButtonPressed(Mouse::Button button){
			int vKey = 0;

			switch(button){
				default:              vKey = 0;           break;
				case Mouse::Left:     vKey = GetSystemMetrics(SM_SWAPBUTTON)? VK_RBUTTON : VK_LBUTTON; break;
				case Mouse::Right:    vKey = GetSystemMetrics(SM_SWAPBUTTON)? VK_LBUTTON : VK_RBUTTON; break;
				case Mouse::Middle:   vKey = VK_MBUTTON;  break;
				case Mouse::XButton1: vKey = VK_XBUTTON1; break;
				case Mouse::XButton2: vKey = VK_XBUTTON2; break;
			}

			return (GetAsyncKeyState(vKey) & 0x8000) != 0;
		}

		/** Get mouse point from current window */
		Point InputImpl::GetMousePosition(){
			POINT pointer;
			GetCursorPos(&pointer);

			if(Platform::WindowImpl::IsCreated()){
				HWND hWnd = Platform::WindowImpl::GetSystemHandle();
				ScreenToClient(hWnd, &pointer);
			}

			return Point(pointer.x, pointer.y);
		}

		/** Set mouse point from current window */
		void InputImpl::SetMousePosition(const Point point){
			POINT pointer{point.X, point.Y};

			if(Platform::WindowImpl::IsCreated()){
				HWND hWnd = Platform::WindowImpl::GetSystemHandle();
				ClientToScreen(hWnd, &pointer);
			}

			SetCursorPos(pointer.x, pointer.y);
		}
	}
}
