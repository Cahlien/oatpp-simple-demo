//
// Created by Matthew Crowell on 3/12/22 at 5:15 PM.
//

#ifndef MARCH_TWELFTH_MESSAGE_DTO_HPP
#define MARCH_TWELFTH_MESSAGE_DTO_HPP

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * This class is the Data Transfer Object representing a message.
 */
class MessageDTO : public oatpp::DTO
{
    /* Initialize the MessageDTO Class, Extending the DTO Class */
    DTO_INIT(MessageDTO, DTO /* Extends */)

    /* Define a Field in the MessageDTO Class of Type Int32 Called statusCode */
    DTO_FIELD(Int32, statusCode);

    /* Define a Field in the MessageDTO Class of Type String Called message */
    DTO_FIELD(String, message);
};

#include OATPP_CODEGEN_END(DTO)


#endif //MARCH_TWELFTH_MESSAGE_DTO_HPP
