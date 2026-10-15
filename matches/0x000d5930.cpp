namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class MessageOverlay {
  public:
    void Show(int, const char*, int, math::Vector, float);
};
class Function {
  public:
    virtual void a();
    virtual void b();
};
class Method5 : public Function {
  public:
    virtual void vfunc_2(MessageOverlay*, void*, int);
    char pad[0x18];
    typedef void (MessageOverlay::*Fn)(int, const char*, int, math::Vector, float);
    Fn fn;
};
void Method5::vfunc_2(MessageOverlay* obj, void* p, int) {
    int* q = (int*)p;
    int a = *q++;
    const char* b = *(const char**)q++;
    int c = *q++;
    math::Vector d = *(math::Vector*)q;
    q += 3;
    float e = *(float*)q;
    Fn f = fn;
    (obj->*f)(a, b, c, d, e);
}