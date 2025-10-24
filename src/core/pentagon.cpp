#include "../include/pentagon.h"
#include <algorithm>

Pentagon::Pentagon()
{
    size_ = 5;
    points_ = new Point[size_];
}

Pentagon::Pentagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4, const Point &p5)
{
    size_ = 5;
    points_ = new Point[size_]{p1, p2, p3, p4, p5};
}

Pentagon::Pentagon(const Pentagon &other)
{
    size_ = other.size_;
    points_ = new Point[size_];
    for (size_t i = 0; i < size_; ++i)
        points_[i] = other.points_[i];
}

Point Pentagon::getCenter() const
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

double Pentagon::getArea() const
{
    double area = 0;
    for (size_t i = 0; i < size_; ++i)
    {
        size_t j = (i + 1) % size_;
        area += points_[i].x * points_[j].y - points_[j].x * points_[i].y;
    }
    return std::abs(area) / 2.0;
}

void Pentagon::print(std::ostream &os) const
{
    for (size_t i = 0; i < size_; ++i)
        os << "(" << points_[i].x << "," << points_[i].y << ") ";
}

void Pentagon::read(std::istream &is)
{
    if (points_)
        delete[] points_;
    size_ = 5;
    points_ = new Point[size_];
    for (size_t i = 0; i < size_; ++i)
        is >> points_[i].x >> points_[i].y;
}

Pentagon &Pentagon::operator=(const Pentagon &other)
{
    if (this == &other)
        return *this;
    Figure::operator=(other);
    return *this;
}

Pentagon &Pentagon::operator=(Pentagon &&other) noexcept
{
    if (this == &other)
        return *this;
    Figure::operator=(std::move(other));
    return *this;
}

bool Pentagon::operator==(const Pentagon &other) const
{
    if (size_ != other.size_)
        return false;

    Point sorted1[5];
    Point sorted2[5];
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

bool Pentagon::operator==(const Figure &other) const
{
    if (const Pentagon *p = dynamic_cast<const Pentagon *>(&other))
        return *this == *p;
    return false;
}

std::unique_ptr<Figure> Pentagon::clone() const
{
    return std::unique_ptr<Figure>(new Pentagon(*this));
}
