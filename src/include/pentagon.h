#pragma once
#include <cmath>
#include <iostream>
#include "figure.h"

class Pentagon : public Figure
{
protected:
    double getArea() const override;

public:
    Pentagon();
    Pentagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4, const Point &p5);
    Pentagon(const Pentagon &other);

    Point getCenter() const override;

    void print(std::ostream &os) const override;
    void read(std::istream &is) override;

    Pentagon &operator=(const Pentagon &other);
    Pentagon &operator=(Pentagon &&other) noexcept;

    bool operator==(const Pentagon &other) const;
    bool operator==(const Figure &other) const override;

    std::unique_ptr<Figure> clone() const override;
};
