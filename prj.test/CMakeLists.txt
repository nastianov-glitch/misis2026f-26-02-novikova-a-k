add_executable(complex_test complex_test.cpp)
target_link_libraries(complex_test PRIVATE complex)

add_executable(complex_io_test complex_io_test.cpp)
target_link_libraries(complex_io_test PRIVATE complex)

add_executable(rational_test rational_test.cpp)
target_link_libraries(rational_test PRIVATE rational)

add_executable(rational_io_test rational_io_test.cpp)
target_link_libraries(rational_io_test PRIVATE rational)

add_executable(queuea_test queuea_test.cpp)
target_link_libraries(queuea_test PRIVATE queuea_lib)

add_executable(stacka_test stacka_test.cpp)
target_link_libraries(stacka_test PRIVATE stacka_lib)

add_executable(stackl_test stackl_test.cpp)
target_link_libraries(stackl_test PRIVATE stackl_lib)