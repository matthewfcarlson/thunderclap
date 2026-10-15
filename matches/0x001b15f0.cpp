typedef unsigned char u8;
void __stdcall init(int, int);
u8 __cdecl query(const char*);
extern const char a[];
extern const char b[];
class Base {
  public:
    Base(int n) { init(n, 2); }
};
class Function2 : public Base {
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
Function2::Function2(int n, int d) : Base(n) {
    data = d;
    z = query(a);
    x = query(b);
    y = query(b);
}