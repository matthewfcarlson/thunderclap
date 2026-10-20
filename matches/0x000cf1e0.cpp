namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
struct HUDOverlay {
    void FUN_00000000(int, int, math::Vector);
};
struct Arguments {
    int a, b;
    math::Vector v;
};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(HUDOverlay*, Arguments*, void*);
};
struct Method3 : Function {
    char reserved[24];
    void (HUDOverlay::*callback)(int, int, math::Vector);
    virtual void vfunc_2(HUDOverlay*, Arguments*, void*);
};
void Method3::vfunc_2(HUDOverlay* object, Arguments* args, void* unused) {
    int* p = &args->a;
    int a = *p++;
    int b = *p++;
    math::Vector v = *(math::Vector*)p;
    (object->*callback)(a, b, v);
}