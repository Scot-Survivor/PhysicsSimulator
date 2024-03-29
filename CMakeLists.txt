cmake_minimum_required(VERSION 3.0)
project(PhysicsSimulator)
find_package(IntelSYCL REQUIRED)
find_package(MKL CONFIG REQUIRED)
cmake_policy(SET CMP0079 NEW)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsycl -fsycl-unnamed-lambda")

include_directories($ENV{DPCPP_HOME}/llvm/build/include)
include_directories($ENV{DPCPP_HOME}/llvm/build/include/sycl/)
include_directories($ENV{DPCPP_HOME}/llvm/build/lib)

#add_compile_options(-fsycl -fsycl-unnamed-lambda)
add_link_options(-fsycl -fsycl-unnamed-lambda)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} src/main.cpp
        src/VectorMath.cpp
        src/VectorMath.h
        src/RigidBody.cpp
        src/RigidBody.h
        src/World.cpp
        src/World.h
)
# Add third party libraries.
add_subdirectory(libs)

# target_include_directories(${PROJECT_NAME} PUBLIC include)
#target_link_libraries(${PROJECT_NAME} Test)
target_compile_options(${PROJECT_NAME} PUBLIC $<TARGET_PROPERTY:MKL::MKL,INTERFACE_COMPILE_OPTIONS>)
target_include_directories(${PROJECT_NAME} PUBLIC include $<TARGET_PROPERTY:MKL::MKL,INTERFACE_INCLUDE_DIRECTORIES>)
target_link_libraries(${PROJECT_NAME} $<LINK_ONLY:MKL::MKL>)
