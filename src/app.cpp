#include "app_component.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/core/macro/codegen.hpp"

/* Includes for Custom Components */
#include "include/request_handler.h"
#include "include/march_twelfth_controller.h"

/* Declare Run Method */
void run();

/* Define Main Method */
int main()
{
    /* Initialize OatPP Environment */
    oatpp::base::Environment::init();

    /* Run the Application */
    run();

    /* Destroy OatPP Environment */
    oatpp::base::Environment::destroy();

    return 0;
}

void run()
{
    /* Register Components in Scope of Run Method */
    AppComponent components;

    /* Inject Router for HTTP Request Routing */
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    /* Instantiate API Controller */
    auto controller = std::make_shared<MarchTwelfthController>();

    /* Register API Controller with Router */
    router->addController(controller);

    /* Inject HTTP Connection Handler with Router */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connection_handler);

    /* Inject TCP Connection Provider with IP Address */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connection_provider);

    /* Create Server Which Takes Provided TCP Connections and Passes Them to HTTP Connection Handler */
    oatpp::network::Server server(connection_provider, connection_handler);

    /* Print Server Info at Start Up */
    OATPP_LOGI("MarchTwelfth", "Server is now running on port %s", connection_provider->getProperty("port").getData());

    /* Run the Server */
    server.run();
}