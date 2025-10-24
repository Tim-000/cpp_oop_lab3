#pragma once
#include <cmath>
#include <iostream>
#include "figure.h"

class Rhombus : public Figure
{
protected:
    double getArea() const override;

public:
    Rhombus();
    Rhombus(const Point &p1, const Point &p2, const Point &p3, const Point &p4);
    Rhombus(const Rhombus &other);

    Point getCenter() const override;

    void print(std::ostream &os) const override;
    void read(std::istream &is) override;

    Rhombus &operator=(const Rhombus &other);
    Rhombus &operator=(Rhombus &&other) noexcept;

    bool operator==(const Rhombus &other) const;
    bool operator==(const Figure &other) const override;

    std::unique_ptr<Figure> clone() const override;
};
