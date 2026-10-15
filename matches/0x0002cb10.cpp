class Obj {
  public:
    char Method(int, int, int, int, char, int);
};
typedef char (Obj::*Fn)(int, int, int, int, char, int);
void __cdecl FUN_0002cb10(Obj* self, int* args, char* out, Fn fn) {
    int* p = args;
    int a = *p++;
    int b = *p++;
    int c = *p++;
    int d = *p++;
    char e = *(char*)p++;
    int f = *p++;
    char value = (self->*fn)(a, b, c, d, e, f);
    if (out)
        *out = value;
}