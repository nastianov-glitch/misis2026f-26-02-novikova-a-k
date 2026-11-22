add_executable(complex_test complex_test.cpp)
target_link_libraries(complex_test complex)

add_executable(rational_test rational_test.cpp)
target_link_libraries(rational_test rational)

add_executable(queuea_test queuea_test.cpp)
target_link_libraries(queuea_test PRIVATE queuea_lib)
target_include_directories(queuea_test PRIVATE ../prj.thirdparty)