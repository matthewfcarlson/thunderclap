typedef unsigned __int64 U64;
extern U64 __cdecl FUN_0027b020(unsigned long);
class C {
    char pad[0x10];
    U64 value;

  public:
    void f(unsigned long);
};
void C::f(unsigned long x) {
    value = FUN_0027b020(x);
}