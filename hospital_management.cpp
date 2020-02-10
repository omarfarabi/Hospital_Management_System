#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

///Global variables...

int i,j,count=0;

///Functions declarations...
void process();
void menu();
void create();
void showAll();
void search();
void del();
void update();
void short_details();
void doctor_list();
void print_bills();

/// Classes

class Doctors
{
protected:
    string dname;
    string time;
    double visit;
public:

    Doctors():dname("n/a"),time("n/a"),visit(0.0) {}
    ~Doctors() {}
    void read()
    {
        cout<<"  Doctor name: ";
        cin>>dname;
        cout<<"  Time: ";
        cin>>time;
        cout<<"  Doctors visit: ";
        cin>>visit;
    }
    void show()
    {
        cout<<"  Doctor name: "<<dname<<endl;
        cout<<"  Time: "<<time<<endl;
        cout<<"  Visit: "<<visit<<endl;
    }
    double getvisit()
    {
        return visit;
    }
};
//class Medicine
//{
//protected:
//    string mname;
//    double mprice;
//public:
//    Medicine
//};

class Test:virtual public Doctors
{
protected:

    string tname;
    double cost;
public:

    Test():tname("n/a"),cost(0.0) {}
    ~Test() {}
    void read()
    {
        cout<<"  Lab-Test name: ";
        cin>>tname;
        cout<<"  Lab-Cost: ";
        cin>>cost;
    }
    void show()
    {
        cout<<"  Lab-Test name: "<<tname<<endl;
        cout<<"  Lab-Test Cost: "<<cost<<endl;

    }
    double getcost()
    {
        return cost;
    }
};


class Patient: virtual public Test
{
private:
    int id;
    string name1;
    string name2;
    string sex;
    string birth;
    string address;
    string blood;
    string problem;
    string tel;
    string nation;
public:
    Patient():id(0),name1("n/a"),name2("n/a"),sex("n/a"),birth("n/a"),
        address("n/a"),blood("n/a"),problem("n/a"),tel("n/a"),nation("n/a") {}
    ~Patient() {}
    int getid()
    {
        return id;
    }
    string getname1()
    {
        return name1;
    }
    string getname2()
    {
        return name2;
    }
    string getproblem()
    {
        return problem;
    }
    string gettel()
    {
        return tel;
    }

    void read()
    {
        cout<<endl<<"         ***<<< Enter the patient details... >>>***"<<endl<<endl;
        cout<<"  ID: ";
        cin>>id;
        cout<<"  1st Name: ";
        cin>>name1;
        cout<<"  Last Name: ";
        cin>>name2;
        cout<<"  Sex: ";
        cin>>sex;
        cout<<"  Birthday(day/month/year): ";
        cin>>birth;
        cout<<"  Address: ";
        cin>>address;
        cout<<"  Blood group: ";
        cin>>blood;
        cout<<"  Problem: ";
        cin>>problem;
        cout<<"  Tel: ";
        cin>>tel;
        cout<<"  Nationality: ";
        cin>>nation;
        Doctors::read();
        Test::read();
        cout<<endl<<endl;
        cout<<"Patient details added... :)";
        cout<<endl<<endl;
        ++count;
    }
    void show()
    {
        cout<<endl;
        cout<<"  ID: "<<id<<endl;
        cout<<"  1st Name: "<<name1<<endl;
        cout<<"  Last Name: "<<name2<<endl;
        cout<<"  Sex: "<<sex<<endl;
        cout<<"  Birthday(day/month/year): "<<birth<<endl;
        cout<<"  Address: "<<address<<endl;
        cout<<"  Blood group: "<<blood<<endl;
        cout<<"  Problem: "<<problem<<endl;
        cout<<"  Tel: "<<tel<<endl;
        cout<<"  Nationality: "<<nation<<endl;
        Doctors::show();
        Test::show();
        cout<<endl;
    }
    string getname3()
    {
        return (name1+" "+name2);
    }
    void print_bill()
    {
        ofstream out;
        out.open("Patient Bills.txt");
        out<<"               ***<<< Patient bill... >>>***"<<endl<<endl<<endl;
        out<<setw(5)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"Total Bill"<<endl;
        for(i=0; i<35; i++)
        {
            out<<"=";
        }
        out<<endl;
        out<<setw(5)<<getid()<<setw(15)<<getname3()<<setw(15)<<getcost()+getvisit()<<endl;
        for(i=0; i<35; i++)
        {
            out<<"=";
        }

        out.close();
    }


} *p[100],*p1;

int main()
{
    char ch;
    string s="farabi04";
    string s1,x;
    cout<<endl<<endl<<"            ***<<<  Welcome to the Hospital management system... >>>***"<<endl<<endl;
    cout<<endl<<" >> Enter password: ";
    cin>>s1;

    for(;;)
    {
         if(s1==s)
            {
                process();
                break;
            }
            else
            {
                cout<<" ***<<<  Wrong passwqord!!! Please try again...  >>>***"<<endl<<endl;
                break;
            }
    }
    }


void process()
{
    int n;
    for(;;)
    {
        menu();
        cout<<" >> Enter your choice: ";
        cin>>n;
        if(n==1)
        {
            doctor_list();
        }
        else if(n==2)
        {
            create();
        }
        else if(n==3)
        {
            showAll();
        }
        else if(n==4)
        {
            search();
        }
        else if(n==5)
        {
            del();
        }
        else if(n==6)
        {
            update();
        }
        else if(n==7)
        {
            short_details();
        }
        else if(n==8)
        {
            print_bills();
        }

        else if(n==9)
        {
            break;
        }
        else
        {
            cout<<endl<<"         ***<<<Invalid input. Please Choose one option from the menu.>>>***"<<endl;
        }
    }
}

