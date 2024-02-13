//
//  test-stack.cpp
//  dsr
//

#include "test-stack.h"
#include <string>

using namespace DataStructures;

void StackTester::setupTest() {
    testStack = Stack::Factory(testType);
}

void StackTester::cleanupTest() {
    testStack.reset();
}


bool TestAddThenNotEmpty(DataStructures::Stack* stackToTest, std::string& errStr);
bool TestAddThenClear(DataStructures::Stack* stackToTest, std::string& errStr);
bool TestAddThenPeek(DataStructures::Stack* stackToTest, std::string& errStr);
bool TestPeekDoesNotRemove(DataStructures::Stack* stackToTest, std::string& errStr);
bool TestPopRemovesItem(DataStructures::Stack* stackToTest, std::string& errStr);

Quality::TestList& StackTester::getTests() {
    static Quality::TestList testList = {
        {
            "Add Item Then Not Empty",
            [&] (std::string& errStr) -> bool { return TestAddThenNotEmpty(testStack.get(), errStr); }
        },
        {
            "Add Item Then Clear Stack",
            [&](std::string& errStr) -> bool {return TestAddThenClear(testStack.get(), errStr); }
        },
        {
            "Add Can Peek What Is Added",
            [&](std::string& errStr) -> bool {return TestAddThenPeek(testStack.get(), errStr); }
        },
        {
            "Peek Does Not Remove",
            [&](std::string& errStr) -> bool {return TestPeekDoesNotRemove(testStack.get(), errStr); }
        },
        {
            "Pop Removes Items",
            [&](std::string& errStr) -> bool { return TestPopRemovesItem(testStack.get(), errStr); }
        },
    };
    
    return testList;
}




bool TestAddThenNotEmpty(DataStructures::Stack* stackToTest, std::string& errStr)
{
    stackToTest->push({10});
    stackToTest->push({15});
    if (true == stackToTest->isEmpty()) {
        errStr = "Stack is empty after pushign 2 items";
        return false;
    }
    
    return true;
}
    
bool TestAddThenClear(DataStructures::Stack* stackToTest, std::string& errStr)
{
    stackToTest->push({10});
    stackToTest->push({15});
    if (true == stackToTest->isEmpty()) {
        errStr = "Stack is empty after pushign 2 items";
        return false;
    }
    stackToTest->clear();
    if (false == stackToTest->isEmpty()) {
        errStr = "Stack is not empty after clear";
        return false;
    }
    
    return true;
}

bool TestAddThenPeek(DataStructures::Stack* stackToTest, std::string& errStr) {
    DataStructures::Typ itm = {.obj = 101010888};
    stackToTest->push({20});
    stackToTest->push({200});
    stackToTest->push(itm);
    auto peekd = stackToTest->peek();
    if (peekd.obj != itm.obj) {
        errStr = "Peeking top item does not provide correct value";
        return false;
    }
    
    return true;
}

bool TestPeekDoesNotRemove(DataStructures::Stack* stackToTest, std::string& errStr) {
    stackToTest->clear();
    
    DataStructures::Typ itm = {.obj = 101010888};
    stackToTest->push(itm);
    auto peekd = stackToTest->peek();
    if (peekd.obj != itm.obj) {
        errStr = "Peeking top item does not provide correct value";
        return false;
    }
    if (stackToTest->isEmpty()) {
        errStr = "Peeking to item popped it";
        return false;
    }
    
    return true;
}

bool TestPopRemovesItem(DataStructures::Stack* stackToTest, std::string& errStr) {
    stackToTest->clear();
    
    DataStructures::Typ itm = {.obj = 101010888};
    stackToTest->push(itm);
    auto popd = stackToTest->pop();
    if (itm.obj != popd.obj) {
        errStr = "Popped object is not correct";
        return false;
    }
    if (false == stackToTest->isEmpty()) {
        errStr = "Popping does not remove";
        return false;
    }
    
    return true;
}



