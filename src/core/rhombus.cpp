#include "../include/rhombus.h"
#include <algorithm>

Rhombus::Rhombus()
{
    size_ = 4;
    points_ = new Point[size_];
}

Rhombus::Rhombus(const Point &p1, const Point &p2, const Point &p3, const Point &p4)
{
    size_ = 4;
    points_ = new Point[size_]{p1, p2, p3, p4};
}

Rhombus::Rhombus(const Rhombus &other)
{
    size_ = other.size_;
    points_ = new Point[size_];
    for (size_t i = 0; i < size_; ++i)
        points_[i] = other.points_[i];
}

Point Rhombus::getCenter() const
{
    double cx = 0, cy = 0;
    for (size_t i = 0; i < size_; ++i)
    {
        cx += points_[i].x;
        cy += points_[i].y;
    }
    return Point{cx / size_, cy / size_};
}

double Rhombus::getArea() const
{
    double area = 0;
    for (size_t i = 0; i < size_; ++i)
    {
        size_t j = (i + 1) % size_;
        area += points_[i].x * points_[j].y - points_[j].x * points_[i].y;
    }
    return std::abs(area) / 2.0;
}

void Rhombus::print(std::ostream &os) const
{
    for (size_t i = 0; i < size_; ++i)
        os << "(" << points_[i].x << "," << points_[i].y << ") ";
}

void Rhombus::read(std::istream &is)
{
    if (points_)
        delete[] points_;
    size_ = 4;
    points_ = new Point[size_];
    for (size_t i = 0; i < size_; ++i)
        is >> points_[i].x >> points_[i].y;
}

Rhombus &Rhombus::operator=(const Rhombus &other)
{
    if (this == &other)
        return *this;
    Figure::operator=(other);
    return *this;
}

Rhombus &Rhombus::operator=(Rhombus &&other) noexcept
{
    if (this == &other)
        return *this;
    Figure::operator=(std::move(other));
    return *this;
}

bool Rhombus::operator==(const Rhombus &other) const
{
    if (size_ != other.size_)
        return false;

    Point sorted1[4];
    Point sorted2[4];
    std::copy(points_, points_ + size_, sorted1);
    std::copy(other.points_, other.points_ + other.size_, sorted2);

    auto cmp = [](const Point &a, const Point &b)
    {
        return (a.x < b.x) || (a.x == b.x && a.y < b.y);
    };

    std::sort(sorted1, sorted1 + size_, cmp);
    std::sort(sorted2, sorted2 + size_, cmp);

    for (size_t i = 0; i < size_; ++i)
        if (!(sorted1[i] == sorted2[i]))
            return false;

    return true;
}

bool Rhombus::operator==(const Figure &other) const
{
    if (const Rhombus *rh = dynamic_cast<const Rhombus *>(&other))
        return *this == *rh;
    return false;
}

std::unique_ptr<Figure> Rhombus::clone() const
{
    return std::unique_ptr<Figure>(new Rhombus(*this));
}
