namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class HUDOverlay {
  public:
    int x;
};
typedef int (HUDOverlay::*Fn_cf0e0)(int, int, math::Vector, math::Vector);
template <class T> inline T Pop(char*& p) {
    T v = *(T*)p;
    p += sizeof(T);
    return v;
}
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(HUDOverlay* o, char* a, int* out);
    int pad[5];
};
class Method4 : public Function {
  public:
    char pad2[0x1c - 0x18];
    Fn_cf0e0 mFn;
    virtual void v2(HUDOverlay* o, char* a, int* out);
};
void Method4::v2(HUDOverlay* o, char* args, int* out) {
    Fn_cf0e0 fn = mFn;
    char* p = args;
    int a1 = Pop<int>(p);
    int a2 = Pop<int>(p);
    math::Vector a3 = Pop<math::Vector>(p);
    math::Vector a4 = Pop<math::Vector>(p);
    int r = (o->*fn)(a1, a2, a3, a4);
    if (out)
        *out = r;
}
