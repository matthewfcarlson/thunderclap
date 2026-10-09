class Base {
  public:
    void Init(void*, int);
};
extern "C" char __cdecl FUN_001d04d0(const char*);
class Target : public Base {
  public:
    int pad0;
    char pad4[0x0c];
    char b10;
    char b11;
    char b12;
    char b13;
    char b14;
    char b15;
    char b16;
    char b17;
    char b18;
    char pad19[3];
    int member1c;
    Target(void* p, int x);
};
Target::Target(void* p, int x) {
    Init(p, 3);
    *(int*)this = 0x420e24;
    member1c = x;
    b18 = FUN_001d04d0((const char*)0x48e100);
    b10 = FUN_001d04d0((const char*)0x48e134);
    b11 = FUN_001d04d0((const char*)0x48e134);
    b12 = FUN_001d04d0((const char*)0x48e134);
}