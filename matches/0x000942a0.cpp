extern char a_942a0[], b[], c[];
extern "C" unsigned char __cdecl check(const char*);
class Base_942a0 {
  public:
    Base_942a0(int, int);
    virtual void f();
    char pad[9];
};
class Method3 : public Base_942a0 {
  public:
    Method3(int, int);
    virtual void f();
    unsigned char v1, v2, v3;
    char pad3[5];
    unsigned char v4;
    char pad4[3];
    int arg;
};
Method3::Method3(int x, int y) : Base_942a0(x, 3) {
    arg = y;
    v4 = check(a_942a0);
    v1 = check(b);
    v2 = check(c);
    v3 = check(c);
}
