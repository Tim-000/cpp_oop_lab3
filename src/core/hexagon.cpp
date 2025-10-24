#include "../include/hexagon.h"
#include <algorithm>

Hexagon::Hexagon()
{
    size_ = 6;
    points_ = new Point[size_];
}

Hexagon::Hexagon(const Point &p1, const Point &p2, const Point &p3,
                 const Point &p4, const Point &p5, const Point &p6)
{
    size_ = 6;
    points_ = new Point[size_]{p1, p2, p3, p4, p5, p6};
}

Hexagon::Hexagon(const Hexagon &other)
{
    size_ = other.size_;
    points_ = new Point[size_];
    for (size_t i = 0; i < size_; ++i)
        points_[i] = other.points_[i];
}

Point Hexagon::getCenter() const
{
    double area = 0;
    double cx = 0, cy = 0;
    for (size_t i = 0; i < size_; ++i)
    {
        size_t j = (i + 1) % size_;
        double cross = points_[i].x * points_[j].y - points_[j].x * points_[i].y;
        area += cross;
        cx += (points_[i].x + points_[j].x) * cross;
        cy += (points_[i].y + points_[j].y) * cross;
    }
    area *= 0.5;
    cx /= (6.0 * area);
    cy /= (6.0 * area);
    return Point{cx, cy};
}

double Hexagon::getArea() const
{
    double area = 0;
    for (size_t i = 0; i < size_; ++i)
    {
        size_t j = (i + 1) % size_;
        area += points_[i].x * points_[j].y - points_[j].x * points_[i].y;
    }
    return std::abs(area) / 2.0;
}

void Hexagon::print(std::ostream &os) const
{
    for (size_t i = 0; i < size_; ++i)
        os << "(" << points_[i].x << "," << points_[i].y << ") ";
}

void Hexagon::read(std::istream &is)
{
    if (points_)
        delete[] points_;
    size_ = 6;
    points_ = new Point[size_];
    for (size_t i = 0; i < size_; ++i)
        is >> points_[i].x >> points_[i].y;
}

Hexagon &Hexagon::operator=(const Hexagon &other)
{
    if (this == &other)
        return *this;
    Figure::operator=(other);
    return *this;
}

Hexagon &Hexagon::operator=(Hexagon &&other) noexcept
{
    if (this == &other)
        return *this;
    Figure::operator=(std::move(other));
    return *this;
}

bool Hexagon::operator==(const Hexagon &other) const
{
    if (size_ != other.size_)
        return false;

    Point sorted1[6];
    Point sorted2[6];
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

bool Hexagon::operator==(const Figure &other) const
{
    if (const Hexagon *h = dynamic_cast<const Hexagon *>(&other))
        return *this == *h;
    return false;
}

std::unique_ptr<Figure> Hexagon::clone() const
{
    return std::unique_ptr<Figure>(new Hexagon(*this));
}
