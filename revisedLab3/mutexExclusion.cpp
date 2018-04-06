/*!author: Jessica Moore
   date: March 2018
   purpose: revised lab of the original lab 3 exercise: using semaphore to demo mutual exclusion */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int count = 0;

/*!to ensure the threads do not run altogether, a mutex lock is placed in the taskA function, ensuring that the count is incremented correctly, no matter what thread gets there first. */
void taskA()
{
    m.lock();
    std::cout << "count before increment is " << count <<std::endl;
    count++;
    std::cout << "count after increment is " << count << std::endl;
    m.unlock();
}

int main(){
  std::thread threadA, threadB, threadC;/*!creating threads. */

    /** Launch the threads */   
    threadA=std::thread(taskA);
    threadB=std::thread(taskA);
    threadC=std::thread(taskA);

    threadA.join();
    threadB.join();
    threadC.join();
    return 0;
}
