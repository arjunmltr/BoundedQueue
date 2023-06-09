Multi-threaded element queue in C++

Class to queue a finite number of elements. This class will be used for
multi-threaded communication as follows:
- Reading thread pops elements while writing thread pushes elements.
- If the queue is empty, reading thread will block and wait for the next element.
- If the queue is full, writing thread will block and wait for another thread to remove an item.
Extra: The reading/writing threads should optionally block for a certain period of time.
