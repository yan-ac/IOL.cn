/*
 * Author: 刘闽晟<notcome@me.com>
 * Released under WTFPL
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <initializer_list>
using namespace std;

typedef string::iterator s_iter;

string ReadFile (const char* filename) {
    ifstream fin(filename);
    stringstream pipe;
    pipe << fin.rdbuf();
    return pipe.str();
}

set<string> ParseDXIOLxxCN (const char* filename) {
    string buffer(ReadFile(filename));
    string prefix("\\def \\");
    set<string> labels;
    
    for (auto i(buffer.begin()); i != buffer.end(); ++ i) {
        for (auto j(prefix.begin()); j != prefix.end(); ++ i, ++ j)
            if (*i != *j) break;
        
        auto isChars = [](char c, initializer_list<char> l) {
            for (auto x:l) if (c == x) return true;
            return false;
        };
        
        string label;
        for (;; ++ i) {
            if (isChars(*i, {'#', ' ', '{'})) break;
            label += *i;
        }
        labels.insert(label);
        
        while (*i != '\n') ++ i;
    }
    
    return labels;
}

/*
 * RemoveSpace
 * \ChineseLabel{xxx} \ChineseLabel => \ChineseLabel{xxx}\ChineseLabel
 * \ChineseLabel\ \ChineseLabel => \ChineseLabel\ChineseLabel
 */

string findLabel (s_iter i, function<void(s_iter&)> moveIter) {
    string label;
    auto isLetter = [](char c) {
        if (c >= 'A' && c <= 'Z') return true;
        if (c >= 'a' && c <= 'z') return true;
        return false;
    };
    
    while (isLetter(*i)) {
        label = *i + label;
        moveIter(i);
    }
    return label;
}

void reduceBrace (s_iter &i) {
    for (int cnt = 1; cnt; -- i) {
        if (*i == '}') cnt ++;
        if (*i == '{') cnt --;
    }
}

string RemoveSpace (const char* filename, set<string> labels) {
    string buffer(ReadFile(filename));
    string result;
    
    for (auto i(buffer.begin()); i != buffer.end(); ++ i) {
        char c = *i;
        if (c == '}' || c == '\\') {
            ++ i;
            if (i == buffer.end()) {
                result += c;
                return result;
            }
            auto s1 = result.end() - 1, s2 = i + 1;
            if (*i == ' ' && *s2 == '\\') {
                if (c == '}') {
                    reduceBrace(s1);
                    if (*s1 == ' ') -- s1;
                }
                string str1(findLabel(s1, [](s_iter &i) { -- i;}));
                string str2(findLabel(s2 + 1, [](s_iter &i) { ++ i;}));
                reverse(str2.begin(), str2.end());
                
                if (c == '}') result += c;
                if (labels.find(str1) == labels.end() || labels.find(str2) == labels.end()) {
                    if (c == '\\') result += c;
                    -- i;
                }
            }
            else result += c, -- i;
        }
        else result += c;
    }
    
    return result;
}

int main (int argc, char *argv[]) {
    if (argc == 2) {
        if (string(argv[1]) == "-h")
            cout << "RemoveSpace dxIOLxxCN.tex IOLxx.tex IOLxx.nospace.tex" << endl;
        return 0;
    }
    else if (argc != 4) {
        cout << "check \"RemoveSpace -h\" for help." << endl;
        return 0;
    }
    
    auto CLabels(ParseDXIOLxxCN(argv[1]));
    auto result(RemoveSpace(argv[2], CLabels));
    
    ofstream fout(argv[3]);
    fout << result;
    
    return 0;
}