/* *****************************************************************************
##
# @file        cube.hpp
# @brief       Cube implementation in context of the hanoi tower exercice
# @copyright   MIT license
# ****************************************************************************/
#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>

namespace hanoi_tower
{

class Cube
{
    public:
    Cube(double length):length_{length}{};
    Cube(const Cube& other):length_{other.getLength()}{};
    double getLength() const {return length_;};
    void setLength(double length) {length_ = length;};
    double getVolume()const{return length_*length_*length_;};
    friend std::ostream& operator<<(std::ostream& stream, const Cube& stack);

    private:
    double length_;
};

} // namespace hanoi_tower

#endif  // CUBE_HPP