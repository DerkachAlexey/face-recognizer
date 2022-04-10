#ifndef COMMON_APPLICATION_PHOTOSAPPLICATIONEXECUTOR_H
#define COMMON_APPLICATION_PHOTOSAPPLICATIONEXECUTOR_H

#include "IApplicationExecutor.hpp"

namespace fr
{

namespace common
{

class PhotosApplicationExecutor : public IApplicationExecutor
{
public:
    void execute() override;
};

} // namespace fr
} // namespace common

#endif // COMMON_APPLICATION_PHOTOSAPPLICATIONEXECUTOR_H
