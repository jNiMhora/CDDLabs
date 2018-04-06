/*!author: Jessica Moore
   date: October 2017
   purpose: using Semaphore class to show the rendezvous pattern.
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskA(std::shared_ptr<Semaphore> aSemaphore, std::shared_ptr<Semaphore> bSemaphore){
  std::cout <<"first statement"<<std::endl;
  aSemaphore->Signal();
  bSemaphore->Wait();
  std::cout <<"second statement"<<std::endl;
  
}
void taskB(std::shared_ptr<Semaphore> bSemaphore, std::shared_ptr<Semaphore> aSemaphore){
  std::cout <<"third statement"<<std::endl;
  bSemaphore->Signal();
  aSemaphore->Wait();
  std::cout <<"fourth statement"<<std::endl;
}

int main(void){
  std::thread threadA, threadB;/*!creating two threads */
  std::shared_ptr<Semaphore> aArrived(new Semaphore);/*! creating two semaphores*/
  std::shared_ptr<Semaphore> bArrived( new Semaphore);

  /**< Launch the threads  */
  threadA=std::thread(taskA, aArrived, bArrived);
  threadB=std::thread(taskB, bArrived, aArrived);

  std::cout << "Launched from the main\n";
  threadA.join();
  threadB.join();
  return 0;
} 

