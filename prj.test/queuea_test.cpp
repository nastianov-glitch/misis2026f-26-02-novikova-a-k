#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <queuea/queuea.hpp>

TEST_CASE("QueueA basic tests") {
    QueueA q;
    CHECK(q.is_empty() == true);
    q.push(10);
    CHECK(q.is_empty() == false);
    CHECK(q.top() == 10);
    q.push(20);
    CHECK(q.top() == 10);
    q.pop();
    CHECK(q.top() == 20);
    q.pop();
    CHECK(q.is_empty() == true);
}

TEST_CASE("Resize test") {
    QueueA q;
    for(int i = 0; i < 10; ++i) q.push(i);
    for(int i = 0; i < 10; ++i) { CHECK(q.top() == i); q.pop(); }
    CHECK(q.is_empty() == true);
}

TEST_CASE("Copy empty") {
    QueueA q1;
    QueueA q2;
    q1.push(1); q1.pop();
    q2 = q1;
    CHECK(q2.is_empty() == true);
}

TEST_CASE("Copy single element") {           // проверка исправленного бага
    QueueA q1;
    q1.push(42);
    QueueA q2(q1);
    CHECK(q2.top() == 42);
    CHECK(q1.top() == 42);
    q2.pop();
    CHECK(q2.is_empty() == true);
    CHECK(q1.is_empty() == false);
}

TEST_CASE("Assign non-empty") {
    QueueA q1;
    for (int i = 1; i <= 5; ++i) q1.push(i);
    QueueA q2;
    q2 = q1;
    for (int i = 1; i <= 5; ++i) {
        CHECK(q2.top() == i);
        q2.pop();
        q1.pop();
    }
    CHECK(q2.is_empty() == true);
    CHECK(q1.is_empty() == true);
}

TEST_CASE("Wrap-around after pops") {
    QueueA q;
    for (int i = 0; i < 5; ++i) { q.push(i); q.pop(); }
    CHECK(q.is_empty() == true);
    for (int i = 0; i < 10; ++i) q.push(100 + i);
    for (int i = 0; i < 10; ++i) { CHECK(q.top() == 100 + i); q.pop(); }
    CHECK(q.is_empty() == true);
}

TEST_CASE("Top on empty throws") {
    QueueA q;
    CHECK_THROWS(q.top());
}