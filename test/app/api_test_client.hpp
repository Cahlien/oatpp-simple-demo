//
// Created by Matthew Crowell on 3/12/22 at 5:36 PM.
//

#ifndef MARCH_TWELFTH_API_TEST_CLIENT_HPP
#define MARCH_TWELFTH_API_TEST_CLIENT_HPP

#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiClient)

class MarchTwelfthApiTestClient : public oatpp::web::client::ApiClient
{
    API_CLIENT_INIT(MarchTwelfthApiTestClient)

    API_CALL("GET", "/hello", getHello)
};

#include OATPP_CODEGEN_END(ApiClient)

#endif //MARCH_TWELFTH_API_TEST_CLIENT_HPP
