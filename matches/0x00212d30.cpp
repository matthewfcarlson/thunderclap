struct Obj_212d30 {
    char pad[8];
    unsigned* out;
    char pad2[4];
    unsigned* state;
};
extern void __cdecl FUN_00217440(Obj_212d30*);
extern unsigned __cdecl FUN_00215010(Obj_212d30*);
unsigned __cdecl FUN_00212d30(Obj_212d30* p) {
    if (p->state[0x4c / 4] >= p->state[0x48 / 4])
        FUN_00217440(p);
    unsigned v = FUN_00215010(p);
    unsigned* q = p->out;
    q[1] = v;
    q[0] = 8;
    p->out = p->out + 2;
    return v;
}