#ifndef AppComponent_hpp
#define AppComponent_hpp

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

#include "oatpp/core/macro/component.hpp"

class AppComponent
{
public:

    /* Create the Connection Provider Component */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, server_connection_provider)
        ([]
                {
                    /* Return a Connection Provider Initialized with the Specified IP Address */
                    return oatpp::network::tcp::server::ConnectionProvider::createShared({
                                "localhost",
                                7777,
                                oatpp::network::Address::IP_4});
                } ());

    /* Create the Router Component */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, http_router)([]
                {
                    return oatpp::web::server::HttpRouter::createShared();
                } ());

    /* Create the Connection Handler Component */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connection_handler)([]
                {
                    /* Inject the HTTP Router Defined Above */
                    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

                    /* Return an HTTP Connection Handler Initialized with the HTTP Router Injected Above */
                    return oatpp::web::server::HttpConnectionHandler::createShared(router);
                } ());

    /* Create the Object Mapper Component to Serialize and Deserialize DTOs */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, object_mapper)([]
               {
                    return oatpp::parser::json::mapping::ObjectMapper::createShared();
               } ());
};

#endif