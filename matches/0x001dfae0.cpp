class Base {
  public:
    Base(const char*, int);
};
extern char FUN_001d04d0(const char*);
class Target : public Base {
  public:
    char pad[0x10];
    char m10;
    char m11;
    char m12;
    char m13;
    char m14;
    char m15;
    char pad16[2];
    char m18;
    char pad19[3];
    int m1c;
    Target(const char*, int);
};
Target::Target(const char* p, int n) : Base(p, 6) {
    *(int*)this = 0x423318;
    m1c = n;
    m18 = FUN_001d04d0((const char*)0x48e100);
    m10 = FUN_001d04d0((const char*)0x48e0f0);
    m11 = FUN_001d04d0((const char*)0x48e0f0);
    m12 = FUN_001d04d0((const char*)0x48e134);
    m13 = FUN_001d04d0((const char*)0x48e0f0);
    m14 = FUN_001d04d0((const char*)0x48e10c);
    m15 = FUN_001d04d0((const char*)0x48e10c);
}