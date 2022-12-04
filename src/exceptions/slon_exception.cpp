#include "slon_exception.hpp"
#include <string>
#include <cstring>

namespace Exceptions
{
    SlonException::SlonException(int index) noexcept : errorIndex(index) {}
    const char* SlonException::what() const noexcept {
        std::string start = "Slon error at ";
        std::string index = std::to_string(errorIndex);
        char *res = new char[start.size() + index.size() + 1];

        strcpy(res, start.c_str());
        strcat(res, index.c_str());

        return res;
    }

} // namespace Exceptions
