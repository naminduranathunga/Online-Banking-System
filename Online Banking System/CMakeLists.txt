cmake_minimum_required(VERSION 3.0)

# Set output directory of executable to ./bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

project(BankingSystem)

# Add all CPP files in ./inc directory to the project
file(GLOB SOURCES "inc/*.cpp")
file(GLOB LIBRARIES "lib/*.cpp")
#file(GLOB SOURCES_COMMANDS "inc/commands/*.cpp")
#file(GLOB UNIT_TESTS "unit_tests/*.cpp")

# Add the main CPP file to the project
set(MAIN_FILE "main.cpp")
set(UNIT_TEST_FILE "test.cpp")

# Set the generator to "MinGW Makefiles"
set(CMAKE_GENERATOR "MinGW Makefiles")


# Create the executable from the sources and the main file
add_executable(BankingSystem ${SOURCES} ${LIBRARIES} ${MAIN_FILE})

#unit tests
#add_executable(test ${SOURCES} ${SOURCES_COMMANDS} ${UNIT_TESTS} ${UNIT_TEST_FILE})
#file(GLOB U_TEST_SOURCES "inc/Account.cpp" "inc/SavingsAccount.cpp" "inc/CurrentAccount.cpp")

#add_executable(UnitTest ${U_TEST_SOURCES} ${LIBRARIES} ${UNIT_TEST_FILE})

