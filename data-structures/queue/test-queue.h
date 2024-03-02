//
//  test-stack.h
//  dsr
//

#pragma once

/// Interface
#include "queue.h"
/// Specific implementation
#include "linked-list-queue.h"

/// Include the quality namespace
#include "test-runner.h"

#include <vector>

namespace DataStructures {



class QueueTester : public Quality::Tester {
public:
    QueueTester(Queue::Type t) : testType(t), Quality::Tester(Quality::RunAllTests, Quality::ResultFormatter::Default) {}
    
    static bool TestAll(std::string& errStr);
    
protected:
    virtual Quality::TestList& getTests() override;
    virtual void setupTest() override;
    virtual void cleanupTest() override;
    
    std::unique_ptr<Queue> testQueue;
    Queue::Type testType;
    
    
};





}

