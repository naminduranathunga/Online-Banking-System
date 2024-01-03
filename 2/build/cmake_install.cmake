<<<<<<< HEAD
# Install script for directory: C:/Users/Rashmi Kavindya/Desktop/Online-Banking-System/2
=======
# Install script for directory: C:/Users/Asus/Desktop/Online-Banking-System/2
>>>>>>> 4b3bd5e98fd2adf1f537cb6e569d81e8a85720f7

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/BankingSystem")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
<<<<<<< HEAD
  set(CMAKE_OBJDUMP "E:/MinGW64/bin/objdump.exe")
=======
  set(CMAKE_OBJDUMP "D:/MinGW64/bin/objdump.exe")
>>>>>>> 4b3bd5e98fd2adf1f537cb6e569d81e8a85720f7
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
file(WRITE "C:/Users/Rashmi Kavindya/Desktop/Online-Banking-System/2/build/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "C:/Users/Asus/Desktop/Online-Banking-System/2/build/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> 4b3bd5e98fd2adf1f537cb6e569d81e8a85720f7
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
