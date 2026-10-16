// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00044910 @ 0x00044910
// Look up five-plus-one named entries in the global registry and seed the six handles.
#include "decls/address.h"

struct Entry_44910 {
    char pad[0x5c];
    int value;                      // 0x5c
};

struct Registry_44910 {
    Entry_44910 *FUN_00232840(unsigned __int64 key);
};

struct Handle_44910 {
    int first;
    int second;
    int third;
    void FUN_00233fe0(int v);
};

extern const char *DAT_0048f698;
extern const char *DAT_0048f69c;
extern Registry_44910 *DAT_004e5af8;

struct Obj_44910 {
    char pad[0xe0];
    Handle_44910 h[6];                    // 0xe0 .. 0x128
    bool FUN_00044910();
};

bool Obj_44910::FUN_00044910()
{
    const char *name = DAT_0048f698;
    Registry_44910 *reg = DAT_004e5af8;
    h[0].FUN_00233fe0(reg->FUN_00232840(FUN_002672f0(name, 0, 0))->value);
    h[1].FUN_00233fe0(h[0].first);
    h[2].FUN_00233fe0(h[0].first);
    h[3].FUN_00233fe0(h[0].first);
    h[4].FUN_00233fe0(h[0].first);
    name = DAT_0048f69c;
    reg = DAT_004e5af8;
    h[5].FUN_00233fe0(reg->FUN_00232840(FUN_002672f0(name, 0, 0))->value);
    return true;
}
