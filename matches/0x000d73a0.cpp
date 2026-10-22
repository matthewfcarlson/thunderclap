struct CtorV_001d0480 {
    CtorV_001d0480(int, int);
    virtual void v_001d0480();
};
extern "C" unsigned char __cdecl lookup(const char*);
extern const char keyA[];
extern const char keyB[];
class Function_d73a0 : public CtorV_001d0480 {
  public:
    Function_d73a0(int a) : CtorV_001d0480(a, 1) { }
};
class Method1 : public Function_d73a0 {
  public:
    virtual void run();
    char pad0[12];
    unsigned char flag1;
    char pad1[7];
    unsigned char flag2;
    char pad2[3];
    int value;
    Method1(int a, int c) : Function_d73a0(a) {
        value = c;
        flag2 = lookup(keyA);
        flag1 = lookup(keyB);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void run();
    int other;
    Closure1(int a, int b, int c);
};
Closure1::Closure1(int a, int b, int c) : Method1(a, c), other(b) {}