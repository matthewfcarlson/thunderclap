typedef unsigned int u32;
extern int vtable;
struct Sub {
    void init();
};
extern u32 __cdecl makeobj(const char*, int);
extern int zeroData;
struct Obj {
    u32 vt;
    char pad[0x18];
    Sub s;
    char pad2[0x1b];
    u32 a;
    u32 b;
    u32 flags;
    unsigned char c[4];
};
Obj* __fastcall FUN_00262090(Obj* p) {
    p->vt = (u32)&vtable;
    p->s.init();
    p->a = makeobj("MySeqTrack", 0);
    p->b = makeobj((const char*)&zeroData, 0);
    p->c[0] &= 0xfc;
    p->flags = (p->flags & 0xfffffc01) | 1;
    return p;
}