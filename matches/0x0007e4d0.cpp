extern unsigned char __cdecl g(const char*);
extern const char a[], b[], c[];
class Base_7e4d0 {
  public:
    virtual void fn();
    Base_7e4d0(int, int);
    char pad[12];
    unsigned char x;
    unsigned char y;
    char pad2[6];
    unsigned char z;
    char pad3[3];
    int u;
};
class Method2 : public Base_7e4d0 {
  public:
    virtual void fn();
    Method2(int p, int r) : Base_7e4d0(p, 2) {
        u = r;
        z = g(a);
        x = g(b);
        y = g(c);
    }
};
class Closure2 : public Method2 {
  public:
    virtual void fn();
    int v;
    Closure2(int, int, int);
};
Closure2::Closure2(int p, int q, int r) : Method2(p, r) {
    v = q;
}