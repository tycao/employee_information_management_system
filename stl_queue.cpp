#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool existOrNot(int, queue<int>);

int main()
{
/*
    queue<int> myQueue;
    myQueue.push(5);
    myQueue.push(6);
    myQueue.push(7);
    myQueue.push(8);
    myQueue.pop();

    cout << myQueue.front() << endl;
    cout << myQueue.back() << endl;
    cout << myQueue.size() << endl;
    cout << myQueue.empty() << endl;
*/
    queue<int> memQueue;
    int page[] = {4, 3, 2, 1, 4, 3, 5, 4, 3, 2, 1, 5};
    int times = 12;
    int tmpValue;
    for (int i = 0; i != 12; ++i)
    {
        if (memQueue.size() < 3)
            memQueue.push(page[i]);
        else
        {
            if (existOrNot(page[i], memQueue))
                times--;
            else
            {
                memQueue.pop();
                memQueue.push(page[i]);
            }
        }
        int size = memQueue.size();
        while (size > 0)
        {
            cout << memQueue.front() << " ";
            tmpValue = memQueue.front();
            memQueue.pop();
            memQueue.push(tmpValue);
            size--;
        }
        cout << endl;
    }
    cout << "使用FIFO策略时，共发生缺页中断" << times << "次。" << endl;
    return 0;
}


bool existOrNot(int num, queue<int> myQueue)
{
    while (!myQueue.empty())
    {
        if (myQueue.front() == num)
            return true;
        else
            myQueue.pop();
    }
    return false;
}
