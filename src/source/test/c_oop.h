
#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct Shape
    {
        // 封装: 使用函数指针把属性与方法封装到结构体中
        void (*draw)(struct Shape *self);
    } Shape;

    void Shape_draw(Shape *self);

    typedef struct Circle
    {
        // 继承：结构体嵌套
        Shape base;
        double radius;
    } Circle;

    void Circle_draw(Shape *self);

    Circle *Circle_new(double radius);

    Shape *Shape_new();

#ifdef __cplusplus
}
#endif
