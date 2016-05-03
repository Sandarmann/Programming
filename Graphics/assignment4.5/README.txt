Aleksandar Straumann
CS 5721
Assignment 4.5

This project uses 6 external class:
	Vector2D
	Vector3D
	Vector4D
	Matrix4
	Triangle
	FrameBuffer

If you run the program from within the build directory as mentioned above you
will be able to see 3 new .ppm files called:
	tri.ppm is the first set of triangles
	tri2.ppm is the second set of 4 triangles
	polygons.ppm is the set of random polygons to be made
	dimensional.ppm is a 3d square

To run this program:
	(first check if build directory already exists.)
		(if it does exist)
			rm -rf build
	(after doing the above):
		mkdir build
		cd build
		cmake ..
		make
	./frame

All prictures will be made in the directory

Will be named orth.ppm and persp.ppm
