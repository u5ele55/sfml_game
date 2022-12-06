#include "string_utilities.hpp"
#include <iostream>
#include <stack>
#include <math.h>
#include "../exceptions/slon_exception.hpp"

std::pair<int, int> StringUtilities::findTwoInts(std::string str) {
    str += " ";
    std::string word = "";
    bool firstFound = false;
    std::pair<int, int> answer = {-1, -1};
    for(int i = 0; i < str.size(); i ++) {
        char sym = str[i];
        if (isDigit(sym)) word += sym;
        else {
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
        } 
    }
    return answer;
}

std::map<std::string, std::string> StringUtilities::slonToMap(const std::string& slon) {
    if (slon[0] != '<') throw Exceptions::SlonException(0);
    if (slon[slon.size()-1] != '>') throw Exceptions::SlonException(slon.size()-1);
    std::map<std::string, std::string> result;
    std::string curKey;
    std::string curValue;

    bool paramValueClosed = true, slonClosed = false;

    int paramStart = slon.size();
    for(int i = 0; i < slon.size(); i ++) 
        if (slon[i] == ' ') {
            paramStart = i+1;
            break;
        }

    bool paramClosed = true; int innerSlon = 0;
    int lastParamOpen = -1;
    
    for(int i = paramStart; i < slon.size()-1; i ++) {
        char sym = slon[i];
        if (sym == ' ' && paramClosed) continue;
        
        if (sym == '{' && !innerSlon) {
            paramClosed = false;
            lastParamOpen = i;
            continue;
        }
        if (!paramClosed) {
            if (sym == '<') 
                innerSlon ++;
            else if (sym == '>')
                innerSlon --;
        }
        if (sym == '}' && !innerSlon) {
            paramClosed = true;
            result[curKey.substr(0, curKey.size()-1)] = curValue;
            //std::cout << curKey << ": -" << curValue << "-\n";
            curKey = ""; curValue = "";
            continue;
        }
        
        if (!paramClosed) 
            curValue += sym;
        else
            curKey += sym;
    }

    if (paramClosed) return result;

    throw Exceptions::SlonException(lastParamOpen);
}

int StringUtilities::hash(const std::string& str, int x, int p) {
    long long h = 0;

    long long xpow = 1;

    for(int i = 0; i < str.size(); i ++) {
        h += str[i] * xpow % p;
        xpow *= x;
        xpow %= p;
        h %= p;
    }

    return h;
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