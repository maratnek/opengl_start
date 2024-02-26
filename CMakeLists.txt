cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                TLS_VERIFY ON)
endif()

# set(CMAKE_BUILD_TYPE "Release")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

message(Directory ${CMAKE_BINARY_DIR})
include(${CMAKE_BINARY_DIR}/conan.cmake)
# include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
conan_cmake_run(
			REQUIRES 
				glfw/3.3.2@
				glew/2.2.0@
				glm/cci.20230113@
				opengl/system@
				# glu/system@
				# mesa-glu/9.0.3@
				# glm/0.9.9.5@g-truc/stable
			# glfw/3.3.2@bincrafters/stable
			OPTIONS glfw3:shared=True
					glm:shared=True
					*:shared=True
			GENERATORS cmake cmake_paths cmake_find_package
			#ENV env_var=value
			# PROFILE gcc
			# CONANFILE conanfile.txt
			IMPORTS "bin, *.dll -> ./bin" # Copies all dll files from packages bin folder to my "bin" folder
			IMPORTS	"lib, *.dylib* -> ./Debug" # Copies all dylib files from packages lib folder to my "bin" folder
			IMPORTS	"lib, *.so* -> ./bin" # Copies all dylib files from packages lib folder to my "bin" folder
			BASIC_SETUP CMAKE_TARGETS 
			# BUILD_TYPE "Debug"
			#BUILD missing
			)
			
conan_set_find_library_paths()
conan_basic_setup()

set(CMAKE_INCLUDE_PATH ${CONAN_INCLUDE_DIRS} ${CMAKE_INCLUDE_PATH})
set(CMAKE_LIBRARY_PATH ${CONAN_LIB_DIRS} ${CMAKE_LIBRARY_PATH})


add_executable ( ${PROJECT_NAME} 
		main.cpp
		Mesh/Mesh.cpp
		Camera.cpp
		LightRenderer.cpp
		ShaderLoader.cpp
)
# message(Message ${CMAKE_CURRENT_SOURCE_DIR})
# message(Message ${CMAKE_CURRENT_BINARY_DIR})
# file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        # DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		"${PROJECT_SOURCE_DIR}/resource"
		$<TARGET_FILE_DIR:${PROJECT_NAME}>
)

# find_package(Threads REQUIRED)
# find_package(glfw glew glm REQUIRED)
# find_package(glfw3 CONFIG REQUIRED)
# find_package(glm REQUIRED)
find_package(GLEW REQUIRED)
# find_package(glfw3 CONFIG REQUIRED)
# find_package(glfw REQUIRED)
# find_package(glfw3 3.2 REQUIRED)
# find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} 
		CONAN_PKG::glfw 
		CONAN_PKG::glew 
		CONAN_PKG::glm
		CONAN_PKG::opengl
		)

enable_testing(false)

#add_executable (${PROJECT_NAME}_test "tests/test.cpp")
add_test(NAME ${PROJECT_NAME}_test COMMAND tests/${PROJECT_NAME}_test)


add_executable (easy easy_ex.cpp)
target_link_libraries(easy 
		CONAN_PKG::glfw 
		CONAN_PKG::glew 
		# CONAN_PKG::glm
		CONAN_PKG::opengl
		)