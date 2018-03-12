#include <boost/program_options.hpp>
#include <boost/program_options/errors.hpp>
#include <iostream>


namespace opt = boost::program_options;

using namespace std;

int main(int argc, char *argv[]) {
    cout << "aa" << endl;
    //����ѡ�����������ֵ��һ���ı�������
    opt::options_description desc("All options");

    //���ѡ����������ֱ�Ϊ��������ʹ�õ����ƣ�ѡ�����ͣ�ѡ������
    desc.add_options()
        ("help",  "product help message")
        ("apples,a", opt::value<int>(), "how many apples do you have")
        ("oranges,o", opt::value<int>(), "how many oranges do you have")
    ;

    //���ڱ��������в����ı���
    opt::variables_map var_map;

    //�������洢����
    opt::store(opt::parse_command_line(argc, argv, desc), var_map);
    opt::notify(var_map);

    if (var_map.count("help")) {
        cout << "here" << endl;
        cout << desc << endl;
        return 0;
    }
    
    //cout << "Fruits count: " 
    //     << var_map["apples"].as<int>() + var_map["oranges"].as<int>()
    //     << endl;

    return 0;
}

