// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001a8e60 @ 0x001a8e60
struct Item {
    char data[0x18];
    void FUN_001a5d50();
};
struct Releasable {
    virtual void v0();
    virtual void release();
};
struct Config {
    char pad0[0x52];
    char flag;
    char pad53;
    int f54;
};
struct Sink {
    void FUN_00203e00(int value);
};
struct Inner {
    void FUN_001b92c0();
};
struct Selector {
    Inner *FUN_00086290(int arg);
};
struct World {
    char pad0[0x54];
    Selector *f54;
};
extern World *DAT_004dd700;
extern char DAT_004e1764;

struct Owner {
    char pad0[0x1c];
    Config *config;
    char pad20[4];
    Releasable *f24;
    Releasable *f28;
    Item items[20];
    Sink *sink;
    void FUN_001a8e60();
};

void Owner::FUN_001a8e60()
{
    DAT_004dd700->f54->FUN_00086290(0)->FUN_001b92c0();
    for (int i = 0; i < 20; i++)
        items[i].FUN_001a5d50();
    if (f28) {
        f28->release();
        f28 = 0;
    }
    if (f24) {
        f24->release();
        f24 = 0;
    }
    if (config->flag)
        sink->FUN_00203e00(config->f54);
    DAT_004e1764 = 0;
}
