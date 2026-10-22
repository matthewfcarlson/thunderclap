typedef unsigned char u8;
struct CtorV_001d0480 {
    CtorV_001d0480(int, int);
    virtual void v_001d0480();
};
u8 __cdecl query(const char*);
extern const char a[];
extern const char b[];
class Function_1b15f0 : public CtorV_001d0480 {
  public:
    Function_1b15f0(int n) : CtorV_001d0480(n, 2) { }
};
class Function2 : public Function_1b15f0 {
  public:
    virtual void f();
    char pad[12];
    u8 x;
    u8 y;
    char pad2[6];
    u8 z;
    char pad3[3];
    int data;
    Function2(int, int);
};
Function2::Function2(int n, int d) : Function_1b15f0(n) {
    data = d;
    z = query(a);
    x = query(b);
    y = query(b);
}