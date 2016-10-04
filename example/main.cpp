/// User Interface Kit
#include "uik/uik.h"


/// Usage
using namespace UIK;



/** Starting point of the program */
int main(int argc, char** argv){
	// Application
	App* app = new App;

	// Settings
	app->SetMode  (App::WINDOWED|App::CENTERED);
	app->SetTitle (u8"User Interface Kit");
	app->SetSize  (900u, 500u);

	// Open window
	app->Open();


	// Main loop of the game
	while(app->IsOpen()){
		// Events
		app->Events();
	}

	// Application exit
	return APP_EXIT_SUCCESS;
}
