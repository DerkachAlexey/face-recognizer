#ifndef SERVICES_SERVICELOCATOR
#define SERVICES_SERVICELOCATOR

#include <map>

#include "Logger.hpp"
#include "UUID.hpp"

namespace fr {

namespace services {

class IService;

class ServicesLocator {
public:
  ServicesLocator() = delete;

  template <typename LocatableService>
  static void registerService(std::shared_ptr<LocatableService> service) {
    auto uniqueId = getUUIDOfService<LocatableService>();

    if (m_services.find(uniqueId) != m_services.end()) {
      m_logger.warn("Service already registered, UUID:" +
                    std::to_string(std::hash<common::UUID>()(uniqueId)));

      return;
    }

    m_services[uniqueId] = service;
  }

  template <typename LocatableService> static LocatableService *getService() {
    auto uniqueId = getUUIDOfService<LocatableService>();

    if (m_services.find(uniqueId) == m_services.end()) {
      m_logger.critical("Service is not registered, UUID:" +
                        std::to_string(std::hash<common::UUID>()(uniqueId)));

      throw std::invalid_argument("Tried to obtain unregistered service");
    }

    return static_cast<LocatableService *>(m_services.at(uniqueId).get());
  }

  template <typename LocatableService> static common::UUID getUUIDOfService() {
    static auto uniqueId = common::UUID();
    return uniqueId;
  }

private:
  inline static std::map<common::UUID, std::shared_ptr<IService>> m_services{};
  inline static common::Logger m_logger{"fr.services.ServicesLocator"};
};

} // namespace services
} // namespace fr

#endif
