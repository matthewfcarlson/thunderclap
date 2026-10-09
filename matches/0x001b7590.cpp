typedef unsigned int u32;
struct Obj {
    char pad[0x124];
    volatile u32 field;
};
extern void __cdecl thunk(u32);
struct Inner {
    void method(int);
};
struct Global {
    char pad[0x50];
    Inner* value;
};
extern Global* g;
void __fastcall target(Obj* p) {
    u32 x = p->field;
    if (x) {
        thunk(x);
        p->field = 0;
    }
    p->field = 0;
    g->value->method(1);
}