#include <iostream>
#include <gtest/gtest.h>
#include "module/func.h"


namespace HelloWorld {
class BirdTest : public testing::Test {
public:
    static void SetUpTestCase() {
        // run before all case executed  .在这个文件的所有测试用例运行之前执行，只执行一次
        std::cout<<"SetUpTestCase"<<std::endl;
    }

    static void TearDownTestCase() {
        // run after all case executed    在这个文件的所有测试用例运行之后执行，只执行一次
        std::cout<<"TearDownTestCase"<<std::endl;
    }

    virtual void SetUp() {
        // Run before each case executed    这个文件的每个测试用例之前执行，每个用例运行前都会执行一遍
        std::cout<<"SetUp"<<std::endl;
    }

    virtual void TearDown() {
        // Run after each case executed    每个用例运行后都执行一遍。
        std::cout<<"TearDown"<<std::endl;
    }

};

Bird bird(10, "john");

TEST_F(BirdTest, get_size) {
    ASSERT_EQ(bird.GetBirdSize(), 10);   // ASSERT如果错误，当前这个函数直接退出，这个函数后面的函数还会继续执行。
}

TEST_F(BirdTest, get_name) {
    EXPECT_EQ(bird.GetBirdName(), "john");  //EXPECT如果错误，这个函数后面的代码还会继续执行。
}

// class HelloWorld : public testing::Test {

// };

// TEST_F(HelloWorld, Test_hello_wold) {
//     std::string in1 = "hello";
//     std::string in2 = "world";

//     std::string expect = "helloworld";
//     std::string output = in1 + in2;
//     EXPECT_STREQ(output.c_str(), expect.c_str());
// }

}