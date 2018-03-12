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
        std::cout << *p << endl;
    }

    //Get the size of the string
    size_t i = p->size();
    cout << "size = " << i << endl;

    //Assign a new value to the string
    *p = "Acts just like a pointer";
} // p is destoyed here, and deletes the string

int main()
{
    test_basic_features();

    cout << "==================" << endl;
    test_scoped_ptr();
} // p is destoyed here, and deletes the string