extern "C" void _ReadWriteBarrier();
struct V3 {
    int x, y, z;
    V3() : x(0), y(0), z(0) { _ReadWriteBarrier(); }
};
struct H3 {
    float x, y, z;
    H3() : x(0.5f), y(0.5f), z(0.5f) {}
};
class ColorState {
  public:
    ColorState();
    V3 a;
    H3 d;
    float g;
    int h, i, j;
    float k;
    int l, m, n;
    float o;
    int p;
};
ColorState::ColorState() {
    h = 0;
    i = 0;
    _ReadWriteBarrier();
    g = 1.0f;
    j = 0;
    k = 1.0f;
    l = 0;
    m = 0;
    n = 0;
    o = 1.0f;
    p = 0;
}