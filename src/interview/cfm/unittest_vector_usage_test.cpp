#include <gtest/gtest.h>

#include <iostream>
#include <vector>
using namespace std;

class TestVector : public testing::Test
{
  public:
    static void SetUpTestCase()
    {
        cout << "SetUpTestCase" << endl;
    }

    static void TearDownTestCase()
    {
        cout << "TearDownTestCase" << endl;
    }

    virtual void SetUp() override
    {
        test_vector.push_back("Hello");
        test_vector.push_back("world");
        test_vector.push_back("Beijing");
        test_vector.push_back("changping");
    }
    virtual void TearDown() override
    {
    }

    vector<string> test_vector;
};

TEST_F(TestVector, Erase)
{
    ASSERT_EQ(test_vector.size(), 4);

    for (vector<string>::iterator iter = test_vector.begin(); iter != test_vector.end();)
    {
        cout << *iter << endl;

        iter = test_vector.erase(iter);
    }

    ASSERT_EQ(test_vector.size(), 0);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}