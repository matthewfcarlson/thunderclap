class Obj {
  public:
    typedef unsigned char (Obj::*Fn)(int, int, int, int);
};
void f(Obj* obj, int* args, unsigned char* out, Obj::Fn fn) {
    int* p = args;
    int a = *p++;
    int b = *p;
    int c = *++p;
    *(unsigned char*)&args = *(unsigned char*)(p + 1);
    unsigned char v = (obj->*fn)(a, b, c, (int)args);
    if (out)
        *out = v;
}