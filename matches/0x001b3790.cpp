struct Vector {
    float x, y, z;
};
extern int a, b, c;
unsigned char __cdecl lookup(const void*);
class Function_1b3790 {
  public:
    virtual void f();
    Function_1b3790(int, int);
    char pad[12];
};
class Function2 : public Function_1b3790 {
  public:
    virtual void f();
    Function2(int, int);
    unsigned char x, y;
    char pad2[6];
    unsigned char z;
    char pad3[3];
    int val;
};
Function2::Function2(int arg, int v) : Function_1b3790(arg, 2) {
    val = v;
    z = lookup(&a);
    x = lookup(&b);
    y = lookup(&c);
}