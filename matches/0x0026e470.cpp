typedef unsigned int U;
extern "C" char* __cdecl strncpy(char*, const char*, U);
class C {
    char pad[0x1c];

  public:
    void helper(void*, U);
    void f(U, char*);
};
void C::f(U a, char* s) {
    char b[0x108];
    *(U*)b = 1;
    *(U*)(b + 4) = a;
    strncpy(b + 8, s, 0x100);
    b[0x107] = 0;
    helper(b, 0x108);
}
