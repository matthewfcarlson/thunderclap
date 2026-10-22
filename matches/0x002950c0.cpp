extern "C" void _ReadWriteBarrier();
class Base {
  public:
    virtual void f();
    char pad[12];
    Base();
};
class Font_2950c0 : public Base {
  public:
    int a, b, c, d, e;
    Font_2950c0() : Base(), a(0), b(0), c(0), d(0), e(0) {}
};
class TextureFont : public Font_2950c0 {
    int x;
    int g, h, i, j, k, l, m;

  public:
    virtual void f();
    TextureFont();
};
TextureFont::TextureFont() : Font_2950c0() {
    _ReadWriteBarrier();
    x = -1;
    _ReadWriteBarrier();
    g = 0;
    h = 0;
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    m = 0;
}