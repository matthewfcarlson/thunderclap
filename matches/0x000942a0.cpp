extern char a[], b[], c[];
extern "C" unsigned char __cdecl check(const char*);
class Base {
  public:
    Base(int, int);
    virtual void f();
    char pad[9];
};
class Method3 : public Base {
  public:
    Method3(int, int);
    virtual void f();
    unsigned char v1, v2, v3;
    char pad3[5];
    unsigned char v4;
    char pad4[3];
    int arg;
};
Method3::Method3(int x, int y) : Base(x, 3) {
    arg = y;
    v4 = check(a);
    v1 = check(b);
    v2 = check(c);
    v3 = check(c);
}
