//
//  test-runner.h
//  dsr
//

#pragma once
#include <functional>
#include <string_view>
#include <vector>
#include <string>

namespace Quality {

using SpecificTestFx = std::function<bool(std::string&)>;
struct Test{
    std::string_view name;
    SpecificTestFx run;
};

using TestBlock = std::vector<Test>;

struct TestResult {
    bool allPassed;
    std::string errorLog;
    
    void addFailedTest(const Test& t, const std::string& err) {
        errorLog += "Test [";
        errorLog += t.name;
        errorLog += "] Failed with error [";
        errorLog += err;
        errorLog += "]\n";
    }
};

/// @class Tester
/// @brief class to manage the test execution of test blocks.
/// Class is not strictly necessary here. As written, this is closer to a namespace than a class. Keeping a class for now because
/// A long term vision of this could be to start to add specific configurations into the tester. Some examples:
///  - Persistence is passed as an argument to "run" currently, could be a construction configuration
///  - There's no formatting configurations. Could update this to ouptut "errorLog" as a JSON
///  - A class allows for inheritence - e.g. if you wanted to create a child class that did shared setup for tests
class Tester {

public:
    enum Persistence {
        QuitOnFailure,
        RunAllTests
    };
    
    Tester() {}
    
    TestResult run(const TestBlock& tests, Persistence persistence=RunAllTests) {
        TestResult res;
        std::string testErrLog;
        for (const auto& _test: tests) {
            testErrLog.clear();
            
            bool passedTest = _test.run(testErrLog);
            if (passedTest) {
                continue;
            }
            
            if (testErrLog.empty()) {
                /// There's no requirement that tests provide an error string (just highly recommended)
                /// If there is no error stirng, we populate a generic message for the user.
                testErrLog = "<No Error Log>";
            }
            res.addFailedTest(_test, testErrLog);
            
            if (QuitOnFailure == persistence) {
                break;
            }
        }
        res.allPassed = res.errorLog.empty();
        return res;
    }
};
}

