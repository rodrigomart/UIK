# About
UIK is free and open source for creating users interfaces on the opengl.

# Example

```C++
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

```

# Lisense

The MIT License (MIT)
Copyright (C) 2016 Rodrigo Martins <rodrigo.matins.071090@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE

#### Author
* Rodrigo Martins <rodrigo.matins.071090@gmail.com>