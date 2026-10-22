// FUN_002a5150 @ 0x002a5150
// equiv-map: ??0Resource@@QAE@XZ = 0x0027b070
class Entity_2a5150 {
public:
    Entity_2a5150();
    virtual void vfunc_0();
    int refs;
};
struct Sub_2a5150 {
    char data[8];
    void FUN_0027af70(const Sub_2a5150* other);
};
namespace pure3d {
class DrawablePrimitive : public Entity_2a5150 {
public:
    DrawablePrimitive(const DrawablePrimitive& src);
    virtual void vfunc_0();
    Sub_2a5150 sub;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
};
DrawablePrimitive::DrawablePrimitive(const DrawablePrimitive& src) : Entity_2a5150() {
    f10 = src.f10;
    sub.FUN_0027af70(&src.sub);
    f14 = src.f14;
    f18 = src.f18;
    f1c = src.f1c;
    f20 = src.f20;
    f24 = src.f24;
    f28 = src.f28;
    f2c = src.f2c;
    f30 = src.f30;
    f34 = src.f34;
    f38 = src.f38;
}
}
