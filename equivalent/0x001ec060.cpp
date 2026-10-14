// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 8/8)
// FUN_001ec060 @ 0x001ec060
struct StringList {
    char data[0x48];
    void FUN_001ef320();
    void FUN_001ef350();
    void FUN_001ef370(const char *s);
};

struct EventSink {
    void *handler;
    bool FUN_001efe20(StringList *args, const void *where, int name, float delay);
};

struct EventConfig {
    EventSink *sink;        // 0
    char pad04[4];
    char enabled;           // 8
};

struct Slot {
    unsigned __int64 FUN_001d4f70();
};

struct Entity {
    char pad00[8];
    char pos[0xe4];         // 0x8: position block passed to the sink
    Slot *slot;             // 0xec
};

extern unsigned __int64 DAT_004e3700;
extern EventConfig *DAT_004e36d8;

void __stdcall FUN_001ec060(Entity *entity, int name)
{
    if (entity == 0)
        return;
    if (entity->slot->FUN_001d4f70() != DAT_004e3700)
        return;

    StringList path;
    path.FUN_001ef320();
    path.FUN_001ef370("Objects");
    path.FUN_001ef370("FE");
    if (DAT_004e36d8->enabled)
        DAT_004e36d8->sink->FUN_001efe20(&path, entity->pos, name, 100.0f);
    path.FUN_001ef350();
}
