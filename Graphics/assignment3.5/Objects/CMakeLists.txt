set(HEADERS Light.h Object3D.h Ray.h Sphere.h Triangle.h)

set(SRC Sphere.cpp Triangle.cpp Light.cpp)

add_library(Objects ${HEADERS} ${SRC})
