#ifndef COMMON_APPLICATION_PHOTOSAPPLICATIONEXECUTOR_H
#define COMMON_APPLICATION_PHOTOSAPPLICATIONEXECUTOR_H

#include "IApplicationExecutor.hpp"
#include "Logger.hpp"

namespace fr
{

namespace common
{

class PhotosApplicationExecutor : public IApplicationExecutor
{
public:
    void execute() override;

private:
    Logger m_logger{"fr.common.application.PhotosApplicationExecutor"};    
};

} // namespace fr
} // namespace common

#endif // COMMON_APPLICATION_PHOTOSAPPLICATIONEXECUTOR_H
