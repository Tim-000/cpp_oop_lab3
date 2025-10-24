#include "../include/array.h"
#include <gtest/gtest.h>

#include "../include/rhombus.h"
#include "../include/pentagon.h"
#include "../include/hexagon.h"

TEST(ArrayTest, AddVariousFigures)
{
    Array array;

    Rhombus *rhombus = new Rhombus({0, 0}, {1, 1}, {2, 0}, {1, -1});
    Pentagon *pentagon = new Pentagon({0, 0}, {1, 2}, {2, 2}, {3, 1}, {1, 0});
    Hexagon *hexagon = new Hexagon({0, 0}, {1, 2}, {2, 2}, {3, 1}, {2, 0}, {1, -1});

    array.addFigure(rhombus);
    array.addFigure(pentagon);
    array.addFigure(hexagon);

    EXPECT_EQ(array.getSize(), 3);
    EXPECT_DOUBLE_EQ(array.getAllArea(),
                     static_cast<double>(*rhombus) +
                         static_cast<double>(*pentagon) +
                         static_cast<double>(*hexagon));

    EXPECT_TRUE(dynamic_cast<Rhombus *>(array.getFigure(0)) != nullptr);
    EXPECT_TRUE(dynamic_cast<Pentagon *>(array.getFigure(1)) != nullptr);
    EXPECT_TRUE(dynamic_cast<Hexagon *>(array.getFigure(2)) != nullptr);
}

TEST(ArrayTest, CopyAndMoveWithVariousFigures)
{
    Array array1;
    array1.addFigure(new Rhombus({0, 0}, {1, 1}, {2, 0}, {1, -1}));
    array1.addFigure(new Pentagon({0, 0}, {1, 2}, {2, 2}, {3, 1}, {1, 0}));
    array1.addFigure(new Hexagon({0, 0}, {1, 2}, {2, 2}, {3, 1}, {2, 0}, {1, -1}));

    Array array2(array1);

    EXPECT_EQ(array2.getSize(), 3);
    EXPECT_DOUBLE_EQ(array2.getAllArea(), array1.getAllArea());

    Array array3(std::move(array1));

    EXPECT_EQ(array3.getSize(), 3);
    EXPECT_EQ(array1.getSize(), 0);

    Array array4;
    array4 = array2;

    EXPECT_EQ(array4.getSize(), 3);
    EXPECT_DOUBLE_EQ(array4.getAllArea(), array2.getAllArea());
}

TEST(ArrayTest, RemoveFiguresPolymorphic)
{
    Array array;
    array.addFigure(new Rhombus({0, 0}, {1, 1}, {2, 0}, {1, -1}));
    array.addFigure(new Pentagon({0, 0}, {1, 2}, {2, 2}, {3, 1}, {1, 0}));
    array.addFigure(new Hexagon({0, 0}, {1, 2}, {2, 2}, {3, 1}, {2, 0}, {1, -1}));

    array.removeFigure(1);

    EXPECT_EQ(array.getSize(), 2);
    EXPECT_TRUE(dynamic_cast<Rhombus *>(array.getFigure(0)) != nullptr);
    EXPECT_TRUE(dynamic_cast<Hexagon *>(array.getFigure(1)) != nullptr);
}

TEST(ArrayTest, OperatorIndexPolymorphic)
{
    Array array;
    array.addFigure(new Rhombus({0, 0}, {1, 1}, {2, 0}, {1, -1}));
    array.addFigure(new Pentagon({0, 0}, {1, 2}, {2, 2}, {3, 1}, {1, 0}));

    Figure *figure1 = array[0];
    Figure *figure2 = array[1];
    Figure *figure3 = array[2];

    EXPECT_TRUE(dynamic_cast<Rhombus *>(figure1) != nullptr);
    EXPECT_TRUE(dynamic_cast<Pentagon *>(figure2) != nullptr);
    EXPECT_EQ(figure3, nullptr);
}

TEST(ArrayTest, GetAllAreaPolymorphic)
{
    Array array;
    array.addFigure(new Rhombus({0, 0}, {0, 2}, {2, 2}, {2, 0}));
    array.addFigure(new Pentagon({0, 0}, {0, 3}, {3, 3}, {3, 0}, {1, 1}));
    array.addFigure(new Hexagon({0, 0}, {2, 0}, {3, 2}, {2, 3}, {1, 3}, {0, 2}));

    EXPECT_DOUBLE_EQ(array.getAllArea(),
                     static_cast<double>(*array.getFigure(0)) +
                         static_cast<double>(*array.getFigure(1)) +
                         static_cast<double>(*array.getFigure(2)));
}
