extern "C" void _ReadWriteBarrier();
namespace pure3d {
class Drawable {
  public:
    virtual void f();
    char pad[12];
    Drawable();
};
struct First {
    int a;
    First() {
        a = 0;
        _ReadWriteBarrier();
    }
};
class DrawableHierarchy : public Drawable, public First {
  public:
    virtual void f();
    int b, c, d, e, g, h, i, j, k, l;
    DrawableHierarchy();
};
DrawableHierarchy::DrawableHierarchy() {
    _ReadWriteBarrier();
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    g = 0;
    h = 0;
    i = 0;
    j = 0;
    k = 0;
    l = 0;
}
} // namespace pure3d