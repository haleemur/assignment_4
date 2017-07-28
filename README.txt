COMP 5421: Assignment 4

Haleemur Ali (40039217)

=======================


Platform Compatibility
======================

The program has been tested on Mac OSX & Windows 10.


compilation instructions (Mac OSX / Linux)

==========================================


note: must have cmake available in the path

browse to the application source folder

create a build directory & create the binary there, i.e. 
execute the following commands on the terminal

```

mkdir build

cd build

cmake 

make

```

from the build directory execute the following terminal command.

this will run a intro script showing the different shapes and possibilities
of printing them & then start the slot machine game.


```

./shapes_run

```


compilation & run instruction (Windows + MSVS)
==============================================

MSVS 2017: MSVS 2017 supports cmake as a build system

open the folder containing the project
Choose Top Menu >> CMake >> Build All
Then Choose Top Menu >> CMake >> Debug >> shapes_run

Prior Versions of MSVS: Does not support CMake
Import the project, build the solution and run.
