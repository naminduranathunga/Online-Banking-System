cmake_minimum_required(VERSION 3.0)
project(BankingSystem)

# Add all CPP files in ./inc directory to the project
file(GLOB SOURCES "inc/*.cpp")
#file(GLOB SOURCES_COMMANDS "inc/commands/*.cpp")
#file(GLOB UNIT_TESTS "unit_tests/*.cpp")

# Add the main CPP file to the project
set(MAIN_FILE "main.cpp")
#set(UNIT_TEST_FILE "unit_test.cpp")

# Set the generator to "MinGW Makefiles"
set(CMAKE_GENERATOR "MinGW Makefiles")


# Create the executable from the sources and the main file
add_executable(BankingSystem ${SOURCES} ${MAIN_FILE})

#unit tests
#add_executable(test ${SOURCES} ${SOURCES_COMMANDS} ${UNIT_TESTS} ${UNIT_TEST_FILE})

