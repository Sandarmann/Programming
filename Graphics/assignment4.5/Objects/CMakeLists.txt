set(HEADERS Light.h Object3D.h Ray.h Sphere.h Triangle.h Matrix4.h)

set(SRC Sphere.cpp Triangle.cpp Light.cpp Matrix4.cpp)

add_library(Objects ${HEADERS} ${SRC})
