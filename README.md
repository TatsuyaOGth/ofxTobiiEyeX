ofxTobiiEyeX
============

ofxTobiiEyeX is a wrapper of [Tobii EyeX](http://www.tobii.com/xperience/) SDK for openFrameworks.

#Notes

- This addon only work on windows (visual studio).
- This addon need Tobii EyeX background software. Download and install Tobii EyeX Engin and EyeX Controller Driver to your computer. You can get that from [hear](http://developer.tobii.com/downloads/).

# Usage

1. Add this addon to your VC project. Include files `libs/TobiiEyeXSdk/include` to search paths, and add library `libs/TobiiEyeXSdk/lib/(x64 or x86)/Tobii.EyeX.Cliend.lib`.
2. On explorer, copy dll file `libs/TobiiEyeXSdk/lib/(x64 or x86)/Tobii.EyeX.Cliend.dll` to your `bin/` directory.
2. On VC, Create the ofxTobiiEyeX's instance.
3. When start your app., call `setup()` and register some event handler function(s) `registerXXX()`.
4. When finish your app., call unregister some event handler function(s) `unregisterXXX()`, and `close()`.
5. Please check `ofxTobiiEyeX/example`, and find functions you need.

# Functions

Presents an overview of what the addon offers.

## Eye-Gaze Point

The point on the screen where your eyes are looking.

## Eye Position

The positions of your eyeballs relative to the screen.

## Fixations

Points on the screen where your eyes linger to focus on something.
