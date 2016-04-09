Aleksandar Straumann
CS 5721
Assignment 2

This project includes 3 external class:
	Vector2D
	Vector3D
	FrameBuffer

Framebuffer will contain the logic necessary for the rasterization. The
methods added are 
	implicit .. a helpter method
	both rasterization algorithms
	isSteep .. determines if delta y is greater than delta x

In folder package you must change directory too the one marked "build"

from there you must call 'cmake ..'
Then you can call 'make'

To run the program you must call ./frame

If you run the program from within the build directory as mentioned above you
will be able to see 3 new .ppm files called:
	circle.ppm
	circleColor.ppm
	colorCreative.ppm
