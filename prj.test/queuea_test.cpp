#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <queuea/queuea.hpp>
#include <doctest.h> 
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
// Переполнение
TEST_CASE("Resize test") {
    QueueA q;
    for(int i = 0; i < 10; ++i) q.push(i);
    for(int i = 0; i < 10; ++i) { CHECK(q.top() == i); q.pop(); }
    CHECK(q.is_empty() == true);
}
//Копирование пустой очереди
TEST_CASE("Copy empty") {
    QueueA q1;
    QueueA q2;
    q1.push(1); q1.pop(); 
    q2 = q1; // Здесь упадёт, если не исправить п.1
    CHECK(q2.is_empty() == true);
}