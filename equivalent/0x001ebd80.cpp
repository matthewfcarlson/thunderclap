// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001ebd80 @ 0x001ebd80
struct Id {
    unsigned __int64 key;
};

struct IdCopy {
    unsigned __int64 key;
    void FUN_0027af30(const Id *src);
    IdCopy(const Id &o) { FUN_0027af30(&o); }
};

struct StringList {
    char data[0x48];
    void FUN_001ef320();
    void FUN_001ef350();
    void FUN_001ef370(const char *s);
    void FUN_001ef3c0(IdCopy id);
};

struct EventSink {
    void *handler;
    bool FUN_001efe20(StringList *args, const void *where, int name, float delay);
};

struct EventConfig {
    EventSink *sink;
    char pad04[4];
    char enabled;
};

struct Descriptor {
    char pad00[8];
    Id id;                  // 0x08
};

struct Prop {
    char pad00[8];
    char where[1];          // 0x08
    char pad09[0xe3];
    Descriptor *descriptor; // 0xec
};

extern EventConfig *DAT_004e36d8;

// Posts a "Objects/Props/<id>" event for a prop.
void __stdcall FUN_001ebd80(Prop *prop, int name, float delay, int unused) {
    if (prop == 0 || prop->descriptor == 0)
        return;
    StringList path;
    path.FUN_001ef320();
    path.FUN_001ef370("Objects");
    path.FUN_001ef370("Props");
    path.FUN_001ef3c0(IdCopy(prop->descriptor->id));
    if (DAT_004e36d8->enabled)
        DAT_004e36d8->sink->FUN_001efe20(&path, prop->where, name, delay);
    path.FUN_001ef350();
}
