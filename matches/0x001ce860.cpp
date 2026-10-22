extern "C" unsigned char __cdecl Find(void*);
extern char gOne;
extern char gTwo;
class Function_1ce860 {
  public:
    Function_1ce860(int, int);
    virtual void f();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int c;
};
class Method1 : public Function_1ce860 {
  public:
    Method1(int x, int y) : Function_1ce860(x, 1) {
        c = y;
        b = Find(&gOne);
        a = Find(&gTwo);
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(int x, int y, int z);
    virtual void f();
    int d;
};
Closure1::Closure1(int x, int y, int z) : Method1(x, z) {
    d = y;
}