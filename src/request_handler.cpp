//
// Created by Matthew Crowell on 3/12/22 at 4:58 PM.
//

#include "include/request_handler.h"
#include "dto/message_dto.hpp"

/* Definition of Request Handler Constructor Taking an Incoming Request as an Argument */
std::shared_ptr<oatpp::web::protocol::http::outgoing::Response> RequestHandler::handle(const
                                                                    std::shared_ptr<IncomingRequest>&
                                                                    request)
{
    /* Instantiate a Message Data Transfer Object Wrapped in a Shared Pointer */
    auto message{MessageDTO::createShared()};

    /* Set the Status Code of the Message Data Transfer Object */
    message->statusCode = 1024;

    /* Set the Message of the Message Data Transfer Object */
    message->message = "Hello from the DTO!";

    /* Return HTTP Response Using the Status code, the Message Data Transfer Object, and the Object Mapper */
    return ResponseFactory::createResponse(Status::CODE_200, message, m_object_mapper);
}