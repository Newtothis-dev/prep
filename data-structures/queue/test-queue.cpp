//
//  test-stack.cpp
//  dsr
//

#include "test-queue.h"
#include <string>

using namespace DataStructures;

void QueueTester::setupTest() {
    testQueue = Queue::Factory(testType);
}

void QueueTester::cleanupTest() {
    testQueue.reset();
}

bool QueueTester::TestAll(std::string& errStr) {
    std::initializer_list<Queue::Type> types = {
        Queue::LinkedListQueue,
    };
    bool allPass = true;
    for (const auto& t: types) {
        QueueTester st(t);
        auto res = st.RunTests();
        errStr += "Testing Queue Type [";
        errStr += Queue::typeAsStr(t);
        errStr += "]. With Results: ";
        if (res.allPassed) {
            errStr += "All Passed";
        }
        else {
            allPass = false;
            errStr += "Has Failures -- \n" + res.errors + "\n";
        }
    }
    return allPass;
}

bool TestNewQueueAlwaysEmpty(DataStructures::Queue* testQ, std::string& errStr) {
    return testQ->isEmpty();
}

bool TestCanAddToQueue(DataStructures::Queue* testQ, std::string& errStr) {
    
    testQ->enqueue({100});
    return false == testQ->isEmpty();
}

bool TestCanDequeue(DataStructures::Queue* testQ, std::string& errStr) {
    const int v = 100;
    testQ->enqueue({v});
    if (testQ->isEmpty()) {
        errStr = "Failed to add";
        return false;
    }
    auto dq = testQ->dequeue();
    if (dq.obj != v) {
        errStr = "Incorrect Value Dequeued";
        return false;
    }
    if (false == testQ->isEmpty()) {
        errStr = "Did not empty queue on dequeue";
        return false;
    }
    return true;
}

bool TestMultiQueue(DataStructures::Queue* testQ, std::string& errStr) {
    
    const int first = 100, second = 200; 
    testQ->enqueue({first});
    testQ->enqueue({second});
    if (testQ->isEmpty()) {
        errStr = "Failed to add";
        return false;
    }
    auto dq = testQ->dequeue();
    if (dq.obj != first) {
        errStr = "Incorrect Value Dequeued";
        return false;
    }
    if (true == testQ->isEmpty()) {
        errStr = "Did not empty queue on dequeue";
        return false;
    }
    dq = testQ->dequeue();
    if (dq.obj != second) {
        errStr = "Incorrect Value Dequeued";
        return false;
    }
    if (false == testQ->isEmpty()) {
        errStr = "Did not empty queue on dequeue";
        return false;
    }
    return true;
}

bool TestClear(DataStructures::Queue* testQ, std::string& errStr) {
    
    const int first = 100, second = 200;
    testQ->enqueue({first});
    testQ->enqueue({second});
    if (testQ->isEmpty()) {
        errStr = "Failed to add";
        return false;
    }
    testQ->clear();
    if (false == testQ->isEmpty()) {
        errStr = "Did not empty queue on dequeue";
        return false;
    }
    return true;
}


Quality::TestList& QueueTester::getTests() {
    
    static Quality::TestList testList = {
        {
            "New Queue Always Empty",
            [&] (std::string& errStr) -> bool { return TestNewQueueAlwaysEmpty(testQueue.get(), errStr); }
        },
        {
            "Test Enqueue Works",
            [&] (std::string& errStr) -> bool { return TestCanAddToQueue(testQueue.get(), errStr); }
        },
        {
            "Test Enqueue Works correctly",
            [&] (std::string& errStr) -> bool { return TestCanDequeue(testQueue.get(), errStr); }
        },
        {
            "Test Multi-queue works",
            [&] (std::string& errStr) -> bool { return TestMultiQueue(testQueue.get(), errStr); }
        }
    };
    
    return testList;
}


