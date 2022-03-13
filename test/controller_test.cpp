//
// Created by Matthew Crowell on 3/12/22 at 5:37 PM.
//

#include "controller_test.h"

#include "include/march_twelfth_controller.h"

#include "app/api_test_client.hpp"
#include "app/test_component.hpp"

#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp-test/web/ClientServerTestRunner.hpp"

void ControllerTest::onRun()
{
    /* Register Test Components */
    TestComponent component{};

    /* Create Client-Server Test Runner */
    oatpp::test::web::ClientServerTestRunner runner{};

    /* Add Controller Endpoints to the Router of the Test Runner */
    runner.addController(std::make_shared<MarchTwelfthController>());

    /* Run Test */
    runner.run([this, &runner] {
        OATPP_COMPONENT(std::shared_ptr<oatpp::network::ClientConnectionProvider>, client_connection_provider);

        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, object_mapper);

        auto request_executor{oatpp::web::client::HttpRequestExecutor::createShared(client_connection_provider)};

        auto client{MarchTwelfthApiTestClient::createShared(request_executor, object_mapper)};

        auto response{client->getHello()};

        OATPP_ASSERT(response->getStatusCode() == 200);

        auto message{response->readBodyToDto<oatpp::Object<MessageDTO>>(object_mapper.get())};

        OATPP_ASSERT(message);
        OATPP_ASSERT(message->statusCode.getValue(0) == 200);
        OATPP_ASSERT(message->message == "Hello, World!");

    }, std::chrono::minutes(10));

    std::this_thread::sleep_for(std::chrono::seconds(1));
}