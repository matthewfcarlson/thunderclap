// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 8/8)
// FUN_001ec060 @ 0x001ec060
#include "decls/data/game/global.h"

struct StringList_1ec060 {
    char data[0x48];
    void FUN_001ef320();
    void FUN_001ef350();
    void FUN_001ef370(const char *s);
};

struct EventSink_1ec060 {
    void *handler;
    bool FUN_001efe20(StringList_1ec060 *args, const void *where, int name, float delay);
};

struct EventConfig_1ec060 {
    EventSink_1ec060 *sink;        // 0
    char pad04[4];
    char enabled;           // 8
};

struct Slot_1ec060 {
    unsigned __int64 FUN_001d4f70();
};

struct Entity {
    char pad00[8];
    char pos[0xe4];         // 0x8: position block passed to the sink
    Slot_1ec060 *slot;             // 0xec
};


void __stdcall FUN_001ec060(Entity *entity, int name)
{
    if (entity == 0)
        return;
    if (entity->slot->FUN_001d4f70() != (*(unsigned __int64*)&DAT_004e3700))
        return;

    StringList_1ec060 path;
    path.FUN_001ef320();
    path.FUN_001ef370("Objects");
    path.FUN_001ef370("FE");
    if ((*(EventConfig_1ec060**)&DAT_004e36d8)->enabled)
        (*(EventConfig_1ec060**)&DAT_004e36d8)->sink->FUN_001efe20(&path, entity->pos, name, 100.0f);
    path.FUN_001ef350();
}
