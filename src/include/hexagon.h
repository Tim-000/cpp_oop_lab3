#pragma once
#include <cmath>
#include <iostream>
#include "figure.h"

class Hexagon : public Figure
{
protected:
    double getArea() const override;

public:
    Hexagon();
    Hexagon(const Point &p1, const Point &p2, const Point &p3,
            const Point &p4, const Point &p5, const Point &p6);
    Hexagon(const Hexagon &other);

    Point getCenter() const override;

    void print(std::ostream &os) const override;
    void read(std::istream &is) override;

    Hexagon &operator=(const Hexagon &other);
    Hexagon &operator=(Hexagon &&other) noexcept;

    bool operator==(const Hexagon &other) const;
    bool operator==(const Figure &other) const override;

    std::unique_ptr<Figure> clone() const override;
};
