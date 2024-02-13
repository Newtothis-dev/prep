//
//  main.cpp
//  dsr - Data Structure Runnertest
//
//

#include <iostream>
#include "test-stack.h"
#include "test-runner.h"


int main(int argc, const char * argv[]) {
    std::string StackResults;
    DataStructures::StackTester::TestAll(StackResults);
    printf("%s\n", StackResults.c_str());
    printf("FIN\n");
}
