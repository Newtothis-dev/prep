//
//  main.cpp
//  dsr - Data Structure Runnertest
//
//

#include <iostream>
#include "test-stack.h"
#include "test-runner.h"


int main(int argc, const char * argv[]) {
    Quality::Tester tester;
    
    const auto& res = tester.run(DataStructures::getAllStackImplTests());
    printf("%s\n", res.errorLog.c_str()); 
}
