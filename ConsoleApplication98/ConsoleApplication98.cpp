
#include <iostream>
#include<string>
#include<fstream>

using namespace std;
class obruch final
{
private:
    int money;// доступно только в обруч
protected:
    string region;// доступно и в обруч и в школе
public:// доступно всем
    void set_tchr(int t)
    {
        teacher = t;
    }
    int teacher;
    obruch()
    {
        money = 0;
        teacher = 0;
        region = "empty";
    }
    obruch(string reg)
    {
        money = 0;
        teacher = 0;
        region = reg;
    }
    string get_region()
    {
        return region;
    }
    
    int get_tchr()
    {
        return teacher;
    }

};
class school
{
    int num_school;
    int classcount;
    int schoolboy;
    
public:
    school()
    {
        num_school=0;
        classcount=0;
        schoolboy=0;
        
    }
    school(int n,int cls,int sclboy)
    {
        num_school = n;
        classcount = cls;
        schoolboy = sclboy;
        
    }
    int get_numschool()
    {
        return num_school;
    }
    void print()
    {
        cout << "number of school " << num_school << " class count " << classcount << " school boy " << schoolboy << endl;
    }

};

int main()
{
    for (int i = 1; i < 10; i++)
    {
        school a(11 * 10^i + 1, 22 * 10^i + 2, 33 * 10^i + 3);
        string my_file = "1.txt";
        fstream f;
        f.open(my_file, ofstream::app);
        if (f.is_open())
        {
            f.write((char*)&a, sizeof(school));

        }
        else
        {

        }

        f.close();
        
    }
    string fl = "1.txt";
    ifstream f;
    f.open(fl);
    if (f.is_open())
    {
        school a;
        while (f.read((char*)&a, sizeof(school)))
        {
            if (a.get_numschool()%2==0)
                a.print();
        }
        f.close();

    }
    
    
    
    
}