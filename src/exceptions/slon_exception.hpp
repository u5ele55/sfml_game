#ifndef SLON_EXCEPTION
#define SLON_EXCEPTION

#include <exception>

namespace Exceptions
{
    class SlonException : public std::exception {
    public:
        SlonException(int index) noexcept;
        const char* what() const noexcept;
    private:
        int errorIndex;
    };
} // namespace Exceptions


#endif