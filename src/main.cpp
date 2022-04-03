#include "Application.hpp"
#include "EnumNamesProvider.hpp"
#include "ServicesLocator.hpp"

void registerServices() {

  auto namesProvider = std::make_shared<fr::services::EnumNamesProvider>();
  fr::services::ServicesLocator::registerService<
      fr::services::EnumNamesProvider>(namesProvider);
}

int main(int argc, char **argv) {
  registerServices();
  fr::common::Application app(argc, argv);
  return 0;
}
