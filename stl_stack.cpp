#include <iostream>
#include <string>
#include <stack>
#include <fstream>
using namespace std;

int main()
{
/*
    stack<int> MyStack;
    MyStack.push(5);
    MyStack.push(6);
    MyStack.push(7);
    MyStack.pop();
    MyStack.pop();
    cout << MyStack.top() << endl;
    cout << MyStack.size() <<endl;
    cout << MyStack.empty() <<endl;
*/
    try
    {
        ifstream in("d:/aa.txt");
        stack<string> s;
        string line;
        while (getline(in, line))
            s.push(line);
        in.close();
        while (!s.empty())
        {
            cout << s.top() << endl;
            s.pop();
        }
    }
    catch(std::runtime_error& e)
    {
        cout << "oops....file not open!" << e.what() << endl;
    }
    catch(std::exception& e)
    {
        cout << "oops....file not open!" << e.what() << endl;
    }
    catch(...)
    {
        cout << "oops....file not open!" << endl;
    }

    return 0;
}
