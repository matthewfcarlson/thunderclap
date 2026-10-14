// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 2/2)
// FUN_00236bc0 @ 0x00236bc0
int FUN_00238190(int index);
int FUN_00266da0(int value);

struct Sink {
    bool FUN_00232290(void *item);
};

struct Item {
    char pad00[0xc];
    unsigned int flags;
    float f10;
    float f14;
};

class Source {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual float v6();
    virtual float v7();
    virtual void v8(); virtual void v9();
    virtual Item *v10(int a, Sink *sink, int c);
    char pad04[4];
    unsigned int mode;
    bool FUN_00236bc0(int a, Sink *sink, int c);
};

bool Source::FUN_00236bc0(int a, Sink *sink, int c)
{
    int saved = FUN_00266da0(FUN_00238190(3));
    Item *item = v10(a, sink, c);
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
