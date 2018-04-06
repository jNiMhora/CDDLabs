/*! Author: Jessica Moore
    Date: 28/9/2017
    Purpose: this main creates two threads and two tasks. It uses a semaphore to
ensure one thread always executes its task completely before the next thread
does the same. */

#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal(); /*!using the semaphore to allow the second thread to run. */
}
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();/*! the second thread must wait until it recieves signal from first thread to proceed, until then, it must wait. */
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

int main(void)
{
  std::thread threadOne, threadTwo;/*!creating 2 threads from spec. */
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
