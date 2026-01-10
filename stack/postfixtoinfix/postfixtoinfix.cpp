#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Calculate {
public:
    int evaluate(const string& expression) {
        stack<int> S;

        for (int i = 0; i < expression.length(); i++) {
            char ch = expression[i];

            if (ch == ' ')
                continue;

            if (isdigit(ch)) {
                S.push(ch - '0');
            } 
            else {

                int no2 = S.top(); S.pop();
                int no1 = S.top(); S.pop();
                int result = 0;

                switch (ch) {
                    case '+': result = no1 + no2; break;
                    case '-': result = no1 - no2; break;
                    case '*': result = no1 * no2; break;
                    case '/': result = no1 / no2; break;
                    default :
                        cout << "Invalid operator: " << ch << endl;
                        return -1;
                }

                S.push(result);
            }
        }

        return S.top();
    }
};

int main() {
    Calculate eval;

    string expr = "23-4+567*+*";
    int result = eval.evaluate(expr);

    cout << "RESULT: " << result << endl;
    return 0;
}
