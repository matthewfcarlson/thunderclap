class DrawableContainer {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
    virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
    virtual void f15(); virtual void f16(); virtual void f17();
    virtual int vfunc_18(int);
};
class Geometry : public DrawableContainer {
public:
    char pad[0x60 - 4];
    int a;
    int b;
    int vfunc_18(int);
};
int Geometry::vfunc_18(int param) {
    int i = a;
    if (i != 0) {
        if (param == 0) return i;
        --param;
    }
    if (b != 0) {
        if (param == 0) return b;
        if (param == 1 && i != 0) return b;
        --param;
    }
    return DrawableContainer::vfunc_18(param);
}