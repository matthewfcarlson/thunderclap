class Base {
  public:
    Base(int, int);
    virtual void f();
    char pad[12];
    char b10;
    char pad2[7];
    char b18;
    char pad3[3];
    int x1c;
};
extern "C" int check(const char*);
extern const char str1[];
extern const char str2[];
class Method1 : public Base {
  public:
    Method1(int a, int c) : Base(a, 1) {
        x1c = c;
        b18 = (char)check(str1);
        b10 = (char)check(str2);
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(int a, int b, int c);
    virtual void f();
    int x20;
};
Closure1::Closure1(int a, int b, int c) : Method1(a, c) {
    x20 = b;
}