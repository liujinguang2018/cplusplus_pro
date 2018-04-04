#include <boost/scoped_ptr.hpp>
#include <string>
#include <iostream>

using namespace std;

struct posix_file
{
    posix_file(const char *file_name)
    {
        cout << "open file:" << file_name << endl;
    }

    ~posix_file()
    {
        cout << "close file" << endl;
    }
};

void test_scoped_ptr()
{
    boost::scoped_ptr<int> p(new int);
    if (p)
    {
        *p = 100;
        cout << *p << endl;
    }
    p.reset();
    assert(p == 0);
    if (!p)
    {
        cout << "scoped_ptr == null" << endl;
    }

    boost::scoped_ptr<posix_file> fp(new posix_file("/tmp/txt"));
}

void test_basic_features()
{
    boost::scoped_ptr<string> p(new string("Use scoped_ptr often"));

    //print the value of the string
    if (p)
    {
        cout << *p << endl;
    }

    //Get the size of the string
    size_t i = p->size();
    cout << "size = " << i << endl;

    //Assign a new value to the string
    *p = "Acts just like a pointer";
} // p is destoyed here, and deletes the string

//scoped_ptr和auto_ptr之间的主要区别在于它们对所有权的处理方式上:
//auto_ptr在复制时会使源auto_ptr自动交出所有权，而scoped_ptr则不允许复制
//C++标准已经废弃了auto_ptr, 由unique_ptr来取代
void scoped_vs_auto() {
    boost::scoped_ptr<std::string> p_scoped(new std::string("Hello"));
    std::auto_ptr<std::string> p_auto(new std::string("Hello"));

    std::cout << "scoped size = " << p_scoped->size() << std::endl;
    std::cout << "auto size = " << p_auto->size() << std::endl;

    //scoped_ptr不能通过赋值来构造或者赋值
    //boost::scoped_ptr<std::string> p_another_scoped = p_scoped;

    //所有权转移
    std::auto_ptr<std::string> p_another_auto = p_auto;
    std::cout << "auto size = " << p_another_auto->size() << std::endl;

    //std::cout << *p_auto << std::endl;
}

int main()
{
    cout << "=======Test basic feature=======" << endl;
    test_basic_features();

    cout << "========Test scoped ptr==========" << endl;
    test_scoped_ptr();

    cout << "=========auto_ptr vs scoped_ptr========" << endl;
    scoped_vs_auto();
}