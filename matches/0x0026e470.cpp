typedef unsigned int U_26e470;
extern "C" char* __cdecl strncpy(char*, const char*, U_26e470);
class C_26e470 {
    char pad[0x1c];

  public:
    void helper(void*, U_26e470);
    void f(U_26e470, char*);
};
void C_26e470::f(U_26e470 a, char* s) {
    char b[0x108];
    *(U_26e470*)b = 1;
    *(U_26e470*)(b + 4) = a;
    strncpy(b + 8, s, 0x100);
    b[0x107] = 0;
    helper(b, 0x108);
}
