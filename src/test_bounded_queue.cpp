#include <iostream>
#include <sstream>
#include "gtest/gtest.h"
#include "bounded_queue.h"
#include <thread>

// Test fixture for Queue tests
class QueueTest : public ::testing::Test {
protected:
    
    void SetUp() {}
    void TearDown() {}
};

TEST_F(QueueTest, PushToNonFullQueue) {
    Queue<int> queue_(2);
    queue_.Push(1);
    queue_.Push(2);
    ASSERT_EQ(queue_.Count(), 2);
}

// Test case for pushing elements to a full queue
TEST_F(QueueTest, PushToFullQueue) {
    Queue<int> queue_(2);
    queue_.Push(1);
    queue_.Push(2);

   // Redirect std::cerr to a stringstream
    std::stringstream errorStream;
    std::streambuf* originalCerrBuffer = std::cerr.rdbuf(errorStream.rdbuf());

    // Call the Push function that should print an error message
    queue_.Push(3);

    // Restore the original std::cerr buffer
    std::cerr.rdbuf(originalCerrBuffer);

    // Verify the error message
    std::string errorMessage = errorStream.str();
    EXPECT_EQ(errorMessage, "CRITICAL: Queue Full \n");
}

TEST_F(QueueTest, PopFromNonEmptyQueue) {
    Queue<int> queue_(2);
    queue_.Push(1);
    queue_.Push(2);
    int element1 = queue_.Pop();
    int element2 = queue_.Pop();
    ASSERT_EQ(element1, 1);
    ASSERT_EQ(element2, 2);
}
// Test case for popping elements from an empty queue
TEST_F(QueueTest, PopFromEmptyQueue) {
    Queue<int> queue_(2);
    
    // Call the Pop function that should throw an exception
    ASSERT_THROW(queue_.Pop(), std::runtime_error);

}

// Test case for checking the count of elements in the queue
TEST_F(QueueTest, CountElements) {
    Queue<int> queue_(2);
    ASSERT_EQ(queue_.Count(), 0);

    queue_.Push(1);
    ASSERT_EQ(queue_.Count(), 1);

    queue_.Push(2);
    ASSERT_EQ(queue_.Count(), 2);

    queue_.Pop();
    ASSERT_EQ(queue_.Count(), 1);
}

// Test case for checking the size of the queue
TEST_F(QueueTest, QueueSize) {
    Queue<int> queue_(2);
    ASSERT_EQ(queue_.Size(), 2);
}

// Test case for checking the push and pop operations together
TEST_F(QueueTest, PushAndPop) {
    Queue<int> queue_(2);
    queue_.Push(1);
    queue_.Push(2);
    int element1 = queue_.Pop();
    int element2 = queue_.Pop();
    ASSERT_EQ(element1, 1);
    ASSERT_EQ(element2, 2);
}
int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
