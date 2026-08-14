#include "manager.hpp"

#include "constants.hpp"

#include <phosphor-logging/lg2.hpp>

namespace cable_manager
{

Manager::Manager(sdbusplus::asio::object_server& objectServer) :
    interface(objectServer.add_interface(constants::rootPath,
                                             constants::serviceName))
{
    // TODO: D-Bus method registrations will be added in future stories.

    interface->initialize();

    lg2::info("Manager initialised on path '{PATH}' interface '{IFACE}'",
              "PATH", constants::rootPath, "IFACE", constants::serviceName);
}

Manager::~Manager()
{
}

} // namespace cable_manager
