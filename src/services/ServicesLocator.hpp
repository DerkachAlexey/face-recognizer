#ifndef SERVICES_SERVICELOCATOR
#define SERVICES_SERVICELOCATOR

#include <map>

#include "common/Logger.hpp"
#include "common/UUID.hpp"

namespace fr
{

namespace services
{

class IService;

class ServicesLocator
{
public:
  ServicesLocator() = delete;

  template <typename LocatableService>
  static void registerService(std::shared_ptr<LocatableService> service)
  {
    auto uniqueId = getUUIDOfService<LocatableService>();

    if (m_services.find(uniqueId) != m_services.end())
    {
        return;
    }

    m_services[uniqueId] = service;
  }

  template <typename LocatableService> static LocatableService* getService()
  {
    auto uniqueId = getUUIDOfService<LocatableService>();

    if (m_services.find(uniqueId) == m_services.end())
    {
        throw std::invalid_argument("Tried to obtain unregistered service");
    }

    return dynamic_cast<LocatableService*>(m_services.at(uniqueId).get());
  }

  template <typename LocatableService> static common::UUID getUUIDOfService()
  {
    static auto uniqueId = common::UUID();
    return uniqueId;
  }

private:
  inline static std::map<common::UUID, std::shared_ptr<IService>> m_services{};
};

} // namespace services
} // namespace fr

#endif
