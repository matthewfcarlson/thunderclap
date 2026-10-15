namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class MessageOverlay {
  public:
    void Show(const char*, int, math::Vector);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Method3 : public Function {
  public:
    char pad[0x18];
    void (MessageOverlay::*fn)(const char*, int, math::Vector);
    virtual void f2(MessageOverlay* obj, void* args, void* other);
};
void Method3::f2(MessageOverlay* obj, void* args, void* other) {
    char* p = (char*)args;
    const char* s = *(const char**)p;
    p += 4;
    int i = *(int*)p;
    p += 4;
    math::Vector v = *(math::Vector*)p;
    (obj->*fn)(s, i, v);
}