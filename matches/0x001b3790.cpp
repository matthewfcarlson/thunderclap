struct Vector {
    float x, y, z;
};
extern int a, b, c;
unsigned char __cdecl lookup(const void*);
class Base {
  public:
    virtual void f();
    Base(int, int);
    char pad[12];
};
class Function2 : public Base {
  public:
    virtual void f();
    Function2(int, int);
    unsigned char x, y;
    char pad2[6];
    unsigned char z;
    char pad3[3];
    int val;
};
Function2::Function2(int arg, int v) : Base(arg, 2) {
    val = v;
    z = lookup(&a);
    x = lookup(&b);
    y = lookup(&c);
}