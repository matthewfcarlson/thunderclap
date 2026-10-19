extern "C" char hulk_at_0048e0f0[];
extern "C" char hulk_at_0048e100[];
class Base {
  public:
    virtual void f();
    char pad[12];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    int x;
    Base(const char*, int);
};
extern "C" unsigned char __cdecl get(unsigned int);
class Middle : public Base {
  public:
    virtual void f();
    Middle(const char* s, int n) : Base(s, 1) {
        x = n;
        b = get(((int)hulk_at_0048e100));
        a = get(((int)hulk_at_0048e0f0));
    }
};
class Derived : public Middle {
  public:
    virtual void f();
    int y;
    Derived(const char*, int, int);
};
Derived::Derived(const char* s, int x, int y) : Middle(s, y) {
    this->y = x;
}