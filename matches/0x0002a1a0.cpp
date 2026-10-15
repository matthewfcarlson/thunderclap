struct Pair {
    char pad[8];
    int a, b;
    Pair* Get(int);
};
extern "C" __int64 __cdecl Split(const char*, int, int);
extern "C" void __cdecl Format(void*, int, int, int);
extern float zero;
extern char buffer;
class C {
  public:
    float* Fn(const char*);
    Pair* Make(__int64);
};
float* C::Fn(const char* s) {
    __int64 v = Split(s, 0, 0);
    Pair* p = Make(v);
    if (p)
        p = p->Get(0);
    if (!p)
        return &zero;
    Format(&buffer, 0x20, p->a, p->b);
    return (float*)&buffer;
}