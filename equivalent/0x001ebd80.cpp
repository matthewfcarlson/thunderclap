// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001ebd80 @ 0x001ebd80
#include "decls/data/game/global.h"

struct Id_1ebd80 {
    unsigned __int64 key;
};

struct IdCopy_1ebd80 {
    unsigned __int64 key;
    void FUN_0027af30(const Id_1ebd80 *src);
    IdCopy_1ebd80(const Id_1ebd80 &o) { FUN_0027af30(&o); }
};

struct StringList_1ebd80 {
    char data[0x48];
    void FUN_001ef320();
    void FUN_001ef350();
    void FUN_001ef370(const char *s);
    void FUN_001ef3c0(IdCopy_1ebd80 id);
};

struct EventSink_1ebd80 {
    void *handler;
    bool FUN_001efe20(StringList_1ebd80 *args, const void *where, int name, float delay);
};

struct EventConfig_1ebd80 {
    EventSink_1ebd80 *sink;
    char pad04[4];
    char enabled;
};

struct Descriptor_1ebd80 {
    char pad00[8];
    Id_1ebd80 id;                  // 0x08
};

struct Prop_1ebd80 {
    char pad00[8];
    char where[1];          // 0x08
    char pad09[0xe3];
    Descriptor_1ebd80 *descriptor; // 0xec
};


// Posts a "Objects/Props/<id>" event for a prop.
void __stdcall FUN_001ebd80(Prop_1ebd80 *prop, int name, float delay, int unused) {
    if (prop == 0 || prop->descriptor == 0)
        return;
    StringList_1ebd80 path;
    path.FUN_001ef320();
    path.FUN_001ef370("Objects");
    path.FUN_001ef370("Props");
    path.FUN_001ef3c0(IdCopy_1ebd80(prop->descriptor->id));
    if ((*(EventConfig_1ebd80**)&DAT_004e36d8)->enabled)
        (*(EventConfig_1ebd80**)&DAT_004e36d8)->sink->FUN_001efe20(&path, prop->where, name, delay);
    path.FUN_001ef350();
}
