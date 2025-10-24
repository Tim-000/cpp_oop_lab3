#include "include/array.h"
#include "include/point.h"
#include "include/rhombus.h"
#include "include/pentagon.h"
#include "include/hexagon.h"

int main()
{

    Rhombus rh({0, 0}, {2, 1}, {4, 0}, {2, -1});
    Pentagon p({0, 0}, {2, 0}, {3, 1}, {1.5, 3}, {-0.5, 1});
    Hexagon h({0, 0}, {1, 0}, {2, 1}, {1.5, 2}, {0.5, 2}, {-0.5, 1});

    std::cout << "Rhombus: ";
    rh.print(std::cout);
    std::cout << "Center: (" << rh.getCenter().x << ", " << rh.getCenter().y << ") ";
    std::cout << "Area: " << static_cast<double>(rh) << std::endl;

    std::cout << "Pentagon: ";
    p.print(std::cout);
    std::cout << "Center: (" << p.getCenter().x << ", " << p.getCenter().y << ") ";
    std::cout << "Area: " << static_cast<double>(p) << std::endl;

    std::cout << "Hexagon: ";
    h.print(std::cout);
    std::cout << "Center: (" << h.getCenter().x << ", " << h.getCenter().y << ") ";
    std::cout << "Area: " << static_cast<double>(h) << std::endl
              << std::endl;

    Array arr(3);
    arr.addFigure(new Rhombus(rh));
    arr.addFigure(new Pentagon(p));
    arr.addFigure(new Hexagon(h));

    arr.printFigures();

    std::cout << "Total area: " << arr.getAllArea() << std::endl;

    Figure *figure = arr[1];
    std::cout << "Figure at index 1: ";
    figure->print(std::cout);
    std::cout << "Area: " << static_cast<double>(*figure) << std::endl;

    return 0;
}
