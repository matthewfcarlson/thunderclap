struct Obj {
    char pad[0x1a8];
    int value;
};
struct Mgr {
    Obj* get(unsigned __int64);
};
struct Holder {
    char pad[4];
    Mgr* mgr;
    void fn(int a, int b);
};
extern "C" unsigned __int64 __cdecl FUN_0027b020(int);
void Holder::fn(int a, int b) {
    Mgr* m = mgr;
    unsigned __int64 x = FUN_0027b020(a);
    Obj* o = m->get(x);
    o->value = b;
}