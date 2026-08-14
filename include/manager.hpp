#pragma once

#include "constants.hpp"

#include <sdbusplus/asio/object_server.hpp>

#include <memory>

namespace cable_manager
{

/**
 * @class Manager
 * @brief Implements the D-Bus APIs exposed by the cable-manager daemon.
 *
 * The Manager class owns the D-Bus interface for the cable-manager service.
 * All methods exposed on that interface are registered and dispatched here.
 *
 */
class Manager
{
  public:
    Manager() = delete;
    Manager(const Manager&) = delete;
    Manager& operator=(const Manager&) = delete;
    Manager(Manager&&) = delete;
    Manager& operator=(Manager&&) = delete;

    /**
     * @brief Construct a Manager and register the D-Bus interface.
     *
     * @param[in] objectServer  sdbusplus object server
     */
    explicit Manager(sdbusplus::asio::object_server& objectServer);

    ~Manager();

  private:
    std::shared_ptr<sdbusplus::asio::dbus_interface> interface;
};

} // namespace cable_manager
