Navigating the Project Directories
==================================

Housekeeping
------------
*bin* -- Takes all your binary files. All executables generated by make. Do not touch.
*build* -- Takes all object files. All object code generated by make. Do not touch.
*doc* -- Human-readable files. Put all words here.
*include* -- All of our header files. .h (c-compatible) and .hpp (not c-compatible) files go here.
*lib* -- Libraries go here.
*src* -- All source files. .h (c-compatible) and .hpp (not c-compatible) files go here.
*test* -- Test files go here.

Compiling and Running the Project
---------------------------------
*make* -- generates bin/runner, which runs the project.
*make test* -- generates bin/tester, which runs tester.cpp in test.
*make clean* -- deletes old .o files and binary executables.

Make sure you clean before compiling; this prevents lots of testing stupidity that happens with cpp projects.
