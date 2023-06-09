#include <iostream>
#include <thread>
#include "bounded_queue.h"

/**
 * @brief Pop function to be executed by the reading thread.
 * @param queue The queue to pop elements from.
 */
void pop(Queue<int>& queue) {
   int value;
    try {
        // Attempt to Pop an element from the queue
        value = queue.Pop();
        std::cout << "Pop() -> " << value << std::endl;;
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}

/**
 * @brief The main function that demonstrates the usage of the bounded queue.
 */
int main() {
  Queue<int> queue(2);

  // Writing thread
  
   std::thread writer([&]() {

   queue.Push(1);
   std::this_thread::sleep_for(std::chrono::seconds(2));
   queue.Push(2);
   queue.Push(3);
   queue.Push(4);
   std::this_thread::sleep_for(std::chrono::milliseconds(600)); 
   queue.Push(5); 
   std::this_thread::sleep_for(std::chrono::seconds(3));
   queue.Push(6);
   queue.Push(7);
   queue.Push(8);

  });

  // Reading thread
   std::thread reader([&]() {
    
   pop(queue);
   std::this_thread::sleep_for(std::chrono::seconds(3));   
   pop(queue);
   pop(queue);
   pop(queue);
   pop(queue);
   std::this_thread::sleep_for(std::chrono::milliseconds(600)); 
   pop(queue);

   });

  writer.join();
  reader.join();

  return 0;
}
