add_executable(complextest complextest.cpp)
target_link_libraries(complextest complex)

add_executable(rationaltest rationaltest.cpp)
target_link_libraries(rationaltest rational)

add_executable(stacks stacks.cpp)
target_link_libraries(stacks rational)