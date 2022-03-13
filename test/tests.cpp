//
// Created by Matthew Crowell on 3/12/22 at 4:42 PM.
//

#include "controller_test.h"

#include <iostream>

void runTests()
{
    OATPP_RUN_TEST(ControllerTest);
}

int main()
{
    oatpp::base::Environment::init();

    runTests();

    std::cout << "\nEnvironment:\n";
    std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << '\n';
    std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << '\n\n';

    OATPP_ASSERT(oatpp::base::Environment::getObjectsCount() == 0);

    oatpp::base::Environment::destroy();

    return 0;
}