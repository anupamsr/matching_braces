#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

bool isMatching(const string & _str)
{
    stack<char> st;
    vector<char> braces{'{', '[', '(',
                        '}', ']', ')'};
    for (const auto & c : _str)
    {
        auto it = find(braces.begin(), braces.end(), c);
        if (it != braces.end())
        {
            size_t i = it - braces.begin();
            if(i >= braces.size() / 2)
            {
                if (st.size() == 0 || st.top() != braces[i - braces.size() / 2])
                {
                    return false;
                }
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
    }
    return st.size() == 0;
}

void print(const string & _str)
{
    cout << "'" << _str << "' is ";
    if (! isMatching(_str))
    {
        cout << "not ";
    }
    cout << "having matching braces." << endl;
}

int main()
{
    print("");
    print("(()(a)aa()a{aa}{a}[]aa[aa]aa)");
    print("a({a}a)");
    print("(a{[a]}a)");
    print("a[({a}a[])]");
    print("[a({a[}a])]");
    print("a({[a}a])");
    print("[a]({a}a)");
    print("(");
    print("]");
    print("({)}");
    print("}");
    print("}{");
    return 0;
}
