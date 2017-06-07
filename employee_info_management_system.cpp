#include <iostream>
#include <string>
#include <fstream>
using namespace std;



/*
员工信息管理系统：
1. 存在一个数据文件，用来存储职工各种信息：职工号，姓名，年龄，性别，邮编，部门，工资
2. 可以注册新职工；
3. 允许修改职工信息
4. 允许删除职工信息；
5，按照按照姓名和部门查询职工信息；
6. 可以按照工资多少进行排名，
7. 可以浏览所有职工信息；
8.有一个主界面，供选择和调用上述选项。
9.用C++中，文件和链表实现
*/
class Staff
{
public:
    Staff() : next(nullptr){}   //默认构造函数
    void registration(Staff*);  // 添加新员工信息
    void query_name(Staff*);    //按照员工姓名查找该员工信息
    void query_depart(Staff*);  //按照部门查找员工信息
    void delete_num(Staff*);    //按照工号删除员工信息
    void delete_name(Staff*);   //按照姓名删除员工信息
    void show_all(Staff*);  //展示所有员工信息
    void update(Staff*);    //更新
    void update_num(Staff*);    //修改员工工号
    void update_name(Staff*);   //修改姓名
    void update_age(Staff*);
    void update_sex(Staff*);
    void update_zip(Staff*);
    void update_depart(Staff*);
    void update_wage(Staff*);
    void update_all(Staff*);
    void sort_up(Staff*);
    void sort_down(Staff*);
    void read(Staff*);
    void write(Staff*);

private:
    string employee_number;
    string name;
    string sex;
    string zip_code;
    string department;
    int age;
    int wage;
    Staff* next = 0;
};

void Staff::registration(Staff* head)
{
    while(head->next != nullptr)
        head = head->next;
    Staff* newnode = new Staff;
    head->next = newnode;
    newnode->next = nullptr;
    cout << "请输入员工信息：" << endl;

    cout << "员工号：" << endl;
    cin >> newnode->employee_number;

    cout << "员工姓名：" << endl;
    cin >> newnode->name;

    cout << "员工性别：" << endl;
    cin >> newnode->sex;

    cout << "员工邮编：" << endl;
    cin >> newnode->zip_code;

    cout << "员工所在部门：" <<endl;
    cin >> newnode->department;

    cout << "员工年龄：" << endl;
    cin >> newnode->age;

    cout << "员工薪资：" << endl;
    cin >> newnode->wage;

}

void Staff::show_all(Staff* head)
{
    int i = 0;
    while (head->next != nullptr)
    {
        ++i;
        cout << i << "." << "工号：";
        cout << head->next->employee_number << "\t";

        cout << "姓名：";
        cout << head->next->name << "\t";

        cout << "性别：";
        cout << head->next->sex << "\t";

        cout << "邮编：";
        cout << head->next->zip_code << "\t";

        cout << "部门：";
        cout << head->next->department << "\t";

        cout << "年龄：";
        cout << head->next->age << "\t";

        cout << "薪资：";
        cout << head->next->wage << "\t" << endl;

        head = head->next;
    }
}

void Staff::query_name(Staff* head)
{
    string n;
    cout << "请输入你想查询的员工姓名：" << endl;
    cin >> n;
    int count = 0;
    while (head->next != nullptr)
    {
        if (head->next->name == n)
        {
            ++count;
            cout << "工号：";
            cout << head->next->employee_number << "\t";

            cout << "姓名：";
            cout << head->next->name << "\t";

            cout << "性别：";
            cout << head->next->sex << "\t";

            cout << "编码：";
            cout << head->next->zip_code << "\t";

            cout << "部门：";
            cout << head->next->department << "\t";

            cout << "年龄：";
            cout << head->next->age << "\t";

            cout << "薪资：";
            cout << head->next->wage << "\t" << endl;
        }
        head = head->next;
    }
    if (count == 0)
        cout << "该员工不存在！" << endl;
}

