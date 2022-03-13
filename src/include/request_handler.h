//
// Created by Matthew Crowell on 3/12/22 at 4:58 PM.
//

#ifndef MARCH_TWELFTH_REQUEST_HANDLER_H
#define MARCH_TWELFTH_REQUEST_HANDLER_H

#include <utility>

#include "oatpp-1.3.0/oatpp/oatpp/web/server/HttpRequestHandler.hpp"
#include "oatpp/core/macro/component.hpp"

class RequestHandler : public oatpp::web::server::HttpRequestHandler
{
public:
    /* Declaration of the Constructor Taking an HTTP Request as an Argument */
    std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override;

    /* Trivial Default Constructor */
    RequestHandler() = default;

private:
    /* Inject Object Mapper as Private Member Variable */
    OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, m_object_mapper);
};


#endif //MARCH_TWELFTH_REQUEST_HANDLER_H
