class DrawableContainer {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual int vfunc_16();
};
class Geometry : public DrawableContainer {
public:
    char pad[0x60 - 4];
    int a;
    int b;
    int vfunc_16();
};
int Geometry::vfunc_16() {
    int r = DrawableContainer::vfunc_16();
    if (a) ++r;
    if (b) ++r;
    return r;
}