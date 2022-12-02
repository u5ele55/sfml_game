#include "string_utilities.hpp"

std::pair<int, int> StringUtilities::findTwoInts(std::string str) {
    std::string word = "";
    bool firstFound = false;
    std::pair<int, int> answer = {-1, -1};
    for(char sym : str) {
        if (sym == ' ') {
            word = "";
            continue;
        }
        word += sym;
        if (isNumber(word)) {
            if (firstFound) 
                answer.second = stoi(word);
            else {
                answer.first = stoi(word);
                firstFound = true;
            }
        }
    }
    return answer;
}

std::map<std::string, std::string> StringUtilities::slonToMap(const std::string& slon) {
    std::map<std::string, std::string> result;
    std::string curKey;
    std::string curValue;

    for(char sym : slon) {
        
    }
}

bool StringUtilities::isNumber(std::string s) {
    bool ans = true;
    for(char c : s) 
        ans &= isDigit(c);
    return ans;
}

bool StringUtilities::isDigit(char sym) {
    return '0' <= sym && sym <= '9';
}