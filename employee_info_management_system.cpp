/*
职工信息管理系统：
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
#include <iostream>
#include <string>
#include <fstream>


using namespace std;


class Staff
{
public:
    Staff():next(NULL){}
    void registration(Staff* head);//注册 尾插
    void query_name(Staff* t);//按照姓名查询员工信息
    void query_depart(Staff* t);//按照部门查询员工信息
    void delete_num(Staff* t);//按工号删除员工信息
    void delete_name(Staff* t);//按姓名删除员工信息
    void show_all(Staff* head);//展示所有员工信息
    void update(Staff* head);
    void update_num(Staff* head);//修改工号
    void update_name(Staff* head);//修改姓名
    void update_age(Staff* head);//修改年龄
    void update_sex(Staff* head);//修改性别
    void update_zip(Staff* head);//修改邮编
    void update_depart(Staff* head);//修改部门
    void update_wage(Staff* head);//修改工资
    void update_all(Staff* head);//修改全部
    void sort_up(Staff* head);//按工资升序排列
    void sort_down(Staff* head);//按工资降序排列
    int read(Staff* head);
    void write(Staff* t);
private:
    string employee_number;//职工号
    string name;//姓名
    int age;//年龄
    string sex;//性别
    string zip_code;//邮编
    string department;//部门
    int wage;//工资
    Staff* next = 0;
};


void Staff::registration(Staff* head)
{
    while(head->next != NULL)
    {
        head = head->next;
    }
    Staff* newnode = new Staff;
    head->next = newnode;
    newnode->next = NULL;
    cout << "请输入员工信息" << endl;
    cout << "职工号: " << endl;
    cin >> newnode->employee_number;
    cout << "职工姓名: " << endl;
    cin >> newnode->name;
    cout << "职工年龄: " << endl;
    cin >> newnode->age;
    cout << "职工性别: " << endl;
    cin >> newnode->sex;
    cout << "职工邮编: " << endl;
    cin >> newnode->zip_code;
    cout << "职工部门: " << endl;
    cin >> newnode->department;
    cout << "职工工资: " << endl;
    cin >> newnode->wage;
}
void Staff::show_all(Staff* head)
{
    int i = 0;
    while(head->next != NULL)
    {
        i++;
        cout << i << "." << "工号：" ;
        cout << head->next->employee_number <<'\t';


        cout << "名字：";
        cout << head->next->name <<'\t';


        cout << "性别：" ;
        cout << head->next->sex <<'\t';


        cout << "年龄：" ;
        cout <<  head->next->age <<'\t';


        cout << "邮编：" ;
        cout << head->next->zip_code << '\t';


        cout << "部门：";
        cout << head->next->department << '\t';


        cout << "工资：" ;
        cout << head->next->wage << endl;
        head = head->next;
    }
}
void Staff::query_name(Staff* t)
{
    string n;
    cout << "请输入你想查询职工姓名:" << endl;
    cin >> n;
    int count = 0;
    while(t->next != NULL)
    {
        if(t->next->name == n)
        {
            cout << "工号：" ;
            cout << t->next->employee_number <<'\t';


            cout << "名字：";
            cout << t->next->name <<'\t';


            cout << "性别：" ;
            cout << t->next->sex <<'\t';


            cout << "年龄：" ;
            cout <<  t->next->age <<'\t';


            cout << "邮编：" ;
            cout << t->next->zip_code << '\t';


            cout << "部门：";
            cout << t->next->department << '\t';


            cout << "工资：" ;
            cout << t->next->wage << endl;
            count++;
        }
        t = t->next;
    }
    if(count == 0)
    {
        cout << "查无此人！" << endl;
    }
}
void Staff::query_depart(Staff* t)
{
    string n;
    cout << "请输入你想查询职工部门:" << endl;
    cin >> n;
    int count = 0;
    while(t->next != NULL)
    {
        if(t->next->department == n)
        {
            cout << "工号：" ;
            cout << t->next->employee_number <<'\t';


            cout << "名字：";
            cout << t->next->name <<'\t';


            cout << "性别：" ;
            cout << t->next->sex <<'\t';


            cout << "年龄：" ;
            cout <<  t->next->age <<'\t';


            cout << "邮编：" ;
            cout << t->next->zip_code << '\t';


            cout << "部门：";
            cout << t->next->department << '\t';


            cout << "工资：" ;
            cout << t->next->wage << endl;
            count++;
        }
        t = t->next;
    }
    if(count == 0)
    {
        cout << "查无此人！" << endl;
    }
}
void Staff::delete_num(Staff* t)
{
    string n;
    cout << "请输入你想删除职工号:" << endl;
    cin >> n;
    int count = 0;
    while(t->next != NULL)
    {
        if(t->next->employee_number == n)
        {
            Staff* temp = t->next;
            t->next = t->next->next;
            delete temp;
            temp = NULL;
            cout << "删除成功！" << endl;
            count++;
            break;
        }
        t = t->next;
    }
    if(count == 0)
    {
        cout << "查无此人！" << endl;
    }
}
void Staff::delete_name(class Staff* t)
{
    string n;
    cout << "请输入你想删除职工的姓名:" << endl;
    cin >> n;
    int count = 0;
    while(t->next != NULL)
    {
        if(t->next->name == n)
        {
        Staff* temp = t->next;
        t->next = t->next->next;
        delete temp;
        temp = NULL;
        cout << "删除成功！" << endl;
        count++;
        break;
        }
        t = t->next;
    }
    if(count == 0)
    {
        cout << "查无此人！" << endl;
    }
}
void Staff::update(class Staff* head)
{
    int num = 0;
    cout << "1.修改员工号" << endl;
    cout << "2.修改员工姓名" << endl;
    cout << "3.修改员工年龄" << endl;
    cout << "4.修改员工性别" << endl;
    cout << "5.修改员工邮编" << endl;
    cout << "6.修改员工部门" << endl;
    cout << "7.修改员工工资" << endl;
    cout << "8.修改全部" << endl;
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
        cout << "请重新输入正确的指令！" << endl;
    }
}
void Staff::update_num(Staff* head)
{
    cout << "输入要修改对象的工号："<< endl;
    int count = 0;
    string temp;
    cin >> temp;
    while(head->next != NULL)
    {
        if(temp == head->next->employee_number)
        {
        count = 1;
        cout<< "输入新工号："<< endl;
        string temp2;
        cin>>temp2;
        head->next->employee_number = temp2;
        cout << "修改成功" << endl;
        break;
        }
        head = head->next;
    }
    if(count == 0)
    {
        cout << "查无此人" << endl;
    }
}
void Staff::update_name(Staff* head)
{
    cout << "输入要修改对象的工号："<< endl;
    int count = 0;
    string temp;
    cin >> temp;
    while(head->next != NULL)
    {
        if(temp == head->next->employee_number)
        {
        count = 1;
        cout << "输入新名字："<< endl;
        string temp2;
        cin >> temp2;
        head->next->name = temp2;
        cout << "修改成功" << endl;
        break;
        }
        head = head->next;
    }
    if(count == 0)
    {
        cout << "查无此人" << endl;
    }
}
void Staff::update_age(Staff* head)
{
    cout << "输入要修改对象的工号："<< endl;
    int count = 0;
    string temp;
    cin >> temp;
    while(head->next != NULL)
    {
        if(temp == head->next->employee_number)
        {
        count = 1;
        cout << "输入新年龄："<< endl;
        int temp2;
        cin >> temp2;
        head->next->age = temp2;
        cout << "修改成功" << endl;
        break;
        }
        head = head->next;
    }
    if(count == 0)
    {
        cout << "查无此人" << endl;
    }
}
void Staff::update_sex(Staff* head)
{
    cout << "输入要修改对象的工号："<< endl;
    int count = 0;
    string temp;
    cin >> temp;
    while(head->next != NULL)
    {
        if(temp == head->next->employee_number)
        {
        count = 1;
        cout << "输入新性别："<< endl;
        string temp2;
        cin >> temp2;
        head->next->sex = temp2;
        cout << "修改成功" << endl;
        break;
        }
        head = head->next;
    }
    if(count == 0)
    {
        cout << "查无此人" << endl;
    }
}
void Staff::update_zip(Staff* head)
{
    cout << "输入要修改对象的工号："<< endl;
    int count = 0;
    string temp;
    cin >> temp;
    while(head->next != NULL)
    {
        if(temp == head->next->employee_number)
        {
        count = 1;
        cout << "输入新邮编："<< endl;
        string temp2;
        cin >> temp2;
        head->next->zip_code = temp2;
        cout << "修改成功" << endl;
        break;
        }
        head = head->next;
    }
    if(count == 0)
    {
        cout << "查无此人" << endl;
    }
}
void Staff::update_depart(Staff* head)
{
    cout << "输入要修改对象的工号："<< endl;
    int count = 0;
    string temp;
    cin >> temp;
    while(head->next != NULL)
    {
        if(temp == head->next->employee_number)
        {
        count = 1;
        cout << "输入新部门："<< endl;
        string temp2;
        cin >> temp2;
        head->next->department = temp2;
        cout << "修改成功" << endl;
        break;
        }
        head = head->next;
    }
    if(count == 0)
    {
        cout << "查无此人" << endl;
    }
}
void Staff::update_wage(Staff* head)
{
    cout << "输入要修改对象的工号："<< endl;
    int count = 0;
    string temp;
    cin >> temp;
    while(head->next != NULL)
    {
        if(temp == head->next->employee_number)
        {
            count = 1;
            cout << "输入新工资："<< endl;
            int temp2;
            cin >> temp2;
            head->next->wage = temp2;
            cout << "修改成功" << endl;
            break;
        }
        head = head->next;
    }
    if(count == 0)
    {
        cout << "查无此人" << endl;
    }
}
void Staff::update_all(Staff* head)
{
    cout<<"输入要修改对象的工号："<<flush;
    int count = 0;
    string tmp;
    cin >> tmp;
    while(head->next != NULL)
    {
        if(tmp == head->next->employee_number)
        {
            count = 1;
            cout << "输入新工号："<< endl;
            string temp;
            int tmp;
            cin >> temp;
            head->next->employee_number = temp;


            cout<< "输入新名字："<< endl;
            cin >> temp;
            head->next->name = temp;


            cout<< "输入新性别："<< endl;
            cin >> temp;
            head->next->sex = temp;


            cout<< "输入新年龄："<< endl;
            cin >> tmp;
            head->next->age = tmp;


            cout<< "输入新邮编："<< endl;
            cin >> temp;
            head->next->zip_code = temp;


            cout<< "输入新部门："<< endl;
            cin >> temp;
            head->next->department = temp;


            cout<< "输入新工资："<< endl;
            cin >> tmp;
            head->next->wage = tmp;
            cout << "修改成功" << endl;
            break;
        }
        head = head->next;
    }
    if(count == 0)
    {
    cout << "查无此人" << endl;
    }
}
void Staff::sort_up(Staff* head)
{
    while(head->next != NULL)
    {
        Staff* temp = head->next;
        while(temp->next != NULL)
        {
            if(head->next->wage > temp->next->wage)
            {
                int a;
                string b;
                a = head->next->wage;
                head->next->wage = temp->next->wage;
                temp->next->wage = a;
                b = head->next->employee_number;
                head->next->employee_number = temp->next->employee_number;
                temp->next->employee_number = b;
                b = head->next->name;
                head->next->name = temp->next->name;
                temp->next->name = b;
                b = head->next->sex;
                head->next->sex = temp->next->sex;
                temp->next->sex = b;
                a = head->next->age;
                head->next->age = temp->next->age;
                temp->next->age = a;
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
    while(head->next != NULL)
    {
        Staff* temp = head->next;
        while(temp->next != NULL)
        {
            if(head->next->wage < temp->next->wage)
            {
                int a;
                string b;
                a = head->next->wage;
                head->next->wage = temp->next->wage;
                temp->next->wage = a;
                b = head->next->employee_number;
                head->next->employee_number = temp->next->employee_number;
                temp->next->employee_number = b;
                b = head->next->name;
                head->next->name = temp->next->name;
                temp->next->name = b;
                b = head->next->sex;
                head->next->sex = temp->next->sex;
                temp->next->sex = b;
                a = head->next->age;
                head->next->age = temp->next->age;
                temp->next->age = a;
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
int Staff::read(Staff* head)
{
    ifstream infile("职工系统.txt");
    while(!infile.eof())
    {
        Staff* newnode = new Staff;
        infile >> newnode->employee_number;
        if(newnode->employee_number.length() == 0)
        {
            delete newnode;
            break;
        }
        infile >> newnode->name;
        infile >> newnode->sex;
        infile >> newnode->age;
        infile >> newnode->zip_code;
        infile >> newnode->department;
        infile >> newnode->wage;
        head->next = newnode;
        head = head->next;
    }
    infile.close();

    return 0;
}
void Staff::write(Staff* t)
{
    ofstream outfile("职工系统.txt");
    while(t->next != NULL)
    {
    outfile << t->next->employee_number <<'\t';
    outfile << t->next->name << '\t';
    outfile << t->next->sex << '\t';
    outfile << t->next->age << '\t';
    outfile << t->next->zip_code << '\t';
    outfile << t->next->department << '\t';
    outfile << t->next->wage << endl;
    t = t->next;
    }
    outfile.close();
}
int main()
{
    Staff* head = new Staff;
    head->read(head);
    string temp;
    cout << "欢迎来到Coder职工系统!" << endl;
    while(1)
    {
        cout << "------------------------------------" << endl;
        //head->show_all(head);
        cout << "------------------------------------" << endl;
        cout << endl;

        cout << "1.注册员工信息" << endl;
        cout << "2.按照姓名查询员工信息" << endl;
        cout << "3.按照部门查询员工信息" << endl;
        cout << "4.按工号删除员工信息" << endl;
        cout << "5.按姓名删除员工信息" << endl;
        cout << "6.按工资升序排列" << endl;
        cout << "7.按工资降序排列" << endl;
        cout << "8.修改员工信息" << endl;
        cout << "0.退出" << endl;
        cout << endl;
        cout << "请输入你想选择的功能：" << endl;
        int number;
        cin >> number;
        switch(number)
        {
        case 1:
        {
        head->registration(head);
        break;
        }
        case 2:
        {
        head->query_name(head);
        break;
        }
        case 3:
        {
        head->query_depart(head);
        break;
        }
        case 4 :
        {
        head->delete_num(head);
        break;
        }
        case 5:
        {
        head->delete_name(head);
        break;
        }
        case 6:
        {
        head->sort_up(head);
        head->show_all(head);
        break;
        }
        case 7:
        {
        head->sort_down(head);
        head->show_all(head);
        break;
        }
        case 8:
        {
        head->update(head);
        break;
        }
        case 0:
        {
        head->write(head);
        return 0;
        }
        default: cout << "请重新输入正确的操作指令" << endl;
        }
    }
}
