struct Fallback { virtual int f0(); virtual int f1(); virtual int f2(); virtual int f3(); virtual int f4(); };
struct Obj { char pad0[0xa0]; void *pA0; char padA4[0x78]; Fallback *fb; };
extern int __fastcall FUN_002fc6f0(void *p);
int __fastcall target(Obj *self) {
    void *p = self->pA0;
    if (p) {
        int r = FUN_002fc6f0(p);
        return r + 0x30;
    }
    Fallback *f = self->fb;
    return f->f4();
}
