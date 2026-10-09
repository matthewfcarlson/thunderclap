typedef unsigned char u8;
typedef unsigned int u32;
struct Sub {
    char pad[8];
};
void __fastcall InitSub(Sub*);
extern char vtUnlockable[];
extern char vtCheat[];
struct CUnlockable {
    virtual void v0();
    char a[4];
    u8 f8;
    char b[7];
    Sub sub;
    u32 f18;
    u8 f1c;
    char c[3];
    u8 f20;
    char d[3];
    u32 f24;
    u8 f28;
};
struct CUnlockableCheat : CUnlockable {};
CUnlockableCheat* __fastcall FUN_00091da0(CUnlockableCheat* self) {
    *(void**)self = vtUnlockable;
    self->f8 = 1;
    InitSub(&self->sub);
    self->f18 = 0;
    self->f20 = 0;
    self->f28 = 0;
    *(void**)self = vtCheat;
    self->f24 = 0xffffffff;
    return self;
}