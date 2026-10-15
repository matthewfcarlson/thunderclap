struct Obj {
    char pad[0x1cf5];
    char flag;
};
extern "C" __int64 __cdecl Find(int, int, int);
class X {
  public:
    Obj* Get(__int64);
    char Run(int a, int b);
};
char X::Run(int a, int b) {
    __int64 v = Find(a, 0, 0);
    Obj* o = Get(v);
    if (!o)
        return 0;
    o->flag = 1;
    return 1;
}