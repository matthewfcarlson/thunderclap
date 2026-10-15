struct Obj {
    char pad[0x140];
    int state;
};
struct Holder {
  public:
    Obj* Get(unsigned long long);
    bool Check(int);
};
extern "C" unsigned long long __cdecl FUN_002672f0(int, int, int);
bool Holder::Check(int x) {
    unsigned long long v = FUN_002672f0(x, 0, 0);
    Obj* o = Get(v);
    if (!o)
        return false;
    return o->state != 3;
}