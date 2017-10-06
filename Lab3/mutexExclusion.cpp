#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int count = 0;

void taskA()
{
    m.lock();
    std::cout << "count is " << count <<std::endl;
    count++;
    m.unlock();
}

int main(){
    std::thread threadA, threadB, threadC;

    /**< Launch the threads */
    threadA=std::thread(taskA);
    threadB=std::thread(taskA);
    threadC=std::thread(taskA);

    threadA.join();
    threadB.join();
    threadC.join();
    //std::cout << "count is" << count <<std::endl;
    return 0;
}
