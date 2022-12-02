#include "string_utilities.hpp"
#include <iostream>
std::pair<int, int> StringUtilities::findTwoInts(std::string str) {
    std::string word = "";
    bool firstFound = false;
    std::pair<int, int> answer = {-1, -1};
    for(int i = 0; i < str.size(); i ++) {
        char sym = str[i];
        if (!isDigit(sym)) {
            if (isNumber(word)) {
                if (firstFound) {
                    answer.second = stoi(word);
                    break;
                }
                else {
                    answer.first = stoi(word);
                    firstFound = true;
                }
            }
            word = "";
        } else
            word += sym;
    }
    return answer;
}

std::map<std::string, std::string> StringUtilities::slonToMap(const std::string& slon) {
    if (slon[0] != '<') return {}; // Incorrect data
    std::map<std::string, std::string> result;
    std::string curKey;
    std::string curValue;

    bool paramValueClosed = true, slonClosed = false;

    int paramStart = slon.size();
    for(int i = 0; i < slon.size(); i ++) {
        if (slon[i] == ' ') {
            paramStart = i+1;
            break;
        }
    }
    
    for(int i = paramStart; i < slon.size(); i ++) {
        char sym = slon[i];
        if (sym == ' ') continue;
        
        if (sym == '{') {
            paramValueClosed = false;
            continue;
        }
        if (sym == '}' && !paramValueClosed) {
            paramValueClosed = true;
            result[curKey.substr(0, curKey.size()-1)] = curValue;
            std::cout << curKey << "->" << curValue << '\n';
            curKey = ""; curValue = "";
            continue;
        }
        if (sym == '>') {
            slonClosed = true;
            continue;
        }
        
        if (!paramValueClosed) 
            curValue += sym;
        else
            curKey += sym;
    }

    if (paramValueClosed && slonClosed) return result;
    return {};
}

bool StringUtilities::isNumber(std::string s) {
    if (!s.size()) return false;
    bool ans = true;
    for(char c : s) 
        ans &= isDigit(c);
    return ans;
}

bool StringUtilities::isDigit(char sym) {
    return '0' <= sym && sym <= '9';
}