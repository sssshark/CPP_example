#include <iostream>
#include "threadpool/threadpool.h"

void print() {
    std::cout<<"print"<<std::endl;
}

int add(int a, int b) {
    return a+b;
}

int main() {
    ThreadPool pool(4);

    auto result = pool.enqueue([](int answer) { return answer; }, 42);

    auto addRes = pool.enqueue(add, 1, 2);
    auto printRes = pool.enqueue(print);
    std::cout<<addRes.get()<<std::endl;
    return 0;
}