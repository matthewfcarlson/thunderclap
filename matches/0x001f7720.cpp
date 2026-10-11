extern "C" char DAT_00424d4c[];
class Base {
  public:
    Base(int, int);
};
extern char sA[];
extern char sB[];
extern char sC[];
class Obj : public Base {
  public:
    Obj(int, int);
    char pad0[0x10];
    char m10, m11, m12;
    char pad13[5];
    char m18;
    char pad19[3];
    int m1c;
};
extern char FUN_001d04d0(const char*);
Obj::Obj(int a, int b) : Base(a, 3) {
    *(int*)this = ((int)DAT_00424d4c);
    m1c = b;
    m18 = FUN_001d04d0(sA);
    m10 = FUN_001d04d0(sB);
    m11 = FUN_001d04d0(sC);
    m12 = FUN_001d04d0(sC);
}