#include <iostream>
#include <map>
#include <gtest/gtest.h>

using namespace std;

class GlobalEnvironment : public testing::Environment
{
  public:
    virtual void SetUp() override
    {
        cout << "Environment SetUp" << endl;
    }

    virtual void TearDown() override
    {
        cout << "Environment TearDown" << endl;
    }
};

class TestMap : public testing::Test
{
  public:
    //添加日志
    static void SetUpTestCase()
    {
        cout << "SetUpTestCase" << endl;
    }
    static void TearDownTestCase()
    {
        cout << "TearDownTestCase" << endl;
    }
    virtual void SetUp() //TEST跑之前会执行SetUp
    {
        cout << "SetUp" << endl;
        test_map.insert(make_pair(1, 0));
        test_map.insert(make_pair(2, 1));
        test_map.insert(make_pair(3, 2));
        test_map.insert(make_pair(4, 3));
        test_map.insert(make_pair(5, 4));
    }
    virtual void TearDown() //TEST跑完之后会执行TearDown
    {
        cout << "TearDown" << endl;
        test_map.clear();
    }
    map<int, int> test_map;
};

TEST_F(TestMap, Find) //此时使用的是TEST_F宏
{
    map<int, int>::iterator it = test_map.find(1);
    ASSERT_NE(it, test_map.end());
}

TEST_F(TestMap, Size)
{
    ASSERT_EQ(test_map.size(), 5);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    testing::Environment *env = new GlobalEnvironment();
    testing::AddGlobalTestEnvironment(env);

    return RUN_ALL_TESTS();
}