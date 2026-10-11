extern "C" char DAT_0042dc94[];
typedef unsigned int u32;
extern void* __cdecl alloc(unsigned int);
class C;
class Obj {
  public:
    u32 vf;
    char pad[0x3c];
    u32 value;
    u32 a44;
    u32 a48;
    u32 unused4c;
    u32 a50;
    u32 a54;
    void init(C*);
    void finish();
};
class C {
  public:
    char pad[0x40];
    u32 value;
    Obj* vfunc_4();
};
Obj* C::vfunc_4() {
    Obj* p = (Obj*)alloc(0x60);
    if (p) {
        p->init(this);
        p->value = 0;
        p->vf = ((int)DAT_0042dc94);
        p->a44 = 0;
        p->a48 = 0;
        p->a50 = 0;
        p->a54 = 0;
        p->value = value;
        p->finish();
        return p;
    }
    return 0;
}