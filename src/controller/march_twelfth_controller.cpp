//
// Created by Matthew Crowell on 3/12/22 at 5:35 PM.
//

#include "include/march_twelfth_controller.h"

/* Definition of the Constructor Taking the Injected Object Mapper */
MarchTwelfthController::MarchTwelfthController(std::shared_ptr<ObjectMapper>& object_mapper)
    : oatpp::web::server::api::ApiController(object_mapper)
{

}
