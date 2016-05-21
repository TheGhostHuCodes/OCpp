#include <iostream>
#include <thread>
#include "StopWatch.h"

int main() {
    {
        StopWatch sw = StopWatch();
        std::chrono::seconds interval(2);
        std::this_thread::sleep_for(interval);
        std::cout << "Hello, World!" << std::endl;
    }
    return 0;
}