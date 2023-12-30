/*
    Viết chương trình kiểm tra tính đúng đắn của dãy đóng mở ngoặc.
    Cụ thể:-------------------------------------------------------------------------------------------
    |   Mở ngoặc cần được đóng đầy đủ.                                                               |
    |   Ngoặc mở sau cần được đóng trước.                                                            |
    |   Ngoặc nhọn {} không được nằm trong ngoặc vuông [] hoặc ngoặc tròn ().Ví dụ [{}] không hợp lệ.|
    |   Ngoặc vuông [] không được nằm trong ngoặc tròn (). Ví dụ ([]) không hợp lệ.                  |
    --------------------------------------------------------------------------------------------------
    Input:
    Đầu vào gồm 1 dòng duy nhất chứa một xâu ký tự không có dấu cách.
    Xâu đầu vào chỉ chứa các ký tự đóng, mở ngoặc của 3 loại.
    Output:
    In ra màn hình VALID nếu xâu hợp lệ, ngược lại in ra màn hình INVALID.
    Sinh viên được dùng các thư viện cấu trúc dữ liệu có sẵn, hoặc tự cài nếu có đam mê.

    For example:
    Input	            Result
    {}()[()()()()]      VALID
    {(})[(]{)}          INVALID
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValidExpression( string& s) {
    stack<char> stack;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.empty()) {
                return false;
            }

            char top = stack.top();
            stack.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return stack.empty();
}

bool isCorrectOrder(string& s) {
    stack<char> stack;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } 
        if(c == '{') {
            stack.pop();
            if(stack.top() == '(' || stack.top() == '[') return false;
        }
        else if(c == '[') {
            stack.pop();
            if(stack.top() == '(') return false;
        }
        else if(c == '(') {
            stack.pop();
        }
    }

    return stack.empty();
}

int main() {
    string s;
    cout << "Nhập chuỗi đóng mở ngoặc: ";
    cin >> s;

    if (isValidExpression(s) && isCorrectOrder(s)) {
        cout << "VALID" << endl;
    } else {
        cout << "INVALID" << endl;
    }

    return 0;
}