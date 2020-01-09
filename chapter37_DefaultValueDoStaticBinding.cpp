#include <iostream>

class Shape
{
public:
    enum class Color
    {
        RED = 0, GREEN, BLUE
    };

    virtual void draw( Color color = Color::RED ) const = 0;
};

class Rectangle : public Shape
{
    virtual void draw( Color color = Color::GREEN ) const override
    {
        std::cout << "color: " << static_cast<int>( color ) << std::endl;
    }
};

int main( void )
{
    std::shared_ptr<Shape> shape = std::make_shared<Rectangle>();
    shape->draw(); // note: default color가 Green이 아니고 RED가 됨!
    return 0;
}
