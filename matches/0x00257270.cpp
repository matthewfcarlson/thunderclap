extern void __cdecl helper(void*, unsigned int);
class C_257270 {
    char pad[0x44];

  public:
    void f(unsigned int x);
};
void C_257270::f(unsigned int x) {
    helper((char*)this + 0x44, x);
}