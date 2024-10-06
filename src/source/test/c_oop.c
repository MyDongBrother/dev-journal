#include <stdio.h>
#include <stdlib.h>
#include "c_oop.h"

void Shape_draw(Shape *self) { printf("Drawing a shape.\n"); }

void Circle_draw(Shape *self)
{
    Circle *circle = (Circle *)self;
    printf("Drawing a circle with radius: %.2f\n", circle->radius);
}

Circle *Circle_new(double radius)
{
    Circle *circle = (Circle *)malloc(sizeof(Circle));
    // 多态：父类与子类方法的函数指针不同
    circle->base.draw = Circle_draw;
    circle->radius    = radius;
    return circle;
}

Shape *Shape_new()
{
    Shape *shape = (Shape *)malloc(sizeof(Shape));
    shape->draw  = Shape_draw;
    return shape;
}
