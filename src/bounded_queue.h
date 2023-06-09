/**
 * @brief A thread-safe queue implementation with a maximum size.
 *
 * This class provides a thread-safe queue with a maximum size. It supports
 * push and pop operations and ensures thread safety using mutex and condition
 * variables.
 *
 * @tparam T The type of elements stored in the queue.
 */

#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <iostream>

template<typename T>
class Queue {
public:
    /**
     * @brief Constructs a Queue object with the specified maximum size.
     *
     * @param size The maximum size of the queue.
     */
    Queue(int size) : max_size_(size) {}

    /**
     * @brief Pushes an element to the queue.
     *
     * This function pushes the specified element to the queue. If the queue
     * is already full, it waits for a specified timeout duration until space
     * becomes available or throws an error if the timeout expires.
     *
     * @param element The element to push to the queue.
     */
    void Push(T element) {
        std::cout << "Executing Push with argument: " << reinterpret_cast<int>(element) << std::endl;
        std::chrono::seconds timeout = std::chrono::seconds(2);
        std::unique_lock<std::mutex> lock(mutex_);
        int previous_count = Count();
        if(previous_count >= max_size_){
            if (cvPush_.wait_for(lock, timeout, [&]() { return queue_.size() < max_size_; })) {
                previous_count = Count();
                queue_.push(element);
                if(!(Count()- previous_count)){
                    std::cerr << "CRITICAL: Error in Pushing Element" << std::endl;
                }
                cvPop_.notify_one();
            }
            else {
                 std::cerr << "CRITICAL: Queue Full \n";
            }
        }
        else {
            queue_.push(element);
            if(!(Count()- previous_count)){
                std::cerr << "CRITICAL: Error in Pushing Element" << std::endl;
            }
            cvPop_.notify_one();
        }
    }

    /**
     * @brief Pops an element from the queue.
     *
     * This function pops an element from the front of the queue. If the queue
     * is empty, it waits for a specified timeout duration until an element
     * becomes available or throws an exception if the timeout expires.
     *
     * @return The element popped from the queue.
     *
     * @throws Throws an exception if the queue is empty and the timeout expires.
     */
    T Pop() {
        std::cout << "Executing Pop" << std::endl;
        std::unique_lock<std::mutex> lock(mutex_);
        std::chrono::seconds timeout = std::chrono::seconds(1);
        int previous_count = Count();
        if(previous_count == 0) {
            if (cvPop_.wait_for(lock, timeout, [&]() { return !queue_.empty(); })) {
                previous_count = Count();
                T element = queue_.front();
                queue_.pop();
                if(!(previous_count-Count())){
                throw std::runtime_error("CRITICAL: Error in Poping Element");
                return T{}; 
            }
                cvPush_.notify_one();
                return element;
            } else {
                throw std::runtime_error("CRITICAL: Queue Empty");
                return T{};
            } 
        }
        else {
            T element = queue_.front();
            queue_.pop();
            if(!(previous_count-Count())){
               throw std::runtime_error("CRITICAL: Error in Poping Element");
               return T{}; 
            }
            cvPush_.notify_one();
            return element;
        }
    }

    /**
     * @brief Returns the current count of elements in the queue.
     *
     * @return The current count of elements in the queue.
     */
    int Count() const {
        return queue_.size();
    }

    /**
     * @brief Returns the maximum size of the queue.
     *
     * @return The maximum size of the queue.
     */
    int Size() const {
        return max_size_;
    }
   
private:
    std::queue<T> queue_;               /**< The underlying container for the queue. */
    std::mutex mutex_;                  /**< Mutex for thread-safe access to the queue. */
    std::condition_variable cvPush_;    /**< Condition variable for push operations. */
    std::condition_variable cvPop_;     /**< Condition variable for pop operations. */
    int max_size_;                      /**< The maximum size of the queue. */
};
