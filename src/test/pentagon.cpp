#include "../include/pentagon.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(PentagonTest, DefaultConstructor)
{
    Pentagon p;
    EXPECT_EQ(p.getSize(), 5);
}

TEST(PentagonTest, ParameterizedConstructor)
{
    Pentagon p({0, 0}, {1, 2}, {2, 2}, {3, 1}, {1, 0});
    EXPECT_EQ(p.getSize(), 5);
}

TEST(PentagonTest, CopyConstructor)
{
    Pentagon p1({0, 0}, {1, 2}, {2, 2}, {3, 1}, {1, 0});
    Pentagon p2(p1);
    EXPECT_TRUE(p1 == p2);
}

TEST(PentagonTest, AreaCalculation)
{
    Pentagon p({0, 0}, {1, 2}, {2, 2}, {3, 1}, {1, 0});
    EXPECT_NEAR(static_cast<double>(p), 3.5, 1e-6);
}

TEST(PentagonTest, CenterCalculation)
{
    Pentagon p({0, 0}, {1, 2}, {2, 2}, {3, 1}, {1, 0});
    Point c = p.getCenter();
    EXPECT_NEAR(c.x, 1.4285714285714286, 1e-6);
    EXPECT_NEAR(c.y, 1.0, 1e-6);
}

TEST(PentagonTest, InputOutput)
{
    std::istringstream in("0 0 1 2 2 2 3 1 1 0");
    Pentagon p;
    p.read(in);
    std::ostringstream out;
    p.print(out);
    EXPECT_EQ(out.str(), "(0,0) (1,2) (2,2) (3,1) (1,0) ");
}

TEST(PentagonTest, Clone)
{
    Pentagon p1({0, 0}, {1, 2}, {2, 2}, {3, 1}, {1, 0});
    auto p2 = p1.clone();
    EXPECT_TRUE(p1 == *p2);
}
