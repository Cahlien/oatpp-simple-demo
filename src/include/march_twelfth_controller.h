//
// Created by Matthew Crowell on 3/12/22 at 5:35 PM.
//

#ifndef MARCH_TWELFTH_MARCH_TWELFTH_CONTROLLER_H
#define MARCH_TWELFTH_MARCH_TWELFTH_CONTROLLER_H

#include "dto/message_dto.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MarchTwelfthController : public oatpp::web::server::api::ApiController
{
public:
    /* Inject Default Object Mapper into Constructor */
    explicit MarchTwelfthController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, object_mapper));

    /* Create Endpoint in API Controller */
    ENDPOINT("GET", "/hello", root)
    {
        /* Instantiate Message Data Transfer Object */
        auto dto= MessageDTO::createShared();

        /* Set Status Code for Message Data Transfer Object */
        dto->statusCode = 200;

        /* Set Message for Message Data Transfer Object */
        dto->message = "Hello, World!";

        /* Return an HTTP Response with the Specific Status Code and DTO */
        return createDtoResponse(Status::CODE_200, dto);
    }
};

#include OATPP_CODEGEN_END(ApiController)

#endif //MARCH_TWELFTH_MARCH_TWELFTH_CONTROLLER_H
