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
using namespace std;

typedef string::iterator s_iter;

string ReadFile (const char* filename) {
    ifstream fin(filename);
    stringstream pipe;
    pipe << fin.rdbuf();
    return pipe.str();
}

bool isChars (char c, const char* list) {
    while (*list) {
        if (c == *list) return true;
        list ++;
    }
    return false;
}

set<string> ParseDXIOLxxCN (const char* filename) {
    string buffer(ReadFile(filename));
    string prefix("\\def \\");
    set<string> labels;
    
    for (s_iter i(buffer.begin()); i != buffer.end(); ++ i) {
        for (s_iter j(prefix.begin()); j != prefix.end(); ++ i, ++ j)
            if (*i != *j) break;
        
        string label;
        for (;; ++ i) {
            if (isChars(*i, "# {")) break;
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

bool isLetter (char c) {
    if (c >= 'A' && c <= 'Z') return true;
    if (c >= 'a' && c <= 'z') return true;
    return false;
};

string findLabelForward (s_iter i) {
    string label;
    while (isLetter(*i)) {
        label = *i + label;
        ++ i;
    }
    return label;
}

string findLabelBackward (s_iter i) {
    string label;
    while (isLetter(*i)) {
        label = *i + label;
        -- i;
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
    
    for (s_iter i(buffer.begin()); i != buffer.end(); ++ i) {
        char c = *i;
        if (c == '}' || c == '\\') {
            ++ i;
            if (i == buffer.end()) {
                result += c;
                return result;
            }
            s_iter s1 = result.end() - 1, s2 = i + 1;
            if (*i == ' ' && *s2 == '\\') {
                if (c == '}') {
                    reduceBrace(s1);
                    if (*s1 == ' ') -- s1;
                }
                string str1(findLabelBackward(s1));
                string str2(findLabelForward(s2 + 1));
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
    
    set<string> CLabels(ParseDXIOLxxCN(argv[1]));
    string result(RemoveSpace(argv[2], CLabels));
    
    ofstream fout(argv[3]);
    fout << result;
    
    return 0;
}