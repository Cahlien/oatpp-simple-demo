# Declare Minimum Version of CMake Required by Project
cmake_minimum_required(VERSION 3.21)

# Define Project Name Variable
set(project_name march_twelfth)

# Name Project
project(${project_name})

# Set C++ Standard for Compiler
set(CMAKE_CXX_STANDARD 20)

# Find OatPP Modules
find_package(oatpp 1.3.0 REQUIRED)

# Create Library for Project
add_library(${project_name}-lib
        src/app_component.hpp
        )

# Link OatPP Libraries to Project Library
target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        )

# Assign Source Folder to Public Sources for Project Library
target_include_directories(${project_name}-lib PUBLIC src)

# Create Project Executable
add_executable(${project_name}-exe
        src/app.cpp
        src/request_handler.cpp
        src/dto/message_dto.hpp
        src/controller/march_twelfth_controller.cpp
        )

# Link Project Library to Project Executable
target_link_libraries(${project_name}-exe ${project_name}-lib)

# Establish Project Library as Dependency for Project Executable
add_dependencies(${project_name}-exe ${project_name}-lib)

# Create Executable Project Tests
add_executable(${project_name}-test
        src/controller/march_twelfth_controller.cpp
        test/tests.cpp
        test/app/api_test_client.hpp
        test/app/test_component.hpp
        test/controller_test.cpp
        test/controller_test.h
        )

# Link Project Library to Executable Project Tests
target_link_libraries(${project_name}-test ${project_name}-lib)

# Add Include Directories for Executable Project Tests
target_include_directories(${project_name}-test PRIVATE src/include)

# Establish Project Library as Dependency for Executable Project Tests
add_dependencies(${project_name}-test ${project_name}-lib)

# Set Properties for Project Library, Project Executable, and Executable Project Tests
set_target_properties(${project_name}-lib ${project_name}-exe ${project_name}-test PROPERTIES
        CXX_STANDARD 20
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        )

# Enable CMake Testing
enable_testing()

# Register Executable Project Tests with CTest
add_test(project-tests ${project_name}-test)