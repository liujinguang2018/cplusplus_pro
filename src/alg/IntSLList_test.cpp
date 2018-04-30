#include <iostream>
#include <gtest/gtest.h>
#include "IntSLList.h"

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

class TestSLList : public testing::Test
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
        sll.addToHead(5);
        sll.addToTail(8);
        sll.addToHead(3);
        sll.addToHead(10);
    }

    virtual void TearDown() //TEST跑完之后会执行TearDown
    {
        cout << "TearDown" << endl;
    }

    IntSLList sll;
};

TEST_F(TestSLList, Find) //此时使用的是TEST_F宏
{
    ASSERT_EQ(sll.isInList(5), true);
    ASSERT_EQ(sll.isInList(8), true);
    ASSERT_EQ(sll.isInList(3), true);
    ASSERT_EQ(sll.isInList(10), true);

    sll.printAll();

    sll.deleteFromTail();
    ASSERT_EQ(sll.isInList(8), false);
    sll.printAll();
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    testing::Environment *env = new GlobalEnvironment();
    testing::AddGlobalTestEnvironment(env);

    return RUN_ALL_TESTS();
}