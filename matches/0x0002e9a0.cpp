extern "C" char FUN_001d04d0(const char*);
extern const char gA[];
extern const char gB[];
struct Base {
    virtual void f0();
    Base(int, int);
    char pad[12];
    char b10;
    char p11[7];
    char b18;
};
struct Method1 : Base {
    Method1(int a, int b) : Base(a, 1) {
        m1c = b;
        b18 = FUN_001d04d0(gA);
        b10 = FUN_001d04d0(gB);
    }
    virtual void f0();
    int m1c;
};
struct Closure1 : Method1 {
    Closure1(int a, int c, int b);
    virtual void f0();
    int m20;
};
Closure1::Closure1(int a, int c, int b) : Method1(a, b) {
    m20 = c;
}
