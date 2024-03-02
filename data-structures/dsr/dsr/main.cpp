//
//  main.cpp
//  dsr - Data Structure Runnertest
//
//

#include <iostream>
#include "test-stack.h"
#include "test-queue.h"
#include "test-runner.h"


int main(int argc, const char * argv[]) {
    
    /**
     No Args for deciding what to run - this tool takes instructions from nobody
     */
    
    
    std::initializer_list<std::function<bool(std::string&)>> tests = {
        DataStructures::StackTester::TestAll,
        DataStructures::QueueTester::TestAll,
    };
    
    std::string results;
    for (auto& t: tests) {
        t(results);
        printf("%s", results.c_str());
        results.clear();
    }
    
    printf("\n\nFIN\n");
}
