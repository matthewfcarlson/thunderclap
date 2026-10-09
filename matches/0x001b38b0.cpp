extern void __stdcall FUN_001d0480(int, int);
extern char __cdecl FUN_001d04d0(int);
class Target {
  public:
    char pad0[0x10];
    char b10, b11, b12, b13, b14;
    char pad15[3];
    char b18;
    char pad19[3];
    int field1c;
    Target(int, int);
};
Target::Target(int a, int b) {
    FUN_001d0480(a, 5);
    *(volatile int*)this = 0x41d9a4;
    field1c = b;
    b18 = FUN_001d04d0(0x48e100);
    b10 = FUN_001d04d0(0x48e134);
    b11 = FUN_001d04d0(0x48e134);
    b12 = FUN_001d04d0(0x48e128);
    b13 = FUN_001d04d0(0x48e128);
    b14 = FUN_001d04d0(0x48e128);
}