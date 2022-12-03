#ifndef STRING_UTILS
#define STRING_UTILS

#include <string>
#include <map>

class StringUtilities {
public:
    /// @brief 
    /// Returns -1 if no int was found.
    /// @return 
    static std::pair<int, int> findTwoInts(std::string str);

    /// @brief 
    /// @param slon SLavik Object Notation - string like <Name param1={data1} param2={data2}>
    /// @return Map with keys param1, param2 and values data1, data2
    /// @throws std::invalid_argument - if string is not slon formatted
    /// @return 
    static std::map<std::string, std::string> slonToMap(const std::string& slon);

    static bool isNumber(std::string s);
    static bool isDigit(char sym);
};


#endif