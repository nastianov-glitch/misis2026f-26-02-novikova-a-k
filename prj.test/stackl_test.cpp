#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <stackl/stackl.hpp>

TEST_CASE("StackL basic tests") {
    StackL s;
    CHECK(s.is_empty());
    s.push(1); s.push(2); s.push(3);
    CHECK_FALSE(s.is_empty());
    CHECK(s.top() == 3);
    s.pop();
    CHECK(s.top() == 2);
    s.pop(); s.pop();
    CHECK(s.is_empty());
}

TEST_CASE("StackL top on empty throws") {
    StackL s;
    CHECK_THROWS(s.top());
}

TEST_CASE("StackL copy and assign are independent") {
    StackL s1;
    for (int i = 0; i < 10; ++i) s1.push(i);
    StackL s2(s1);
    StackL s3; s3 = s1;
    s1.clear();
    CHECK(s1.is_empty());
    for (int i = 9; i >= 0; --i) {
        CHECK(s2.top() == i); s2.pop();
        CHECK(s3.top() == i); s3.pop();
    }
    CHECK(s2.is_empty());
    CHECK(s3.is_empty());
}