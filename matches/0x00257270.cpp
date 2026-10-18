extern int __cdecl helper(void*, unsigned int);
class C_257270 {
    char pad[0x44];

  public:
    int f(unsigned int x);
};
int C_257270::f(unsigned int x) {
    return helper((char*)this + 0x44, x);
}