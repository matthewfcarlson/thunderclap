extern unsigned char FUN_001d04d0(const char*);
extern char g100[], g0f0[], g134[];
class Base {
  public:
    Base(const char*, int);
    virtual void v0();
    char pad[0xc];
};
class CFEManager : public Base {
  public:
    CFEManager(const char*, int);
    char c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c1a, c1b;
    int m1c;
};
CFEManager::CFEManager(const char* p, int x) : Base(p, 6) {
    m1c = x;
    c18 = FUN_001d04d0(g100);
    c10 = FUN_001d04d0(g0f0);
    c11 = FUN_001d04d0(g0f0);
    c12 = FUN_001d04d0(g0f0);
    c13 = FUN_001d04d0(g0f0);
    c14 = FUN_001d04d0(g134);
    c15 = FUN_001d04d0(g134);
}
