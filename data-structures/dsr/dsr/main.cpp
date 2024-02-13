//
//  main.cpp
//  dsr - Data Structure Runnertest
//
//

#include <iostream>
#include "test-stack.h"
#include "test-runner.h"


int main(int argc, const char * argv[]) {
    DataStructures::StackTester tester(DataStructures::Stack::VectorStack);
    
    const auto& res = tester.RunTests();
    printf("%s\n", res.errors.c_str()); 
    printf("FIN\n"); 
}