void Staff::query_depart(Staff* head)
{
    string n;
    cout << "请输入你想查询的员工所在的部门：" << endl;
    cin >> n;
    int count = 0;
    while (head->next != nullptr)
    {
        if (head->next->department == n)
        {
            ++count;
            cout << "工号：" ;
            cout << head->next->employee_number << "\t";

            cout << "姓名：" ;
            cout << head->next->name << "\t";

            cout << "性别：" ;
            cout << head->next->sex << "\t";

            cout << "编码：" ;
            cout << head->next->zip_code << "\t";

            cout << "部门：" ;
            cout << head->next->department << "\t";

            cout << "年龄：" ;
            cout << head->next->age << "\t";

            cout << "薪资：" ;
            cout << head->next->wage << "\t" << endl;
        }
        head = head->next;
    }
    if (count == 0)
        cout << "该员工不存在！" << endl;
}

void Staff::delete_num(Staff* head)
{
    string n;
    cout << "请输入把你想删除的员工的工号：" << endl;
    cin >> n;
    int count = 0;
    while (head->next != nullptr)
    {
        if (head->next->employee_number == n)
        {
            ++count;
            Staff *temp = head->next;
            head->next = head->next->next;
            delete temp;
            temp = nullptr;
            cout << "删除成功！" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
        cout << "该员工不存在！" << endl;
}

void Staff::delete_name(Staff* head)
{
    string n;
    cout << "请输入你想删除的员工的姓名：" << endl;
    cin >> n;
    int count = 0;
    while (head->next != nullptr)
    {
        if (head->next->name == n)
        {
            ++count;
            Staff* temp = head->next;
            head->next = head->next->next;
            delete temp;
            temp = 0;
            cout << "删除成功！" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
        cout << "该员工不存在！" << endl;
}

void Staff::update(Staff* head)
{
    int num = 0;
    cout << "1. 修改员工号" << endl;
    cout << "2. 修改员工姓名" << endl;
    cout << "3. 修改员工年龄" << endl;
    cout << "4. 修改员工性别" << endl;
    cout << "5. 修改员工邮编" << endl;
    cout << "6. 修改员工部门" << endl;
    cout << "7. 修改员工薪资" << endl;
    cout << "8. 修改全部" << endl;

    cin >> num;
    switch(num)
    {
    case 1:
        update_num(head);
        break;
    case 2:
        update_name(head);
        break;
    case 3:
        update_age(head);
        break;
    case 4:
        update_sex(head);
        break;
    case 5:
        update_zip(head);
        break;
    case 6:
        update_depart(head);
        break;
    case 7:
        update_wage(head);
        break;
    case 8:
        update_all(head);
        break;
    default:
        cout << "输入有误！" << endl;
    }
}

void Staff::update_num(Staff* head)
{
    string n;
    cout << "请输入需要修改的员工的工号：" << endl;
    cin >> n;
    int count = 0;
    while (head->next != nullptr)
    {
        if (head->next->employee_number != n)
        {
            ++count;
            cout << "请输入新工号：" << endl;
            string nn;
            cin >> nn;
            head->next->employee_number = nn;
            cout << "修改成功" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
        cout << "该员工不存在！" << endl;
}

void Staff::update_name(Staff* head)
{
    string n;
    cout << "请输入要修改的员工名字：" << endl;
    cin >> n;
    int count = 0;
    while (head->next != nullptr)
    {
        if (head->next->name == n)
        {
            ++count;
            cout << "请输入新名字：" << endl;
            string nn;
            cin >> nn;
            head->next->name = nn;
            cout << "修改成功！" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
        cout << "该员工不存在！" << endl;
}

void Staff::update_age(Staff* head)
{
    string n;
    cout << "请输入需要修改的员工工号：" << endl;
    cin >> n;
    int count = 0;
    while (head->next != nullptr)
    {
        if (head->next->employee_number == n)
        {
            ++count;
            int nn;
            cout << "请输入新年龄：" << endl;
            cin >> nn;
            head->next->age = nn;
            cout << "修改成功！" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
        cout << "该用户不存在！" << endl;
}

void Staff::update_sex(Staff* head)
{
    string n;
    cout << "请输入需要修改的员工工号：" << endl;
    cin >> n;
    int count = 0;
    while (head->next != nullptr)
    {
        if (head->next->employee_number == n)
        {
            ++count;
            string nn;
            cout << "请输入新性别：" << endl;
            cin >> nn;
            head->next->sex = nn;
            cout << "修改成功！" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
        cout << "该用户不存在！" << endl;
}

void Staff::update_zip(Staff* head)
{
    string n;
    cout << "请输入需要修改的员工工号：" << endl;
    cin >> n;
    int count = 0;
    while (head->next != nullptr)
    {
        if (head->next->employee_number == n)
        {
            ++count;
            string nn;
            cout << "请输入新编码：" << endl;
            cin >> nn;
            head->next->zip_code= nn;
            cout << "修改成功！" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
        cout << "该用户不存在！" << endl;
}

void Staff::update_depart(Staff* head)
{
    string n;
    cout << "请输入需要修改的员工工号：" << endl;
    cin >> n;
    int count = 0;
    while (head->next != nullptr)
    {
        if (head->next->employee_number == n)
        {
            ++count;
            string nn;
            cout << "请输入新部门：" << endl;
            cin >> nn;
            head->next->department = nn;
            cout << "修改成功！" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
        cout << "该用户不存在！" << endl;
}

void Staff::update_wage(Staff* head)
{
    string n;
    cout << "请输入需要修改的员工工号：" << endl;
    cin >> n;
    int count = 0;
    while (head->next != nullptr)
    {
        if (head->next->employee_number == n)
        {
            ++count;
            int nn;
            cout << "请输入新薪资：" << endl;
            cin >> nn;
            head->next->wage = nn;
            cout << "修改成功！" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
        cout << "该用户不存在！" << endl;
}

void Staff::update_all(Staff* head)
{
    string n;
    cout << "请输入需要修改的员工工号：" << endl;
    cin >> n;
    int count = 0;
    while (head->next != nullptr)
    {
        if (head->next->employee_number == n)
        {
            ++count;
            string nn;
            int ii = 0;
            cout << "请输入新的员工工号：" << endl;
            cin >> nn;
            head->next->employee_number = nn;

            cout << "请输入新的员工姓名：" << endl;
            cin >> nn;
            head->next->name = nn;

            cout << "请输入新的性别：" << endl;
            cin >> nn;
            head->next->sex = nn;

            cout << "请输入新的年龄：" << endl;
            cin >> ii;
            head->next->age = ii;

            cout << "请输入新的部门：" << endl;
            cin >> nn;
            head->next->department = nn;

            cout << "请输入新的邮编：" << endl;
            cin >> nn;
            head->next->zip_code = nn;

            cout << "请输入新的薪资：" << endl;
            cin >> ii;
            head->next->wage = ii;

            cout << "修改成功！" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
        cout << "该员工不存在！" << endl;
}

void Staff::sort_up(Staff* head)
{
    while (head->next != nullptr)
    {
        Staff* temp = head->next;
        while (temp->next != nullptr)
        {
            if (head->next->wage > temp->next->wage)
            {
                int a;
                string b;
                a = head->next->wage;
                head->next->wage = temp->next->wage;
                temp->next->wage = a;

                a = head->next->age;
                head->next->age = temp->next->age;
                temp->next->age = a;

                b = head->next->employee_number;
                head->next->employee_number = temp->next->employee_number;
                temp->next->employee_number = b;

                b = head->next->name;
                head->next->name = temp->next->name;
                temp->next->name = b;

                b = head->next->sex;
                head->next->sex = temp->next->sex;
                temp->next->sex = b;

                b = head->next->zip_code;
                head->next->zip_code = temp->next->zip_code;
                temp->next->zip_code = b;

                b = head->next->department;
                head->next->department = temp->next->department;
                temp->next->department = b;
            }
            temp = temp->next;
        }
        head = head->next;
    }
}


void Staff::sort_down(Staff* head)
{
    while (head->next != nullptr)
    {
        Staff* temp = head->next;
        while (temp->next != nullptr)
        {
            if (head->next->wage < temp->next->wage)
            {
                int a;
                string b;
                a = head->next->wage;
                head->next->wage = temp->next->wage;
                temp->next->wage = a;

                a = head->next->age;
                head->next->age = temp->next->age;
                temp->next->age = a;

                b = head->next->employee_number;
                head->next->employee_number = temp->next->employee_number;
                temp->next->employee_number = b;

                b = head->next->name;
                head->next->name = temp->next->name;
                temp->next->name = b;

                b = head->next->sex;
                head->next->sex = temp->next->sex;
                temp->next->sex = b;

                b = head->next->zip_code;
                head->next->zip_code = temp->next->zip_code;
                temp->next->zip_code = b;

                b = head->next->department;
                head->next->department = temp->next->department;
                temp->next->department = b;
            }
            temp = temp->next;
        }
        head = head->next;
    }
}
void Staff::read(Staff* head)
{
    try
    {
        ifstream in("employee_info.txt");
        while (!in.eof())
        {
            Staff* newnode = new Staff;
            in >> newnode->employee_number;
            if (newnode->employee_number.length() == 0)
            {
                delete newnode;
                break;
            }
            in >> newnode->name
                >> newnode->sex
                >> newnode->age
                >> newnode->zip_code
                >> newnode->department
                >> newnode->wage;
            head->next = newnode;
            head = head->next;
        }
        in.close();
    }
    catch(std::exception& e)
    {
        cout << e.what() << endl;
    }
}

void Staff::write(Staff* head)
{
    try
    {
        ofstream on("employee_info.txt");
        while (head->next != nullptr)
        {
            on << head->next->employee_number << "\t"
                << head->next->name << "\t"
                << head->next->sex << "\t"
                << head->next->age << "\t"
                << head->next->zip_code << "\t"
                << head->next->department << "\t"
                << head->next->wage << "\t" << endl;
            head = head->next;
        }
        on.close();
    }
    catch(std::exception& e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    Staff* head = new Staff;
    head->read(head);
    string str;
    cout << "欢迎来到员工信息管理系统~" << endl;
    while (true)
    {
        cout << "-------------------------" << endl;
        head->show_all(head);
        cout << "-------------------------" << endl;
        cout << "1. 注册员工信息：" << endl;
        cout << "2. 按照姓名查询员工信息" << endl;
        cout << "3. 按照部门查询员工信息" << endl;
        cout << "4. 按工号删除员工信息" << endl;
        cout << "5. 按姓名删除员工信息" << endl;
        cout << "6. 按工资升序排列" << endl;
        cout << "7. 按工资降序排列" << endl;
        cout << "8. 修改员工信息" << endl;
        cout << "0. 退出" << endl;
        cout << endl;
        int n;
        cout << "请输入选择的功能：" << endl;
        cin >> n;
        switch(n)
        {
        case 1:
            head->registration(head);
            break;
        case 2:
            head->query_name(head);
            break;
        case 3:
            head->query_depart(head);
            break;
        case 4:
            head->delete_num(head);
            break;
        case 5:
            head->delete_name(head);
            break;
        case 6:
            head->sort_up(head);
            break;
        case 7:
            head->sort_down(head);
            break;
        case 8:
            head->update(head);
            break;
        case 0:
            head->write(head);
            return 0;
        default:
            cout << "输入有误。请重新输入！" << endl;
        }
    }
    return 0;
}
