#include "../include/hexagon.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(HexagonTest, DefaultConstructor)
{
    Hexagon h;
    EXPECT_EQ(h.getSize(), 6);
}

TEST(HexagonTest, ParameterizedConstructor)
{
    Hexagon h({0, 0}, {1, 2}, {2, 2}, {3, 1}, {2, 0}, {1, -1});
    EXPECT_EQ(h.getSize(), 6);
}

TEST(HexagonTest, CopyConstructor)
{
    Hexagon h1({0, 0}, {1, 2}, {2, 2}, {3, 1}, {2, 0}, {1, -1});
    Hexagon h2(h1);
    EXPECT_TRUE(h1 == h2);
}

TEST(HexagonTest, AreaCalculation)
{
    Hexagon h({0, 0}, {1, 2}, {2, 2}, {3, 1}, {2, 0}, {1, -1});
    EXPECT_NEAR(static_cast<double>(h), 5.0, 1e-6);
}

TEST(HexagonTest, CenterCalculation)
{
    Hexagon h({0, 0}, {1, 2}, {2, 2}, {3, 1}, {2, 0}, {1, -1});
    Point c = h.getCenter();
    EXPECT_NEAR(c.x, 1.3999999999999999, 1e-6);
    EXPECT_NEAR(c.y, 0.6666666666666666, 1e-6);
}

TEST(HexagonTest, InputOutput)
{
    std::istringstream in("0 0 1 2 2 2 3 1 2 0 1 -1");
    Hexagon h;
    h.read(in);
    std::ostringstream out;
    h.print(out);
    EXPECT_EQ(out.str(), "(0,0) (1,2) (2,2) (3,1) (2,0) (1,-1) ");
}

TEST(HexagonTest, Clone)
{
    Hexagon h1({0, 0}, {1, 2}, {2, 2}, {3, 1}, {2, 0}, {1, -1});
    auto h2 = h1.clone();
    EXPECT_TRUE(h1 == *h2);
}
