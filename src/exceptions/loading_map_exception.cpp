#include "loading_map_exception.hpp"
#include <string>
#include <cstring>
#include <map>


namespace Exceptions
{
    LoadingMapException::LoadingMapException(Step step, Reason reason) noexcept : m_step(step), m_reason(reason) {}

    const char* LoadingMapException::what() const noexcept {
        std::map<Step, std::string> steps = {
            {Step::CellCreation, "Cell creation"},
            {Step::FieldCreation, "Field creation"},
            {Step::PlayerCreation, "Player creation"},
            {Step::Undefined, "unknown step"},
        };
        std::map<Reason, std::string> reasons = {
            {Reason::FileChanged, "File is changed"},
            {Reason::FileDataIncorrect, "File data is incorrect"},
            {Reason::NoFile, "File not found"},
        };
        
        std::string stepStart = "Map loading error occured at ";
        std::string reasonStart = " with reason of ";
        
        char *res = new char[stepStart.size() + reasonStart.size() + reasons[m_reason].size() + steps[m_step].size() + 1];

        strcpy(res, stepStart.c_str());
        strcat(res, steps[m_step].c_str());
        
        strcat(res, reasonStart.c_str());
        strcat(res, reasons[m_reason].c_str());

        return res;
    }
} // namespace Exceptions
