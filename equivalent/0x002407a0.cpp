// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 12/12)
// FUN_002407a0 @ 0x002407a0
struct Str_2407a0 {
    Str_2407a0 *FUN_0023fc40(const char *text, int flag);
};

struct Subsystem_2407a0 {
    virtual void init();
    char pad04[0x68 - 4];
    int handle;
};

struct Loader_2407a0 {
    Loader_2407a0 *FUN_0024d360(Subsystem_2407a0 *sys);
};

struct Registry_2407a0 {
    void FUN_00265210(Loader_2407a0 *loader, int handle);
};

extern Str_2407a0 *DAT_004e5ca0;
extern int DAT_004e5ca4;
extern int DAT_004e5ca8;
extern int DAT_004e5cac;
extern Registry_2407a0 *DAT_00527c58;

void *FUN_0008d690(unsigned int size);
inline void *operator new(unsigned int, void *p) throw() { return p; }
Subsystem_2407a0 *FUN_00256660();
Subsystem_2407a0 *FUN_00245330();
Subsystem_2407a0 *FUN_00241660();
Subsystem_2407a0 *FUN_00255d20();
Subsystem_2407a0 *FUN_00255480();
Subsystem_2407a0 *FUN_00254e70();
Subsystem_2407a0 *FUN_00254a70();
Subsystem_2407a0 *FUN_00254640();
Subsystem_2407a0 *FUN_00253c50();
Subsystem_2407a0 *FUN_00253770();
Subsystem_2407a0 *FUN_00253390();
Subsystem_2407a0 *FUN_00252fb0();
Subsystem_2407a0 *FUN_00252b50();
Subsystem_2407a0 *FUN_002527a0();
Subsystem_2407a0 *FUN_00252370();
Subsystem_2407a0 *FUN_002518d0();
Subsystem_2407a0 *FUN_002513c0();
Subsystem_2407a0 *FUN_00250db0();
Subsystem_2407a0 *FUN_002509b0();
Subsystem_2407a0 *FUN_00250540();
Subsystem_2407a0 *FUN_002500d0();
Subsystem_2407a0 *FUN_0024fc50();
Subsystem_2407a0 *FUN_0024f810();
Subsystem_2407a0 *FUN_0024ea00();
Subsystem_2407a0 *FUN_0024e540();
Subsystem_2407a0 *FUN_0024df00();
void *FUN_0024d200();
Loader_2407a0 *FUN_00247530(void *);
Subsystem_2407a0 *FUN_0024d5a0();
int FUN_00242bd0();
int FUN_00267f80();

void FUN_002407a0(unsigned int flags)
{
    Str_2407a0 *str;
    DAT_004e5ca4 = flags;
    void *mem = FUN_0008d690(0xc);
    if (mem != 0) {
        str = ((Str_2407a0 *)mem)->FUN_0023fc40("english", 2);
        DAT_004e5ca0 = str;
    } else {
        DAT_004e5ca0 = 0;
    }
    FUN_00256660()->init();
    FUN_00245330()->init();
    FUN_00241660()->init();
    FUN_00255d20()->init();
    FUN_00255480()->init();
    FUN_00254e70()->init();
    FUN_00254a70()->init();
    FUN_00254640()->init();
    FUN_00253c50()->init();
    FUN_00253770()->init();
    FUN_00253390()->init();
    FUN_00252fb0()->init();
    FUN_00252b50()->init();
    FUN_002527a0()->init();
    FUN_00252370()->init();
    FUN_002518d0()->init();
    FUN_002513c0()->init();
    FUN_00250db0()->init();
    FUN_002509b0()->init();
    FUN_00250540()->init();
    FUN_002500d0()->init();
    FUN_0024fc50()->init();
    FUN_0024f810()->init();
    FUN_0024ea00()->init();
    FUN_0024e540()->init();
    FUN_0024df00();
    if (flags & 1) {
        Loader_2407a0 *l;
        l = FUN_00247530(FUN_0024d200());
        if (l != 0)
            l = l->FUN_0024d360(FUN_00245330());
        DAT_00527c58->FUN_00265210(l, FUN_00245330()->handle);
        l = FUN_00247530(FUN_0024d200());
        if (l != 0)
            l = l->FUN_0024d360(FUN_00256660());
        DAT_00527c58->FUN_00265210(l, FUN_00256660()->handle);
        l = FUN_00247530(FUN_0024d200());
        if (l != 0)
            l = l->FUN_0024d360(FUN_00241660());
        DAT_00527c58->FUN_00265210(l, FUN_00241660()->handle);
        l = FUN_00247530(FUN_0024d200());
        if (l != 0)
            l = l->FUN_0024d360(FUN_0024d5a0());
        DAT_00527c58->FUN_00265210(l, FUN_0024d5a0()->handle);
    }
    DAT_004e5cac = FUN_00242bd0();
    DAT_004e5ca8 = FUN_00267f80();
}
