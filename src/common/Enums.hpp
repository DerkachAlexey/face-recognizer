#ifndef COMMON_ENUMS
#define COMMON_ENUMS

namespace fr
{

namespace enums
{

enum class ApplicationMode
{
    REGISTRATION = 1,
    RECOGNITION = 2,
    REMOVAL = 3, // If we want to delete a person from DB
    UNKNOWN = 4
};

enum class Extensions
{
    JPG = 0,
    PNG = 1
};

} // namespace enums
} // namespace fr

#endif
