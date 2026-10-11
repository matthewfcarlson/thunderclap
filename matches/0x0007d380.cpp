extern "C" char DAT_003ff014[];
extern "C" char FUN_001d04d0(const char*);
extern const char s0[], s1[], s2[], s3[];
class Base {
  public:
    void Init(const char*, int);
};
class Target : public Base {
  public:
    int vptr;
    char pad4[12];
    char b10;
    char b11;
    char b12;
    char b13;
    char pad14[4];
    char b18;
    char pad19[3];
    int member1c;
    Target(const char*, int);
};
Target::Target(const char* p, int x) {
    Init(p, 4);
    vptr = ((int)DAT_003ff014);
    member1c = x;
    b18 = FUN_001d04d0(s0);
    b10 = FUN_001d04d0(s1);
    b11 = FUN_001d04d0(s2);
    b12 = FUN_001d04d0(s3);
    b13 = FUN_001d04d0(s3);
}