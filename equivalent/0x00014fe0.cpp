// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 4/4)
// CSweepAction::vfunc_6 @ 0x00014fe0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0

struct Name {
    char data[8];
    void FUN_0027b040(const char *s);
};

class Driver {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    Name name;                // 0x8
    char pad10[4];
    int mode;                 // 0x14
    Driver *FUN_002248f0(int a);
};

struct LayerSet {
    void FUN_00222890(Driver *d, float dur, float a, float b, float c, float e, float f);
};

struct Params {
    char pad0[0x18];
    float a;                  // 0x18
    float c;                  // 0x1c
    float e;                  // 0x20
};

struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(void *owner);
LayerSet *__fastcall FUN_00059a40(Context *ctx);
void *thunk_FUN_0008d690(unsigned int size);

class CSweepAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x18];
    void *owner;              // 0x1c
    Params *params;           // 0x20
    Driver *driver;           // 0x24
};

bool CSweepAction::vfunc_6(int arg)
{
    LayerSet *layers = FUN_00059a40(FUN_000592a0(owner));
    if (layers == 0)
        return false;
    Params *p = params;
    float c = p->c;
    float e = p->e;
    float a = p->a;
    Driver *mem = (Driver *)thunk_FUN_0008d690(0x70);
    Driver *d = 0;
    if (mem)
        d = mem->FUN_002248f0(0);
    driver = d;
    d->name.FUN_0027b040("sweep");
    driver->AddRef();
    driver->mode = 2;
    layers->FUN_00222890(driver, -1.0f, a, 1.0f, c, e, -1.0f);
    return true;
}
