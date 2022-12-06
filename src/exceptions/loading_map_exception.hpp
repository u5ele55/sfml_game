#ifndef LOADING_MAP_EXCEPTION
#define LOADING_MAP_EXCEPTION

#include <exception>

namespace Exceptions
{
    class LoadingMapException : public std::exception {
    public:
        enum class Step { CellCreation, FieldCreation, PlayerCreation, Undefined };
        enum class Reason { FileChanged, FileDataIncorrect, NoFile };

        LoadingMapException(Step step, Reason reason) noexcept;
        const char* what() const noexcept;
    private:
        Step m_step;
        Reason m_reason;
    };
} // namespace Exceptions


#endif