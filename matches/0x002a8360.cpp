extern "C" char DAT_0042dc94[];
typedef unsigned int u32_2a8360;
extern void* __cdecl alloc(unsigned int);
class C_2a8360;
class Obj_2a8360 {
  public:
    u32_2a8360 vf;
    char pad[0x3c];
    u32_2a8360 value;
    u32_2a8360 a44;
    u32_2a8360 a48;
    u32_2a8360 unused4c;
    u32_2a8360 a50;
    u32_2a8360 a54;
    void init(C_2a8360*);
    void finish();
};
class C_2a8360 {
  public:
    char pad[0x40];
    u32_2a8360 value;
    Obj_2a8360* vfunc_4();
};
Obj_2a8360* C_2a8360::vfunc_4() {
    Obj_2a8360* p = (Obj_2a8360*)alloc(0x60);
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