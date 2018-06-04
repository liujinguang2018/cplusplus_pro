#include <vector>
#include <iostream>
#include <iterator>

using namespace std;


void capacity_size_test()
{
    vector<int> v;

    cout << "capacity: " << v.capacity() << endl;

    v.insert(v.begin(), 3);

    cout << "size = " << v.size() << ", capacity = " << v.capacity() << endl;
}

void iter_input_test()
{
    cout << "input double parameter: " << endl;
    
    istream_iterator<double> first(cin);
    istream_iterator<double> end_of_file;

    vector<double> buf(first, end_of_file);
    for (auto iter = buf.begin(); iter != buf.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    cout << "Verify the capacity and size: " << endl;
    capacity_size_test();
    cout << endl;

    cout << "Test iterator input for vector " << endl;
    iter_input_test();
}