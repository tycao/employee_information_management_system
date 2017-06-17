#include <iostream>

using namespace std;

template<typename T> class ListNode
{
public:
    ListNode() : link(nullptr) {}
    ListNode(T value) : link(nullptr), data(value) { }
    ~ListNode(){}
    void SetLink(ListNode<T>* next);
    ListNode<T>* GetLink(void);
    T& GetData(void);
private:
    T data;
    ListNode<T>* link;
};
template<typename T> void ListNode<T>::SetLink(ListNode<T>* next) { this->link = next; }
template<typename T> ListNode<T>* ListNode<T>::GetLink(void) { return this->link; }
template<typename T> T& ListNode<T>::GetData(void) { return this->data; }

template<typename T> class List
{
public:
    List();
    ~List() { }
    bool AddTail (T value);
    bool RemoveTail();
    bool InsertAt(int, T);
    bool RemoveAt(int);
    T& GetAt(int);
    bool IsEmpty();
    int GetCount();
    void RemoveAll();
    ListNode<T>* GetHead();
    ListNode<T>* GetTail();
    void SetTail(ListNode<T>* newtail);
    ListNode<T>* GetNodeAt(int index);
private:
    ListNode<T>* head;
    ListNode<T>* tail;
};

template<typename T> List<T>::List()    //创建表头节点，并初始化head和tail
{
    head = tail = new ListNode<T>;
    head->SetLink(nullptr); //表头节点中存储的指针置为nullptr（空指针）
}

template<typename T> bool List<T>::AddTail(T value) //向表位添加新节点
{
    ListNode<T>* add = new ListNode<T>(value);
    tail->SetLink(add);
    tail = tail->GetLink();
    if (tail != nullptr)
        return true;
    else
        return false;
}

template<typename T> bool List<T>::RemoveTail() //删除表尾节点
{
    return RemoveAt( this->GetCount() - 1 );
}

template<class T> bool List<T>::InsertAt(int index, T value) //在指定索引的节点前插入一个新节点
{
    if (index > GetCount() - 1 || index < 0)
    {
        cout << "A wrong position...." << endl;
        return false;
    }
    ListNode<T>* current = head;
    while (index)
    {
        --index;
        current = current->GetLink();
    }
    ListNode<T>* add = new ListNode<T>(value);
    add->SetLink(current->GetLink());
    current->SetLink(add);
    if (current->GetLink() != nullptr)
        return true;
    else
        return false;
}

template<class T> bool List<T>::RemoveAt(int index) //按照索引值删除节点
{
    if (index > this->GetCount() - 1 or index < 0)
    {
        cout << "A wrong position..." << endl;
        return false;
    }
    ListNode<T> *cur, *curPre;
    cur = head;
    curPre = cur->GetLink();
    while (index)
    {
        cur = cur->GetLink();
        curPre = curPre->GetLink();
        --index;
    }
    if (tail == curPre)
        tail = cur;
    cur->SetLink(curPre->GetLink());
    if (curPre != nullptr)
        return true;
    else
        return false;
}

template<class T> T& List<T>::GetAt(int index)
{
    if (index > this->GetCount() - 1 || index < 0)
        cout << "A wrong position..." << endl;
    ListNode<T>* current = head->GetLink();
    while (index)
    {
        --index;
        current = current->GetLink();
    }
    return current->GetData();
}

template<class T> bool List<T>::IsEmpty()
{
    return head->GetLink() == nullptr;
}
template<class T> int List<T>::GetCount()   //返回链表中的节点个数
{
    int count = 0;
    ListNode<T>* cur = head->GetLink();
    while (cur != nullptr)
    {
        ++count;
        cur = cur->GetLink();
    }
    return count;
}

template<class T> void List<T>::RemoveAll()
{
    ListNode<T>* cur;
    while (head->GetLink() != nullptr)
    {
        cur = head->GetLink();
        head->SetLink(cur->GetLink());
        delete cur;
    }
    tail = head;
}
template<class T> ListNode<T>* List<T>::GetHead()   //获得头指针
{
    return this->head;
}
template<class T> ListNode<T>* List<T>::GetTail()   //获得尾指针
{
    return this->tail;
}
template<class T> void List<T>::SetTail(ListNode<T>* newtail)   //改变尾指针的指向
{
    tail = newtail;
}
template<class T> ListNode<T>* List<T>::GetNodeAt(int index)    //返回索引值为index的节点指针
{
    if (index > this->GetCount() - 1 || index < 0)
    {
        cout << "A wrong position...." << endl;
        return false;
    }
    ListNode<T>* cur = head->GetLink();
    while (index)
    {
        cur = cur->GetLink();
        --index;
    }
    return cur;
}

int main()
{
    //创建两个链表
    List<int> listFirst;
    List<int> listSecond;
    //初始化链表listFirst
    listFirst.AddTail(1);
    listFirst.AddTail(6);
    listFirst.AddTail(8);
    listFirst.AddTail(9);
    listFirst.AddTail(13);
    //初始化链表listSecond
    listSecond.AddTail(0);
    listSecond.AddTail(3);
    listSecond.AddTail(4);
    listSecond.AddTail(6);
    listSecond.AddTail(11);
    listSecond.AddTail(17);

    cout << "listFirst : ";
    for (int i = 0; i != listFirst.GetCount(); ++i)
        cout << listFirst.GetAt(i) << " ";
    cout << endl;

    cout << "listSecond : ";
    for (int i = 0; i != listSecond.GetCount(); ++i)
        cout << listSecond.GetAt(i) << " ";
    cout << endl;
    while (listSecond.GetCount() != 0)
    {
        int indexFirst = 0;
        while (listSecond.GetAt(0) > listFirst.GetAt(indexFirst))
        {
            ++indexFirst;
            if (indexFirst == listFirst.GetCount())
                break;
        }
        if (indexFirst == listFirst.GetCount())
        {
            listFirst.AddTail(listSecond.GetAt(0));
            listSecond.RemoveAt(0);
        }
        else
        {
            listFirst.InsertAt(indexFirst, listSecond.GetAt(0));
            listSecond.RemoveAt(0);
        }
    }

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\nlistFirst : ";
    for (int i = 0; i != listFirst.GetCount(); ++i)
        cout << listFirst.GetAt(i) << " ";
    cout << endl;

    cout << "listSecond : ";
    for (int i = 0; i != listSecond.GetCount(); ++i)
        cout << listSecond.GetAt(i) << " ";
    cout << endl;

    return 0;
}
