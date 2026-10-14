typedef unsigned __int64 U64_e0170;
extern U64_e0170 __cdecl FUN_0027b020(unsigned long);
class C_e0170 {
    char pad[0x10];
    U64_e0170 value;

  public:
    void f(unsigned long);
};
void C_e0170::f(unsigned long x) {
    value = FUN_0027b020(x);
}