#include "../include/rhombus.h"
#include <gtest/gtest.h>

TEST(RhombusTest, DefaultConstructor)
{
    Rhombus rh;
    EXPECT_EQ(rh.getSize(), 4);
}

TEST(RhombusTest, ParameterizedConstructor)
{
    Rhombus rh({0, 0}, {2, 1}, {4, 0}, {2, -1});
    EXPECT_EQ(rh.getSize(), 4);
}

TEST(RhombusTest, CopyConstructor)
{
    Rhombus r1({0, 0}, {2, 1}, {4, 0}, {2, -1});
    Rhombus r2(r1);
    EXPECT_TRUE(r1 == r2);
}

TEST(RhombusTest, AreaCalculation)
{
    Rhombus rh({0, 0}, {2, 1}, {4, 0}, {2, -1});
    EXPECT_NEAR(static_cast<double>(rh), 4.0, 1e-6);
}

TEST(RhombusTest, CenterCalculation)
{
    Rhombus rh({0, 0}, {2, 1}, {4, 0}, {2, -1});
    Point c = rh.getCenter();
    EXPECT_DOUBLE_EQ(c.x, 2.0);
    EXPECT_DOUBLE_EQ(c.y, 0.0);
}

TEST(RhombusTest, InputOutput)
{
    std::istringstream in("0 0 2 1 4 0 2 -1");
    Rhombus rh;
    rh.read(in);
    std::ostringstream out;
    rh.print(out);
    EXPECT_EQ(out.str(), "(0,0) (2,1) (4,0) (2,-1) ");
}

TEST(RhombusTest, Clone)
{
    Rhombus r1({0, 0}, {2, 1}, {4, 0}, {2, -1});
    auto r2 = r1.clone();
    EXPECT_TRUE(r1 == *r2);
}
