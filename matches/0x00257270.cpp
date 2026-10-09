extern void __cdecl helper(void*, unsigned int);
class C {
    char pad[0x44];

  public:
    void f(unsigned int x);
};
void C::f(unsigned int x) {
    helper((char*)this + 0x44, x);
}