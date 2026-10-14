typedef unsigned int u32_1b7590;
struct Obj_1b7590 {
    char pad[0x124];
    volatile u32_1b7590 field;
};
extern void __cdecl thunk(u32_1b7590);
struct Inner_1b7590 {
    void method(int);
};
struct Global_1b7590 {
    char pad[0x50];
    Inner_1b7590* value;
};
extern Global_1b7590* g_1b7590;
void __fastcall target(Obj_1b7590* p) {
    u32_1b7590 x = p->field;
    if (x) {
        thunk(x);
        p->field = 0;
    }
    p->field = 0;
    g_1b7590->value->method(1);
}