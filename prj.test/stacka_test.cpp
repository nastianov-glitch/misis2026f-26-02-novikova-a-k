#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <stacka/stacka.hpp>

TEST_CASE("StackA basic tests") {
    StackA s;
    CHECK(s.is_empty());
    s.push(1); s.push(2); s.push(3);
    CHECK_FALSE(s.is_empty());
    CHECK(s.top() == 3);
    s.pop();
    CHECK(s.top() == 2);
    s.pop(); s.pop();
    CHECK(s.is_empty());
}

TEST_CASE("StackA resize on many pushes") {
    StackA s;
    for (int i = 0; i < 100; ++i) s.push(i);
    for (int i = 99; i >= 0; --i) {
        CHECK(s.top() == i);
        s.pop();
    }
    CHECK(s.is_empty());
}

TEST_CASE("StackA top on empty throws") {
    StackA s;
    CHECK_THROWS(s.top());
}

TEST_CASE("StackA copy and assign are independent") {
    StackA s1;
    for (int i = 0; i < 10; ++i) s1.push(i);
    StackA s2(s1);
    StackA s3; s3 = s1;
    s1.clear();
    CHECK(s1.is_empty());
    for (int i = 9; i >= 0; --i) {
        CHECK(s2.top() == i); s2.pop();
        CHECK(s3.top() == i); s3.pop();
    }
    CHECK(s2.is_empty());
    CHECK(s3.is_empty());
}
