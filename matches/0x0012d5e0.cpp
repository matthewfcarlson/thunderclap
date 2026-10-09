typedef unsigned int u32; typedef unsigned char u8;
extern void* __cdecl alloc(unsigned int);
struct Sub { char pad[8]; void init(); };
struct Threat { u32 vptr; char pad4[8]; u8 flagC; char padD[3]; Sub sub; u8 flag18; void init(int); };
struct Factory { void* vtable; Threat* vfunc_5(); };
Threat* Factory::vfunc_5() {
    Threat* p = (Threat*)alloc(0x20);
    if (p) {
        p->init(0);
        p->vptr = 0x410bd4;
        p->flagC = 1;
        p->sub.init();
        p->flag18 = 1;
        return p;
    }
    return 0;
}
