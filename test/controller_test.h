//
// Created by Matthew Crowell on 3/12/22 at 5:37 PM.
//

#ifndef MARCH_TWELFTH_CONTROLLER_TEST_H
#define MARCH_TWELFTH_CONTROLLER_TEST_H

#include "oatpp-test/UnitTest.hpp"

class ControllerTest : public oatpp::test::UnitTest
{
public:
    ControllerTest() : UnitTest("TEST[ControllerTest]" /* Test Tag for logs */){}
    void onRun() override;
};


#endif //MARCH_TWELFTH_CONTROLLER_TEST_H
