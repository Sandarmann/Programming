Aleksandar Straumann
CS 5721
Assignment 3

This project includes 3 external class:
	Vector2D
	Vector3D
	FrameBuffer

Framebuffer will contain the logic necessary for the rasterization. 

If you run the program from within the build directory as mentioned above you
will be able to see 3 new .ppm files called:
	tri.ppm is the first set of triangles
	tri2.ppm is the second set of 4 triangles
	polygons.ppm is the set of random polygons to be made
	dimensional.ppm is a 3d square

To run this program:
	mkdir build
	cd build
	cmake ..
	make
	./frame

All prictures will be made in the directory