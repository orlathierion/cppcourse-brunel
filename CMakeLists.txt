cmake_minimum_required (VERSION 2.6)
project (Neuron) 

enable_testing()
find_package(GTest)
include_directories(${GTEST_INCLUDE_DIRS}...})

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})

set (CMAKE_CXX_FLAGS "-O3 -W -Wall -pedantic -std=c++11") 
add_executable (neuron neuron.cpp main_neuron.cpp network.cpp) 
add_executable (neuron_unittest neuron.cpp network.cpp neuron_unittest.cpp)


 target_link_libraries(neuron_unittest ${GTEST_BOTH_LIBRARIES} pthread)
add_test (neuron_unittest neuron_unittest)  

###### Doxygen generation ######
# We first check if Doxygen is present.
find_package(Doxygen)
if(DOXYGEN_FOUND)

    # We then check if the Doxygen.in configuration file exists
    IF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.txt.bak)
        message(FATAL_ERROR "Doxygen configuration file is needed to build the documentation:
         - ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.txt not found.
         - Generate one in the project folder with doxygen -g Doxyfile.in")
    ENDIF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.txt.bak)

    # We configure the doxyfile for make.
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.txt ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
ELSE(DOXYGEN_FOUND)
    message(FATAL_ERROR "Doxygen is needed to build the documentation.")
ENDIF(DOXYGEN_FOUND)


