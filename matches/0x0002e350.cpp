class Base {
  public:
    void Init(int, int);
};
class Method3 : public Base {
  public:
    int v;
    char p[0x0c];
    unsigned char b10, b11, b12;
    char q[5];
    unsigned char b18;
    int m1c;
    Method3(int, int);
};
extern "C" unsigned char __cdecl FUN_001d04d0(const char*);
extern const char s1[];
extern const char s2[];
extern const char DAT_0048e0f0[];
extern const char DAT_0048e10c[];
Method3::Method3(int a, int x) {
    Init(a, 3);
    v = 0x3f432c;
    m1c = x;
    b18 = FUN_001d04d0(s1);
    b10 = FUN_001d04d0(DAT_0048e0f0);
    b11 = FUN_001d04d0(DAT_0048e10c);
    b12 = FUN_001d04d0(DAT_0048e10c);
}