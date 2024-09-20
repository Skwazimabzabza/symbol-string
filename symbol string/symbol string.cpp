#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*Не получилось корректно реализовать конец строки точкой с запятой */

class String {

    char str;

public:

    bool isMatchingPair(char open, char close) {
        if (open == '(' && close == ')') return true;
        if (open == '{' && close == '}') return true;
        if (open == '[' && close == ']') return true;
        return false;
    }

    void checkBrackets(const std::string& str) {
        std::stack<char> bracketStack;  
        int errorIndex = -1;    

        
        for (size_t i = 0; i < str.length(); i++) {
            char ch = str[i];

            
            if (ch == '(' || ch == '{' || ch == '[') {
                bracketStack.push(ch);
            }
            
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (bracketStack.empty()) {
                    errorIndex = i;
                    break;
                }
                char open = bracketStack.top();
                bracketStack.pop();

                if (!isMatchingPair(open, ch)) {
                    errorIndex = i;
                    break;
                }



                
                
            }


            else if (ch == ';') {
                break;
            }           
            

            

            
        }

        if (!bracketStack.empty() && errorIndex == -1) {
            errorIndex = str.length();
        }

        // Вывод результатов
        if (errorIndex == -1) {
            std::cout << "Строка корректна: " << str << std::endl;
        }
        else {
            std::cout << "Ошибка в строке: " << str.substr(0, errorIndex + 1) << std::endl;
        }
    }
};


int main() {
    setlocale(LC_ALL, "Ru");

    String str;

    std::string inputStr;

    std::cout << "Введите строку со скобками ";
    getline(cin, inputStr);

    
    str.checkBrackets(inputStr);

    return 0;
}