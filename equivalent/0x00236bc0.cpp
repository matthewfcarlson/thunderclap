// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 2/2)
// FUN_00236bc0 @ 0x00236bc0
int FUN_00238190(int index);
int FUN_00266da0(int value);

struct Sink_236bc0 {
    bool FUN_00232290(void *item);
};

struct Item_236bc0 {
    char pad00[0xc];
    unsigned int flags;
    float f10;
    float f14;
};

class Source_236bc0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual float v6();
    virtual float v7();
    virtual void v8(); virtual void v9();
    virtual Item_236bc0 *v10(int a, Sink_236bc0 *sink, int c);
    char pad04[4];
    unsigned int mode;
    bool FUN_00236bc0(int a, Sink_236bc0 *sink, int c);
};

bool Source_236bc0::FUN_00236bc0(int a, Sink_236bc0 *sink, int c)
{
    int saved = FUN_00266da0(FUN_00238190(3));
    Item_236bc0 *item = v10(a, sink, c);
    if (!item) {
        FUN_00266da0(saved);
        return false;
    }
    item->f10 = v6();
    item->f14 = v7();
    item->flags ^= (mode ^ item->flags) & 3;
    bool ok = sink->FUN_00232290(item);
    FUN_00266da0(saved);
    return ok;
}
