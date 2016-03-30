This is an example C++ library for Arduino 0004+, based on one created by
Nicholas Zambetti for Wiring 0006+

Installation
--------------------------------------------------------------------------------

To install this library, just place this entire folder as a subfolder in your
Arduino/lib/targets/libraries folder.

When installed, this library should look like:

Arduino/lib/targets/libraries/RoverUNT                (this library's folder)
Arduino/lib/targets/libraries/RoverUNT/RoverUNT.cpp   (the library implementation file)
Arduino/lib/targets/libraries/RoverUNT/RoverUNT.h     (the library description file)
Arduino/lib/targets/libraries/RoverUNT/keywords.txt   (the syntax coloring file)
Arduino/lib/targets/libraries/RoverUNT/examples       (the examples in the "open" menu)
Arduino/lib/targets/libraries/RoverUNT/readme.txt     (this file)

Building
--------------------------------------------------------------------------------

After this library is installed, you just have to start the Arduino application.
You may see a few warning messages as it's built.

To use this library in a sketch, go to the Sketch | Import Library menu and
select RoverUNT.  This will add a corresponding line to the top of your sketch:
#include <RoverUNT.h>

To stop using this library, delete that line from your sketch.

Geeky information:
After a successful build of this library, a new file named "RoverUNT.o" will appear
in "Arduino/lib/targets/libraries/RoverUNT". This file is the built/compiled library
code.

If you choose to modify the code for this library (i.e. "RoverUNT.cpp" or "RoverUNT.h"),
then you must first 'unbuild' this library by deleting the "RoverUNT.o" file. The
new "RoverUNT.o" with your code will appear after the next press of "verify"
