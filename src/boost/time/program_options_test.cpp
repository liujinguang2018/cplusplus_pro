#include <boost/program_options.hpp>
#include <boost/program_options/errors.hpp>
#include <iostream>


namespace opt = boost::program_options;

using namespace std;

int main(int argc, char *argv[]) {
    cout << "aa" << endl;
    //构造选项描述项，并赋值给一个文本描述符
    opt::options_description desc("All options");

    //添加选项，三个参数分别为命令行中使用的名称，选项类型，选项描述
    desc.add_options()
        ("help",  "product help message")
        ("apples,a", opt::value<int>(), "how many apples do you have")
        ("oranges,o", opt::value<int>(), "how many oranges do you have")
    ;

    //用于保存命令行参数的变量
    opt::variables_map var_map;

    //解析并存储参数
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

