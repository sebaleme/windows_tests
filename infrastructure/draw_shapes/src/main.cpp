/* *****************************************************************************
##
# @file        main.cpp
# @brief       Game class for the draw shape exercice
# @copyright   MIT license
# ****************************************************************************/
#include <vector>
#include <iostream>

using namespace std;

enum class EShapes
{
    circle = 0,
    square,
    rectangle,
    shape
};

ostream& operator<< (ostream& stream, EShapes f_shape)
{
    switch(f_shape)
    {
        case EShapes::circle:
        {
            stream << "circle";
            break;
        }
        case EShapes::square:
        {
            stream << "square";
            break;
        }
        case EShapes::rectangle:
        {
            stream << "rectangle";
            break;
        }
        default:
        {
            stream << "shape";
            break;
        }
    }

    return stream;
};

class Shape
{
    public:
    Shape(EShapes f_shape): m_shape{f_shape}{};
    virtual void draw(){cout << "I am a shape" << endl;};
    EShapes getType(){return m_shape;};

    protected:
    EShapes m_shape;
};

class Circle : public Shape
{
    public:
    Circle(int radius): Shape{ EShapes::circle}, m_radius{radius} {};
    void draw(){cout << "I am a " << m_shape << " of radius " << m_radius << endl;};
    private:
    int m_radius;
};

class Square : public Shape
{
    public:
    Square(int side): Shape{ EShapes::square}, m_side{side}{};
    void draw(){cout << "I am a " << m_shape << " of side " << m_side << endl;};
    private:
    int m_side;
};

class Rectangle : public Shape
{
    public:
    Rectangle(int length, int width): Shape{ EShapes::rectangle}, m_length{length}, m_width{length}{};
    void draw(){cout << "I am a " << m_shape << " of length " << m_length << " and width " << m_width << endl;};
    private:
    int m_length;
    int m_width;
};

void draw(const vector<unique_ptr<Shape>>& f_shapes)
{
    for(auto& shape : f_shapes)
    {
        switch(shape->getType())
        {
            case EShapes::circle:
            {
                static_cast<Circle*>(shape.get())->draw();
                break;
            }
            case EShapes::square:
            {
                static_cast<Square*>(shape.get())->draw();
                break;
            }
            case EShapes::rectangle:
            {
                static_cast<Rectangle*>(shape.get())->draw();
                break;
            }
            default:
            {
                shape->draw();
                break;
            }
        }
    }
};


int main()
{
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(5));
    shapes.push_back(make_unique<Square>(5));
    shapes.push_back(make_unique<Rectangle>(5,8));

    draw(shapes);
}