void menu()
{
    cout<<endl<<endl;
    cout<<"      ***********************************************"<<endl;
    cout<<"      ***********************************************"<<endl;
    cout<<"      **                                           **"<<endl;
    cout<<"      **    1 for Show all doctors information...  **"<<endl;
    cout<<"      **    2 for add patient details ...          **"<<endl;
    cout<<"      **    3 for show patients list...            **"<<endl;
    cout<<"      **    4 for search patients details...       **"<<endl;
    cout<<"      **    5 for delete patients details...       **"<<endl;
    cout<<"      **    6 for Update patients detail           **"<<endl;
    cout<<"      **    7 for Short details of patients..      **"<<endl;
    cout<<"      **    8 for Print total bill of patients...  **"<<endl;
    cout<<"      **    9 for Exit...                          **"<<endl;
    cout<<"      **                                           **"<<endl;
    cout<<"      ***********************************************"<<endl;
    cout<<"      ***********************************************"<<endl<<endl<<endl;
}
void create()
{
    p[count]=new Patient;
    p[count]->read();
}
void showAll()
{
    for(i=0; i<count; ++i)
    {
        cout<<endl<<"         ***<<<  Full Details of patient  "<<i+1<<" >>>***"<<endl;
        for(j=0; j<8; j++)
        {
            cout<<" ";
        }
        for(j=0; j<46; j++)
        {
            cout<<"-";
        }
        cout<<endl;
        p[i]->show();
    }
    cout<<endl<<endl<<"        ***<<<  Total Number of patient: "<<count<<"  >>>***"<<endl<<endl;
}
void search_menu()
{
    ifstream in;
    string str;
    in.open("search menu.txt");
    while(getline(in,str))
    {
        cout<<str<<endl;
    }
    in.close();
}

void search()
{
    int x,id1,found1=0,found2=0,found3=0;

    for(;;)
    {
        search_menu();

        cout<<endl<<"  >> Enter your choice: ";
        cin>>x;

        if(x==1)
        {
            cout<<endl<<"  >> Enter the patient id u want to search: ";
            cin>>id1;
            for(i=0; i<count; i++)
            {
                if(id1==p[i]->getid())
                {
                    p[i]->show();
                    found1=1;
                }
            }
            if(found1!=1)
            {
                cout<<endl<<"       ***<<<  Sry,ID not found...  >>>***"<<endl<<endl;
            }
        }


        else if(x==2)
        {
            string s;
            cout<<endl<<"  >> Enter first name: ";
            cin>>s;
            for(i=0; i<count; i++)
            {
                if(s==p[i]->getname1())
                {
                    p[i]->show();
                    found2=1;
                }
            }

            if(found2!=1)
            {
                cout<<endl<<"  ***<<<  Sry,1st name not found.  >>>***"<<endl<<endl;
            }
        }
        else if(x==3)
        {
            string s2;
            cout<<endl<<"  >> Enter last name: ";
            cin>>s2;
            for(i=0; i<count; i++)
            {
                if(s2==p[i]->getname2())
                {
                    p[i]->show();
                    found3=1;
                }
            }
            if(found3!=1)
            {
                cout<<endl<<"  ***<<<  Sry,last name not found.  >>>***"<<endl<<endl;

            }
        }
        else if(x==4)
        {
            break;
        }
    }
}
void del()
{
    int i,del_id,pos,ele;
    for(;;)
    {
        cout<<">> Enter the ID you want to delete: ";
        cin>>del_id;
        for(i=0; i<count; i++)
        {
            if(del_id==p[i]->getid())
            {
                pos=i+1;
            }
        }

        if(pos>=count+1)
        {
            cout<<"  ***<<< Impossible!!! Please input a valid ID  >>>*** "<<endl;
        }
        else
        {
            for(i=pos-1; i<count-1; i++)
            {
                p[i]=p[i+1];
            }
        }
        count--;
        cout<<"  ***<<< ID successfully DELETED >>>***"<<endl;
        break;

    }

}
void update()
{
    int i,j,up_id,pos1;
    cout<<"enter the id you want to update: ";
    cin>>up_id;
    for(i=0; i<count; i++)
    {
        if(up_id==p[i]->getid())
        {
            pos1=i+1;

        }
    }
    cout<<"Enter new info"<<endl;

    p1=new Patient;
    p1->read();
    count--;
    p[pos1-1]=p1;
    cout<<"  ***<<< ID successfully UPDATED >>>***"<<endl;
    //delete p1;
}
void short_details()
{
    string name[100];
    cout<<setw(5)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"PROBLEM"<<setw(15)<<"TELEPHONE"<<endl;
    for(i=0; i<count; i++)
    {
        name[i]=p[i]->getname1()+" "+p[i]->getname2();
        cout<<setw(5)<<p[i]->getid()<<setw(15)<<name[i]<<setw(15)<<p[i]->getproblem()<<setw(15)<<p[i]->gettel()<<endl;
    }
}
void print_bills()
{

    int i,j,up_id,pos1;
    cout<<endl<<"  >> Enter the id you want to show the bill: ";
    cin>>up_id;
    for(i=0; i<count; i++)
    {
        if(up_id==p[i]->getid())
        {
            pos1=i+1;

        }
    }
    p[pos1-1]->print_bill();
}
void doctor_list()
{
    ifstream in;
    string str;
    in.open("doc details.txt");
    while(getline(in,str))
    {
        cout<<str<<endl;
    }
    in.close();
}
