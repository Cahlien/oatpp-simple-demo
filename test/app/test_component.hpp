//
// Created by Matthew Crowell on 3/12/22 at 5:36 PM.
//

#ifndef MARCH_TWELFTH_TEST_COMPONENT_HPP
#define MARCH_TWELFTH_TEST_COMPONENT_HPP

#include "oatpp/web/server/HttpConnectionHandler.hpp"

#include "oatpp/network/virtual_/client/ConnectionProvider.hpp"
#include "oatpp/network/virtual_/server/ConnectionProvider.hpp"
#include "oatpp/network/virtual_/Interface.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "oatpp/core/macro/component.hpp"

class TestComponent
{
public:
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::virtual_::Interface>, virtual_interface)([] {
        return oatpp::network::virtual_::Interface::obtainShared("virtualhost");
    } ());

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, server_connection_provider)([] {
        OATPP_COMPONENT(std::shared_ptr<oatpp::network::virtual_::Interface>, interface);
        return oatpp::network::virtual_::server::ConnectionProvider::createShared(interface);
    } ());

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ClientConnectionProvider>, client_connection_provider)([] {
        OATPP_COMPONENT(std::shared_ptr<oatpp::network::virtual_::Interface>, interface);
        return oatpp::network::virtual_::client::ConnectionProvider::createShared(interface);
    } ());

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, http_router)([] {
        return oatpp::web::server::HttpRouter::createShared();
    } ());

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, server_connection_handler)([] {
        OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);
        return oatpp::web::server::HttpConnectionHandler::createShared(router);
    } ());

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, object_mapper)([] {
        return oatpp::parser::json::mapping::ObjectMapper::createShared();
    } ());
};

#endif //MARCH_TWELFTH_TEST_COMPONENT_HPP
