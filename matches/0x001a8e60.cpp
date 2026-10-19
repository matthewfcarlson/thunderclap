// FUN_001a8e60 @ 0x001a8e60
#include "decls/address.h"
#include "decls/data/game/hulkfight/scenario.h"
struct Item_1a8e60 {
    char data[0x18];
    void FUN_001a5d50();
};
struct Releasable_1a8e60 {
    virtual void v0();
    virtual void release();
};
struct Config_1a8e60 {
    char pad0[0x52];
    char flag;
    char pad53;
    int f54;
};
struct Sink_1a8e60 {
    void FUN_00203e00(int value);
};
struct Inner_1a8e60 {
    void FUN_001b92c0(int arg);
};
struct Selector_1a8e60 {
    Inner_1a8e60 *FUN_00086290();
};
struct World {
    char pad0[0x54];
    Selector_1a8e60 *f54;
};

struct Owner_1a8e60 {
    char pad0[0x1c];
    Config_1a8e60 *config;
    char pad20[4];
    Releasable_1a8e60 *f24;
    Releasable_1a8e60 *f28;
    Item_1a8e60 items[20];
    Sink_1a8e60 *sink;
    void FUN_001a8e60();
};

void Owner_1a8e60::FUN_001a8e60()
{
    DAT_004dd700->f54->FUN_00086290()->FUN_001b92c0(0);
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
    (*(char*)&DAT_004e1764) = 0;
}
